#ifndef LISTAENLAZADASIMPLE_H
#define LISTAENLAZADASIMPLE_H

#include "nodo.h"
#include <iostream>
#include <fstream>

using std::string;

class listaEnlazadaSimple
{
public:
    nodo* head;
    int tamaño;
    int valorNuevo;
    string filename;

    listaEnlazadaSimple();

    void insertar(int valor, int pos);

    bool eliminar(int valor, int pos);
    bool eliminarPorPosicion(int pos);
    bool eliminarPorValor(int valor);

    bool buscar(int valor);

    nodo* getHead();
    int getTamaño();
    int getValorNodo(int pos);

    string lista();
    void cargar();
    void borrarTodo();
};

#endif // LISTAENLAZADASIMPLE_H
