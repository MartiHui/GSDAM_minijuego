#ifndef BASKET_H
#define BASKET_H

#include <QWidget>
#include <QRectF>

#include "color.h"

class Basket : public QWidget
{
    Q_OBJECT
private:
    Color color_;
    QRectF rect_ {0.0, 0.0, 50.0, 50.0};

public:
    explicit Basket(QWidget *parent = nullptr);
    void setRandomPosition(int width, int height);
    Color getColor();
    QRectF getRect();

signals:

public slots:
};

#endif // BASKET_H
