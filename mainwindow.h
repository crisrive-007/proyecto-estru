#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QVariantAnimation>
#include <QMessageBox>
#include <QGraphicsColorizeEffect>
#include <QPropertyAnimation>
#include "nodo.h"
#include "listaenlazadasimple.h"
#include "listaenlazadadoble.h"
#include "estructuras.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int x, y, indice, nuevoTamaño, tamañoAnterior;
    listaEnlazadaSimple listaSimple;
    listaEnlazadaDoble listaDoble;
    void insertarNodo(QGraphicsItem* nodo);
    void eliminarNodo(int valor);
    void buscarNodo(int valor);
    void dibujarLista();
    void insertarValor(int valor);
    QGraphicsScene* getEscena() {
        return escena;
    }

private slots:
    void on_botonInsertar_clicked();

    void on_botonEliminar_clicked();

    void on_botonBuscar_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* escena;
    Estructuras estructura;
    void setListaSimple() {
        estructura = Estructuras::ListaSimple;
    }
    void setListaDoble() {
        estructura = Estructuras::ListaDoble;
    }
    void setStack() {
        estructura = Estructuras::Stack;
    }
    void setQueue() {
        estructura = Estructuras::Queue;
    }
    void setArbolBST() {
        estructura = Estructuras::ArbolBST;
    }
    void setArbolAVL() {
        estructura = Estructuras::ArbolAVL;
    }
};
#endif // MAINWINDOW_H
