#ifndef HILO_H
#define HILO_H
#include <QThread>

class Hilo : public QThread{
public:
    Hilo();
    void run();
};

#endif // HILO_H
