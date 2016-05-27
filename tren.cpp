#include "tren.h"

Tren::Tren(QString pDestino, QString pCapitan, QString pPlaca){
    destino = pDestino;
    capitan = pCapitan;
    placa = pPlaca;
    this->listaAsientos = new listaPasajero();
    this->bodega = new listaEquipaje();
    this->siguiente = NULL;
    this->pesoBodega = 500;
    this->pesoPasajero = 300;
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
