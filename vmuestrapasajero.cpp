#include "vmuestrapasajero.h"
#include "ui_vmuestrapasajero.h"
#include "principal.h"
#include <QDebug>

vmuestrapasajero::vmuestrapasajero(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vmuestrapasajero)
{
    ui->setupUi(this);
}

vmuestrapasajero::~vmuestrapasajero()
{
    delete ui;
}

void vmuestrapasajero::actualizar()
{
    ui->txfApellido->setText(this->amo->apellidos);
    ui->txfDestino->setText(this->amo->destino);
    ui->txfEstatura->setText(QString::number(this->amo->estatura));
    ui->txfID->setText(QString::number(this->amo->ID));
    ui->txfNacio->setText(this->amo->nacionalidad);
    ui->txfNombre->setText(this->amo->nombre);
    ui->txfPeso->setText(QString::number(this->amo->peso));
    ui->txfTelefono->setText(QString::number(this->amo->telefono));
}
