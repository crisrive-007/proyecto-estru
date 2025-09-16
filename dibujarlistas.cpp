#include "dibujarlistas.h"
#include "nodoGrafico.h"
#include "mainwindow.h"


dibujarListas::dibujarListas(MainWindow* main, listaEnlazadaSimple* simple, listaEnlazadaDoble* doble) {
    this->m = main;
    this->simple = simple;
    this->doble = doble;
}

void dibujarListas::dibujarListaSimple(nodo* cabeza) {
    nodo* it = cabeza;

    // ✅ Usar variables LOCALES en lugar de modificar m->x, m->y
    int x = 50;  // Variable local
    int y = 100; // Variable local

    // Resetear las variables de la clase al inicio
    m->indice = 0;
    m->nuevoTamaño = 0;

    QGraphicsScene* escena = m->getEscena();

    // Calcular el número total de nodos
    nodo* contador = cabeza;
    int numNodos = 0;
    while(contador != nullptr) {
        numNodos++;
        contador = contador->next;
    }

    int anchoTotal = (numNodos - 1) * 100 + 50;
    int xCentro = x + (anchoTotal / 2);

    QGraphicsTextItem* titulo = new QGraphicsTextItem("LISTA SIMPLE");
    titulo->setDefaultTextColor(Qt::cyan);
    QFont font = titulo->font();
    font.setBold(true);
    titulo->setFont(font);
    titulo->setScale(2.0);
    QRectF boundingRect = titulo->boundingRect();
    int anchoTitulo = boundingRect.width() * titulo->scale();
    titulo->setPos(xCentro - (anchoTitulo / 2), y - 150);
    escena->addItem(titulo);

    // Variable para guardar el nodo nuevo
    nodoGrafico* nodoNuevo = nullptr;
    int posicionActual = 0;

    while(it != nullptr) {
        m->nuevoTamaño++;
        nodoGrafico* nodo = new nodoGrafico(it->valor);
        escena->addItem(nodo);
        QPoint puntoAparicion(x, y); // ✅ Usar variable local x, y

        if (it == cabeza) {
            QGraphicsTextItem* textoHead = new QGraphicsTextItem("HEAD");
            textoHead->setDefaultTextColor(Qt::white);
            textoHead->setPos(x-5, y - 30); // ✅ Usar variable local x, y
            textoHead->setScale(1.5);
            escena->addItem(textoHead);
        }

        if (it->next == nullptr && it != cabeza) {
            QGraphicsTextItem* textoTail = new QGraphicsTextItem("TAIL");
            textoTail->setDefaultTextColor(Qt::white);
            textoTail->setPos(x+1, y - 30); // ✅ Usar variable local x, y
            textoTail->setScale(1.5);
            escena->addItem(textoTail);
        }

        nodo->setPos(puntoAparicion);

        if (it->valor == simple->valorNuevo) {
            nodoNuevo = nodo;
            nodo->setScale(0.0);
            nodo->setOpacity(0.0);
            simple->valorNuevo = -999;
        } else {
            nodo->setScale(1.0);
            nodo->setOpacity(1.0);
        }

        if(it->next != nullptr) {
            escena->addLine(x+50, y+24, x+100, y+24, QPen(Qt::white, 2)); // ✅ Usar x, y locales
            escena->addLine(x+100, y+24, x+90, y+19, QPen(Qt::white, 2));
            escena->addLine(x+100, y+24, x+90, y+29, QPen(Qt::white, 2));
        }
        else {
            escena->addLine(x+50, y+24, x+100, y+24, QPen(Qt::white, 2)); // ✅ Usar x, y locales
            escena->addLine(x+100, y+24, x+90, y+19, QPen(Qt::white, 2));
            escena->addLine(x+100, y+24, x+90, y+29, QPen(Qt::white, 2));
            QGraphicsTextItem* textoNull = new QGraphicsTextItem("nullptr");
            textoNull->setDefaultTextColor(Qt::white);
            textoNull->setPos(x+110, y); // ✅ Usar x, y locales
            textoNull->setScale(2);
            escena->addItem(textoNull);
        }

        it = it->next;
        x += 100; // ✅ Modificar solo la variable LOCAL
        posicionActual++;
    }

    // ANIMAR SOLO EL NODO NUEVO (si existe)
    if (nodoNuevo != nullptr) {
        m->insertarNodo(nodoNuevo);
    }

    m->tamañoAnterior = m->nuevoTamaño;

    // ✅ NO es necesario resetear m->x, m->y porque no las modificamos
}

void dibujarListas::dibujarListaDoble(nodoDLL* cabeza) {
    nodoDLL* it = cabeza;

    // ✅ Usar variables LOCALES en lugar de modificar m->x, m->y
    int x = 50;  // Variable local
    int y = 100; // Variable local

    // Resetear las variables de la clase al inicio
    m->indice = 0;
    m->nuevoTamaño = 0;

    QGraphicsScene* escena = m->getEscena();

    // Calcular el número total de nodos
    nodoDLL* contador = cabeza;
    int numNodos = 0;
    while(contador != nullptr) {
        numNodos++;
        contador = contador->next;
    }

    int anchoTotal = (numNodos - 1) * 100 + 50;
    int xCentro = x + (anchoTotal / 2);

    QGraphicsTextItem* titulo = new QGraphicsTextItem("LISTA DOBLEMENTE ENLAZADA");
    titulo->setDefaultTextColor(Qt::cyan);
    QFont font = titulo->font();
    font.setBold(true);
    titulo->setFont(font);
    titulo->setScale(2.0);
    QRectF boundingRect = titulo->boundingRect();
    int anchoTitulo = boundingRect.width() * titulo->scale();
    titulo->setPos(xCentro - (anchoTitulo / 2), y - 150);
    escena->addItem(titulo);

    // Variable para guardar el nodo nuevo
    nodoGrafico* nodoNuevo = nullptr;
    int posicionActual = 0;

    while(it != nullptr) {
        m->nuevoTamaño++;
        nodoGrafico* nodo = new nodoGrafico(it->valor);
        escena->addItem(nodo);
        QPoint puntoAparicion(x, y); // ✅ Usar variable local x, y

        if (it == cabeza) {
            QGraphicsTextItem* textoHead = new QGraphicsTextItem("HEAD");
            textoHead->setDefaultTextColor(Qt::white);
            textoHead->setPos(x-5, y - 30); // ✅ Usar variable local x, y
            textoHead->setScale(1.5);
            escena->addItem(textoHead);
        }

        if (it->next == nullptr && it != cabeza) {
            QGraphicsTextItem* textoTail = new QGraphicsTextItem("TAIL");
            textoTail->setDefaultTextColor(Qt::white);
            textoTail->setPos(x+1, y - 30); // ✅ Usar variable local x, y
            textoTail->setScale(1.5);
            escena->addItem(textoTail);
        }

        nodo->setPos(puntoAparicion);

        if (it->valor == doble->valorNuevo) {
            nodoNuevo = nodo;
            nodo->setScale(0.0);
            nodo->setOpacity(0.0);
            doble->valorNuevo = -999;
        } else {
            nodo->setScale(1.0);
            nodo->setOpacity(1.0);
        }

        // Dibujar flecha hacia el siguiente nodo
        if(it->next != nullptr) {
            escena->addLine(x+50, y+12, x+100, y+12, QPen(Qt::white, 2)); // ✅ Usar x, y locales
            escena->addLine(x+95, y+7, x+100, y+12, QPen(Qt::white, 2));
            escena->addLine(x+95, y+17, x+100, y+12, QPen(Qt::white, 2));
        } else {
            escena->addLine(x+50, y+12, x+100, y+12, QPen(Qt::white, 2)); // ✅ Usar x, y locales
            escena->addLine(x+95, y+7, x+100, y+12, QPen(Qt::white, 2));
            escena->addLine(x+95, y+17, x+100, y+12, QPen(Qt::white, 2));

            QGraphicsTextItem* textoNextNull = new QGraphicsTextItem("nullptr");
            textoNextNull->setDefaultTextColor(Qt::white);
            textoNextNull->setPos(x+105, y-17); // ✅ Usar x, y locales
            textoNextNull->setScale(2);
            escena->addItem(textoNextNull);
        }

        // Dibujar flecha hacia el nodo anterior (específico de lista doble)
        if(it->prev != nullptr) {
            escena->addLine(x-50, y+36, x, y+36, QPen(Qt::white, 2)); // ✅ Usar x, y locales
            escena->addLine(x-50, y+36, x-45, y+31, QPen(Qt::white, 2));
            escena->addLine(x-50, y+36, x-45, y+41, QPen(Qt::white, 2));
        } else {
            escena->addLine(x-50, y+36, x, y+36, QPen(Qt::white, 2)); // ✅ Usar x, y locales
            escena->addLine(x-50, y+36, x-45, y+31, QPen(Qt::white, 2));
            escena->addLine(x-50, y+36, x-45, y+41, QPen(Qt::white, 2));

            QGraphicsTextItem* textoPrevNull = new QGraphicsTextItem("nullptr");
            textoPrevNull->setDefaultTextColor(Qt::white);
            textoPrevNull->setPos(x-140, y+10); // ✅ Usar x, y locales
            textoPrevNull->setScale(2);
            escena->addItem(textoPrevNull);
        }

        it = it->next;
        x += 100; // ✅ Modificar solo la variable LOCAL
        posicionActual++;
    }

    // ANIMAR SOLO EL NODO NUEVO (si existe)
    if (nodoNuevo != nullptr) {
        m->insertarNodo(nodoNuevo);
    }

    m->tamañoAnterior = m->nuevoTamaño;

    // ✅ NO es necesario resetear m->x, m->y porque no las modificamos
}

void dibujarListas::dibujarStack(nodo* cabeza) {
    nodo* it = cabeza;
    m->x = 50;
    m->y = 100;
    m->indice = 0;
    m->nuevoTamaño = 0;
    QGraphicsScene* escena = m->getEscena();

    nodo* contador = cabeza;
    int numNodos = 0;
    while(contador != nullptr) {
        numNodos++;
        contador = contador->next;
    }

    int anchoTotal = (numNodos - 1) * 100 + 50;
    int xCentro = m->x + (anchoTotal / 2);

    QGraphicsTextItem* titulo = new QGraphicsTextItem("PILA (STACK)");
    titulo->setDefaultTextColor(Qt::cyan);
    QFont font = titulo->font();
    font.setBold(true);
    titulo->setFont(font);
    titulo->setScale(2.0);

    QRectF boundingRect = titulo->boundingRect();
    int anchoTitulo = boundingRect.width() * titulo->scale();
    titulo->setPos(xCentro - (anchoTitulo / 2), m->y - 150);
    escena->addItem(titulo);

    while(it != nullptr) {
        nodoGrafico* nodo = new nodoGrafico(it->valor);
        escena->addItem(nodo);
        QPoint puntoAparicion(m->x, m->y);

        if (it == cabeza) {
            QGraphicsTextItem* textoTop = new QGraphicsTextItem("HEAD");
            textoTop->setDefaultTextColor(Qt::white);
            textoTop->setPos(m->x-5, m->y - 30);
            textoTop->setScale(1.5);
            escena->addItem(textoTop);
        }

        if (it->next == nullptr && it != cabeza) {
            QGraphicsTextItem* textoTail = new QGraphicsTextItem("TAIL");
            textoTail->setDefaultTextColor(Qt::white);
            textoTail->setPos(m->x+1, m->y - 30);
            textoTail->setScale(1.5);
            escena->addItem(textoTail);
        }

        if (m->nuevoTamaño == 0) {
            nodo->setPos(puntoAparicion);
            m->insertarNodo(nodo);
            m->nuevoTamaño++;
        }
        else {
            nodo->setPos(puntoAparicion);
        }
        if(it->next != nullptr) {
            escena->addLine(m->x+50, m->y+24, m->x+100, m->y+24, QPen(Qt::white, 2));
            escena->addLine(m->x+100, m->y+24, m->x+90, m->y+19, QPen(Qt::white, 2));
            escena->addLine(m->x+100, m->y+24, m->x+90, m->y+29, QPen(Qt::white, 2));
        }
        else {
            escena->addLine(m->x+50, m->y+24, m->x+100, m->y+24, QPen(Qt::white, 2));
            escena->addLine(m->x+100, m->y+24, m->x+90, m->y+19, QPen(Qt::white, 2));
            escena->addLine(m->x+100, m->y+24, m->x+90, m->y+29, QPen(Qt::white, 2));
            QGraphicsTextItem* textoNull = new QGraphicsTextItem("nullptr");
            textoNull->setDefaultTextColor(Qt::white);
            textoNull->setPos(m->x+110, m->y);
            textoNull->setScale(2);
            escena->addItem(textoNull);
        }
        it = it->next;
        m->x += 100;
    }
    m->tamañoAnterior = m->nuevoTamaño;
}

void dibujarListas::dibujarQueue(nodo* cabeza) {
    nodo* it = cabeza;
    m->x = 50;
    m->y = 100;
    m->indice = 0;
    m->nuevoTamaño = 0;
    QGraphicsScene* escena = m->getEscena();

    nodo* contador = cabeza;
    int numNodos = 0;
    while(contador != nullptr) {
        numNodos++;
        contador = contador->next;
    }

    int anchoTotal = (numNodos - 1) * 100 + 50;
    int xCentro = m->x + (anchoTotal / 2);

    QGraphicsTextItem* titulo = new QGraphicsTextItem("COLA (QUEUE)");
    titulo->setDefaultTextColor(Qt::cyan);
    QFont font = titulo->font();
    font.setBold(true);
    titulo->setFont(font);
    titulo->setScale(2.0);

    QRectF boundingRect = titulo->boundingRect();
    int anchoTitulo = boundingRect.width() * titulo->scale();
    titulo->setPos(xCentro - (anchoTitulo / 2), m->y - 150);
    escena->addItem(titulo);

    while(it != nullptr) {
        m->nuevoTamaño++;
        nodoGrafico* nodo = new nodoGrafico(it->valor);
        escena->addItem(nodo);
        QPoint puntoAparicion(m->x, m->y);

        if (it == cabeza) {
            QGraphicsTextItem* textoHead = new QGraphicsTextItem("HEAD");
            textoHead->setDefaultTextColor(Qt::white);
            textoHead->setPos(m->x-5, m->y - 30);
            textoHead->setScale(1.5);
            escena->addItem(textoHead);
        }

        if (it->next == nullptr && it != cabeza) {
            QGraphicsTextItem* textoTail = new QGraphicsTextItem("TAIL");
            textoTail->setDefaultTextColor(Qt::white);
            textoTail->setPos(m->x+1, m->y - 30);
            textoTail->setScale(1.5);
            escena->addItem(textoTail);
        }

        if (m->nuevoTamaño > m->tamañoAnterior) {
            nodo->setPos(puntoAparicion);
            m->insertarNodo(nodo);
        }
        else {
            nodo->setPos(puntoAparicion);
        }

        if(it->next != nullptr) {
            escena->addLine(m->x+50, m->y+24, m->x+100, m->y+24, QPen(Qt::white, 2));
            escena->addLine(m->x+100, m->y+24, m->x+90, m->y+19, QPen(Qt::white, 2));
            escena->addLine(m->x+100, m->y+24, m->x+90, m->y+29, QPen(Qt::white, 2));
        }
        else {
            escena->addLine(m->x+50, m->y+24, m->x+100, m->y+24, QPen(Qt::white, 2));
            escena->addLine(m->x+100, m->y+24, m->x+90, m->y+19, QPen(Qt::white, 2));
            escena->addLine(m->x+100, m->y+24, m->x+90, m->y+29, QPen(Qt::white, 2));
            QGraphicsTextItem* textoNull = new QGraphicsTextItem("nullptr");
            textoNull->setDefaultTextColor(Qt::white);
            textoNull->setPos(m->x+110, m->y);
            textoNull->setScale(2);
            escena->addItem(textoNull);
        }
        it = it->next;
        m->x += 100;
    }
    m->tamañoAnterior = m->nuevoTamaño;
}

void dibujarListas::dibujarArbolBST(nodoArbol* raiz) {
    if (raiz == nullptr) {
        return;
    }

    QGraphicsScene* escena = m->getEscena();

    // Configurar posición inicial y parámetros
    int xInicial = 400; // Posición central horizontal
    int yInicial = 100; // Posición inicial vertical
    int espacioVertical = 80; // Espaciado entre niveles
    int espacioHorizontalBase = 200; // Espaciado horizontal base

    // Título del árbol
    QGraphicsTextItem* titulo = new QGraphicsTextItem("ÁRBOL BST");
    titulo->setDefaultTextColor(Qt::cyan);
    QFont font = titulo->font();
    font.setBold(true);
    titulo->setFont(font);
    titulo->setScale(2.0);
    QRectF boundingRect = titulo->boundingRect();
    int anchoTitulo = boundingRect.width() * titulo->scale();
    titulo->setPos(xInicial - (anchoTitulo / 2), yInicial - 60);
    escena->addItem(titulo);

    // Etiqueta ROOT para la raíz
    QGraphicsTextItem* textoRoot = new QGraphicsTextItem("ROOT");
    textoRoot->setDefaultTextColor(Qt::yellow);
    textoRoot->setPos(xInicial - 15, yInicial - 35);
    textoRoot->setScale(1.2);
    escena->addItem(textoRoot);

    // Dibujar el árbol recursivamente
    dibujarNodoArbol(escena, raiz, xInicial, yInicial, espacioHorizontalBase, espacioVertical, 0);
}

void dibujarListas::dibujarNodoArbol(QGraphicsScene* escena, nodoArbol* nodo,
                                     int x, int y, int espacioHorizontal,
                                     int espacioVertical, int nivel) {
    if (nodo == nullptr) {
        return;
    }

    // Crear el nodo gráfico
    nodoGrafico* nodoGraf = new nodoGrafico(nodo->valor);
    nodoGraf->setPos(x, y);

    // Verificar si es un nodo nuevo para animación
    bool esNodoNuevo = false;
    if (m->nuevoTamaño > m->tamañoAnterior) {
        // Lógica para determinar si es el nodo recién insertado
        // Esto dependerá de cómo manejes la identificación del nodo nuevo
        esNodoNuevo = true; // Simplificado por ahora
        m->nuevoTamaño++;
    }

    if (esNodoNuevo) {
        nodoGraf->setScale(0.0);
        nodoGraf->setOpacity(0.0);
        m->insertarNodo(nodoGraf); // Animar el nodo nuevo
    } else {
        nodoGraf->setScale(1.0);
        nodoGraf->setOpacity(1.0);
    }

    escena->addItem(nodoGraf);

    // Calcular posiciones para hijos
    int espacioReducido = espacioHorizontal / 2;
    int siguienteNivel = y + espacioVertical;

    // Dibujar hijo izquierdo
    if (nodo->left != nullptr) {
        int xIzquierdo = x - espacioReducido;

        // Línea hacia el hijo izquierdo
        escena->addLine(x + 15, y + 40, xIzquierdo + 35, siguienteNivel + 10,
                        QPen(Qt::white, 2));

        // Flecha
        escena->addLine(xIzquierdo + 35, siguienteNivel + 10,
                        xIzquierdo + 30, siguienteNivel + 5, QPen(Qt::white, 2));
        escena->addLine(xIzquierdo + 35, siguienteNivel + 10,
                        xIzquierdo + 40, siguienteNivel + 5, QPen(Qt::white, 2));

        // Llamada recursiva para el hijo izquierdo
        dibujarNodoArbol(escena, nodo->left, xIzquierdo, siguienteNivel,
                         espacioReducido, espacioVertical, nivel + 1);
    }

    // Dibujar hijo derecho
    if (nodo->right != nullptr) {
        int xDerecho = x + espacioReducido;

        // Línea hacia el hijo derecho
        escena->addLine(x + 35, y + 40, xDerecho + 15, siguienteNivel + 10,
                        QPen(Qt::white, 2));

        // Flecha
        escena->addLine(xDerecho + 15, siguienteNivel + 10,
                        xDerecho + 10, siguienteNivel + 5, QPen(Qt::white, 2));
        escena->addLine(xDerecho + 15, siguienteNivel + 10,
                        xDerecho + 20, siguienteNivel + 5, QPen(Qt::white, 2));

        // Llamada recursiva para el hijo derecho
        dibujarNodoArbol(escena, nodo->right, xDerecho, siguienteNivel,
                         espacioReducido, espacioVertical, nivel + 1);
    }

    // Agregar etiquetas para nodos hoja (nullptr)
    if (nodo->left == nullptr) {
        int xIzquierdo = x - espacioReducido;
        escena->addLine(x + 15, y + 40, xIzquierdo + 35, siguienteNivel + 10,
                        QPen(Qt::gray, 1, Qt::DashLine));

        QGraphicsTextItem* textoNull = new QGraphicsTextItem("nullptr");
        textoNull->setDefaultTextColor(Qt::gray);
        textoNull->setPos(xIzquierdo + 5, siguienteNivel + 15);
        textoNull->setScale(0.8);
        escena->addItem(textoNull);
    }

    if (nodo->right == nullptr) {
        int xDerecho = x + espacioReducido;
        escena->addLine(x + 35, y + 40, xDerecho + 15, siguienteNivel + 10,
                        QPen(Qt::gray, 1, Qt::DashLine));

        QGraphicsTextItem* textoNull = new QGraphicsTextItem("nullptr");
        textoNull->setDefaultTextColor(Qt::gray);
        textoNull->setPos(xDerecho - 15, siguienteNivel + 15);
        textoNull->setScale(0.8);
        escena->addItem(textoNull);
    }
}

// Función auxiliar para contar nodos (útil para el manejo de animaciones)
int dibujarListas::contarNodos(nodoArbol* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return 1 + contarNodos(nodo->left) + contarNodos(nodo->right);
}

// Función auxiliar para calcular la altura del árbol
int dibujarListas::alturaArbol(nodoArbol* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    int alturaIzq = alturaArbol(nodo->left);
    int alturaDer = alturaArbol(nodo->right);
    return 1 + std::max(alturaIzq, alturaDer);
}
