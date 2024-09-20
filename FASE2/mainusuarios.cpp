#include "mainusuarios.h"
#include "Usuarios.h"
#include "ui_mainusuarios.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <QDebug>
#include "ListaUsuarios.h"
using namespace std;

MainUsuarios::MainUsuarios(ListaU& listaUsuarios, MainPrincipal* mainPrincipal, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainUsuarios)
    , listaUsuarios(listaUsuarios)
    , mainPrincipal(mainPrincipal)  // Inicializar el puntero a la ventana principal.
    //consultar si se modifica.
    , currentUser(nullptr)
{
    ui->setupUi(this);
// Muestra la tabla con datos de usuarios en solicitudes
    ui->CargaUsuariosSoli->setColumnCount(4);  // Nombres, Apellidos, Correo, Nacimiento
    QStringList headers = {"Nombres", "Apellidos", "Correo", "Nacimiento"};
    ui->CargaUsuariosSoli->setHorizontalHeaderLabels(headers);
    ui->CargaUsuariosSoli->setHorizontalHeaderLabels(headers);
    ui->CargaUsuariosSoli->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->CargaUsuariosSoli->setSelectionBehavior(QAbstractItemView::SelectRows);
    cargarUsuariosEnTabla();
}

MainUsuarios::~MainUsuarios()
{
    delete ui;
}
//========================Pestaña Buscar============================================

void MainUsuarios::on_buscarB_clicked() {
    QString email = ui->BuscarCorreo->text();
    ListaU::AVLNode* node = listaUsuarios.findUser(email.toStdString());

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

//============================Pestaña Salir======================================
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

//=======================Pestaña Perfil==========================================
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
    if (currentUser != nullptr && listaUsuarios.deleteNode(listaUsuarios.root, currentUser->user.getEmail())) {
        QMessageBox::information(this, "Perfil", "Cuenta eliminada correctamente.");
        close();  // Cierra la ventana si la cuenta se elimina
    } else {
        QMessageBox::warning(this, "Error", "No se pudo eliminar la cuenta.");
    }
}

//========================= Pestaña Solicitudes =======================================

//--------------------------- Enviar solicitud ----------------------------------------
void MainUsuarios::cargarUsuariosEnTabla() {
    ui->CargaUsuariosSoli->setRowCount(0);  // Limpiar la tabla antes de llenarla
    cargarDesdeAVL(listaUsuarios.root);  // Comienza desde la raíz
}

void MainUsuarios::cargarDesdeAVL(ListaU::AVLNode* node) {
    if (node != nullptr) {
        cargarDesdeAVL(node->left);  // Visitar hijo izquierdo

        int row = ui->CargaUsuariosSoli->rowCount();
        ui->CargaUsuariosSoli->insertRow(row);
        ui->CargaUsuariosSoli->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(node->user.getFirstName())));
        ui->CargaUsuariosSoli->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(node->user.getLastName())));
        ui->CargaUsuariosSoli->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(node->user.getEmail())));
        ui->CargaUsuariosSoli->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(node->user.getBirthDate())));
        cargarDesdeAVL(node->right);  // Visitar hijo derecho
    }
}

void MainUsuarios::on_CargaUsuariosSoli_cellClicked(int row, int column)
{
    QString email = ui->CargaUsuariosSoli->item(row, 2)->text();  // Suponiendo que la columna 2 es correo
    // Aquí podrías almacenar el correo en una variable miembro si necesitas usarlo en otra parte de la clase
    qDebug() << "Correo del usuario seleccionado: " << email;
}

void MainUsuarios::on_enviarSoli_clicked()
{
    try {

        int row = ui->CargaUsuariosSoli->currentRow();

        if (row < 0 || ui->CargaUsuariosSoli->item(row, 2) == nullptr) {
            QMessageBox::warning(this, "Solicitud de Amistad", "Seleccione un usuario válido.");
            return;  // Evitar continuar si no hay una fila seleccionada
        }

        QString emisor = ui->BuscarCorreo->text();  // Obtener el correo desde el perfil
        QString receptor = ui->CargaUsuariosSoli->item(row, 2)->text();  // Obtener el correo del receptor (columna 2)

        // Verificar los valores obtenidos
        qDebug() << "Fila seleccionada: " << row;
        qDebug() << "Correo del emisor: " << emisor;
        qDebug() << "Correo del receptor: " << receptor;

        // Lógica para enviar la solicitud
        if (listaUsuarios.enviarSolicitud(emisor.toStdString(), receptor.toStdString())) {
            QMessageBox::information(this, "Solicitud de Amistad", "Solicitud enviada correctamente.");

            //11 Cargar las solicitudes enviadas para reflejar el cambio
            cargarSolicitudesEnviadas();

            // Volver a la pestaña de usuarios
            ui->USUARIO->setCurrentIndex(0);  // Cambia el índice de la pestaña (asumiendo que la pestaña de usuarios es la 0)
        } else {
            QMessageBox::warning(this, "Solicitud de Amistad", "No se pudo enviar la solicitud.");
        }
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
        qDebug() << "Excepción capturada: " << e.what();
    }
    catch (...) {
        QMessageBox::critical(this, "Error", "Ocurrió un error inesperado.");
        qDebug() << "Excepción desconocida capturada.";
    }
}

//--------------------------- Aceptar y rechazar solicitudes recibidas -------------------------
void MainUsuarios::on_soliRecibidas_cellClicked(int row, int column)
{
    // Aquí obtendrás el correo del usuario que envió la solicitud
    QString emisor = ui->soliRecibidas->item(row, 1)->text(); // Suponiendo que la columna 1 es correo emisor
    qDebug() << "Correo del emisor de la solicitud recibida: " << emisor;
}

void MainUsuarios::on_aceptarSoli_clicked()
{
}

void MainUsuarios::on_rechazarSoli_clicked()
{
}

//--------------------------- Cancelar solicitudes enviadas ------------------------------------
// Tabla de solicitudes enviadas
void MainUsuarios::on_soliEnviadas_cellClicked(int row, int column)
{
    //1..0 Obtener el correo del receptor al hacer clic en la solicitud
    QString receptor = ui->soliEnviadas->item(row, 0)->text();  // Suponiendo que la columna 1 es el correo del receptor
    qDebug() << "Correo del receptor de la solicitud enviada: " << receptor;
}

// Funcion para que aparezcan en la tabla de solicitudes enviadas el correo del receptor
void MainUsuarios::cargarSolicitudesEnviadas() {
    // Limpiar la tabla de solicitudes enviadas
    ui->soliEnviadas->setRowCount(0);

    if (currentUser) {
        // Obtener las solicitudes enviadas por el usuario actual
        const list<string>& enviadas = currentUser->user.getSolicitudesU()->getSolicitudesEnviadas();

        qDebug() << "Número de solicitudes enviadas: " << enviadas.size();
        // Llenar la tabla con las solicitudes enviadas
        int row = 0;
        for (const string& receptor : enviadas) {
            ui->soliEnviadas->insertRow(row);
            ui->soliEnviadas->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(receptor)));
            row++;
        }
    } else {
        qDebug() << "No hay usuario actualmente registrado.";
    }
}

// button para cancelar la solicitud enviada
void MainUsuarios::on_cancelarSoliEnviada_clicked()
{
    try {
        int row = ui->soliEnviadas->currentRow(); // Obtener la fila seleccionada en la tabla de solicitudes enviadas

        if (row < 0) {
            QMessageBox::warning(this, "Cancelar Solicitud", "Debe seleccionar una solicitud para cancelar.");
            return; // Evitar continuar si no hay una fila seleccionada
        }
        //cambiar a 0
        QString receptor = ui->soliEnviadas->item(row, 0)->text(); // Suponiendo que la columna 1 es correo receptor

        QString emisor = QString::fromStdString(currentUser->user.getEmail());

            // Lógica para cancelar la solicitud
            if (listaUsuarios.cancelarSolicitud(receptor.toStdString(), emisor.toStdString())) {
                QMessageBox::information(this, "Cancelar Solicitud", "Solicitud cancelada correctamente.");
                cargarUsuariosEnTabla(); // Volver a cargar la tabla de solicitudes enviadas
            } else {
                QMessageBox::warning(this, "Cancelar Solicitud", "No se pudo cancelar la solicitud.");
            }

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
        qDebug() << "Excepción capturada: " << e.what();
    } catch (...) {
        QMessageBox::critical(this, "Error", "Ocurrió un error inesperado.");
        qDebug() << "Excepción desconocida capturada.";
    }
}






