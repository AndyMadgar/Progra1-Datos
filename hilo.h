#ifndef HILO_H
#define HILO_H
#include <QThread>
#include "principal.h"

//Hilo que controla los viajes.
class Hilo : public QThread{
public:
    Hilo();
    void run();
    Principal *ventanaPrincipal = new Principal();
};

#endif // HILO_H
