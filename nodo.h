#ifndef NODO_H
#define NODO_H

class nodo
{
public:
    int valor;
    nodo* next;
    nodo(int valor);
};

class nodoDLL
{
public:
    int valor;
    nodoDLL* next;
    nodoDLL* prev;
    nodoDLL(int valor);
};

#endif // NODO_H
