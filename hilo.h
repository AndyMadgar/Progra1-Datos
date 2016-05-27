#ifndef HILO_H
#define HILO_H
#include <QThread>
#include "principal.h"
#include "dios.h"

class Hilo : public QThread{
public:
    Dios *dios = new Dios();
    Hilo();
    void run();
};

#endif // HILO_H
