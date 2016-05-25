#ifndef TICKET_H
#define TICKET_H
#include <QString>
#include "tren.h"
class Ticket
{
public:
    int asiento;
    class Tren *transporte;
    QString destino;
    class Ticket *siguiente;
    Ticket(int, Tren*, QString);
};
class listaTickets{
public:
    Ticket *primero;
    listaTickets(){primero = NULL;}
    bool listaVacia(){return primero == NULL;}
    void insertar(Ticket *);
};
#endif // TICKET_H
