#include "tren.h"

/*
 * Constructor
 * Entradas: Los datos para crear el tren
 * Salidas: El tren ya creado
*/
Tren::Tren(QString pDestino, QString pCapitan, QString pPlaca){
    destino = pDestino;
    capitan = pCapitan;
    placa = pPlaca;
    this->listaAsientos = new listaPasajero();
    this->bodega = new listaEquipaje();
    this->pesoBodega = 500;
    this->pesoPasajero = 300;
}


