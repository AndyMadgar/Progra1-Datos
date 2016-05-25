#include "tren.h"

Tren::Tren(QString pDestino, QString pCapitan, int pPlaca){
    destino = pDestino;
    capitan = pCapitan;
    placa = pPlaca;
    siguiente = NULL;
}

void listaTrenes::insertar(Tren *nuevo){
    if(listaVacia()){
        primero = nuevo;
        return;
    }
    else{
        Tren *tmp = primero;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = nuevo;
    }
}

Tren *listaTrenes::buscar(QString placa){
    if(listaVacia()){
        return NULL;
    }
    else{
        Tren *tmp = primero;
        while(tmp->siguiente != NULL){
            if(tmp->placa == placa){
                return tmp;
            }
            else{
                tmp = tmp->siguiente;
            }
        }
        return NULL;
    }
}
