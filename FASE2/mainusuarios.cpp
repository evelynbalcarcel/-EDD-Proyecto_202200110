#include "mainusuarios.h"
#include "ui_mainusuarios.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QString>


MainUsuarios::MainUsuarios(ListaU& listaUsuarios, MainPrincipal* mainPrincipal, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainUsuarios)
    , listaUsuarios(listaUsuarios)
    , mainPrincipal(mainPrincipal)  // Inicializar el puntero a la ventana principal.
    , currentUser(nullptr)
{
    ui->setupUi(this);
}

MainUsuarios::~MainUsuarios()
{
    delete ui;
}

void MainUsuarios::on_buscarB_clicked() {
    QString email = ui->BuscarCorreo->text();
    ListaU::Node* node = listaUsuarios.findUser(email.toStdString());

    if (node != nullptr) {
        currentUser = node;  // Asignar el usuario actual al puntero currentUser

        // Llenar los campos con los datos del usuario
        ui->nombreU->setText(QString::fromStdString(node->user.getFirstName()));
        ui->apellidoU->setText(QString::fromStdString(node->user.getLastName()));
        ui->correoU->setText(QString::fromStdString(node->user.getEmail()));
        ui->fechaU->setText(QString::fromStdString(node->user.getBirthDate()));
    } else {
        QMessageBox::warning(this, "Buscar", "No se encontró un usuario con ese correo.");
        ui->nombreU->clear();
        ui->apellidoU->clear();
        ui->correoU->clear();
        ui->fechaU->clear();
    }
}

void MainUsuarios::on_salirUsuario_clicked() {
    close();
    if (mainPrincipal != nullptr) {
        mainPrincipal->show();  // Muestra la ventana principal si no es nula
    }
}


void MainUsuarios::on_USUARIO_currentChanged(int index) {
    if (index == 4 && currentUser != nullptr) {  // Cuando se selecciona la pestaña de Perfil
        User& user = currentUser->user;

        // Llenar los campos del perfil con los datos del usuario actual
        ui->nombreP->setText(QString::fromStdString(user.getFirstName()));
        ui->apellidoP->setText(QString::fromStdString(user.getLastName()));
        ui->correoP->setText(QString::fromStdString(user.getEmail()));
        ui->contraP->setText(QString::fromStdString(user.getPassword()));
        ui->fechaP->setText(QString::fromStdString(user.getBirthDate()));
    }
}

void MainUsuarios::on_ModifcarD_clicked()
{
    if (currentUser != nullptr) {
        // Recoger los datos modificados de los QLineEdit
        std::string newFirstName = ui->nombreP->text().toStdString();
        std::string newLastName = ui->apellidoP->text().toStdString();
        std::string newEmail = ui->correoP->text().toStdString();
        std::string newPassword = ui->contraP->text().toStdString();
        std::string newBirthDate = ui->fechaP->text().toStdString();

        // Actualizar el objeto usuario actual
        currentUser->user.setFirstName(newFirstName);
        currentUser->user.setLastName(newLastName);
        currentUser->user.setEmail(newEmail);
        currentUser->user.setPassword(newPassword);
        currentUser->user.setBirthDate(newBirthDate);

        QMessageBox::information(this, "Perfil", "Datos actualizados correctamente.");
    } else {
        QMessageBox::warning(this, "Error", "No se pudo actualizar el perfil.");
    }
}

void MainUsuarios::on_ElimanarC_clicked()
{
    if (currentUser != nullptr && listaUsuarios.deleteAccount(currentUser->user.getEmail(), currentUser->user.getPassword())) {
        QMessageBox::information(this, "Perfil", "Cuenta eliminada correctamente.");
        close();  // Cierra la ventana si la cuenta se elimina
    } else {
        QMessageBox::warning(this, "Error", "No se pudo eliminar la cuenta.");
    }
}

