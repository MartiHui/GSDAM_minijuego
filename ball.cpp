#include "ball.h"

Ball::Ball(QWidget *parent) : QWidget(parent)
{
    changeColor();
}

void Ball::changeColor() {
    color_.setRandomColor();
}

Color Ball::getColor() {
    return color_;
}

QRectF Ball::getHitbox(int posX, int posY) {
    return QRectF(posX-hitbox_.width()/2, posY-hitbox_.height()/2, hitbox_.width(), hitbox_.height());
}

QRectF Ball::getEllipse(int posX, int posY) {
    return QRectF(posX-ellipse_.width()/2, posY-ellipse_.height()/2, ellipse_.width(), ellipse_.height());
}


