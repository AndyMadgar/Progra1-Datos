#include "viaje.h"

Viaje::Viaje(Tren *pTransporte, QDateTime pInicio, QDateTime pFinal){
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

void listaViajes::ajustarTiempos(Viaje *tmp){
    QDateTime actual= QDateTime.currentDateTime();
    if (tmp->final>=actual){
        tmp2=tmp->siguiente;
        ajustarTiempos(tmp2);
    }
    else{
    }
    while(tmp->siguiente != NULL){
        actual= QDateTime.currentDateTime();
        if (tmp->siguiente->final>=actual){
            inicio=tmp->siguiente;
        }
        else(){

        }
        tmp = tmp->siguiente;
    }


}
