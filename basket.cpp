#include <cstdlib>

#include "basket.h"

// Asigna al objeto una posición aleatoria dentro de la pantalla
// Parametros:
//      width : anchura de la ventana
//      height : altura de la ventana
void Basket::setRandomPosition(int width, int height) {
    int posX = std::rand() % width;
    int posY = std::rand() % height;
    m_rect.setRect(posX, posY, m_rect.width(), m_rect.height());
}

QRectF Basket::getRect() {
    return m_rect;
}
