#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QString>

#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    m_ball = new Ball();

    // Creamos tres canastas de tres colores diferentes
    m_basketList[0] = new Basket();
    m_basketList[0]->m_color.setRgb(255, 0, 0);

    m_basketList[1] = new Basket();
    m_basketList[1]->m_color.setRgb(0, 255, 0);

    m_basketList[2] = new Basket();
    m_basketList[2]->m_color.setRgb(0, 0, 255);

    // Posicionamos las canastas en la ventana
    changeBasketsPositions();
}


// Cambiamos la posición de todas las canastas, comprobando que no se solapan entre ellas
void Canvas::changeBasketsPositions() {
    for (int i = 0; i < 3; i++) {
        bool correctPosition = true;
        do {
            m_basketList[i]->setRandomPosition(800, 700);
            for (int j = 0; j < i; j++) {
                if (m_basketList[i]->getRect().intersects(m_basketList[j]->getRect())) {
                    correctPosition = false;
                    break;
                } else {
                    correctPosition = true;
                } // end if
            } // end for
        } while (!correctPosition);
    }
}

void Canvas::paintEvent(QPaintEvent *) {
    QPen pen(QColor(0, 0, 0, 255)); // Para dibujar un borde en todo lo que dibujemos
    pen.setWidth(2);
    QPainter painter(this);
    painter.setPen(pen);
    //painter.drawRect(ball_->getHitbox(mouseX_, mouseY_));

    // Dibujar las canastas
    for (int i = 0; i < 3; i++) {
        QBrush brush(m_basketList[i]->m_color); // Para rellenar el rectángulo
        painter.setBrush(brush);

        painter.drawRect(m_basketList[i]->getRect());
    }

    // Dibujar la pelota
    QBrush brush(m_ball->m_color);
    painter.setBrush(brush);
    painter.drawEllipse(m_ball->getEllipse(m_mouseX, m_mouseY));
}

// Cuando movemos el ratón comprobamos si hemos tocado una canasta. En caso afirmativo,
// si es del mismo color se le aumenta la puntuación, de lo contrario, se le resta
void Canvas::mouseMoveEvent(QMouseEvent *event) {
    m_mouseX = event->x();
    m_mouseY = event->y();

    for (int i = 0; i < 3; i++) {
        if (m_ball->getHitbox(m_mouseX, m_mouseY).intersects(m_basketList[i]->getRect())) {
            if (m_ball->m_color == m_basketList[i]->m_color) {
                m_puntuacion++;
            } else {
                m_puntuacion -= 100;
            }

            updatePuntuacion();

            m_ball->changeColor();

            changeBasketsPositions(); // Recolocamos las canastas

            break;
        }
    }

    repaint();
}

// Modificamos la etiqueta para que muestre la puntuación correcta
void Canvas::updatePuntuacion() {
    m_info->setText("Puntos: " + QString::number(m_puntuacion));
}
