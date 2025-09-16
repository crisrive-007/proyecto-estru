#ifndef ARBOLBST_H
#define ARBOLBST_H

#include "nodo.h"

class arbolBST
{
public:
    nodoArbol* root;
    arbolBST();

    bool insertar(int valor);
    nodoArbol* insertarNodo(nodoArbol* actual, nodoArbol* nuevo);

    bool eliminar(int valor);
    nodoArbol* eliminarNodo(nodoArbol* actual, int valor);

    nodoArbol* sucesor(nodoArbol* actual);
    nodoArbol* mostLeftChild(nodoArbol* actual);
    nodoArbol* predecesor(nodoArbol* actual);
    nodoArbol* mostRightChild(nodoArbol* actual);
};

#endif // ARBOLBST_H
