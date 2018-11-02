#include <QColor>
#include <QDebug>
#include <cstdlib>

#include "color.h"

Color::Color() {
    colorRgb_.setRgb(255, 255, 255);
}

void Color::setToRed() {
    qDebug() << "entrando en setToRed";
    colorRgb_.setRgb(255, 0, 0);
    colorName_ = Color::RED;
}

void Color::setToGreen() {
    colorRgb_.setRgb(0, 255, 0);
    colorName_ = Color::GREEN;
}

void Color::setToBlue() {
    colorRgb_.setRgb(0, 0, 255);
    colorName_ = Color::BLUE;
}

void Color::setRandomColor() {
    switch(std::rand() % 3) {
    case 0:
        setToRed();
        break;

    case 1:
        setToGreen();
        break;

    case 2:
        setToBlue();
        break;
    }
}

bool Color::isSameColor(Color other) {
    return colorName_ == other.colorName_;
}

QColor Color::getColorRgb() {
    return colorRgb_;
}
