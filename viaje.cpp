#include "viaje.h"

Viaje::Viaje(Tren *pTransporte, QDateTime pInicio, QDateTime pFinal){
    this->transporte = pTransporte;
    this->inicio = pInicio;
    this->final = pFinal;
    this->siguiente = NULL;
}

void listaViajes::Push(Viaje *nuevo){
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
void  listaViajes::Pop(){
    if (listaVacia()){
    }
    else{
        Viaje *tmp = this->primero;
        this->primero= tmp->siguiente;
    }
}

void listaViajes::ajustarTiempos(){
    QDateTime actual = QDateTime::currentDateTime();
    Viaje *tmp = this->primero;
    if (tmp->final >= actual){
        this->primero = tmp->siguiente;
    }
    else{
        Viaje *tmp2 = NULL;
        while(tmp->siguiente != NULL){
            actual = QDateTime::currentDateTime();
            if (tmp->final >= actual){
                tmp2 = tmp;
                tmp = NULL;
                tmp = this->primero;
                while(tmp->siguiente != NULL){
                    tmp = tmp->siguiente;
                }
                tmp->siguiente = tmp2->siguiente;
            }

            tmp = tmp->siguiente;
        }
        if (tmp->final >= actual){
            tmp2 = tmp;
            tmp = NULL;
            tmp = this->primero;
            while(tmp->siguiente != NULL){
                tmp = tmp->siguiente;
            }
            tmp->siguiente = tmp2->siguiente;

        }
    }

}
