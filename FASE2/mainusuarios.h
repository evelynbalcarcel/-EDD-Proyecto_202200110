#ifndef MAINUSUARIOS_H
#define MAINUSUARIOS_H
#include <QDialog>
#include "ListaUsuarios.h"
#include "Usuarios.h"
#include "MainPrincipal.h"
using namespace std;
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

    void on_salirUsuario_clicked();

    void on_USUARIO_currentChanged(int index);

    void on_ElimanarC_clicked();

    void on_ModifcarD_clicked();

//funociones Usuarios
    void on_CargaUsuariosSoli_cellClicked(int row, int column);
    void cargarUsuariosEnTabla();
    void cargarDesdeAVL(ListaU::AVLNode* node);
    void on_enviarSoli_clicked();

//Funciones Solicitudes recibidas
    void on_soliRecibidas_cellClicked(int row, int column);
    void on_aceptarSoli_clicked();
    void on_rechazarSoli_clicked();

// Funciones Solicitudes enviadas
    void on_soliEnviadas_cellClicked(int row, int column);
    void on_cancelarSoliEnviada_clicked();
    void cargarSolicitudesEnviadas();

private:
    Ui::MainUsuarios *ui;
    ListaU& listaUsuarios;
    //User* currentUser; // mantine el usuario actual
    MainPrincipal* mainPrincipal;
    ListaU::AVLNode* currentUser;

};
#endif // MAINUSUARIOS_H
