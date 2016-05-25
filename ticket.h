#ifndef TICKET_H
#define TICKET_H
#include <QString>
#include "tren.h"
class Ticket
{
public:
    int asiento;
    Tren *transporte;
    QString destino;
    Ticket(int, Tren*, QString);
};

#endif // TICKET_H
