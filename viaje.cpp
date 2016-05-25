#include "viaje.h"

Viaje::Viaje(Tren *pTransporte, QString pInicio, QString pFinal){
    this->transporte = pTransporte;
    this->inicio = pInicio;
    this->final = pFinal;
    this->siguiente = NULL;
}

void listaViajes::Insertar(Viaje *nuevo){
    if(listaVacia()){
        primero = nuevo;
    }
    else{
        Viaje *tmp = primero;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = nuevo;
    }
}
