#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QImage>
#include <QPaintEvent>
#include <QLabel>

#include "ball.h"
#include "basket.h"

// Widget propio para mostrar el juego
class Canvas : public QWidget {
    Q_OBJECT
public:
    int m_puntuacion {0}; // Puntuación actual del jugador
    QLabel *m_info; // Etiqueta para mostrar la puntuación

    explicit Canvas(QWidget *parent = nullptr);
    void changeBasketsPositions();
    void updatePuntuacion();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

private:
    Ball *m_ball;
    Basket *m_basketList[3]; // Lista con todos los rectángulos de la partida
    int m_mouseX {0};
    int m_mouseY {0};
};

#endif // CANVAS_H
