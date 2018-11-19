#ifndef BASKET_H
#define BASKET_H

#include <QRectF>
#include <QColor>

// Clase para los rectángulos que el jugador debe tocar con la pelota
class Basket {
private:
    // Tanto el rectángulo que se muestra como la hitbox
    QRectF m_rect {0.0, 0.0, 50.0, 50.0};

public:
    // El color del rectángulo
    QColor m_color;

    void setRandomPosition(int width, int height);
    QRectF getRect();
};

#endif // BASKET_H
