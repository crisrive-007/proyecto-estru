#include "listaenlazadadoble.h"

listaEnlazadaDoble::listaEnlazadaDoble() {
    this->head = nullptr;
}

void listaEnlazadaDoble::insertar(int valor) {
    nodoDLL* newNode = new nodoDLL(valor);

    if(this->head == nullptr) {
        this->head = newNode;
        return;
    }

    nodoDLL* it = head;
    while(it->next != nullptr) {
        it = it->next;
    }

    it->next = newNode;
    newNode->prev = it;
}

bool listaEnlazadaDoble::eliminar(int valor) {
    if(this->head == nullptr) {
        return false;
    }

    if(this->head->valor == valor) {
        nodoDLL* tmp = this->head;
        if(this->head->next != nullptr) {
            this->head->next->prev = nullptr;
        }
        this->head = this->head->next;
        delete tmp;
        return true;
    }

    nodoDLL* it = this->head;
    while(it->next != nullptr) {
        if(it->next->valor == valor) {
            nodoDLL* tmp = it->next;
            it->next = tmp->next;
            if(tmp->next != nullptr) {
                tmp->next->prev = it;
            }
            delete tmp;
            return true;
        }
        it = it->next;
    }
    return false;
}

bool listaEnlazadaDoble::buscar(int valor) {
    if(this->head == nullptr) {
        return false;
    }

    nodoDLL* it = head;
    while(it != nullptr) {
        if(it->valor = valor) {
            return true;
        }

        it = it->next;
    }

    return false;
}
