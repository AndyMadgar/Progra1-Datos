#include "vagregartren.h"
#include "ui_vagregartren.h"
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
    this->close();
}

/*
 * Funcion que se ejecuta cuando se le da clic al boton agregar, carga los datos necesarios para crear un nuevo tren
 * Entradas: Ninguna
 * Salidas: Ninguna
*/
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

    this->close();
}
