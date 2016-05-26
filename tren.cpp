#include "tren.h"

Tren::Tren(QString pDestino, QString pCapitan, QString pPlaca){
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

bool Tren::calcEspacio(Pasajero *cliente){
    int pesoCliente = cliente->peso;
    int pesoBodega = 0;
    Equipaje *tmp = cliente->equipaje->primero;
    while(tmp != NULL){
        if(tmp->isInHand){
            pesoCliente += tmp->peso;
        }
        else{
            pesoBodega += tmp->peso;
        }
        tmp = tmp->siguiente;
    }
    if(pesoCliente > this->pesoPasajero && pesoBodega > this->pesoBodega){
        return false;
    }
    else{
        this->pesoBodega -= pesoBodega;
        this->pesoPasajero -= pesoCliente;
        return true;
    }
}
