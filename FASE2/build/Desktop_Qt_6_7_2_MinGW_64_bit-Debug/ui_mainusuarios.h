/********************************************************************************
** Form generated from reading UI file 'mainusuarios.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINUSUARIOS_H
#define UI_MAINUSUARIOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainUsuarios
{
public:
    QTabWidget *USUARIO;
    QWidget *buscar;
    QPushButton *buscarB;
    QLabel *datosU;
    QLineEdit *nombreU;
    QLineEdit *BuscarCorreo;
    QLineEdit *apellidoU;
    QLineEdit *correoU;
    QLineEdit *fechaU;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *publi;
    QWidget *soli;
    QWidget *reportes;
    QWidget *perfil;
    QLabel *datosU_2;
    QLabel *label_3;
    QLineEdit *fechaP;
    QLabel *label_6;
    QLineEdit *nombreP;
    QLabel *label_7;
    QLineEdit *apellidoP;
    QLabel *label_8;
    QLineEdit *correoP;
    QLineEdit *contraP;
    QLabel *label_9;
    QPushButton *ModifcarD;
    QPushButton *ElimanarC;
    QWidget *salir;
    QPushButton *salirUsuario;

    void setupUi(QDialog *MainUsuarios)
    {
        if (MainUsuarios->objectName().isEmpty())
            MainUsuarios->setObjectName("MainUsuarios");
        MainUsuarios->resize(673, 447);
        USUARIO = new QTabWidget(MainUsuarios);
        USUARIO->setObjectName("USUARIO");
        USUARIO->setGeometry(QRect(20, 20, 631, 421));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        USUARIO->setFont(font);
        buscar = new QWidget();
        buscar->setObjectName("buscar");
        buscarB = new QPushButton(buscar);
        buscarB->setObjectName("buscarB");
        buscarB->setGeometry(QRect(320, 20, 111, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        buscarB->setFont(font1);
        datosU = new QLabel(buscar);
        datosU->setObjectName("datosU");
        datosU->setGeometry(QRect(20, 80, 211, 21));
        nombreU = new QLineEdit(buscar);
        nombreU->setObjectName("nombreU");
        nombreU->setGeometry(QRect(210, 120, 281, 31));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        nombreU->setFont(font2);
        BuscarCorreo = new QLineEdit(buscar);
        BuscarCorreo->setObjectName("BuscarCorreo");
        BuscarCorreo->setGeometry(QRect(20, 20, 281, 31));
        BuscarCorreo->setFont(font2);
        apellidoU = new QLineEdit(buscar);
        apellidoU->setObjectName("apellidoU");
        apellidoU->setGeometry(QRect(210, 180, 281, 31));
        apellidoU->setFont(font2);
        correoU = new QLineEdit(buscar);
        correoU->setObjectName("correoU");
        correoU->setGeometry(QRect(210, 240, 281, 31));
        correoU->setFont(font2);
        fechaU = new QLineEdit(buscar);
        fechaU->setObjectName("fechaU");
        fechaU->setGeometry(QRect(210, 300, 281, 31));
        fechaU->setFont(font2);
        label = new QLabel(buscar);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 130, 91, 31));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(false);
        label->setFont(font3);
        label_2 = new QLabel(buscar);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 180, 91, 31));
        label_2->setFont(font3);
        label_4 = new QLabel(buscar);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(120, 240, 71, 31));
        label_4->setFont(font3);
        label_5 = new QLabel(buscar);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 300, 191, 31));
        label_5->setFont(font3);
        USUARIO->addTab(buscar, QString());
        publi = new QWidget();
        publi->setObjectName("publi");
        USUARIO->addTab(publi, QString());
        soli = new QWidget();
        soli->setObjectName("soli");
        USUARIO->addTab(soli, QString());
        reportes = new QWidget();
        reportes->setObjectName("reportes");
        USUARIO->addTab(reportes, QString());
        perfil = new QWidget();
        perfil->setObjectName("perfil");
        datosU_2 = new QLabel(perfil);
        datosU_2->setObjectName("datosU_2");
        datosU_2->setGeometry(QRect(10, 10, 81, 21));
        label_3 = new QLabel(perfil);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(130, 30, 91, 31));
        label_3->setFont(font3);
        fechaP = new QLineEdit(perfil);
        fechaP->setObjectName("fechaP");
        fechaP->setGeometry(QRect(240, 270, 281, 31));
        fechaP->setFont(font2);
        label_6 = new QLabel(perfil);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(130, 90, 91, 31));
        label_6->setFont(font3);
        nombreP = new QLineEdit(perfil);
        nombreP->setObjectName("nombreP");
        nombreP->setGeometry(QRect(240, 30, 281, 31));
        nombreP->setFont(font2);
        label_7 = new QLabel(perfil);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(150, 150, 71, 31));
        label_7->setFont(font3);
        apellidoP = new QLineEdit(perfil);
        apellidoP->setObjectName("apellidoP");
        apellidoP->setGeometry(QRect(240, 90, 281, 31));
        apellidoP->setFont(font2);
        label_8 = new QLabel(perfil);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 270, 191, 31));
        label_8->setFont(font3);
        correoP = new QLineEdit(perfil);
        correoP->setObjectName("correoP");
        correoP->setGeometry(QRect(240, 140, 281, 31));
        correoP->setFont(font2);
        contraP = new QLineEdit(perfil);
        contraP->setObjectName("contraP");
        contraP->setGeometry(QRect(240, 210, 281, 31));
        contraP->setFont(font2);
        label_9 = new QLabel(perfil);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(110, 210, 111, 31));
        label_9->setFont(font3);
        ModifcarD = new QPushButton(perfil);
        ModifcarD->setObjectName("ModifcarD");
        ModifcarD->setGeometry(QRect(210, 330, 151, 31));
        ModifcarD->setFont(font1);
        ElimanarC = new QPushButton(perfil);
        ElimanarC->setObjectName("ElimanarC");
        ElimanarC->setGeometry(QRect(400, 330, 141, 31));
        ElimanarC->setFont(font1);
        USUARIO->addTab(perfil, QString());
        salir = new QWidget();
        salir->setObjectName("salir");
        salirUsuario = new QPushButton(salir);
        salirUsuario->setObjectName("salirUsuario");
        salirUsuario->setGeometry(QRect(150, 100, 361, 61));
        salirUsuario->setFont(font);
        USUARIO->addTab(salir, QString());

        retranslateUi(MainUsuarios);

        USUARIO->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainUsuarios);
    } // setupUi

    void retranslateUi(QDialog *MainUsuarios)
    {
        MainUsuarios->setWindowTitle(QCoreApplication::translate("MainUsuarios", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        USUARIO->setToolTip(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        buscarB->setText(QCoreApplication::translate("MainUsuarios", "BUSCAR", nullptr));
        datosU->setText(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p><span style=\" color:#ff0000;\">DATOS DEL USUARIO</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        nombreU->setToolTip(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        nombreU->setWhatsThis(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        nombreU->setText(QString());
#if QT_CONFIG(tooltip)
        BuscarCorreo->setToolTip(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su correo</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        BuscarCorreo->setText(QString());
#if QT_CONFIG(tooltip)
        apellidoU->setToolTip(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        apellidoU->setWhatsThis(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        apellidoU->setText(QString());
#if QT_CONFIG(tooltip)
        correoU->setToolTip(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        correoU->setWhatsThis(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        correoU->setText(QString());
#if QT_CONFIG(tooltip)
        fechaU->setToolTip(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        fechaU->setWhatsThis(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        fechaU->setText(QString());
        label->setText(QCoreApplication::translate("MainUsuarios", "Nombres:", nullptr));
        label_2->setText(QCoreApplication::translate("MainUsuarios", "Apellidos:", nullptr));
        label_4->setText(QCoreApplication::translate("MainUsuarios", "Correo:", nullptr));
        label_5->setText(QCoreApplication::translate("MainUsuarios", "Fecha de nacimiento:", nullptr));
        USUARIO->setTabText(USUARIO->indexOf(buscar), QCoreApplication::translate("MainUsuarios", "Buscar", nullptr));
        USUARIO->setTabText(USUARIO->indexOf(publi), QCoreApplication::translate("MainUsuarios", "Publicaciones", nullptr));
        USUARIO->setTabText(USUARIO->indexOf(soli), QCoreApplication::translate("MainUsuarios", "Solicitudes", nullptr));
        USUARIO->setTabText(USUARIO->indexOf(reportes), QCoreApplication::translate("MainUsuarios", "Reportes", nullptr));
        datosU_2->setText(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p><span style=\" color:#ff0000;\">PERFIL</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainUsuarios", "Nombres:", nullptr));
#if QT_CONFIG(tooltip)
        fechaP->setToolTip(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        fechaP->setWhatsThis(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        fechaP->setText(QString());
        label_6->setText(QCoreApplication::translate("MainUsuarios", "Apellidos:", nullptr));
#if QT_CONFIG(tooltip)
        nombreP->setToolTip(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        nombreP->setWhatsThis(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        nombreP->setText(QString());
        label_7->setText(QCoreApplication::translate("MainUsuarios", "Correo:", nullptr));
#if QT_CONFIG(tooltip)
        apellidoP->setToolTip(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        apellidoP->setWhatsThis(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        apellidoP->setText(QString());
        label_8->setText(QCoreApplication::translate("MainUsuarios", "Fecha de nacimiento:", nullptr));
#if QT_CONFIG(tooltip)
        correoP->setToolTip(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        correoP->setWhatsThis(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        correoP->setText(QString());
#if QT_CONFIG(tooltip)
        contraP->setToolTip(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        contraP->setWhatsThis(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p>Ingrese su contrase\303\261a</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        contraP->setText(QString());
        label_9->setText(QCoreApplication::translate("MainUsuarios", "Contrase\303\261a:", nullptr));
#if QT_CONFIG(tooltip)
        ModifcarD->setToolTip(QCoreApplication::translate("MainUsuarios", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ModifcarD->setText(QCoreApplication::translate("MainUsuarios", "MODIFICAR DATOS", nullptr));
        ElimanarC->setText(QCoreApplication::translate("MainUsuarios", "ELIMINAR CUENTA", nullptr));
        USUARIO->setTabText(USUARIO->indexOf(perfil), QCoreApplication::translate("MainUsuarios", "Perfil", nullptr));
        salirUsuario->setText(QCoreApplication::translate("MainUsuarios", "SALIR DEL LA INTERFAZ USUARIO", nullptr));
        USUARIO->setTabText(USUARIO->indexOf(salir), QCoreApplication::translate("MainUsuarios", "SALIR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainUsuarios: public Ui_MainUsuarios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUSUARIOS_H
