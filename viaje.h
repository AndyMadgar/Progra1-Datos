#ifndef VIAJE_H
#define VIAJE_H
#include "tren.h"
#include <QDateTime>

class Viaje{
public:
    Tren *transporte;
    QString inicio;
    QString final;
    int transcurrido;
    int restante;
    int total;
    class Viaje *siguiente;
    Viaje(Tren*, QString, QString);

};


class listaViajes{
public:
    class Viaje *primero;
    listaViajes(){primero = NULL;}
    bool listaVacia(){return primero == NULL;}
    void Insertar(Viaje *nuevo);
    Viaje *buscar();
    //void eliminar();

};

#endif // VIAJE_H
