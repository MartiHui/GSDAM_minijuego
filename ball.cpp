#include "ball.h"

Ball::Ball(QWidget *parent) : QWidget(parent)
{
    changeColor();
}

void Ball::changeColor() {
    switch(std::rand() % 3) {
    case 0:
        color_.setRgb(255, 0, 0);
        break;

    case 1:
        color_.setRgb(0, 255, 0);
        break;

    case 2:
        color_.setRgb(0, 0, 255);
        break;
    }
}

QRectF Ball::getHitbox(int posX, int posY) {
    return QRectF(posX-hitbox_.width()/2, posY-hitbox_.height()/2, hitbox_.width(), hitbox_.height());
}

QRectF Ball::getEllipse(int posX, int posY) {
    return QRectF(posX-ellipse_.width()/2, posY-ellipse_.height()/2, ellipse_.width(), ellipse_.height());
}


