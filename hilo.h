#ifndef HILO_H
#define HILO_H
#include <QThread>
#include "pasajero.h"
#include "viaje.h"
#include "principal.h"

class Hilo : public QThread{
public:
    Principal *p = new Principal();
    Hilo(listaPasajero *, listaViajes *);
    void run();
};

#endif // HILO_H
