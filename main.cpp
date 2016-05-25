#include "principal.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "pasajero.h"
#include "tren.h"
#include "equipaje.h"

listaPasajero *pasajeros = new listaPasajero();
listaTrenes *listTrenes = new listaTrenes();

void cargarPasajeros(){
    QFile file("/home/shiki/Documentos/Datos/Estacion_Trenes/Datos/Pasajeros.xlsx");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "No se pudo cargar el archivo de pasajeros";
        return;
    }
    Pasajero *nuevo;

    QTextStream in(&file);
    QString nombre;
    QString apellido;
    int id;
    int telf;
    QString nacio;
    int peso;
    int estatura;
    QString destino;
    int pesoMaleta;
    bool isHand;
    QStringList data;
    while(!in.atEnd()){
        QString line = in.readLine();
        data = line.split(",");
        nombre = data.at(0);
        apellido = data.at(1);
        id = data.at(2).toInt();
        telf = data.at(3).toInt();
        nacio = data.at(4);
        peso = data.at(5).toInt();
        estatura = data.at(6).toInt();
        destino = data.at(7);
        pesoMaleta = data.at(8).toInt();
        isHand = data.at(9).toInt() == 1; // 1=true 0=false

        nuevo = new Pasajero(nombre, apellido, id, telf, nacio, peso, estatura, destino);
        Equipaje *mal = new Equipaje(pesoMaleta, nuevo, isHand);
        nuevo->equipaje->insertar(mal);
        pasajeros->insertar(nuevo);
    }
    file.flush();
    file.close();

}

void cargarTrenes(){
    QFile file("/home/shiki/Documentos/Datos/Estacion_Trenes/Datos/Trenes.xlsx");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "No se pudo cargar el archivo de trenes";
        return;
    }
    Tren *nuevo;
    QTextStream in(&file);
    QString destino;
    QString capitan;
    int placa;
    QStringList data;
    while(!in.atEnd()){
        QString line = in.readLine();
        data = line.split(",");
        destino = "";
        capitan = data.at(0);
        placa = data.at(1).toInt();

        nuevo = new Tren(destino, capitan, placa);
        listTrenes->insertar(nuevo);
    }
    file.flush();
    file.close();
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Principal w;
    w.show();

    return a.exec();
}
