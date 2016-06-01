#include "vagregaequipaje.h"
#include "ui_vagregaequipaje.h"
#include "equipaje.h"

vagregaequipaje::vagregaequipaje(QWidget *parent):QDialog(parent),ui(new Ui::vagregaequipaje){
    ui->setupUi(this);
}

vagregaequipaje::~vagregaequipaje(){
    delete ui;
}

/*
 * Funcion que se ejecuta cuando se le da clic al boton agregar, carga los datos de la maleta para agregar al pasajero
 * Entradas: Ninguna
 * Salidas: Ninguna
*/
void vagregaequipaje::on_btnAgregar_clicked(){

    int peso = ui->txfPeso->text().toInt();
    bool isMano = ui->chxMano->checkState() == 1;

    Equipaje *nuevo = new Equipaje(peso, this->amo, isMano);
    this->amo->equipaje->insertar(nuevo);
    this->close();
}
