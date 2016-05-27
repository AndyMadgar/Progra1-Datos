#include <QApplication>
#include "hilo.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Hilo *h1 = new Hilo();
    h1->start();
    return a.exec();
}
