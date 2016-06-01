#ifndef EQUIPAJE_H
#define EQUIPAJE_H
#include "pasajero.h"

/*
 * Instituto Tecnologico de Costa Rica
 * Estructura de Datos
 * Lista Doble Enlazada
 * Para Equipaje
*/

class Equipaje{
public:
    //Declaracion de Atributos
    int peso;
    class Pasajero *amo;
    bool isInHand;
    class Equipaje *siguiente;
    class Equipaje *anterior;
    //Constructor
    Equipaje(int, Pasajero *, bool);
};

class listaEquipaje{
public:
    //Declaracion de atributos
    Equipaje *primero;
    //Contrctor
    listaEquipaje(){primero = NULL;}
    //Declaracion de Funciones
    bool listaVacia(){return primero == NULL;}
    void insertar(Equipaje *);
};

#endif // EQUIPAJE_H
