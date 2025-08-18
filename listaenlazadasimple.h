#ifndef LISTAENLAZADASIMPLE_H
#define LISTAENLAZADASIMPLE_H

#include "nodo.h"

class listaEnlazadaSimple
{
public:
    nodo* head;
    int tamaño;
    listaEnlazadaSimple();
    void insertar(int valor, int pos);
    bool eliminar(int valor);
    bool buscar(int valor);
    nodo* getHead();
};

#endif // LISTAENLAZADASIMPLE_H
