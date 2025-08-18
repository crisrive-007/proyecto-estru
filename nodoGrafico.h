#ifndef NODOGRAFICO_H
#define NODOGRAFICO_H

#include <QGraphicsItem>
#include <QPainter>
#include <QString>

class nodoGrafico : public QGraphicsItem
{
public:
    explicit nodoGrafico(int valor, QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    void setValor(int nuevoValor);
    int getValor() const;

private:
    int valor;
};

#endif // NODOGRAFICO_H
