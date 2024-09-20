#include "MainPrincipal.h"
#include "ui_mainprincipal.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include "Usuarios.h"
#include "mainusuarios.h"
#include "mainadmin.h"
using namespace std;
MainPrincipal::MainPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPrincipal)
{
    ui->setupUi(this);
    // Inicializar el administrador con un usuario Admin
    listaUsuarios.addUser(User("Admin", "Admin", "01-01-1970", "admin@gmail.com", "EDD2S2024"));
}

MainPrincipal::~MainPrincipal()
{
    delete ui;
}

void MainPrincipal::on_iniciosesion_clicked()
{
    // Obtener correo y contraseña de los campos de entrada
    QString email = ui->correoI->text();
    QString password = ui->contrasenaI->text();

    // Verificar si el usuario y contraseña son válidos
    if (listaUsuarios.login(email.toStdString(), password.toStdString())) {
        if (email == "admin@gmail.com" && password == "EDD2S2024") {
            QMessageBox::information(this, "Inicio de Sesión", "Sesión de administrador iniciada correctamente.");

            // Crear y mostrar la ventana de administración
            mainadmin *ventanaAdmin = new mainadmin(this, listaUsuarios);  // Asegúrate de que listaUsuarios sea accesible aquí y pasa como referencia si es necesario
            ventanaAdmin->setAttribute(Qt::WA_DeleteOnClose);  // Asegura que la ventana se elimine de la memoria al cerrarse
            ventanaAdmin->show();

        } else {
            // Mostrar mensaje de inicio de sesión de usuario
            QMessageBox::information(this, "Inicio de Sesión", "Sesión de usuario iniciada correctamente.");
            // Crear y mostrar la ventana de usuarios
            MainUsuarios *ventanaUsuarios = new MainUsuarios(listaUsuarios, this);  // Asegúrate de que listaUsuarios sea accesible aquí y pasa como referencia si es necesario
            ventanaUsuarios->setAttribute(Qt::WA_DeleteOnClose);  // Asegura que la ventana se elimine de la memoria al cerrarse
            ventanaUsuarios->show();

        }
    } else {
        // Mostrar mensaje de error si el correo o contraseña son incorrectos
        QMessageBox::warning(this, "Error", "Correo o contraseña incorrectos.");
    }
}


void MainPrincipal::on_registrarse_clicked()
{
    // Obtener la información directamente de los QLineEdit en la interfaz de usuario
    QString firstName = ui->nombreR->text();
    QString lastName = ui->apellidoR->text();
    QString birthDate = ui->fechaR->text();
    QString email = ui->correoR->text();
    QString password = ui->contrasenaR->text();
    // Agregar el nuevo usuario a la lista
    listaUsuarios.addUser(User(firstName.toStdString(), lastName.toStdString(), birthDate.toStdString(), email.toStdString(), password.toStdString()));

    // Mostrar mensaje de registro exitoso
    QMessageBox::information(this, "Registro", "Usuario registrado correctamente.");
}

void MainPrincipal::on_informacion_clicked()
{
    // Mostrar información sobre el autor y el proyecto
    QMessageBox::information(this, "Información",
                             "EVELYN MARICELY BALCARCEL RIVERA\n"
                             "202200110\n"
                             "Ingeniería en Ciencias y Sistemas\n"
                             "Laboratorio Estructura de Datos\n"
                             "PROYECTO FASE: Social Structure\n"
                             "Auxiliar: Carlos Javier Castro\n"
                             "Sección: B");
}

void MainPrincipal::on_salir_clicked()
{
    // Cerrar la aplicación
    QApplication::quit();
}



void MainPrincipal::on_INTERFAZ_currentChanged(int index)
{
    switch(index) {
    case 0:  // Tab de inicio de sesión
        // Puedes inicializar o limpiar campos si es necesario
        ui->correoI->clear();
        ui->contrasenaI->clear();
        break;

    case 1:  // Tab de registro

        break;

    case 2:  // Tab de información

        break;

    case 3:
        on_salir_clicked();
        break;
    }
}



