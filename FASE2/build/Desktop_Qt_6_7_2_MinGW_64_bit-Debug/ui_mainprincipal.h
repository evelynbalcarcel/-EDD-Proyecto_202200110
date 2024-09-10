/********************************************************************************
** Form generated from reading UI file 'mainprincipal.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPRINCIPAL_H
#define UI_MAINPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPrincipal
{
public:
    QWidget *centralwidget;
    QTabWidget *INTERFAZ;
    QWidget *tab;
    QPushButton *iniciosesion;
    QLabel *correo_2;
    QLabel *contra;
    QLineEdit *contrasenaI;
    QLineEdit *correoI;
    QWidget *tab_2;
    QPushButton *registrarse;
    QLabel *nombre;
    QLabel *correR;
    QLabel *contraR;
    QLabel *fecha;
    QLabel *apellido;
    QLineEdit *nombreR;
    QLineEdit *correoR;
    QLineEdit *fechaR;
    QLineEdit *apellidoR;
    QLineEdit *contrasenaR;
    QWidget *tab_3;
    QPushButton *informacion;
    QWidget *salir;
    QPushButton *salir1;

    void setupUi(QMainWindow *MainPrincipal)
    {
        if (MainPrincipal->objectName().isEmpty())
            MainPrincipal->setObjectName("MainPrincipal");
        MainPrincipal->resize(640, 393);
        QFont font;
        font.setPointSize(10);
        MainPrincipal->setFont(font);
        centralwidget = new QWidget(MainPrincipal);
        centralwidget->setObjectName("centralwidget");
        INTERFAZ = new QTabWidget(centralwidget);
        INTERFAZ->setObjectName("INTERFAZ");
        INTERFAZ->setGeometry(QRect(10, 20, 621, 361));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        INTERFAZ->setFont(font1);
        tab = new QWidget();
        tab->setObjectName("tab");
        iniciosesion = new QPushButton(tab);
        iniciosesion->setObjectName("iniciosesion");
        iniciosesion->setGeometry(QRect(210, 250, 161, 41));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        iniciosesion->setFont(font2);
        correo_2 = new QLabel(tab);
        correo_2->setObjectName("correo_2");
        correo_2->setGeometry(QRect(140, 40, 191, 41));
        contra = new QLabel(tab);
        contra->setObjectName("contra");
        contra->setGeometry(QRect(140, 150, 131, 21));
        contrasenaI = new QLineEdit(tab);
        contrasenaI->setObjectName("contrasenaI");
        contrasenaI->setGeometry(QRect(140, 190, 281, 31));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(false);
        contrasenaI->setFont(font3);
        correoI = new QLineEdit(tab);
        correoI->setObjectName("correoI");
        correoI->setGeometry(QRect(140, 90, 281, 31));
        correoI->setFont(font3);
        INTERFAZ->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        registrarse = new QPushButton(tab_2);
        registrarse->setObjectName("registrarse");
        registrarse->setGeometry(QRect(310, 280, 141, 31));
        registrarse->setFont(font2);
        nombre = new QLabel(tab_2);
        nombre->setObjectName("nombre");
        nombre->setGeometry(QRect(40, 20, 101, 31));
        correR = new QLabel(tab_2);
        correR->setObjectName("correR");
        correR->setGeometry(QRect(40, 170, 181, 31));
        contraR = new QLabel(tab_2);
        contraR->setObjectName("contraR");
        contraR->setGeometry(QRect(40, 220, 101, 31));
        fecha = new QLabel(tab_2);
        fecha->setObjectName("fecha");
        fecha->setGeometry(QRect(40, 120, 191, 31));
        apellido = new QLabel(tab_2);
        apellido->setObjectName("apellido");
        apellido->setGeometry(QRect(40, 70, 101, 31));
        nombreR = new QLineEdit(tab_2);
        nombreR->setObjectName("nombreR");
        nombreR->setGeometry(QRect(240, 20, 281, 31));
        nombreR->setFont(font3);
        correoR = new QLineEdit(tab_2);
        correoR->setObjectName("correoR");
        correoR->setGeometry(QRect(240, 170, 281, 31));
        correoR->setFont(font3);
        fechaR = new QLineEdit(tab_2);
        fechaR->setObjectName("fechaR");
        fechaR->setGeometry(QRect(240, 120, 281, 31));
        fechaR->setFont(font3);
        apellidoR = new QLineEdit(tab_2);
        apellidoR->setObjectName("apellidoR");
        apellidoR->setGeometry(QRect(240, 70, 281, 31));
        apellidoR->setFont(font3);
        contrasenaR = new QLineEdit(tab_2);
        contrasenaR->setObjectName("contrasenaR");
        contrasenaR->setGeometry(QRect(240, 220, 281, 31));
        contrasenaR->setFont(font3);
        INTERFAZ->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        informacion = new QPushButton(tab_3);
        informacion->setObjectName("informacion");
        informacion->setGeometry(QRect(170, 100, 261, 71));
        informacion->setFont(font1);
        INTERFAZ->addTab(tab_3, QString());
        salir = new QWidget();
        salir->setObjectName("salir");
        salir1 = new QPushButton(salir);
        salir1->setObjectName("salir1");
        salir1->setGeometry(QRect(150, 100, 281, 61));
        salir1->setFont(font1);
        INTERFAZ->addTab(salir, QString());
        MainPrincipal->setCentralWidget(centralwidget);

        retranslateUi(MainPrincipal);

        INTERFAZ->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *MainPrincipal)
    {
        MainPrincipal->setWindowTitle(QCoreApplication::translate("MainPrincipal", "MainPrincipal", nullptr));
#if QT_CONFIG(tooltip)
        INTERFAZ->setToolTip(QCoreApplication::translate("MainPrincipal", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        iniciosesion->setText(QCoreApplication::translate("MainPrincipal", "INICIO DE SESION", nullptr));
        correo_2->setText(QCoreApplication::translate("MainPrincipal", "Correo Electronico", nullptr));
        contra->setText(QCoreApplication::translate("MainPrincipal", "Contrase\303\261a", nullptr));
#if QT_CONFIG(tooltip)
        contrasenaI->setToolTip(QCoreApplication::translate("MainPrincipal", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        contrasenaI->setWhatsThis(QCoreApplication::translate("MainPrincipal", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        contrasenaI->setText(QString());
#if QT_CONFIG(tooltip)
        correoI->setToolTip(QCoreApplication::translate("MainPrincipal", "<html><head/><body><p>Ingrese su correo</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        correoI->setText(QString());
        INTERFAZ->setTabText(INTERFAZ->indexOf(tab), QCoreApplication::translate("MainPrincipal", "INICIO DE SESI\303\223N", nullptr));
        registrarse->setText(QCoreApplication::translate("MainPrincipal", "REGISTRARSE ", nullptr));
        nombre->setText(QCoreApplication::translate("MainPrincipal", "Nombres:", nullptr));
        correR->setText(QCoreApplication::translate("MainPrincipal", "Correo electronico:", nullptr));
        contraR->setText(QCoreApplication::translate("MainPrincipal", "Contrase\303\261a:", nullptr));
        fecha->setText(QCoreApplication::translate("MainPrincipal", "Fecha de nacimiento:", nullptr));
        apellido->setText(QCoreApplication::translate("MainPrincipal", "Apellidos:", nullptr));
        nombreR->setText(QString());
        correoR->setText(QString());
        fechaR->setText(QString());
        apellidoR->setText(QString());
        contrasenaR->setText(QString());
        INTERFAZ->setTabText(INTERFAZ->indexOf(tab_2), QCoreApplication::translate("MainPrincipal", "REGISTRARSE", nullptr));
        informacion->setText(QCoreApplication::translate("MainPrincipal", "MOSTRAR INFORMACI\303\223N", nullptr));
        INTERFAZ->setTabText(INTERFAZ->indexOf(tab_3), QCoreApplication::translate("MainPrincipal", "INFORMACI\303\223N", nullptr));
        salir1->setText(QCoreApplication::translate("MainPrincipal", "SALIR DE LA APLICACI\303\223N", nullptr));
        INTERFAZ->setTabText(INTERFAZ->indexOf(salir), QCoreApplication::translate("MainPrincipal", "SALIR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPrincipal: public Ui_MainPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPRINCIPAL_H
