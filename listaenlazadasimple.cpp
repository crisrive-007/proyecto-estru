#include "listaenlazadasimple.h"

using std::ofstream;
using std::ifstream;

listaEnlazadaSimple::listaEnlazadaSimple() {
    this->head = nullptr;
    this->filename = "listaSimple.txt";
    this->valorNuevo = 0;
    this->tamaño = 0;
}

void listaEnlazadaSimple::insertar(int valor, int pos) {
    nodo* newNode = new nodo(valor);
    this->valorNuevo = valor;

    //caso 1: la lista esta vacia
    if(head == nullptr) {
        head = newNode;
        tamaño++;
        return;
    }

    //caso 2: insertar en la cabeza
    if(pos == 0) {
        newNode->next = head;
        head = newNode;
        tamaño++;
        return;
    }

    //caso 3: insertar al final
    if(pos == -1 || pos >= tamaño) {
        nodo* it = head;
        while(it->next != nullptr) {
            it = it->next;
        }
        it->next = newNode;
        tamaño++;
        return;
    }

    //caso 4: insertar por posicion
    nodo* it = head;
    for(int i = 0; i < pos - 1 && it != nullptr; i++) {
        it = it->next;
    }

    if(it != nullptr) {
        newNode->next = it->next;
        it->next = newNode;
        tamaño++;
    }
}

bool listaEnlazadaSimple::eliminar(int valor, int pos) {
    if(head == nullptr) {
        return false;
    }

    // Eliminar por posición
    if(valor == -1 && pos != -1) {
        return eliminarPorPosicion(pos);
    }
    // Eliminar por valor
    else if(pos == -1 && valor != -1) {
        return eliminarPorValor(valor);
    }

    return false;
}

bool listaEnlazadaSimple::eliminarPorPosicion(int pos) {
    //caso 1: posicion ingresada es invalida
    if(pos < 0 || pos >= tamaño) {
        return false;
    }

    //caso 2: eliminar la cabeza
    if(pos == 0) {
        nodo* temp = head;
        head = head->next;
        delete temp;
        tamaño--;
        return true;
    }

    //caso 3: eliminar enmedio
    nodo* it = head;
    for(int i = 0; i < pos-1; i++) {
        it = it->next;
    }

    nodo* temp = it->next;
    it->next = temp->next;
    delete temp;
    tamaño--;
    return true;
}

bool listaEnlazadaSimple::eliminarPorValor(int valor) {
    //caso 1: eliminar la cabeza
    if(head->valor == valor) {
        nodo* temp = head;
        head = head->next;
        delete temp;
        tamaño--;
        return true;
    }

    //caso 2: buscar nodo a eliminar
    nodo* it = head;
    while(it->next != nullptr) {
        if(it->next->valor == valor) {
            nodo* temp = it->next;
            it->next = temp->next;
            delete temp;
            tamaño--;
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

int listaEnlazadaSimple::getTamaño() {
    return this->tamaño;
}

int listaEnlazadaSimple::getValorNodo(int pos) {
    if(pos < 0 || pos >= tamaño || head == nullptr) {
        return -1;
    }

    nodo* it = head;
    for(int i = 0; i < pos; i++) {
        it = it->next;
    }

    return it->valor;
}

string listaEnlazadaSimple::lista() {
    string datos;

    nodo* it = head;
    while(it != nullptr) {
        datos += std::to_string(it->valor);
        if(it->next != nullptr) {
            datos += "\n";
        }
        it = it->next;
    }

    return datos;
}

void listaEnlazadaSimple::cargar() {
    ifstream archivo(filename);
    if(!archivo.is_open()) return;

    borrarTodo();

    int valor;
    while(archivo >> valor) {
        insertar(valor, -1);
    }

    archivo.close();
}

void listaEnlazadaSimple::borrarTodo() {
    nodo* it = head;

    while(it != nullptr) {
        nodo* temp = it;
        it = it->next;
        delete temp;
    }

    head = nullptr;
    tamaño = 0;
}
