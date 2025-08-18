#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "nodoGrafico.h"
#include "dibujarlistas.h"

dibujarListas* dibujar;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    showMaximized();
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    ui->graphicsView->setScene(escena);
    estructura = Estructuras::ListaSimple;
    connect(ui->actionLista_Simple, &QAction::triggered, this, &MainWindow::setListaSimple);
    connect(ui->actionLista_Doble, &QAction::triggered, this, &MainWindow::setListaDoble);
    connect(ui->actionStack, &QAction::triggered, this, &MainWindow::setStack);
    connect(ui->actionQueue, &QAction::triggered, this, &MainWindow::setQueue);
    connect(ui->action_rbol_BST, &QAction::triggered, this, &MainWindow::setArbolBST);
    connect(ui->action_rbol_AVL, &QAction::triggered, this, &MainWindow::setArbolAVL);
    dibujar = new dibujarListas(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insertarNodo(QGraphicsItem* nodo) {
    nodo->setScale(0.0);

    QVariantAnimation* anim = new QVariantAnimation(this);
    anim->setDuration(400);
    anim->setStartValue(0.0);
    anim->setEndValue(1.0);
    anim->setEasingCurve(QEasingCurve::InOutQuad);
    connect(anim, &QVariantAnimation::valueChanged, [nodo](const QVariant &value) {
        nodo->setScale(value.toDouble());
    });

    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::eliminarNodo(int valor) {
    QGraphicsItem* nodoELiminado = nullptr;

    for (QGraphicsItem* item : escena->items()) {
        nodoGrafico* nodo = dynamic_cast<nodoGrafico*>(item);
        if (nodo && nodo->getValor() == valor) {
            nodoELiminado = nodo;
            break;
        }
    }

    if (!nodoELiminado) {
        QMessageBox::information(this, "Error.", "No se encontró el nodo a eliminar.");
        return;
    }

    QVariantAnimation* anim = new QVariantAnimation(this);
    anim->setDuration(300);
    anim->setStartValue(1.0);
    anim->setEndValue(0.0);
    anim->setEasingCurve(QEasingCurve::InOutQuad);

    connect(anim, &QVariantAnimation::valueChanged, [nodoELiminado](const QVariant &value) {
        nodoELiminado->setScale(value.toDouble());
    });

    connect(anim, &QVariantAnimation::finished, [this, valor, nodoELiminado]() {
        escena->removeItem(nodoELiminado);
        delete nodoELiminado;

        listaSimple.eliminar(valor);
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

void MainWindow::dibujarLista() {
    escena->clear();

    switch(estructura) {
    case Estructuras::ListaSimple:
        dibujar->dibujarListaSimple(listaSimple.head);
        break;

    case Estructuras::ListaDoble:
        dibujar->dibujarListaDoble(listaDoble.head);
    }
}

void MainWindow::insertarValor(int valor) {
    switch(estructura) {
    case Estructuras::ListaSimple:
        listaSimple.insertar(valor, 0);
        break;

    case Estructuras::ListaDoble:
        listaDoble.insertar(valor);
    }
}

void MainWindow::on_botonInsertar_clicked()
{
    QString textoValor = ui->lineEdit->text();
    QString textoPos = ui->lineEdit_2->text();
    int valor, pos;
    if(textoValor.isEmpty()) {
        QMessageBox::information(this, "Error.", "Tienes que ingresar un valor.");
        return;
    } else {
        valor = textoValor.toInt();
    }

    if(textoPos.isEmpty()) {
        pos = -1;
    } else {
        pos = textoPos.toInt();
    }

    insertarValor(valor);

    dibujarLista();

    ui->lineEdit->clear();
}


void MainWindow::on_botonEliminar_clicked()
{
    QString texto = ui->lineEdit->text();
    if(texto.isEmpty()) {
        return;
    }

    int valor = texto.toInt();
    if (!listaSimple.eliminar(valor)) {
        QMessageBox::information(this, "Error.", "No se encontró el nodo.");
        return;
    }

    eliminarNodo(valor);

    ui->lineEdit->clear();
}


void MainWindow::on_botonBuscar_clicked()
{
    QString texto = ui->lineEdit->text();
    if (texto.isEmpty()) {
        return;
    }

    int valor = texto.toInt();

    if (!listaSimple.buscar(valor)) {
        QMessageBox::information(this, "Búsqueda", "El valor no está en la lista.");
        return;
    }

    buscarNodo(valor);

    ui->lineEdit->clear();
}
