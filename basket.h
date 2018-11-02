#ifndef BASKET_H
#define BASKET_H

#include <QWidget>
#include <QRectF>
#include <QColor>

class Basket : public QWidget
{
    Q_OBJECT
private:
    QRectF rect_ {0.0, 0.0, 50.0, 50.0};

public:
    QColor color_;

    explicit Basket(QWidget *parent = nullptr);
    void setRandomPosition(int width, int height);
    QRectF getRect();

signals:

public slots:
};

#endif // BASKET_H
