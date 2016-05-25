#ifndef TREN_H
#define TREN_H
#include <QString>
#include "pasajero.h"
#include "equipaje.h"

class Tren{
public:
    class listaPasajero *listaAsientos;
    class listaEquipaje *bodega;
    QString destino;
    QString capitan;
    QString placa;
    int pesoBodega=500;
    int pesoPasajero=300;
    class Tren *siguiente;
    Tren(QString, QString, int);
};

class listaTrenes{
public:
    class Tren *primero;
    listaTrenes(){primero = NULL;}
    bool listaVacia(){return primero == NULL;}
    void insertar(Tren *);
    Tren *buscar(QString);
};

#endif // TREN_H
