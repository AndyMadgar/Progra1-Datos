#ifndef HILO_H
#define HILO_H
#include <QThread>
#include "principal.h"

class Hilo : public QThread{
public:
    Principal *ventanaPrincipal = new Principal();
    Hilo(listaPasajero*, listaViajes*);
    void run();
};

#endif // HILO_H
