#ifndef EQUIPAJE_H
#define EQUIPAJE_H
#include "pasajero.h"

class Equipaje{
public:
    int peso;
    class Pasajero *amo;
    bool isInHand;
    class Equipaje *siguiente;
    Equipaje(int, Pasajero *, bool);
};

class listaEquipaje{
public:
    Equipaje *primero;
    listaEquipaje(){primero = NULL;}
    bool listaVacia(){return primero == NULL;}
    void insertar(Equipaje *);
};

#endif // EQUIPAJE_H
