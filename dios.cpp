#include "dios.h"
#include "ui_dios.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

Dios::Dios(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dios)
{
    ui->setupUi(this);
    this->ventanaPrincipal = new Principal();
    this->colaEspera = new listaPasajero();
    this->colaTicket = cargarPasajeros();
    this->colaViajes = cargarViajes();

    ////////////////////////////////////////////

    this->ventanaPrincipal->colaEspera = this->colaEspera;
    this->ventanaPrincipal->colaTicket = this->colaTicket;
    this->ventanaPrincipal->colaViajes = this->colaViajes;

    this->ventanaPrincipal->setVisible(true);
    this->ventanaPrincipal->show();
}

Dios::~Dios()
{
    delete ui;
}

listaPasajero* Dios::cargarPasajeros(){
    QFile file("/home/shiki/Documentos/Datos/Estacion_Trenes/Datos/Pasajeros.xlsx");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "No se pudo cargar el archivo de pasajeros";
        return NULL;
    }
    listaPasajero *lista = new listaPasajero();
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
        lista->Push(nuevo);
    }
    file.flush();
    file.close();
    return lista;

}

listaViajes *Dios::cargarViajes(){
    QFile file("/home/shiki/Documentos/Datos/Estacion_Trenes/Datos/Viajes.xlsx");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "No se pudo cargar el archivo de trenes";
        return NULL;
    }
    Tren *nuevo;
    Viaje *viajeNuevo;
    listaViajes *lista = new listaViajes();
    QTextStream in(&file);
    QString destino;
    QString capitan;
    QString placa;
    QDateTime inicio;
    QDateTime final;
    QStringList data;
    while(!in.atEnd()){
        QString line = in.readLine();
        data = line.split(",");
        capitan = data.at(0);
        placa = data.at(1);
        destino = data.at(2);
        QDateTime actual = QDateTime::currentDateTime();
        inicio = actual.addSecs(data.at(3).toInt());
        final = inicio.addSecs(data.at(4).toInt());
        nuevo = new Tren(destino, capitan, placa);
        viajeNuevo = new Viaje(nuevo, inicio, final);
        lista->Push(viajeNuevo);
    }
    file.flush();
    file.close();
    return lista;
}

