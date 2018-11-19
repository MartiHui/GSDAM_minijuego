#ifndef BALL_H
#define BALL_H

#include <QRectF>
#include <QColor>

// Clase para la pelota que el jugador moverá por la pantalla
class Ball {
private:
    // El rectángulo que detecterá el contacto
    QRectF m_hitbox {0.0, 0.0, 45.0, 45.0};
    // La elipse que se mostrará en pantalla
    QRectF m_ellipse {0.0, 0.0, 65.0, 65.0};

public:
    // El color actual de la pelota
    QColor m_color;

    Ball();
    void changeColor();
    QRectF getHitbox(int posX, int posY);
    QRectF getEllipse(int posX, int posY);


};

#endif // BALL_H
