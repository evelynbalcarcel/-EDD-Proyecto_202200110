#include "mainadmin.h"
#include "ui_mainadmin.h"
#include <QListWidgetItem>
#include <QListWidgetItem>
#include <QWidget>
#include <QString>
#include <QMessageBox>
#include "ListaUsuarios.h"

mainadmin::mainadmin(MainPrincipal* mainPrincipal, ListaU& listaUsuarios, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainadmin)
    , mainPrincipal(mainPrincipal)
    , listaUsuarios(listaUsuarios)
{
    ui->setupUi(this);
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


void mainadmin::on_CargaUsuarios_clicked()
{
    // Crear una instancia de ListaU o acceder a la ya existente
    QString text = ui->cargaUsuarios->toPlainText();  // Obtener el texto en formato JSON del área de texto
    listaUsuarios.jsonUsuaios(text.toStdString());  // Cargar los usuarios
    QMessageBox::information(this, "Carga Usuarios", "Usuarios cargados correctamente.");
}




