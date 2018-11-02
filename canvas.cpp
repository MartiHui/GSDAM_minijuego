#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QString>

#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);

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
    /*for (int i = 0; i < 3; i++) {
        qDebug() << "b1";
        bool correctPosition = true;
        do {
            qDebug() << "b2";
            basketList_[i]->setRandomPosition(800, 700);
            if (basketList_[i]->getRect().intersects(ball_->getHitbox(mouseX_, mouseY_))) {
                qDebug() << "b3";
                correctPosition = false;
            } else {
                qDebug() << "b4" << i << " ";
                for (int j = 0; j < 3; j++)
                {
                    qDebug() << "w";
                }


                for (int j = 0; j < i-1; j++) {
                    qDebug() << "b5";
                    qDebug() << "i: " << i << "J: " << j;
                    if (basketList_[i]->getRect().intersects(basketList_[j]->getRect())) {

                        qDebug() << "b6";
                        correctPosition = false;
                        break;
                    }
                }



            }
            qDebug() << "b7";
        } while (!correctPosition);
    }*/
    for (int i = 0; i < 3; i++) {
        basketList_[i]->setRandomPosition(800, 700);
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
        //qDebug() << basketList_[i]->getRect();
        //qDebug() << basketList_[i]->getColor().getColorRgb();
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

            info_->setText(QString::number(puntuacion_));

            ball_->changeColor();
            qDebug() << "a42";

            changeBasketsPositions();
            qDebug() << "a5";

        }
    }

    repaint();
}
