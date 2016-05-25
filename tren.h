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
    int placa;
    int pesoBodega;
    int pesoPasajero;
    int pesoTotal;
    class Tren *siguiente;
    Tren(QString, QString, int);
    bool calcEspacio(Pasajero*);
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
