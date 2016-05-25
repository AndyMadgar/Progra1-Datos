#include "principal.h"
#include "ui_principal.h"
#include "vagregarpasajero.h"

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_btnAgregaPasajero_clicked()
{
    vAgregarPasajero ventana;
    ventana.setModal(true);
    this->setVisible(false);
    ventana.exec();
    while(ventana.isVisible()){
    }
    this->setVisible(true);
}
