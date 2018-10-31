#ifndef COLOR_H
#define COLOR_H

#include <QColor>

class Color
{
private:
    QColor colorRgb_;
    enum name {RED, GREEN, BLUE} colorName_;

public:
    Color();
    void setToRed();
    void setToGreen();
    void setToBlue();
    void setRandomColor();

    bool isSameColor(Color other);
    QColor getColorRgb();
};

#endif // COLOR_H
