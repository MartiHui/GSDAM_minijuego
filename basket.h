#ifndef BASKET_H
#define BASKET_H

#include <QWidget>

#include "color.h"

class Basket : public QWidget
{
    Q_OBJECT
private:
    Color color_;

public:
    explicit Basket(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // BASKET_H
