#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QString>

#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    ball_ = new Ball();

    basketList_[0] = new Basket();
    basketList_[0]->color_.setRgb(255, 0, 0);

    basketList_[1] = new Basket();
    basketList_[1]->color_.setRgb(0, 255, 0);

    basketList_[2] = new Basket();
    basketList_[2]->color_.setRgb(0, 0, 255);

    changeBasketsPositions();
}

void Canvas::changeBasketsPositions() {
    for (int i = 0; i < 3; i++) {
        bool correctPosition = true;
        do {
            basketList_[i]->setRandomPosition(800, 700);
            for (int j = 0; j < i; j++) {
                if (basketList_[i]->getRect().intersects(basketList_[j]->getRect())) {
                    correctPosition = false;
                    break;
                } else {
                    correctPosition = true;
                } // end if
            } // end for
        } while (!correctPosition);
    }
}

void Canvas::paintEvent(QPaintEvent *) {
    QPen pen(QColor(0, 0, 0, 255));
    pen.setWidth(2);
    QPainter painter(this);
    painter.setPen(pen);
    //painter.drawRect(ball_->getHitbox(mouseX_, mouseY_));

    for (int i = 0; i < 3; i++) {
        QBrush brush(basketList_[i]->color_);
        painter.setBrush(brush);

        painter.drawRect(basketList_[i]->getRect());
    }

    QBrush brush(ball_->color_);
    painter.setBrush(brush);
    painter.drawEllipse(ball_->getEllipse(mouseX_, mouseY_));
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    mouseX_ = event->x();
    mouseY_ = event->y();

    for (int i = 0; i < 3; i++) {
        if (ball_->getHitbox(mouseX_, mouseY_).intersects(basketList_[i]->getRect())) {
            if (ball_->color_ == basketList_[i]->color_) {
                puntuacion_++;
            } else {
                puntuacion_ -= 100;
            }

            updatePuntuacion();

            ball_->changeColor();

            changeBasketsPositions();

        }
    }

    repaint();
}

void Canvas::updatePuntuacion() {
    info_->setText("Puntos: " + QString::number(puntuacion_));
}
