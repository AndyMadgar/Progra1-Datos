#ifndef EQUIPAJE_H
#define EQUIPAJE_H
#include "pasajero.h"

typedef class Equipaje{
public:
    int peso;
    Pasajero *amo;
    bool isInHand;
    class Equipaje *siguiente;
    Equipaje(int, Pasajero*, bool);
}*maleta;

typedef class listaEquipaje{
public:
    maleta primero;
    listaEquipaje(){primero = NULL;}
    bool listaVacia(){return primero == NULL;}
    void insertar(maleta);

}*lMaleta;

#endif // EQUIPAJE_H
