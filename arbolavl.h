#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include "nodo.h"

class arbolAVL
{
public:
    nodoArbol* root;
    arbolAVL();

    void insertar(int valor);
    nodoArbol* insertarNodo(nodoArbol* actual, nodoArbol* nuevo);

    int getHeight(nodoArbol* nodo);
    int getBalanceFactor(nodoArbol* nodo);
    int max(int a, int b);

    nodoArbol* rotateRight(nodoArbol* y);
    nodoArbol* rotateLeft(nodoArbol* x);

    bool eliminar(int valor);
    nodoArbol* eliminarNodo(nodoArbol* actual, int valor);

    nodoArbol* sucesor(nodoArbol* actual);
    nodoArbol* mostLeftChild(nodoArbol* actual);
    nodoArbol* predecesor(nodoArbol* actual);
    nodoArbol* mostRightChild(nodoArbol* actual);
};

#endif // ARBOLAVL_H
