#ifndef TREN_H
#define TREN_H
#include "equipaje.h"
#include "pasajero.h"

class Tren{
public:
    class listaPasajero *listaAsientos;
    class listaEquipaje *bodega;
    QString destino;
    QString capitan;
    int placa;
    int pesoBodega;
    int pesoPasajero;
    int pesoTotal;
    class Tren *siguiente;

    Tren(QString, QString, int);

};

class listaTrenes{
public:
    class Tren *primero;
    listaTrenes(){primero = NULL;}
    bool listaVacia(){return primero == NULL;}
    void insertar(Tren *);
    Tren *buscar(int);
};

#endif // TREN_H
