#ifndef ESTACIONPRINCIPAL_H
#define ESTACIONPRINCIPAL_H
#include <QString>
#include "tren.h"
#include "viaje.h"

class EstacionPrincipal{
public:
    Viaje *viajesCurso;
   // Hilo *hilo;
    trenes Ltrenes;
    //Cola *compraTickets;
    //Cola *esperaTren;
    Viaje *viajes;
    EstacionPrincipal();
};

#endif // ESTACIONPRINCIPAL_H
