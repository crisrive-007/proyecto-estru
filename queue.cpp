#include "queue.h"

using std::ofstream;
using std::ifstream;

queue::queue() {
    this->head = nullptr;
    this->tail = nullptr;
    this->filename = "queue.txt";
    cargar();
}

void queue::enqueue(int valor) {
    nodo* newNode = new nodo(valor);
    if(this->head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
        tamaño++;
        return;
    }

    this->tail->next = newNode;
    this->tail = newNode;
    tamaño++;
}

bool queue::dequeue() {
    if(this->head == nullptr) {
        return false;
    }

    nodo* temp = this->head;
    this->head = this->head->next;
    delete temp;
    tamaño--;
    return true;
}

bool queue::search(int valor) {
    if(this->head == nullptr) {
        return false;
    }

    nodo* it = this->head;

    while(it != nullptr) {
        if(it->valor == valor) {
            return true;
        }

        it = it->next;
    }

    return false;
}

string queue::lista() {
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

void queue::cargar() {
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
        this->enqueue(valor);
    }
    archivo.close();
}

void queue::borrarTodo() {
    nodo* it = head;

    while(it != nullptr) {
        nodo* temp = it;
        it = it->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;
    tamaño = 0;
}
