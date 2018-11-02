#include <cstdlib>

#include "basket.h"

Basket::Basket()
{

}

void Basket::setRandomPosition(int width, int height) {
    int posX = std::rand() % width;
    int posY = std::rand() % height;
    rect_.setRect(posX, posY, rect_.width(), rect_.height());
}

QRectF Basket::getRect() {
    return rect_;
}
