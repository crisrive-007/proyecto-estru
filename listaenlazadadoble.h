#ifndef LISTAENLAZADADOBLE_H
#define LISTAENLAZADADOBLE_H

#include "nodo.h"
#include <iostream>
#include <fstream>

using std::string;

class listaEnlazadaDoble
{
public:
    nodoDLL* head;
    int tamaño;
    int valorNuevo;
    string filename;

    listaEnlazadaDoble();

    void insertar(int valor, int pos);

    bool eliminar(int valor, int pos);
    bool eliminarPorPosicion(int pos);
    bool eliminarPorValor(int valor);

    bool buscar(int valor);

    int getTamaño();
    int getValorNodo(int pos);
    void cargar();
    string lista();
    void borrarTodo();
};

#endif // LISTAENLAZADADOBLE_H
