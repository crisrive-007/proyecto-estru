#include "listaenlazadadoble.h"

using std::ofstream;
using std::ifstream;

listaEnlazadaDoble::listaEnlazadaDoble() {
    this->head = nullptr;
    this->filename = "listaDoble.txt";
    this->valorNuevo = 0;
    this->tamaño = 0;
    cargar();
}

void listaEnlazadaDoble::insertar(int valor, int pos) {
    nodoDLL* newNode = new nodoDLL(valor);
    this->valorNuevo = valor;

    //caso 1: la lista esta vacia
    if(this->head == nullptr) {
        this->head = newNode;
        tamaño++;
        return;
    }

    //caso 2: insertar en la cabeza
    if(pos == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        tamaño++;
        return;
    }

    nodoDLL* it = head;

    //caso 3: insertar al final
    if(pos == -1 || pos >= tamaño) {
        while(it->next != nullptr) {
            it = it->next;
        }
        it->next = newNode;
        newNode->prev = it;
        tamaño++;
        return;
    }

    //caso 4: insertar pos posicion
    for (int i = 0; i < pos-1 && it != nullptr; ++i) {
        it = it->next;
    }

    it->next->prev = newNode;
    newNode->next = it->next;
    it->next = newNode;
    newNode->prev = it;
    tamaño++;
}

bool listaEnlazadaDoble::eliminar(int valor, int pos) {
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

bool listaEnlazadaDoble::eliminarPorPosicion(int pos) {
    //caso 1: posicion ingresada es invalida
    if(pos < 0 || pos >= tamaño) {
        return false;
    }

    //caso 2: eliminar la cabeza
    if(pos == 0) {
        nodoDLL* temp = head;
        if(head->next != nullptr) {
            head->next->prev = nullptr;
        }
        head = head->next;
        delete temp;
        tamaño--;
        return true;
    }

    //caso 3: eliminar enmedio
    nodoDLL* it = head;
    for(int i = 0; i < pos-1; i++) {
        it = it->next;
    }

    nodoDLL* temp = it->next;
    it->next = temp->next;
    if(temp->next != nullptr) {
        temp->next->prev = it;
    }
    delete temp;
    tamaño--;
    return true;
}

bool listaEnlazadaDoble::eliminarPorValor(int valor) {
    //caso 1: eliminar la cabeza
    if(head->valor == valor) {
        nodoDLL* temp = head;
        if(head->next != nullptr) {
            head->next->prev = nullptr;
        }
        head = head->next;
        delete temp;
        tamaño--;
        return true;
    }

    //caso 2: buscar nodo a eliminar
    nodoDLL* it = this->head;
    while(it->next != nullptr) {
        if(it->next->valor == valor) {
            nodoDLL* tmp = it->next;
            it->next = tmp->next;
            if(tmp->next != nullptr) {
                tmp->next->prev = it;
            }
            delete tmp;
            tamaño--;
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
        if(it->valor == valor) {
            return true;
        }

        it = it->next;
    }

    return false;
}

int listaEnlazadaDoble::getTamaño() {
    return this->tamaño;
}

int listaEnlazadaDoble::getValorNodo(int pos) {
    if(pos < 0 || pos >= tamaño || head == nullptr) {
        return -1;
    }

    nodoDLL* it = head;
    for(int i = 0; i < pos; i++) {
        it = it->next;
    }

    return it->valor;
}

string listaEnlazadaDoble::lista() {
    string datos;

    nodoDLL* it = head;
    while(it != nullptr) {
        datos += std::to_string(it->valor);
        if(it->next != nullptr) {
            datos += "\n";
        }
        it = it->next;
    }

    return datos;
}

void listaEnlazadaDoble::cargar() {
    ifstream archivo(filename);
    if(!archivo.is_open()) return;

    while(head != nullptr) {
        nodoDLL* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    tamaño = 0;

    int valor;
    while(archivo >> valor) {
        this->insertar(valor, 0);
    }
    archivo.close();
}

void listaEnlazadaDoble::borrarTodo() {
    nodoDLL* it = head;

    while(it != nullptr) {
        nodoDLL* temp = it;
        it = it->next;
        delete temp;
    }

    head = nullptr;
    tamaño = 0;
}
