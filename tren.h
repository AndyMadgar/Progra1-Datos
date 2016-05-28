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
    int pesoBodega;
    int pesoPasajero;
    class Tren *siguiente;
    Tren(QString, QString, QString);

};

#endif // TREN_H
