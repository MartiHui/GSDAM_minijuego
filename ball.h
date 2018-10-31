#ifndef BALL_H
#define BALL_H

#include <QWidget>

#include "color.h"

class Ball : public QWidget
{
    Q_OBJECT
private:
    Color color_;
public:
    explicit Ball(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // BALL_H
