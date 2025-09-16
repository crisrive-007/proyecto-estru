#include "arbolavl.h"

arbolAVL::arbolAVL() {
    this->root = nullptr;
}

void arbolAVL::insertar(int valor) {
    insertarNodo(root, new nodoArbol(valor));
    return;
}

nodoArbol* arbolAVL::insertarNodo(nodoArbol* actual, nodoArbol* nuevo) {
    if(actual == nullptr) {
        return nuevo;
    }

    if(actual->valor == nuevo->valor) {
        delete nuevo;
        return actual;
    }

    if(nuevo->valor < actual->valor) {
        actual->left = insertarNodo(actual->left, nuevo);
    } else if(nuevo->valor > actual->valor) {
        actual->right = insertarNodo(actual->right, nuevo);
    }

    //actualizar el height
    actual->height = max(getHeight(actual->left), getHeight(actual->right));

    //calcular el bf (factor de balance)
    int balance = getBalanceFactor(actual);

    //caso 1: izquierdo izquierdo
    if(balance > 1 && nuevo->valor < actual->left->valor) {
        return rotateRight(actual);
    }

    //caso 2: izquierdo derecho
    else if(balance > 1 && nuevo->valor > actual->left->valor) {
        actual->left = rotateLeft(actual->left);
        return rotateRight(actual);
    }

    //caso 3: derecho derecho
    else if(balance < -1 && nuevo->valor > actual->left->valor) {
        return rotateLeft(actual);
    }

    //caso 4: derecho izquierdo
    else if(balance < -1 && nuevo->valor < actual->left->valor) {
        actual->right = rotateRight(actual->right);
        return rotateLeft(actual);
    }
}

//obtener height
int arbolAVL::getHeight(nodoArbol* nodo) {
    if(nodo == nullptr) {
        return 0;
    }

    return nodo->height;
}

//obtener factor de balance
int arbolAVL::getBalanceFactor(nodoArbol* nodo) {
    if(nodo == nullptr) {
        return 0;
    }

    return getHeight(nodo->left) - getHeight(nodo->right);
}

int arbolAVL::max(int a, int b) {
    return (a > b) ? a : b;
}

nodoArbol* arbolAVL::rotateRight(nodoArbol* y) {
    nodoArbol* x = y->left;
    nodoArbol* T2 = x->right;

    //rotacion
    x->right = y;
    y->left = T2;

    //actualizar los heights
    y->height = max(getHeight(y->left), getHeight(y->right));
    x->height = max(getHeight(x->left), getHeight(x->right));

    return x;
}

nodoArbol* arbolAVL::rotateLeft(nodoArbol* x) {
    nodoArbol* y = x->right;
    nodoArbol* T2 = y->left;

    //rotaciones
    x->right = T2;
    y->left = x;

    //actualizar los heights
    x->height = max(getHeight(x->left), getHeight(x->right));
    y->height = max(getHeight(y->left), getHeight(y->right));

    return y;
}

bool arbolAVL::eliminar(int valor) {
    nodoArbol* nodo = this->eliminarNodo(this->root, valor);
    if(nodo == nullptr) {
        return false;
    }

    return true;
}

nodoArbol* arbolAVL::eliminarNodo(nodoArbol* actual, int valor) {
    if(actual == nullptr) {
        return nullptr;
    }

    if(actual->valor < valor) {
        actual->left = eliminarNodo(actual->left, valor);
    } else if(actual->valor > valor) {
        actual->right = eliminarNodo(actual->right, valor);
    }

    else {
        //si el nodo no tiene hijos o solo tiene 1 hijo
        if(actual->left == nullptr || actual->right == nullptr) {
            nodoArbol* subarbol = actual->left == nullptr ? actual->left : actual->right;

            //caso 1: no tiene hijos
            if(subarbol == nullptr) {
                subarbol = actual;
                actual = nullptr;
            }

            //caso 2: tiene un hijo
            *actual = *subarbol;
            delete subarbol;
        } else {
            //caso 3: tiene 2 hijos
            nodoArbol* sucesor = this->sucesor(actual);
            actual->valor = sucesor->valor;
            actual->right = eliminarNodo(actual->right, valor);
        }
    }

    //balanceo
    if(actual == nullptr) {
        return nullptr;
    }

    actual->height = 1 + max(getHeight(actual->left), getHeight(actual->right));

    int balance = getBalanceFactor(actual);

    //caso 1: izquierdo izquierdo
    if(balance > 1 && actual->valor < actual->left->valor) {
        return rotateRight(actual);
    }

    //caso 2: izquierdo derecho
    else if(balance > 1 && actual->valor > actual->left->valor) {
        actual->left = rotateLeft(actual->left);
        return rotateRight(actual);
    }

    //caso 3: derecho derecho
    else if(balance < -1 && actual->valor > actual->left->valor) {
        return rotateLeft(actual);
    }

    //caso 4: derecho izquierdo
    else if(balance < -1 && actual->valor < actual->left->valor) {
        actual->right = rotateRight(actual->right);
        return rotateLeft(actual);
    }
}

nodoArbol* arbolAVL::sucesor(nodoArbol* actual) {
    if(actual == nullptr) {
        return nullptr;
    }

    return mostLeftChild(actual->right);
}

nodoArbol* arbolAVL::mostLeftChild(nodoArbol* actual) {
    if(actual == nullptr) {
        return nullptr;
    }

    if(actual->left == nullptr) {
        return actual;
    } else {
        return mostLeftChild(actual->left);
    }
}
