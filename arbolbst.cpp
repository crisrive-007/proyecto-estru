#include "arbolbst.h"

arbolBST::arbolBST() {
    this->root = nullptr;
}

bool arbolBST::insertar(int valor) {
    nodoArbol* newNode = new nodoArbol(valor);

    //caso 1: la raiz esta vacia
    if(this->root == nullptr) {
        this->root = newNode;
        return true;
    }

    //caso 2: validar duplicado
    if(this->root->valor == valor) {
        return false;
    }

    //caso 3: el valor es mayor que el nodo actual
    if(valor > this->root->valor) {
        this->root->right = insertarNodo(this->root->right, newNode);
    } else {
        //caso 4: el valor es menor que el nodo actual
        this->root->left = insertarNodo(this->root->left, newNode);
    }

    return true;
}

nodoArbol* arbolBST::insertarNodo(nodoArbol* actual, nodoArbol* nuevo) {
    if(actual == nullptr) {
        return nuevo;
    }

    //caso 1: el valor es mayor que el nodo actual
    if(nuevo->valor > actual->valor) {
        actual->right = insertarNodo(actual->right, nuevo);
    } else if(nuevo->valor < actual->valor) {
        //caso 2: el valor es menor que el nodo actual
        actual->left = insertarNodo(actual->left, nuevo);
    } else {
        delete nuevo;
    }

    return actual;
}

nodoArbol* arbolBST::sucesor(nodoArbol* actual) {
    if(actual == nullptr) {
        return nullptr;
    }

    return mostLeftChild(actual);
}

nodoArbol* arbolBST::mostLeftChild(nodoArbol* actual) {
    if(actual == nullptr) {
        return nullptr;
    }

    if(actual->left == nullptr) {
        return actual;
    } else {
        return mostLeftChild(actual->left);
    }
}

nodoArbol* arbolBST::predecesor(nodoArbol* actual) {
    if(actual == nullptr) {
        return nullptr;
    }

    return mostRightChild(actual);
}


nodoArbol* arbolBST::mostRightChild(nodoArbol* actual) {
    if(actual == nullptr) {
        return nullptr;
    }

    if(actual->right == nullptr) {
        return actual;
    } else {
        return mostRightChild(actual);
    }
}


bool arbolBST::eliminar(int valor) {
    return eliminarNodo(this->root, valor);
}

nodoArbol* arbolBST::eliminarNodo(nodoArbol* actual, int valor) {
    //caso 1: el nodo es nullptr
    if(actual == nullptr) {
        return nullptr;
    }

    //caso 2: el valor es menor que el nodo actual
    if(valor < actual->valor) {
        actual->left = eliminarNodo(actual->left, valor);
    } else if(valor > actual->valor) {
        //caso 3: el valor es mayor que el nodo actual
        actual->right = eliminarNodo(actual->right, valor);
    }
    //caso 4: el valor es igual al nodo actual
    else {
        //caso 4a: solo tiene un hijo derecho
        if(actual->left == nullptr && actual->right != nullptr) {
            nodoArbol* right = actual->right;
            delete actual;
            return right;
        }
        //caso 4b: solo tiene un hijo izquierdo
        else if(actual->left != nullptr && actual->right == nullptr) {
            nodoArbol* left = actual->left;
            delete actual;
            return left;
        }

        //caso 4c: no tiene hijos, es nodo hoja
        else if(actual->left == nullptr && actual->right == nullptr) {
            delete actual;
            return nullptr;
        }

        //caso 4d: tiene dos hijos
        else {
            nodoArbol* predecesor = this->predecesor(actual);
            actual->valor = predecesor->valor;
            actual->left = this->eliminarNodo(actual->left, actual->valor);
        }

        return actual;
    }
}
