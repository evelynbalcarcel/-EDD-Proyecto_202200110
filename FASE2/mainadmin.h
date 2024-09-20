#ifndef MAINADMIN_H
#define MAINADMIN_H

#include <QDialog>
#include "MainPrincipal.h"
#include "ListaUsuarios.h"
using namespace std;
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

    void on_cargaUsuariosBuscar_cellClicked(int row, int column);
    void cargarUsuariosTable();
    void cargarAVL(ListaU::AVLNode* node);

    void on_CargaUsuariosJSON_clicked();
    void on_CargaSoliJSON_clicked();
    void on_CargaPubliJSON_clicked();

    void on_bucarUsuariosAdmin_clicked();

    void on_modificarUsuariosAdmin_clicked();

    void on_eliminarUsuariosAdmin_clicked();

    void on_comboBoxOrden_activated(int index);

    void on_AplicarOrdenAdmin_clicked();


private:
    Ui::mainadmin *ui;
    MainPrincipal* mainPrincipal;
    ListaU& listaUsuarios;
    ListaU::AVLNode* currentUser;
};

#endif // MAINADMIN_H
