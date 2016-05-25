#include "vagregapasajero.h"
#include "ui_vagregapasajero.h"
#include "principal.h"
#include "vagregaequipaje.h"
#include <QDebug>

vagregapasajero::vagregapasajero(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vagregapasajero)
{
    ui->setupUi(this);
}

vagregapasajero::~vagregapasajero()
{
    delete ui;
}

void vagregapasajero::on_btnVolver_clicked()
{
    Principal *p = new Principal();
    p->colaEspera = this->colaEspera;
    p->colaTicket = this->colaTicket;
    p->colaTrenes = this->colaTrenes;
    p->show();
    this->close();
}

void vagregapasajero::on_btnAgregar_clicked()
{
    QString nombre = ui->txfNombre->text();
    QString apellido = ui->txfApellidos->text();
    QString nacio = ui->txfNacio->text();
    QString destino = ui->cbxDestino->currentText();
    int id = ui->txfID->text().toInt();
    int telf = ui->txfTelefono->text().toInt();
    int peso = ui->txfPeso->text().toInt();
    int estatura = ui->txfEstatura->text().toInt();

    Pasajero *nuevo = new Pasajero(nombre, apellido, id, telf, nacio, peso, estatura, destino);

    vagregaequipaje *v = new vagregaequipaje();
    v->colaEspera = this->colaEspera;
    v->colaTicket = this->colaTicket;
    v->colaTrenes = this->colaTrenes;
    v->amo = nuevo;
    this->hide();
    v->exec();
    this->close();
}
