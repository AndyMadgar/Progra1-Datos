#include <QApplication>
#include "hilo.h"

/* Funcion principal del programa que se encarga de la creacion de hilo
 * Entradas: Ninguna
 * Salidas: Ninguna
*/
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Hilo *h1 = new Hilo();
    h1->start();
    return a.exec();
}
