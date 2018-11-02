#ifndef BALL_H
#define BALL_H

#include <QWidget>
#include <QRectF>
#include <QColor>

class Ball : public QWidget
{
    Q_OBJECT
private:
    QRectF hitbox_ {0.0, 0.0, 45.0, 45.0};
    QRectF ellipse_ {0.0, 0.0, 65.0, 65.0};

public:
    QColor color_;

    explicit Ball(QWidget *parent = nullptr);
    void changeColor();
    QRectF getHitbox(int posX, int posY);
    QRectF getEllipse(int posX, int posY);


signals:

public slots:
};

#endif // BALL_H
