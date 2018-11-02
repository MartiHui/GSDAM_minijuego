#include <cstdlib>

#include "basket.h"
#include "color.h"

Basket::Basket(QWidget *parent) : QWidget(parent)
{

}

void Basket::setRandomPosition(int width, int height) {
    int posX = std::rand() % width;
    //rect_.setLeft(posX);
    int posY = std::rand() % height;
    //rect_.setTop(posY);
    rect_.setRect(posX, posY, rect_.width(), rect_.height());
}

Color Basket::getColor() {
    return color_;
}

QRectF Basket::getRect() {
    return rect_;
}
