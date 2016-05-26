#include "vagregartren.h"
#include "ui_vagregartren.h"
#include "principal.h"
#include "viaje.h"

vagregartren::vagregartren(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vagregartren)
{
    ui->setupUi(this);
}

vagregartren::~vagregartren()
{
    delete ui;
}

void vagregartren::on_btnVolver_clicked()
{
    Principal *p = new Principal();
    p->colaEspera = this->colaEspera;
    p->colaTicket = this->colaTicket;
    p->colaViajes = this->colaViajes;

    p->setVisible(true);
    this->close();
    p->show();
}

void vagregartren::on_btnAgregar_clicked()
{
    QString capitan = ui->txfCapitan->text();
    QString destino = ui->cbxDestino->currentText();
    QString placa = ui->txfPlaca->text();
    QDateTime actual = QDateTime::currentDateTime();
    QDateTime inicio = actual.addSecs(ui->txfInicio->text().toInt());
    QDateTime final = inicio.addSecs(ui->txfFin->text().toInt());

    Tren *nuevo = new Tren(destino, capitan, placa);
    Viaje *viajeNuevo = new Viaje(nuevo, inicio, final);
    this->colaViajes->Push(viajeNuevo);

    Principal *p = new Principal();
    p->colaEspera = this->colaEspera;
    p->colaTicket = this->colaTicket;
    p->colaViajes = this->colaViajes;

    p->setVisible(true);
    this->close();
    p->show();
}
