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
