#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "principal.h"
#include "pasajero.h"
#include "viaje.h"

class Controlador{
public:
    listaPasajero *listPasajeros = new listaPasajero();
    listaViajes *listViajes = new listaViajes();
    void cargarPasajeros();
    void cargarViajes();
    Controlador();

};

#endif // CONTROLADOR_H
