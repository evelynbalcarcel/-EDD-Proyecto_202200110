#ifndef MAINADMIN_H
#define MAINADMIN_H

#include <QDialog>
#include "MainPrincipal.h"
#include "ListaUsuarios.h"

namespace Ui {
class mainadmin;
}

class mainadmin : public QDialog
{
    Q_OBJECT

public:
    explicit mainadmin(MainPrincipal* mainPrincipal, ListaU& listaUsuarios, QWidget *parent = nullptr);  // Pasar MainPrincipal como puntero
    ~mainadmin();

private slots:

    void on_salirAdmin_clicked();

    void on_CargaUsuarios_clicked();

private:
    Ui::mainadmin *ui;
    MainPrincipal* mainPrincipal;
    ListaU& listaUsuarios;
};

#endif // MAINADMIN_H
