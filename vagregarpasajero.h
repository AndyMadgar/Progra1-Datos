#ifndef VAGREGARPASAJERO_H
#define VAGREGARPASAJERO_H

#include <QDialog>

namespace Ui {
class vAgregarPasajero;
}

class vAgregarPasajero : public QDialog
{
    Q_OBJECT

public:
    explicit vAgregarPasajero(QWidget *parent = 0);
    ~vAgregarPasajero();

private slots:
    void on_pushButton_clicked();

    void on_btnAgregarPasajero_clicked();

private:
    Ui::vAgregarPasajero *ui;
};

#endif // VAGREGARPASAJERO_H
