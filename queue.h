#ifndef QUEUE_H
#define QUEUE_H

#include "nodo.h"
#include <iostream>
#include <fstream>

using std::string;

class queue
{
public:
    nodo* head;
    nodo* tail;
    int tamaño;
    string filename;
    queue();
    void enqueue(int valor);
    bool dequeue();
    bool search(int valor);
    int getTamaño() {
        return tamaño;
    }
    string lista();
    void cargar();
    void borrarTodo();
};

#endif // QUEUE_H
