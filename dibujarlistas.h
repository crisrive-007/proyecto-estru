#ifndef DIBUJARLISTAS_H
#define DIBUJARLISTAS_H

#include "mainwindow.h"
#include <QGraphicsScene>

class dibujarListas
{
public:
    dibujarListas(MainWindow* main);
    MainWindow* m;
    void dibujarListaSimple(nodo* cabeza);
    void dibujarListaDoble(nodoDLL* cabeza);
    void dibujarStack();
    void dibujarQueue();
    void dibujarArbolBST();
    void dibujarArbolAVL();
};

#endif // DIBUJARLISTAS_H
