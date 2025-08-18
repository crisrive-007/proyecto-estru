#include "dibujarlistas.h"
#include "nodoGrafico.h"


dibujarListas::dibujarListas(MainWindow* main) {
    this->m = main;
}

void dibujarListas::dibujarListaSimple(nodo* cabeza) {
    nodo* it = cabeza;

    m->x = 50;
    m->y = 100;
    m->indice = 0;
    m->nuevoTamaño = 0;
    QGraphicsScene* escena = m->getEscena();

    while(it != nullptr) {
        m->nuevoTamaño++;

        nodoGrafico* nodo = new nodoGrafico(it->valor);
        escena->addItem(nodo);

        QPoint puntoAparicion(m->x, m->y);

        if (m->nuevoTamaño > m->tamañoAnterior) {
            nodo->setPos(puntoAparicion);
            m->insertarNodo(nodo);
        }
        else {
            nodo->setPos(puntoAparicion);
        }

        if(it->next != nullptr) {
            escena->addLine(m->x+50, m->y+24, m->x+100, m->y+24, QPen(Qt::white));
        }

        it = it->next;
        m->x += 100;
    }

    m->tamañoAnterior = m->nuevoTamaño;
}

void dibujarListas::dibujarListaDoble(nodoDLL* cabeza) {
    nodoDLL* it = cabeza;
    m->x = 50;
    m->y = 100;
    m->indice = 0;
    m->nuevoTamaño = 0;
    QGraphicsScene* escena = m->getEscena();

    while(it != nullptr) {
        m->nuevoTamaño++;
        nodoGrafico* nodo = new nodoGrafico(it->valor);
        escena->addItem(nodo);
        QPoint puntoAparicion(m->x, m->y);

        if (m->nuevoTamaño > m->tamañoAnterior) {
            nodo->setPos(puntoAparicion);
            m->insertarNodo(nodo);
        }
        else {
            nodo->setPos(puntoAparicion);
        }

        if(it->next != nullptr) {
            escena->addLine(m->x+50, m->y+12, m->x+100, m->y+12, QPen(Qt::white));
            escena->addLine(m->x+95, m->y+7, m->x+100, m->y+12, QPen(Qt::white));
            escena->addLine(m->x+95, m->y+17, m->x+100, m->y+12, QPen(Qt::white));
        }

        if(it->prev != nullptr) {
            escena->addLine(m->x-50, m->y+36, m->x, m->y+36, QPen(Qt::white));
            escena->addLine(m->x-50, m->y+36, m->x-45, m->y+31, QPen(Qt::white));
            escena->addLine(m->x-50, m->y+36, m->x-45, m->y+41, QPen(Qt::white));
        }

        it = it->next;
        m->x += 100;
    }

    m->tamañoAnterior = m->nuevoTamaño;
}
