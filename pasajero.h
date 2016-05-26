#ifndef PASAJERO_H
#define PASAJERO_H
#include <QString>
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
    class listaEquipaje *equipaje;
    class listaTickets *ticketes;
    class Pasajero *siguiente;

    Pasajero(QString, QString, int, int, QString, int, int, QString);
};

class listaPasajero{
public:
    Pasajero *primero;

    listaPasajero(){primero = NULL;}
    bool listaVacia(){return primero == NULL;}
    void Push(Pasajero *);
    Pasajero *buscar(int);
    int cuentaPos(int);
    void Pop();
    void Mostrar();

};

#endif // PASAJERO_H
