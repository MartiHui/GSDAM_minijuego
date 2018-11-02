#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>

#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    ball_ = new Ball;

    basketList_[0] = new Basket;
    qDebug() << basketList_[0]->getColor().getColorRgb();
    basketList_[0]->getColor().setToRed();
    qDebug() << basketList_[0]->getColor().getColorRgb();

    basketList_[1] = new Basket;
    basketList_[1]->getColor().setToGreen();

    basketList_[2] = new Basket;
    basketList_[2]->getColor().setToBlue();

    changeBasketsPositions();
}

void Canvas::changeBasketsPositions() {
    for (int i = 0; i < 3; i++) {
        basketList_[i]->setRandomPosition(800, 700);
    }
}

void Canvas::paintEvent(QPaintEvent *) {
    QPen pen(QColor(0, 0, 0, 255));
    pen.setWidth(2);
    QPainter painter(this);
    painter.setPen(pen);

    QBrush brush(ball_->getColor().getColorRgb());
    painter.setBrush(brush);
    painter.drawEllipse(ball_->getEllipse(mouseX_, mouseY_));
    //painter.drawRect(ball_->getHitbox(mouseX_, mouseY_));

    for (int i = 0; i < 3; i++) {
        QBrush brush(basketList_[i]->getColor().getColorRgb());
        painter.setBrush(brush);

        painter.drawRect(basketList_[i]->getRect());
        //qDebug() << basketList_[i]->getRect();
        //qDebug() << basketList_[i]->getColor().getColorRgb();
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    mouseX_ = event->x();
    mouseY_ = event->y();
    repaint();
}
