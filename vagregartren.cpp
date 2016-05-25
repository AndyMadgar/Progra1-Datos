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
    p->colaTrenes = this->colaViajes;

    p->setVisible(true);
    this->close();
    p->show();
}

void vagregartren::on_btnAgregar_clicked()
{
    QString capitan = ui->txfCapitan->text();
    QString destino = ui->cbxDestino->currentText();
    int placa = ui->txfPlaca->text().toInt();

    Tren *nuevo = new Tren(destino, capitan, placa);
    this->colaViajes->insertar(nuevo);

    Principal *p = new Principal();
    p->colaEspera = this->colaEspera;
    p->colaTicket = this->colaTicket;
    p->colaTrenes = this->colaViajes;

    p->setVisible(true);
    this->close();
    p->show();
}
