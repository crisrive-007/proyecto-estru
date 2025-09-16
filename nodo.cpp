#include "nodo.h"

nodo::nodo(int valor) {
    this->valor = valor;
    this->next = nullptr;
}

nodoDLL::nodoDLL(int valor) {
    this->valor = valor;
    this->next = nullptr;
    this->prev = nullptr;
}

nodoStack::nodoStack(int valor) {
    this->valor = valor;
    this->next = nullptr;
}

nodoArbol::nodoArbol(int valor) {
    this->valor = valor;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 1;
}
