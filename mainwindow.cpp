#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "nodoGrafico.h"
#include "dibujarlistas.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    showMaximized();
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    ui->graphicsView->setScene(escena);
    estructura = Estructuras::ListaSimple;

    x = y = indice = nuevoTamaño = tamañoAnterior = 0;

    listaSimple = new listaEnlazadaSimple();
    listaDoble = new listaEnlazadaDoble();

    dibujar = new dibujarListas(this, listaSimple, listaDoble);

    connect(ui->actionLista_Simple, &QAction::triggered, this, &MainWindow::setListaSimple);
    connect(ui->actionLista_Doble, &QAction::triggered, this, &MainWindow::setListaDoble);
    connect(ui->actionStack, &QAction::triggered, this, &MainWindow::setStack);
    connect(ui->actionQueue, &QAction::triggered, this, &MainWindow::setQueue);
    connect(ui->action_rbol_BST, &QAction::triggered, this, &MainWindow::setArbolBST);
    connect(ui->action_rbol_AVL, &QAction::triggered, this, &MainWindow::setArbolAVL);
    connect(ui->actionGuardar_2, &QAction::triggered, this, &MainWindow::guardarArchivo);
    connect(ui->actionCargar, &QAction::triggered, this, &MainWindow::cargarArchivo);

    listaSimple->cargar();
    dibujarLista();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dibujar;
    delete listaSimple;
}

void MainWindow::insertarValor(int valor, int posicion) {
    switch(estructura) {
    case Estructuras::ListaSimple:
        listaSimple->insertar(valor, posicion);
        break;

    case Estructuras::ListaDoble:
        listaDoble->insertar(valor, posicion);
        break;

    case Estructuras::Stack:
        stack.push(valor);
        break;

    case Estructuras::Queue:
        queue.enqueue(valor);
        break;

    case Estructuras::ArbolBST:
        arbolBST.insertar(valor);
        break;

    default:
        break;
    }
}

bool MainWindow::eliminarValor(int valor, int pos) {
    switch(estructura) {
    case Estructuras::ListaSimple:
        if(listaSimple->eliminar(valor, pos))
            return true;
        break;

    case Estructuras::ListaDoble:
        if(listaDoble->eliminar(valor, pos))
            return true;
        break;

    case Estructuras::Stack:
        if(stack.pop())
            return true;
        break;

    case Estructuras::Queue:
        if(queue.dequeue())
            return true;
        break;

    case Estructuras::ArbolBST:
        if(arbolBST.eliminar(valor)) {
            return true;
        }
        break;

    default:
        break;
    }
    return false;
}

bool MainWindow::buscarValor(int valor) {
    switch(estructura) {
    case Estructuras::ListaSimple:
        if(listaSimple->buscar(valor))
            return true;
        break;

    case Estructuras::ListaDoble:
        if(listaDoble->buscar(valor))
            return true;
        break;

    case Estructuras::Stack:
        if(stack.search(valor))
            return true;
        break;

    case Estructuras::Queue:
        if(queue.search(valor))
            return true;
        break;

    default:
        break;
    }
    return false;
}

void MainWindow::dibujarLista() {
    escena->clear();

    switch(estructura) {
    case Estructuras::ListaSimple:
        dibujar->dibujarListaSimple(listaSimple->head);
        break;

    case Estructuras::ListaDoble:
        dibujar->dibujarListaDoble(listaDoble->head);
        break;

    case Estructuras::Stack:
        dibujar->dibujarStack(stack.head);
        break;

    case Estructuras::Queue:
        dibujar->dibujarQueue(queue.head);
        break;

    case Estructuras::ArbolBST:
        dibujar->dibujarArbolBST(arbolBST.root);
        break;

    default:
        break;
    }
}

void MainWindow::insertarNodo(QGraphicsItem* nodo) {
    if (!nodo) return;

    QParallelAnimationGroup* animationGroup = new QParallelAnimationGroup(this);

    QVariantAnimation* scaleAnim = new QVariantAnimation();
    scaleAnim->setDuration(500);
    scaleAnim->setStartValue(0.0);
    scaleAnim->setEndValue(1.0);
    scaleAnim->setEasingCurve(QEasingCurve::OutBack);

    QVariantAnimation* opacityAnim = new QVariantAnimation();
    opacityAnim->setDuration(400);
    opacityAnim->setStartValue(0.0);
    opacityAnim->setEndValue(1.0);
    opacityAnim->setEasingCurve(QEasingCurve::OutCubic);

    connect(scaleAnim, &QVariantAnimation::valueChanged, [nodo](const QVariant &value) {
        nodo->setScale(value.toDouble());
    });

    connect(opacityAnim, &QVariantAnimation::valueChanged, [nodo](const QVariant &value) {
        nodo->setOpacity(value.toDouble());
    });

    animationGroup->addAnimation(scaleAnim);
    animationGroup->addAnimation(opacityAnim);

    connect(animationGroup, &QParallelAnimationGroup::finished, [animationGroup]() {
        animationGroup->deleteLater();
    });

    animationGroup->start();
}

void MainWindow::eliminarNodo(int valor, int pos) {

    if (valor == -1 && (estructura == Estructuras::Stack || estructura == Estructuras::Queue)) {
        switch(estructura) {
        case Estructuras::Stack:
            if(stack.head != nullptr) {
                valor = stack.peek();
            } else {
                QMessageBox::information(this, "Error", "Stack vacío");
                return;
            }
            break;
        case Estructuras::Queue:
            if(queue.head != nullptr) {
                valor = queue.head->valor;
            } else {
                QMessageBox::information(this, "Error", "Queue vacía");
                return;
            }
            break;
        default:
            QMessageBox::information(this, "Error", "Operación no válida");
            return;
        }
    } else if(valor == -1 && pos != -1) {
        switch(estructura){
            case Estructuras::ListaSimple:
                if(listaSimple->head != nullptr) {
                    valor = listaSimple->getValorNodo(pos);
                } else {
                    QMessageBox::information(this, "Error", "Lista vacía");
                    return;
                }
                break;
            case Estructuras::ListaDoble:
                if(listaDoble->head != nullptr) {
                    valor = listaDoble->getValorNodo(pos);
                } else {
                    QMessageBox::information(this, "Error", "Lista vacía");
                    return;
                }
                break;
        }
    }

    QGraphicsItem* nodoEliminado = nullptr;

    for (QGraphicsItem* item : escena->items()) {
        nodoGrafico* nodo = dynamic_cast<nodoGrafico*>(item);
        if (nodo && nodo->getValor() == valor) {
            nodoEliminado = nodo;
            break;
        }
    }

    if (!nodoEliminado) {
        QMessageBox::information(this, "Error.", "No se encontró el nodo a eliminar.");
        return;
    }

    QVariantAnimation* anim = new QVariantAnimation(this);
    anim->setDuration(300);
    anim->setStartValue(1.0);
    anim->setEndValue(0.0);
    anim->setEasingCurve(QEasingCurve::InOutQuad);

    connect(anim, &QVariantAnimation::valueChanged, [nodoEliminado](const QVariant &value) {
        nodoEliminado->setScale(value.toDouble());
    });

    connect(anim, &QVariantAnimation::finished, [this, valor, nodoEliminado]() {
        escena->removeItem(nodoEliminado);
        delete nodoEliminado;
        dibujarLista();
    });

    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::buscarNodo(int valor) {
    for (QGraphicsItem* item : escena->items()) {
        nodoGrafico* nodo = dynamic_cast<nodoGrafico*>(item);
        if (nodo && nodo->getValor() == valor) {
            QGraphicsColorizeEffect* efecto = new QGraphicsColorizeEffect();
            nodo->setGraphicsEffect(efecto);

            QPropertyAnimation* anim = new QPropertyAnimation(efecto, "strength");
            anim->setDuration(1000);
            anim->setStartValue(0.0);
            anim->setKeyValueAt(0.5, 1.0);
            anim->setEndValue(0.0);

            efecto->setColor(Qt::yellow);

            anim->start(QAbstractAnimation::DeleteWhenStopped);
            break;
        }
    }
}

void MainWindow::on_botonInsertar_clicked()
{
    QString textoValor = ui->lineEdit->text();
    QString textoPos = ui->lineEdit_2->text();

    if(textoValor.isEmpty()) {
        QMessageBox::information(this, "Error", "Debes ingresar un valor.");
        return;
    }

    int valor = textoValor.toInt();
    int posicion = -1; // CORRECCION: Inicializar siempre

    if(!textoPos.isEmpty()) {
        posicion = textoPos.toInt();
    }

    insertarValor(valor, posicion);
    dibujarLista();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_botonEliminar_clicked()
{
    QString textoValor = ui->lineEdit->text();
    QString textoPos = ui->lineEdit_2->text();
    int valor;
    int pos = -1; // CORRECCION: Inicializar siempre

    if (estructura == Estructuras::Stack || estructura == Estructuras::Queue) {
        valor = -1;
        pos = -1; // CORRECCION: Asegurar inicialización
    } else {
        if (textoValor.isEmpty() && textoPos.isEmpty()) {
            QMessageBox::information(this, "Error", "Ingrese un valor o posición"); // CORRECCION: Mensaje más claro
            return;
        }

        if(textoValor.isEmpty())
            valor = -1;
        else
            valor = textoValor.toInt();

        if(textoPos.isEmpty())
            pos = -1;
        else
            pos = textoPos.toInt();
    }

    eliminarNodo(valor, pos);

    if (!eliminarValor(valor, pos)) {
        QMessageBox::information(this, "Error", "No se pudo eliminar");
        return;
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear(); // CORRECCION: Limpiar ambos campos
}

void MainWindow::on_botonBuscar_clicked()
{
    QString texto = ui->lineEdit->text();
    if (texto.isEmpty()) {
        return;
    }

    int valor = texto.toInt();

    if (!buscarValor(valor)) {
        QMessageBox::information(this, "Búsqueda", "El valor no está en la lista.");
        return;
    }

    buscarNodo(valor);

    ui->lineEdit->clear();
}

void MainWindow::on_botonReiniciar_clicked()
{
    switch(estructura) {
    case Estructuras::ListaSimple:
        listaSimple->borrarTodo();
        dibujarLista();
        break;

    case Estructuras::ListaDoble:
        listaDoble->borrarTodo();
        dibujarLista();
        break;

    case Estructuras::Stack:
        stack.borrarTodo();
        dibujarLista();
        break;

    case Estructuras::Queue:
        queue.borrarTodo();
        dibujarLista();
        break;

    case Estructuras::ArbolBST:
        break;

    default:
        break;
    }
}
