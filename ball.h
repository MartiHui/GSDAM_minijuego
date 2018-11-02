#ifndef BALL_H
#define BALL_H


#include <QRectF>
#include <QColor>

class Ball
{

private:
    QRectF hitbox_ {0.0, 0.0, 45.0, 45.0};
    QRectF ellipse_ {0.0, 0.0, 65.0, 65.0};

public:
    QColor color_;

    Ball();
    void changeColor();
    QRectF getHitbox(int posX, int posY);
    QRectF getEllipse(int posX, int posY);


};

#endif // BALL_H
