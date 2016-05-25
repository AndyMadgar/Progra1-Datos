#include "ticket.h"

Ticket::Ticket(int pAsiento, Tren *pTransporte, QString pDestino){
    this->asiento = pAsiento;
    this->transporte = pTransporte;
    this->destino = pDestino;
}

void listaTickets::insertar(Ticket *ticket){
    if(listaVacia()){
        primero = ticket;
        return;
    }
    else{
        Ticket *tmp = primero;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = ticket;
    }
    return;
}
