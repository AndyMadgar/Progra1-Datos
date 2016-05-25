#ifndef VIAJE_H
#define VIAJE_H
#include "tren.h"
#include <QDateTime>

typedef class Viaje{
public:
    tren transporte;
    QString inicio;
    QString final;
    int transcurrido;
    int restante;
    int total;
    class Viaje *siguiente;
    Viaje(Tren*, QString, QString);

}*viaje;


typedef class listaViajes{
public:
    viaje primero;
    listaViajes(){primero = NULL;}
    bool listaVacia(){return primero == NULL;}
    void Insertar(viaje nuevo);
    viaje buscar();
    //void eliminar();

}*viajes;

#endif // VIAJE_H
