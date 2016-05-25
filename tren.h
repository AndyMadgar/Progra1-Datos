#ifndef TREN_H
#define TREN_H
#include "equipaje.h"

typedef class listaAsiento{
public:
    int numero;
    class listaAsiento *siguiente;
}*asiento;

typedef class Tren{
public:
    asiento asientos;
    listaEquipaje bodega;
    QString destino;
    QString capitan;
    int placa;
    int pesoBodega;
    int pesoPasajero;
    int pesoTotal;
    class Tren *siguiente;

    Tren(QString, QString, int);

}*tren;

typedef class listaTrenes{
public:
    tren primero;
    listaTrenes(){primero = NULL;}
    bool listaVacia(){return primero == NULL;}
    void insertar(tren);
    tren buscar(int);

}*listaTrenes;

#endif // TREN_H
