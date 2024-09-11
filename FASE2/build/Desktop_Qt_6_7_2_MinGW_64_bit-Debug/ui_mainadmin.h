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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainadmin
{
public:
    QTabWidget *ADMINISTRADOR;
    QWidget *tab;
    QPushButton *BuscarA_2;
    QLineEdit *BuscarA;
    QLabel *orden;
    QListWidget *OrdenB;
    QPushButton *AplicarA;
    QWidget *tab_2;
    QPushButton *CargaUsuarios;
    QLabel *solicitudes;
    QLabel *publicaciones;
    QPushButton *CargaSoli;
    QPushButton *CargaPubli;
    QLabel *usuarios;
    QPlainTextEdit *cargaUsuarios;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_4;
    QWidget *tab_3;
    QLabel *arbolU;
    QLabel *listaP;
    QPushButton *generarReportes;
    QWidget *salir;
    QPushButton *salirAdmin;

    void setupUi(QDialog *mainadmin)
    {
        if (mainadmin->objectName().isEmpty())
            mainadmin->setObjectName("mainadmin");
        mainadmin->resize(696, 459);
        ADMINISTRADOR = new QTabWidget(mainadmin);
        ADMINISTRADOR->setObjectName("ADMINISTRADOR");
        ADMINISTRADOR->setGeometry(QRect(10, 20, 671, 411));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        ADMINISTRADOR->setFont(font);
        tab = new QWidget();
        tab->setObjectName("tab");
        BuscarA_2 = new QPushButton(tab);
        BuscarA_2->setObjectName("BuscarA_2");
        BuscarA_2->setGeometry(QRect(10, 20, 71, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        BuscarA_2->setFont(font1);
        BuscarA = new QLineEdit(tab);
        BuscarA->setObjectName("BuscarA");
        BuscarA->setGeometry(QRect(90, 20, 221, 31));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        BuscarA->setFont(font2);
        orden = new QLabel(tab);
        orden->setObjectName("orden");
        orden->setGeometry(QRect(350, 20, 71, 31));
        orden->setFont(font2);
        OrdenB = new QListWidget(tab);
        OrdenB->setObjectName("OrdenB");
        OrdenB->setGeometry(QRect(420, 20, 151, 31));
        AplicarA = new QPushButton(tab);
        AplicarA->setObjectName("AplicarA");
        AplicarA->setGeometry(QRect(580, 20, 71, 31));
        AplicarA->setFont(font1);
        ADMINISTRADOR->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        CargaUsuarios = new QPushButton(tab_2);
        CargaUsuarios->setObjectName("CargaUsuarios");
        CargaUsuarios->setGeometry(QRect(20, 320, 161, 31));
        CargaUsuarios->setFont(font1);
        solicitudes = new QLabel(tab_2);
        solicitudes->setObjectName("solicitudes");
        solicitudes->setGeometry(QRect(240, 10, 131, 31));
        publicaciones = new QLabel(tab_2);
        publicaciones->setObjectName("publicaciones");
        publicaciones->setGeometry(QRect(450, 10, 161, 31));
        CargaSoli = new QPushButton(tab_2);
        CargaSoli->setObjectName("CargaSoli");
        CargaSoli->setGeometry(QRect(220, 320, 181, 31));
        CargaSoli->setFont(font1);
        CargaPubli = new QPushButton(tab_2);
        CargaPubli->setObjectName("CargaPubli");
        CargaPubli->setGeometry(QRect(440, 320, 201, 31));
        CargaPubli->setFont(font1);
        usuarios = new QLabel(tab_2);
        usuarios->setObjectName("usuarios");
        usuarios->setGeometry(QRect(30, 10, 101, 31));
        cargaUsuarios = new QPlainTextEdit(tab_2);
        cargaUsuarios->setObjectName("cargaUsuarios");
        cargaUsuarios->setGeometry(QRect(20, 50, 161, 261));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        cargaUsuarios->setFont(font3);
        plainTextEdit_2 = new QPlainTextEdit(tab_2);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(220, 50, 181, 261));
        plainTextEdit_4 = new QPlainTextEdit(tab_2);
        plainTextEdit_4->setObjectName("plainTextEdit_4");
        plainTextEdit_4->setGeometry(QRect(440, 50, 201, 261));
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
        generarReportes->setGeometry(QRect(230, 310, 181, 31));
        generarReportes->setFont(font1);
        generarReportes->setStyleSheet(QString::fromUtf8("border-bottom-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));
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

        ADMINISTRADOR->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(mainadmin);
    } // setupUi

    void retranslateUi(QDialog *mainadmin)
    {
        mainadmin->setWindowTitle(QCoreApplication::translate("mainadmin", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        ADMINISTRADOR->setToolTip(QCoreApplication::translate("mainadmin", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        BuscarA_2->setText(QCoreApplication::translate("mainadmin", "Buscar", nullptr));
#if QT_CONFIG(tooltip)
        BuscarA->setToolTip(QCoreApplication::translate("mainadmin", "<html><head/><body><p>Ingrese su correo</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        BuscarA->setText(QString());
        orden->setText(QCoreApplication::translate("mainadmin", "Orden", nullptr));
        AplicarA->setText(QCoreApplication::translate("mainadmin", "Aplicar", nullptr));
        ADMINISTRADOR->setTabText(ADMINISTRADOR->indexOf(tab), QCoreApplication::translate("mainadmin", "BUSCAR", nullptr));
        CargaUsuarios->setText(QCoreApplication::translate("mainadmin", "CARGAR USUARIOS", nullptr));
        solicitudes->setText(QCoreApplication::translate("mainadmin", "SOLICITUDES", nullptr));
        publicaciones->setText(QCoreApplication::translate("mainadmin", "PUBLICACIONES", nullptr));
        CargaSoli->setText(QCoreApplication::translate("mainadmin", "CARGAR SOLICITUDES", nullptr));
        CargaPubli->setText(QCoreApplication::translate("mainadmin", "CARGAR PUBLICACIONES", nullptr));
        usuarios->setText(QCoreApplication::translate("mainadmin", "USUARIOS", nullptr));
        cargaUsuarios->setPlainText(QString());
        ADMINISTRADOR->setTabText(ADMINISTRADOR->indexOf(tab_2), QCoreApplication::translate("mainadmin", "CARGAS MASIVAS", nullptr));
        arbolU->setText(QCoreApplication::translate("mainadmin", "Arbol de usuarios", nullptr));
        listaP->setText(QCoreApplication::translate("mainadmin", "Lista de publicaciones", nullptr));
        generarReportes->setText(QCoreApplication::translate("mainadmin", "GENERAR REPORTES", nullptr));
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
