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


