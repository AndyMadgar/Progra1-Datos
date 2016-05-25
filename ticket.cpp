#include "ticket.h"

Ticket::Ticket(int pAsiento, Tren *pTransporte, QString pDestino){
    this->asiento = pAsiento;
    this->transporte = pTransporte;
    this->destino = pDestino;
}
