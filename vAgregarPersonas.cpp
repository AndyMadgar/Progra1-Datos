#include "vAgregarPasajeros.h"
#include "vAgregarPasajeros.h"

vAgregarPasajeros::vAgregaPasajeros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vAgregarPasajeros)
{
    ui->setupUi(this);
}

vAgregarPasajeros::~vAgregarPasajeros()
{
    delete ui;
}
