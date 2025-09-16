#include "stack.h"

using std::ofstream;
using std::ifstream;

stack::stack() {
    this->head = nullptr;
    this->filename = "stack.txt";
    cargar();
}

void stack::push(int valor) {
    nodo* newNode = new nodo(valor);
    if(this->head == nullptr) {
        this->head = newNode;
        tamaño++;
        return;
    }

    newNode->next = this->head;
    this->head = newNode;
    tamaño++;
}

bool stack::pop() {
    if(this->head == nullptr) {
        return false;
    }

    nodo* temp = this->head;
    if(this->head->next != nullptr) {
        this->head = this->head->next;
    } else {
        this->head = nullptr;
    }

    delete temp;
    tamaño--;
    return true;
}

bool stack::search(int valor) {
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

int stack::peek() {
    return this->head->valor;
}

string stack::lista() {
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

void stack::cargar() {
    ifstream archivo(filename);
    if(!archivo.is_open()) return;

    while(head != nullptr) {
        nodo* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    tamaño = 0;

    int valor;
    while(archivo >> valor) {
        this->push(valor);
    }
    archivo.close();
}

void stack::borrarTodo() {
    nodo* it = head;

    while(it != nullptr) {
        nodo* temp = it;
        it = it->next;
        delete temp;
    }

    head = nullptr;
    tamaño = 0;
}
