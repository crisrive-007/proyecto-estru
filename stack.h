#ifndef STACK_H
#define STACK_H

#include "nodo.h"
#include <iostream>
#include <fstream>

using std::string;

class stack
{
public:
    nodo* head;
    int tamaño;
    string filename;
    stack();
    void push(int valor);
    bool pop();
    bool search(int valor);
    int peek();
    int getTamaño() {
        return tamaño;
    }
    void cargar();
    string lista();
    void borrarTodo();
};

#endif // STACK_H
