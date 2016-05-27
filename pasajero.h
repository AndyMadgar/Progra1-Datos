#ifndef PASAJERO_H
#define PASAJERO_H
#include <QString>
#include "equipaje.h"
#include "ticket.h"

class Pasajero{
public:
    QString nombre;
    QString apellidos;
    QString nacionalidad;
    QString destino;
    int ID;
    int telefono;
    int peso;
    int estatura;
    int cantTickets;
    class listaEquipaje *equipaje;
    class listaTickets *ticketsComprados;
    class Pasajero *siguiente;
    Pasajero(QString, QString, int, int, QString, int, int, QString,int);
};

class listaPasajero{
public:
    Pasajero *primero;
    listaPasajero(){primero = NULL;}
    bool listaVacia(){return primero == NULL;}
    void Push(Pasajero *);
    void Pop();
    Pasajero *buscar(int);
};

#endif // PASAJERO_H
