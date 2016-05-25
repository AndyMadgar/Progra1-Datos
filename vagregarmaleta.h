#ifndef VAGREGARMALETA_H
#define VAGREGARMALETA_H

#include <QDialog>
#include "pasajero.h"
namespace Ui {
class vAgregarMaleta;
}

class vAgregarMaleta : public QDialog
{
    Q_OBJECT

public:
    explicit vAgregarMaleta(QWidget *parent = 0);
    ~vAgregarMaleta();
    Pasajero *amo;
    QDialog ventanaPasajero;

private slots:
    void on_pushButton_clicked();

private:
    Ui::vAgregarMaleta *ui;
};

#endif // VAGREGARMALETA_H
