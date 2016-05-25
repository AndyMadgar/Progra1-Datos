#ifndef VAGREGARPASAJEROS_H
#define VAGREGARPASAJEROS_H

#include <QDialog>

namespace Ui {
class vAgregarPasajeros;
}

class vAgregarPasajeros : public QDialog
{
    Q_OBJECT

public:
    explicit vAgregarPasajeros(QWidget *parent = 0);
    ~vAgregarPasajeros();

private:
    Ui::vAgregarPasajeros *ui;
};

#endif // VAGREGARPASAJEROS_H
