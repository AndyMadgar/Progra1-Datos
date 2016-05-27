#include "vmuestraviajes.h"
#include "ui_vmuestraviajes.h"

vmuestraviajes::vmuestraviajes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vmuestraviajes)
{
    ui->setupUi(this);
}

vmuestraviajes::~vmuestraviajes()
{
    delete ui;
}

void vmuestraviajes::acctualizarHoras(){

}
