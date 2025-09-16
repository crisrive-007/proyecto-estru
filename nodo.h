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

class nodoStack {
public:
    int valor;
    nodoStack* next;
    nodoStack(int valor);
};

class nodoArbol {
public:
    int valor;
    nodoArbol* left;
    nodoArbol* right;
    int height;
    nodoArbol(int valor);
};

#endif // NODO_H
