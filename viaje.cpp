#include "viaje.h"

Viaje::Viaje(tren pTransporte, QString pInicio, QString pFinal){
    this->transporte = pTransporte;
    this->inicio = pInicio;
    this->final = pFinal;
    this->siguiente = NULL;
}

void listaViajes::Insertar(viaje nuevo){
    if(listaVacia()){
        primero = nuevo;
    }
    else{
        viaje tmp = primero;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = nuevo;
    }
}
