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
    Viaje(Tren*, QDateTime, QDateTime);

};


class listaViajes{
public:
    class Viaje *primero;
    listaViajes(){primero = NULL;}
    bool listaVacia(){return primero == NULL;}
    void Insertar(Viaje *nuevo);
    Viaje *buscar();
    //void eliminar();
    void ajustarTiempos();

};

#endif // VIAJE_H
