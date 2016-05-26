#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "principal.h"

class Controlador{
public:
    Principal *ventanaPrincipal = new Principal();
    void cargarPasajeros();
    void cargarViajes();
    Controlador();

};

#endif // CONTROLADOR_H
