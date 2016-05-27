#include "ticket.h"

Ticket::Ticket(int pAsiento, Tren *pTransporte, QString pDestino){
    this->asiento = pAsiento;
    this->transporte = pTransporte;
    this->destino = pDestino;
    this->siguiente=NULL;
}

void listaTickets::insertar(Ticket *ticket){
    if(listaVacia()){
        this->primero = ticket;
        return;
    }
    else{
        Ticket *tmp = this->primero;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = ticket;
    }
    return;
}
