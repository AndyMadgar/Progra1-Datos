#ifndef VIAJE_H
#define VIAJE_H
#include "tren.h"
#include <QDateTime>

class Viaje{
public:
    Tren *transporte;
    QDateTime inicio;
    QDateTime final;
    int transcurrido;
    int restante;
    class Viaje *siguiente;
    Viaje();
    Viaje(Tren*, QDateTime, QDateTime);
};

class listaViajes{
public:
    class Viaje *primero;
    listaViajes(){primero = NULL;}
    bool listaVacia(){return primero == NULL;}
    void Push(Viaje *nuevo);
    void Pop();
    Viaje *buscar(QString);
    Viaje *buscarDestino(QString);

};

#endif // VIAJE_H
