#include "mainadmin.h"
#include "ui_mainadmin.h"
#include <QListWidgetItem>
#include <QListWidgetItem>
#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QFormLayout>

#include "ListaUsuarios.h"
using namespace std;
mainadmin::mainadmin(MainPrincipal* mainPrincipal, ListaU& listaUsuarios, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainadmin)
    , mainPrincipal(mainPrincipal)
    , listaUsuarios(listaUsuarios)
{
    ui->setupUi(this);
    // Muestra la tabla con datos de usuarios en Buscar Admin
    ui->cargaUsuariosBuscar->setColumnCount(4);  // Nombres, Apellidos, Correo, Nacimiento
    QStringList headers = {"Nombres", "Apellidos", "Correo", "Nacimiento"};
    ui->cargaUsuariosBuscar->setHorizontalHeaderLabels(headers);
    ui->cargaUsuariosBuscar->setHorizontalHeaderLabels(headers);
    ui->cargaUsuariosBuscar->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->cargaUsuariosBuscar->setSelectionBehavior(QAbstractItemView::SelectRows);
    cargarUsuariosTable();
}

mainadmin::~mainadmin()
{
    delete ui;
}

void mainadmin::on_salirAdmin_clicked()
{
    close();
    if (mainPrincipal != nullptr) {
        mainPrincipal->show();  // Muestra la ventana principal
    }
}

//=================================Pestaña Buscar===============================================
void mainadmin::on_bucarUsuariosAdmin_clicked()
{
    QString email = ui->BuscarAdmin->text();
    ListaU::AVLNode* node = listaUsuarios.findUser(email.toStdString());

    if (node != nullptr) {
        currentUser = node;  // Asignar el usuario actual al puntero currentUser

        // Llenar los campos con los datos del usuario
        int row = ui->cargaUsuariosBuscar->rowCount();
        ui->cargaUsuariosBuscar->insertRow(row);
        ui->cargaUsuariosBuscar->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(node->user.getFirstName())));
        ui->cargaUsuariosBuscar->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(node->user.getLastName())));
        ui->cargaUsuariosBuscar->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(node->user.getEmail())));
        ui->cargaUsuariosBuscar->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(node->user.getBirthDate())));

        // Seleccionar la fila correspondiente
        for (int i = 0; i < ui->cargaUsuariosBuscar->rowCount(); ++i) {
            if (ui->cargaUsuariosBuscar->item(i, 2)->text() == email) {  // Suponiendo que la columna 2 es correo
                ui->cargaUsuariosBuscar->selectRow(i);
                ui->cargaUsuariosBuscar->setCurrentCell(i, 2);  // Opcional: Selecciona la celda del correo
                break;  // Salir del bucle una vez que se encuentra la fila
            }
        }
    } else {
        QMessageBox::warning(this, "Buscar", "No se encontró un usuario con ese correo.");
    }
}

void mainadmin::on_cargaUsuariosBuscar_cellClicked(int row, int column)
{
    QString email = ui->cargaUsuariosBuscar->item(row, 2)->text();  // Suponiendo que la columna 2 es correo
    qDebug() << "Correo del usuario seleccionado: " << email;
}

void mainadmin::cargarUsuariosTable() {
    ui->cargaUsuariosBuscar->setRowCount(0);  // Limpiar la tabla antes de llenarla
    cargarAVL(listaUsuarios.root);  // Comienza desde la raíz
}

void mainadmin::cargarAVL(ListaU::AVLNode* node) {
    if (node != nullptr) {
        cargarAVL(node->left);  // Visitar hijo izquierdo

        int row = ui->cargaUsuariosBuscar->rowCount();
        ui->cargaUsuariosBuscar->insertRow(row);
        ui->cargaUsuariosBuscar->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(node->user.getFirstName())));
        ui->cargaUsuariosBuscar->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(node->user.getLastName())));
        ui->cargaUsuariosBuscar->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(node->user.getEmail())));
        ui->cargaUsuariosBuscar->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(node->user.getBirthDate())));
        cargarAVL(node->right);  // Visitar hijo derecho
    }
}

void mainadmin::on_modificarUsuariosAdmin_clicked()
{
    // Verifica si hay una fila seleccionada
    QModelIndexList selectedIndexes = ui->cargaUsuariosBuscar->selectionModel()->selectedRows();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Modificar Usuarios desde Administrador", "SeleccionE una fila en la tabla.");
        return;
    }

    // Obtén el índice de la primera fila seleccionada
    int row = selectedIndexes.first().row();

    // Obtén el correo electrónico del usuario seleccionado
    QString email = ui->cargaUsuariosBuscar->item(row, 2)->text();  // Suponiendo que la columna 2 es correo

    // Encuentra el nodo del usuario basado en el correo electrónico
    ListaU::AVLNode* node = listaUsuarios.findUser(email.toStdString());

    if (node == nullptr) {
        QMessageBox::warning(this, "Modificar Usuarios desde Administrador", "No se encontró el usuario con el correo seleccionado.");
        return;
    }

    // Muestra un diálogo para modificar los datos del usuario
    QDialog dialog(this);
    dialog.setWindowTitle("Modificar Usuarios desde Administrador");

    // Crear los campos para editar los datos
    QFormLayout layout(&dialog);

    QLineEdit* firstNameEdit = new QLineEdit(QString::fromStdString(node->user.getFirstName()), &dialog);
    QLineEdit* lastNameEdit = new QLineEdit(QString::fromStdString(node->user.getLastName()), &dialog);
    QLineEdit* emailEdit = new QLineEdit(QString::fromStdString(node->user.getEmail()), &dialog);
    QLineEdit* birthDateEdit = new QLineEdit(QString::fromStdString(node->user.getBirthDate()), &dialog);

    layout.addRow("Nombre:", firstNameEdit);
    layout.addRow("Apellido:", lastNameEdit);
    layout.addRow("Correo:", emailEdit);
    layout.addRow("Fecha de Nacimiento:", birthDateEdit);

    QPushButton* saveButton = new QPushButton("Modificar", &dialog);
    layout.addWidget(saveButton);

    connect(saveButton, &QPushButton::clicked, &dialog, [&]() {
        // Actualiza los datos del usuario
        node->user.setFirstName(firstNameEdit->text().toStdString());
        node->user.setLastName(lastNameEdit->text().toStdString());
        node->user.setEmail(emailEdit->text().toStdString());
        node->user.setBirthDate(birthDateEdit->text().toStdString());

        // Actualiza la tabla
        ui->cargaUsuariosBuscar->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(node->user.getFirstName())));
        ui->cargaUsuariosBuscar->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(node->user.getLastName())));
        ui->cargaUsuariosBuscar->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(node->user.getEmail())));
        ui->cargaUsuariosBuscar->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(node->user.getBirthDate())));

        dialog.accept();  // Cierra el diálogo
    });

    dialog.exec();  // Muestra el diálogo
}

void mainadmin::on_eliminarUsuariosAdmin_clicked()
{
    // Verifica si hay una fila seleccionada
    QModelIndexList selectedIndexes = ui->cargaUsuariosBuscar->selectionModel()->selectedRows();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Eliminar Usuario", "Por favor, selecciona una fila en la tabla.");
        return;
    }

    // Obtén el índice de la primera fila seleccionada
    int row = selectedIndexes.first().row();

    // Obtén el correo electrónico del usuario seleccionado
    QString email = ui->cargaUsuariosBuscar->item(row, 2)->text();  // Suponiendo que la columna 2 es correo

    // Encuentra el nodo del usuario basado en el correo electrónico
    ListaU::AVLNode* node = listaUsuarios.findUser(email.toStdString());

    if (node == nullptr) {
        QMessageBox::warning(this, "Eliminar Usuario", "No se encontro el usuario con el correo seleccionado.");
        return;
    }

    // Confirma la eliminación
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmar Eliminacion",
                                  "¿Estas seguro de que deseas eliminar este usuario?",
                                  QMessageBox:: Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Elimina el usuario del árbol AVL
        listaUsuarios.root = listaUsuarios.deleteNode(listaUsuarios.root, email.toStdString());

        // Elimina la fila de la tabla
        ui->cargaUsuariosBuscar->removeRow(row);

        // Mensaje de éxito
        QMessageBox::information(this, "Eliminar Usuario", "Usuario eliminado correctamente.");
    }
}

void mainadmin::on_comboBoxOrden_activated(int index)
{

}

void mainadmin::on_AplicarOrdenAdmin_clicked()
{

}

//===============================Pestaña Cargas Masivas================================================
void mainadmin::on_CargaUsuariosJSON_clicked()
{
    QString text = ui->cargaUsuarios->toPlainText();  // Obtener el texto en formato JSON del area de texto
    listaUsuarios.jsonUsuaios(text.toStdString());  // Cargar los usuarios
    QMessageBox::information(this, "Carga Usuarios", "Usuarios cargados correctamente.");
}

void mainadmin::on_CargaSoliJSON_clicked()
{
    // Crear una instancia de ListaU o acceder a la ya existente
    QString text = ui->cargaSolicitudes->toPlainText();  // Obtener el texto en formato JSON del área de texto
    listaUsuarios.jsonSolicitudes(text.toStdString());  // Cargar los usuarios
    QMessageBox::information(this, "Carga Solicitudes", "Solicitudes cargados correctamente.");
}


void mainadmin::on_CargaPubliJSON_clicked()
{
    // Crear una instancia de ListaU o acceder a la ya existente
    QString text = ui->cargaPublicaciones->toPlainText();  // Obtener el texto en formato JSON del área de texto
    listaUsuarios.jsonPublicaciones(text.toStdString());  // Cargar los usuarios
    QMessageBox::information(this, "Carga Publicaciones", "Publicaciones cargados correctamente.");
}

