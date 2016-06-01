#ifndef PASAJERO_H
#define PASAJERO_H
#include <QString>
#include "equipaje.h"
#include "ticket.h"

/*
 * Instituto Tecnologico de Costa Rica
 * Estructura de Datos
 * Lista Doble Enlazada
 * Para Pasajeros
*/
class Pasajero{
public:
    //Declaracion de atributos
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
    class Pasajero *anterior;
    //Constructor
    Pasajero(QString, QString, int, int, QString, int, int, QString,int);
};

//Clase para crear la lista de pasajeros
class listaPasajero{
public:
    //Declaracion de atributos
    Pasajero *primero;
    //Constructor
    listaPasajero(){primero = NULL;}
    //Declaracion de funciones
    bool listaVacia(){return primero == NULL;}
    void Push(Pasajero *);
    //void Pop();
    void eliminar(Pasajero *);
    Pasajero *buscar(int);
    void mostrar();
};

#endif // PASAJERO_H
