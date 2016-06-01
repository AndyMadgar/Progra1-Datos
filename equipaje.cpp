#include "equipaje.h"

/* Constructor
 * Entradas: Datos para crear el nodo de equipaje
 * Salida: Ninguna
*/
Equipaje::Equipaje(int pPeso, Pasajero *pAmo, bool pHand){
    this->peso = pPeso;
    this->amo = pAmo;
    this->isInHand = pHand;
    this->siguiente = NULL;
    this->anterior = NULL;
}

/* Funcion que permite insertar nuevos equipajes a la lista de equipajes
 * Entradas: Un puntero de equipaje
 * Salidas: Ninguna
*/
void listaEquipaje::insertar(Equipaje *equi){
    if(listaVacia()){
        this->primero = equi;
        this->primero->anterior = NULL;
        return;
    }
    else{
        Equipaje *tmp =this->primero;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = equi;
        tmp->siguiente->anterior = tmp;
    }
}
