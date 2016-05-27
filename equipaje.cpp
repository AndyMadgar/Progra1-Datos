#include "equipaje.h"

Equipaje::Equipaje(int pPeso, Pasajero *pAmo, bool pHand){
    this->peso = pPeso;
    this->amo = pAmo;
    this->isInHand = pHand;
    this->siguiente = NULL;
}

void listaEquipaje::insertar(Equipaje *equi){
    if(listaVacia()){
        this->primero = equi;
        return;
    }
    else{
        Equipaje *tmp =this->primero;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = equi;
    }
    return;
}
