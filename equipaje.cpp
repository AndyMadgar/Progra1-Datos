#include "equipaje.h"

Equipaje::Equipaje(int pPeso, Pasajero *pAmo, bool pHand){
    this->peso = pPeso;
    this->amo = pAmo;
    this->isInHand = pHand;
}

void listaEquipaje::insertar(Equipaje *equi){
    if(listaVacia()){
        primero = equi;
        return;
    }
    else{
        Equipaje *tmp = primero;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        tmp->siguiente = equi;
    }
    return;
}
