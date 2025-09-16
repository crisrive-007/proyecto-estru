#ifndef DIBUJARLISTAS_H
#define DIBUJARLISTAS_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPen>
#include "nodo.h"
#include "listaenlazadasimple.h"
#include "listaenlazadadoble.h"

class MainWindow;

class dibujarListas
{
public:
    dibujarListas(MainWindow* main, listaEnlazadaSimple* simple, listaEnlazadaDoble* doble);
    listaEnlazadaSimple* simple;
    listaEnlazadaDoble* doble;

    void dibujarListaSimple(nodo* cabeza);
    void dibujarListaDoble(nodoDLL* cabeza);
    void dibujarStack(nodo* cabeza);
    void dibujarQueue(nodo* cabeza);
    void dibujarArbolBST(nodoArbol* root);
    void dibujarArbolAVL(nodoArbol* root);

private:
    MainWindow* m;
    void dibujarNodoArbol(QGraphicsScene* escena, nodoArbol* nodo, int x, int y, int espacioHorizontal, int espacioVertical, int nivel);
    int contarNodos(nodoArbol* nodo);
    int alturaArbol(nodoArbol* nodo);
};
#endif // DIBUJARLISTAS_H
