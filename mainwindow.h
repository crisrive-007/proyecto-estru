#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVariantAnimation>
#include <QMessageBox>
#include <QGraphicsColorizeEffect>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QFileDialog>
#include "nodo.h"
#include "listaenlazadasimple.h"
#include "listaenlazadadoble.h"
#include "stack.h"
#include "queue.h"
#include "arbolbst.h"
#include "estructuras.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class dibujarListas;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int x, y, indice, nuevoTamaño, tamañoAnterior;
    dibujarListas* dibujar;
    listaEnlazadaSimple* listaSimple;
    listaEnlazadaDoble* listaDoble;
    stack stack;
    queue queue;
    arbolBST arbolBST;

    void insertarNodo(QGraphicsItem* nodo);
    void eliminarNodo(int valor, int pos);
    void buscarNodo(int valor);
    void dibujarLista();
    void insertarValor(int valor, int posicion);
    bool eliminarValor(int valor, int posicion);
    bool buscarValor(int valor);

    QGraphicsScene* getEscena() {
        return escena;
    }

private slots:
    void on_botonInsertar_clicked();
    void on_botonEliminar_clicked();
    void on_botonBuscar_clicked();

    void on_botonReiniciar_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* escena;
    Estructuras estructura;

    void setListaSimple() {
        estructura = Estructuras::ListaSimple;
        dibujarLista();
    }
    void setListaDoble() {
        estructura = Estructuras::ListaDoble;
        dibujarLista();
    }
    void setStack() {
        estructura = Estructuras::Stack;
        dibujarLista();
    }
    void setQueue() {
        estructura = Estructuras::Queue;
        dibujarLista();
    }
    void setArbolBST() {
        estructura = Estructuras::ArbolBST;
        dibujarLista();
    }
    void setArbolAVL() {
        estructura = Estructuras::ArbolAVL;
        dibujarLista();
    }

    string guardarInformacion() {
        switch(estructura) {
        case Estructuras::ListaSimple:
            return listaSimple->lista();
            break;
        case Estructuras::ListaDoble:
            return listaDoble->lista();
            break;
        case Estructuras::Stack:
            return stack.lista();
            break;
        case Estructuras::Queue:
            return queue.lista();
            break;
        }
    }

    void cargarInformacion(int valor) {
        switch(estructura) {
        case Estructuras::ListaSimple:
            listaSimple->insertar(valor, -1);
            break;
        case Estructuras::ListaDoble:
            listaDoble->insertar(valor, -1);
            break;
        case Estructuras::Stack:
            stack.push(valor);
            break;
        case Estructuras::Queue:
            queue.enqueue(valor);
            break;
        }
    }

    void guardarArchivo() {
        QString filename = QFileDialog::getSaveFileName(this, "Save project", "C://", "Archivos de texto (*.txt);;Todos los archivos (*)");

        if (!filename.isEmpty()) {
            QFile file(filename);

            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << QString::fromStdString(guardarInformacion()) << Qt::endl;
                qDebug() << "Archivo guardado exitosamente en:" << filename;
            } else {
                qDebug() << "Error al abrir el archivo para escribir:" << file.errorString();
            }
        } else {
            qDebug() << "Operación de guardado cancelada.";
        }
    }

    void cargarArchivo() {
        QString filename = QFileDialog::getOpenFileName(this, "Load project", "C://", "Acrhivos de texto (*.txt);;Todos los archivos (*)");

        on_botonReiniciar_clicked();
        if(!filename.isEmpty()) {
            QFile file(filename);

            if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                while(!in.atEnd()) {
                    QString text = in.readLine();
                    int valor = text.toInt();
                    cargarInformacion(valor);
                    qDebug() << text;
                }
                file.close();
                dibujarLista();
            } else {
                qDebug() << "Operación de cargado cancelada.";
            }
        }
    }
};
#endif // MAINWINDOW_H
