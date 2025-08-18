#include "nodografico.h"

nodoGrafico::nodoGrafico(int valor, QGraphicsItem* parent)
    : QGraphicsItem(parent), valor(valor) {}

QRectF nodoGrafico::boundingRect() const {
    return QRectF(0, 0, 50, 50);
}

// Dibuja el nodo
void nodoGrafico::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    // Fondo del nodo
    painter->setBrush(Qt::black);
    painter->setPen(Qt::white);
    painter->drawEllipse(boundingRect());

    // Texto centrado
    painter->setPen(Qt::white);
    painter->setFont(QFont("Arial", 15));
    painter->drawText(boundingRect(), Qt::AlignCenter, QString::number(valor));
}

// Cambiar valor
void nodoGrafico::setValor(int nuevoValor) {
    valor = nuevoValor;
    update();
}

int nodoGrafico::getValor() const {
    return valor;
}
