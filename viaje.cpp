#include "viaje.h"
#include <QDebug>

Viaje::Viaje(Tren *pTransporte, QDateTime pInicio, QDateTime pFinal){
    this->transporte = pTransporte;
    this->inicio = pInicio;
    this->final = pFinal;
    this->siguiente = NULL;
    //calcular restante y transcurrido
}

Viaje::Viaje(){
    this->transporte = NULL;
    this->inicio = QDateTime::currentDateTime();
    this->final = QDateTime::currentDateTime();
    this->siguiente = NULL;
}

void listaViajes::Push(Viaje *nuevo){
    if(listaVacia()){
        this->primero = nuevo;
    }
    else{
        Viaje *tmp = this->primero;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = nuevo;
    }
}

void  listaViajes::Pop(){
    if (listaVacia()){
    }
    else{
        Viaje *tmp = this->primero;
        this->primero= tmp->siguiente;
    }
}

Viaje *listaViajes::buscar(QString id){
    if(listaVacia()){
        return NULL;
    }
    else{
        Viaje *tmp = this->primero;
        while(tmp != NULL){
            if(tmp->transporte->placa == id){
                return tmp;
            }
            else{
                tmp = tmp->siguiente;
            }
        }
        return NULL;
    }
}

Viaje *listaViajes::buscarDestino(QString Destino){
    if(listaVacia()){
        return NULL;
    }
    else{
        Viaje *tmp = this->primero;
        while(tmp != NULL){
            if(tmp->transporte->destino == Destino){
                return tmp;
            }
            else{
                tmp = tmp->siguiente;
            }
        }
        Viaje *x = new Viaje();
        return x;
    }
}


