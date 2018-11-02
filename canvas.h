#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QImage>
#include <QPaintEvent>
#include <QLabel>

#include "ball.h"
#include "basket.h"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    int puntuacion_ {0};
    QLabel *info_;

    explicit Canvas(QWidget *parent = nullptr);
    void changeBasketsPositions();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

private:
    Ball *ball_;
    Basket *basketList_[3];
    int mouseX_ {0};
    int mouseY_ {0};
};

#endif // CANVAS_H
