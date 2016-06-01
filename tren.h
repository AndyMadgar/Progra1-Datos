#ifndef TREN_H
#define TREN_H
#include <QString>
#include "pasajero.h"
#include "equipaje.h"

/*
 * Instituto Tecnologico de Costa Rica
 * Estructura de Datos
 * Lista Doble Enlazada
 * Para Tren
*/
class Tren{
public:
    //Declaracion de atributos
    class listaPasajero *listaAsientos;
    class listaEquipaje *bodega;
    QString destino;
    QString capitan;
    QString placa;
    int pesoBodega;
    int pesoPasajero;
    //Constructor
    Tren(QString, QString, QString);

};

#endif // TREN_H
