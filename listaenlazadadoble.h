#ifndef LISTAENLAZADADOBLE_H
#define LISTAENLAZADADOBLE_H

#include "nodo.h"

class listaEnlazadaDoble
{
public:
    nodoDLL* head;
    listaEnlazadaDoble();
    void insertar(int valor);
    bool eliminar(int valor);
    bool buscar(int valor);
};

#endif // LISTAENLAZADADOBLE_H
