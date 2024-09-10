#ifndef MAINUSUARIOS_H
#define MAINUSUARIOS_H

#include <QDialog>
#include "ListaUsuarios.h"
#include "Usuarios.h"
#include "MainPrincipal.h"

namespace Ui {
class MainUsuarios;
}

class MainUsuarios : public QDialog
{
    Q_OBJECT

public:
    explicit MainUsuarios(ListaU& listaUsuarios, MainPrincipal* mainPrincipal, QWidget *parent = nullptr);
    ~MainUsuarios();

    User* findUser(const std::string& email);

private slots:

    void on_buscarB_clicked();

    void on_USUARIO_currentChanged(int index);

    void on_salirUsuario_clicked();

    void on_ModifcarD_clicked();

    void on_ElimanarC_clicked();

private:
    Ui::MainUsuarios *ui;
    ListaU& listaUsuarios;
    //User* currentUser; // mantine el usuario actual
    MainPrincipal* mainPrincipal;
    ListaU::Node* currentUser;
};
#endif // MAINUSUARIOS_H
