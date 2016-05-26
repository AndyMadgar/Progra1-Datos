#include "controlador.h"
#include <QApplication>
#include "hilo.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Controlador *controlador=new Controlador();
    controlador->cargarPasajeros();
    controlador->cargarViajes();
    Hilo *h1 = new Hilo(controlador->listPasajeros, controlador->listViajes);
    h1->start();
    return a.exec();

}
