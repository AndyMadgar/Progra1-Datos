#include "vagregartrenes.h"
#include "ui_vagregartrenes.h"
#include "tren.h"
#include "principal.h"
vAgregarTrenes::vAgregarTrenes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vAgregarTrenes)
{
    ui->setupUi(this);
}

vAgregarTrenes::~vAgregarTrenes()
{
    delete ui;
}

void vAgregarTrenes::on_pushButton_clicked()
{
    QString pDestino=ui->cmbxDestino->currentText();
    QString pCapitan=ui->txtfCapitan->text();
    int pPlaca=ui->txtfPlaca->text().toInt();

    Principal *p;

    Tren *tre = new Tren(pDestino, pCapitan, pPlaca);
    p->ColaTrenes->insertar(tre);
    this->close();
}
