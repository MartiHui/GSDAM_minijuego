#ifndef BASKET_H
#define BASKET_H


#include <QRectF>
#include <QColor>

class Basket
{

private:
    QRectF rect_ {0.0, 0.0, 50.0, 50.0};

public:
    QColor color_;

    Basket();
    void setRandomPosition(int width, int height);
    QRectF getRect();

};

#endif // BASKET_H
