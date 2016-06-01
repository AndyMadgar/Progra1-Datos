#include "ticket.h"

/*
 * Constructor
 * Entradas: Datos para crear el ticket
 * Salidas: Ticket ya creado
*/
Ticket::Ticket(int pAsiento, Tren *pTransporte, QString pDestino){
    this->asiento = pAsiento;
    this->transporte = pTransporte;
    this->destino = pDestino;
    this->siguiente=NULL;
}

/*
 * Funcion que se encarga de insertar un nuevo ticket en la lista de tickets
 * Entradas: El ticket a insertar
 * Salidas: Ninguna
*/
void listaTickets::insertar(Ticket *ticket){
    if(listaVacia()){
        this->primero = ticket;
        this->primero->anterior = NULL;
        return;
    }
    else{
        Ticket *tmp = this->primero;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = ticket;
        tmp->siguiente->anterior = ticket;
    }
    return;
}
