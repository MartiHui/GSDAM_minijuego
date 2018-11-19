#include "ball.h"

Ball::Ball() {
    changeColor(); // Asignamos un color inicial
}

// Asigna a la pelota un color aleatorio entre verde, rojo y azul
void Ball::changeColor() {
    switch(std::rand() % 3) {
    case 0:
        m_color.setRgb(255, 0, 0);
        break;

    case 1:
        m_color.setRgb(0, 255, 0);
        break;

    case 2:
        m_color.setRgb(0, 0, 255);
        break;
    }
}

// Devuelve la hitbox centrada en el ratón
// Parametros:
//      posX : posición X del ratón
//      posY : posición Y del ratón
QRectF Ball::getHitbox(int posX, int posY) {
    return QRectF(posX-m_hitbox.width()/2,
                  posY-m_hitbox.height()/2,
                  m_hitbox.width(),
                  m_hitbox.height());
}

// Devuelve la elipse centrada en el ratón
// Parametros:
//      posX : posición X del ratón
//      posY : posición Y del ratón
QRectF Ball::getEllipse(int posX, int posY) {
    return QRectF(posX-m_ellipse.width()/2,
                  posY-m_ellipse.height()/2,
                  m_ellipse.width(),
                  m_ellipse.height());
}


