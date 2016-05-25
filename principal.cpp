#include "principal.h"
#include "ui_principal.h"
#include "vagregarpasajero.h"
#include "vagregartrenes.h"
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

void Principal::on_btnAgregaTren_clicked()
{
    vAgregarTrenes ventana;
    ventana.setModal(true);
    this->setVisible(false);
    ventana.exec();
    while(ventana.isVisible()){
    }
    this->setVisible(true);
}
