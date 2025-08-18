#include "listaenlazadasimple.h"

listaEnlazadaSimple::listaEnlazadaSimple() {
    this->head = nullptr;
}

void listaEnlazadaSimple::insertar(int valor, int pos) {
    nodo* newNode = new nodo(valor);

    if(head == nullptr) {
        head = newNode;
        return;
    }

    nodo* it = head;

    while(it->next != nullptr) {
        it = it->next;
    }

    it->next = newNode;
    tamaño++;
}

bool listaEnlazadaSimple::eliminar(int valor) {
    if(head == nullptr) {
        return false;
    }

    if(head->valor == valor) {
        nodo* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    nodo* it = head;
    while(it->next != nullptr) {
        if(it->next->valor == valor) {
            nodo* temp = it->next;
            it->next = temp->next;
            delete temp;
            return true;
        }

        it = it->next;
    }

    return false;
}

bool listaEnlazadaSimple::buscar(int valor) {
    if(head == nullptr) {
        return false;
    }

    nodo* it = head;
    while(it != nullptr) {
        if(it->valor == valor) {
            return true;
        }

        it = it->next;
    }

    return false;
}

nodo* listaEnlazadaSimple::getHead() {
    return this->head;
}
