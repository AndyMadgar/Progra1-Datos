#ifndef TICKET_H
#define TICKET_H
#include <QString>
#include "tren.h"

/*
 * Instituto Tecnologico de Costa Rica
 * Estructura de Datos
 * Lista Doble Enlazada
 * Para Tickets
*/
class Ticket{
public:
    //Declaracion de atributos
    int asiento;
    class Tren *transporte;
    QString destino;
    class Ticket *siguiente;
    class Ticket *anterior;
    //Constructor
    Ticket(int, Tren*, QString);
};

//Lista para el manejo de los ticketes
class listaTickets{
public:
    //Declaracion de atributos
    Ticket *primero;
    //Constructor
    listaTickets(){primero = NULL;}
    //Declaracion de funciones
    bool listaVacia(){return primero == NULL;}
    void insertar(Ticket *);
};

#endif // TICKET_H
