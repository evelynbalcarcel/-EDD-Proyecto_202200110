/********************************************************************************
** Form generated from reading UI file 'mainadmin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINADMIN_H
#define UI_MAINADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainadmin
{
public:
    QTabWidget *ADMINISTRADOR;
    QWidget *tab;
    QPushButton *bucarUsuariosAdmin;
    QLineEdit *BuscarAdmin;
    QLabel *orden;
    QPushButton *AplicarOrdenAdmin;
    QComboBox *comboBoxOrden;
    QTableWidget *cargaUsuariosBuscar;
    QPushButton *modificarUsuariosAdmin;
    QPushButton *eliminarUsuariosAdmin;
    QWidget *tab_2;
    QPushButton *CargaUsuariosJSON;
    QLabel *solicitudes;
    QLabel *publicaciones;
    QPushButton *CargaSoliJSON;
    QPushButton *CargaPubliJSON;
    QLabel *usuarios;
    QPlainTextEdit *cargaUsuarios;
    QPlainTextEdit *cargaSolicitudes;
    QPlainTextEdit *cargaPublicaciones;
    QWidget *tab_3;
    QLabel *arbolU;
    QLabel *listaP;
    QPushButton *generarReportes;
    QLabel *cargaArbolU;
    QWidget *salir;
    QPushButton *salirAdmin;

    void setupUi(QDialog *mainadmin)
    {
        if (mainadmin->objectName().isEmpty())
            mainadmin->setObjectName("mainadmin");
        mainadmin->resize(696, 459);
        ADMINISTRADOR = new QTabWidget(mainadmin);
        ADMINISTRADOR->setObjectName("ADMINISTRADOR");
        ADMINISTRADOR->setGeometry(QRect(10, 20, 671, 421));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        ADMINISTRADOR->setFont(font);
        tab = new QWidget();
        tab->setObjectName("tab");
        bucarUsuariosAdmin = new QPushButton(tab);
        bucarUsuariosAdmin->setObjectName("bucarUsuariosAdmin");
        bucarUsuariosAdmin->setGeometry(QRect(20, 30, 71, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        bucarUsuariosAdmin->setFont(font1);
        BuscarAdmin = new QLineEdit(tab);
        BuscarAdmin->setObjectName("BuscarAdmin");
        BuscarAdmin->setGeometry(QRect(100, 30, 261, 31));
        BuscarAdmin->setFont(font1);
        orden = new QLabel(tab);
        orden->setObjectName("orden");
        orden->setGeometry(QRect(380, 30, 61, 31));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        orden->setFont(font2);
        AplicarOrdenAdmin = new QPushButton(tab);
        AplicarOrdenAdmin->setObjectName("AplicarOrdenAdmin");
        AplicarOrdenAdmin->setGeometry(QRect(570, 30, 71, 31));
        AplicarOrdenAdmin->setFont(font1);
        comboBoxOrden = new QComboBox(tab);
        comboBoxOrden->addItem(QString());
        comboBoxOrden->addItem(QString());
        comboBoxOrden->addItem(QString());
        comboBoxOrden->setObjectName("comboBoxOrden");
        comboBoxOrden->setGeometry(QRect(440, 30, 111, 31));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(false);
        comboBoxOrden->setFont(font3);
        cargaUsuariosBuscar = new QTableWidget(tab);
        if (cargaUsuariosBuscar->columnCount() < 6)
            cargaUsuariosBuscar->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        cargaUsuariosBuscar->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        cargaUsuariosBuscar->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        cargaUsuariosBuscar->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        cargaUsuariosBuscar->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        cargaUsuariosBuscar->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        cargaUsuariosBuscar->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        cargaUsuariosBuscar->setObjectName("cargaUsuariosBuscar");
        cargaUsuariosBuscar->setGeometry(QRect(20, 100, 621, 261));
        cargaUsuariosBuscar->setFont(font1);
        modificarUsuariosAdmin = new QPushButton(tab);
        modificarUsuariosAdmin->setObjectName("modificarUsuariosAdmin");
        modificarUsuariosAdmin->setGeometry(QRect(470, 160, 101, 31));
        modificarUsuariosAdmin->setFont(font1);
        eliminarUsuariosAdmin = new QPushButton(tab);
        eliminarUsuariosAdmin->setObjectName("eliminarUsuariosAdmin");
        eliminarUsuariosAdmin->setGeometry(QRect(470, 210, 101, 31));
        eliminarUsuariosAdmin->setFont(font1);
        ADMINISTRADOR->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        CargaUsuariosJSON = new QPushButton(tab_2);
        CargaUsuariosJSON->setObjectName("CargaUsuariosJSON");
        CargaUsuariosJSON->setGeometry(QRect(20, 320, 191, 31));
        CargaUsuariosJSON->setFont(font1);
        solicitudes = new QLabel(tab_2);
        solicitudes->setObjectName("solicitudes");
        solicitudes->setGeometry(QRect(250, 10, 131, 31));
        publicaciones = new QLabel(tab_2);
        publicaciones->setObjectName("publicaciones");
        publicaciones->setGeometry(QRect(470, 10, 161, 31));
        CargaSoliJSON = new QPushButton(tab_2);
        CargaSoliJSON->setObjectName("CargaSoliJSON");
        CargaSoliJSON->setGeometry(QRect(240, 320, 191, 31));
        CargaSoliJSON->setFont(font1);
        CargaPubliJSON = new QPushButton(tab_2);
        CargaPubliJSON->setObjectName("CargaPubliJSON");
        CargaPubliJSON->setGeometry(QRect(460, 320, 191, 31));
        CargaPubliJSON->setFont(font1);
        usuarios = new QLabel(tab_2);
        usuarios->setObjectName("usuarios");
        usuarios->setGeometry(QRect(60, 10, 101, 31));
        cargaUsuarios = new QPlainTextEdit(tab_2);
        cargaUsuarios->setObjectName("cargaUsuarios");
        cargaUsuarios->setGeometry(QRect(20, 50, 191, 261));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        cargaUsuarios->setFont(font4);
        cargaSolicitudes = new QPlainTextEdit(tab_2);
        cargaSolicitudes->setObjectName("cargaSolicitudes");
        cargaSolicitudes->setGeometry(QRect(460, 50, 191, 261));
        cargaSolicitudes->setFont(font4);
        cargaPublicaciones = new QPlainTextEdit(tab_2);
        cargaPublicaciones->setObjectName("cargaPublicaciones");
        cargaPublicaciones->setGeometry(QRect(240, 50, 191, 261));
        cargaPublicaciones->setFont(font4);
        ADMINISTRADOR->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        arbolU = new QLabel(tab_3);
        arbolU->setObjectName("arbolU");
        arbolU->setGeometry(QRect(40, 30, 171, 31));
        listaP = new QLabel(tab_3);
        listaP->setObjectName("listaP");
        listaP->setGeometry(QRect(420, 30, 201, 31));
        generarReportes = new QPushButton(tab_3);
        generarReportes->setObjectName("generarReportes");
        generarReportes->setGeometry(QRect(230, 330, 181, 31));
        generarReportes->setFont(font1);
        generarReportes->setStyleSheet(QString::fromUtf8("border-bottom-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));
        cargaArbolU = new QLabel(tab_3);
        cargaArbolU->setObjectName("cargaArbolU");
        cargaArbolU->setGeometry(QRect(20, 70, 251, 231));
        cargaArbolU->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        ADMINISTRADOR->addTab(tab_3, QString());
        salir = new QWidget();
        salir->setObjectName("salir");
        salirAdmin = new QPushButton(salir);
        salirAdmin->setObjectName("salirAdmin");
        salirAdmin->setGeometry(QRect(130, 90, 391, 61));
        salirAdmin->setFont(font);
        salirAdmin->setStyleSheet(QString::fromUtf8("border-top-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.33 rgba(0, 0, 0, 255), stop:0.34 rgba(255, 30, 30, 255), stop:0.66 rgba(255, 0, 0, 255), stop:0.67 rgba(255, 255, 0, 255), stop:1 rgba(255, 255, 0, 255));\n"
""));
        ADMINISTRADOR->addTab(salir, QString());

        retranslateUi(mainadmin);

        ADMINISTRADOR->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(mainadmin);
    } // setupUi

    void retranslateUi(QDialog *mainadmin)
    {
        mainadmin->setWindowTitle(QCoreApplication::translate("mainadmin", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        ADMINISTRADOR->setToolTip(QCoreApplication::translate("mainadmin", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        bucarUsuariosAdmin->setText(QCoreApplication::translate("mainadmin", "Buscar", nullptr));
#if QT_CONFIG(tooltip)
        BuscarAdmin->setToolTip(QCoreApplication::translate("mainadmin", "<html><head/><body><p>Ingrese su correo</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        BuscarAdmin->setText(QString());
        orden->setText(QCoreApplication::translate("mainadmin", "Orden", nullptr));
        AplicarOrdenAdmin->setText(QCoreApplication::translate("mainadmin", "Aplicar", nullptr));
        comboBoxOrden->setItemText(0, QCoreApplication::translate("mainadmin", "Inorden", nullptr));
        comboBoxOrden->setItemText(1, QCoreApplication::translate("mainadmin", "Preorden", nullptr));
        comboBoxOrden->setItemText(2, QCoreApplication::translate("mainadmin", "Postoden", nullptr));

        QTableWidgetItem *___qtablewidgetitem = cargaUsuariosBuscar->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("mainadmin", "Nombres", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = cargaUsuariosBuscar->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("mainadmin", "Apellidos", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = cargaUsuariosBuscar->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("mainadmin", "Correo", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = cargaUsuariosBuscar->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("mainadmin", "Nacimiento", nullptr));
        modificarUsuariosAdmin->setText(QCoreApplication::translate("mainadmin", "Modificar", nullptr));
        eliminarUsuariosAdmin->setText(QCoreApplication::translate("mainadmin", "Eliminar", nullptr));
        ADMINISTRADOR->setTabText(ADMINISTRADOR->indexOf(tab), QCoreApplication::translate("mainadmin", "BUSCAR", nullptr));
        CargaUsuariosJSON->setText(QCoreApplication::translate("mainadmin", "CARGAR USUARIOS", nullptr));
        solicitudes->setText(QCoreApplication::translate("mainadmin", "SOLICITUDES", nullptr));
        publicaciones->setText(QCoreApplication::translate("mainadmin", "PUBLICACIONES", nullptr));
        CargaSoliJSON->setText(QCoreApplication::translate("mainadmin", "CARGAR SOLICITUDES", nullptr));
        CargaPubliJSON->setText(QCoreApplication::translate("mainadmin", "CARGAR PUBLICACIONES", nullptr));
        usuarios->setText(QCoreApplication::translate("mainadmin", "USUARIOS", nullptr));
        cargaUsuarios->setPlainText(QString());
        ADMINISTRADOR->setTabText(ADMINISTRADOR->indexOf(tab_2), QCoreApplication::translate("mainadmin", "CARGAS MASIVAS", nullptr));
        arbolU->setText(QCoreApplication::translate("mainadmin", "\303\201rbol de usuarios", nullptr));
        listaP->setText(QCoreApplication::translate("mainadmin", "Lista de publicaciones", nullptr));
        generarReportes->setText(QCoreApplication::translate("mainadmin", "GENERAR REPORTES", nullptr));
        cargaArbolU->setText(QString());
        ADMINISTRADOR->setTabText(ADMINISTRADOR->indexOf(tab_3), QCoreApplication::translate("mainadmin", "REPORTES", nullptr));
        salirAdmin->setText(QCoreApplication::translate("mainadmin", "SALIR DEL MODULO ADMINISTRADOR ", nullptr));
        ADMINISTRADOR->setTabText(ADMINISTRADOR->indexOf(salir), QCoreApplication::translate("mainadmin", "SALIR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainadmin: public Ui_mainadmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINADMIN_H
