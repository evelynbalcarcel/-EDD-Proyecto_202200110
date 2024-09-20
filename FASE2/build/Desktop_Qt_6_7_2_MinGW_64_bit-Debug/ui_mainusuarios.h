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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
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
    QFrame *line_12;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QFrame *line_13;
    QFrame *line_14;
    QFrame *line_15;
    QFrame *line_16;
    QWidget *publi;
    QLabel *label_14;
    QFrame *line;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QLabel *label_15;
    QLabel *label_16;
    QComboBox *comboBox_3;
    QLabel *label_17;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QFrame *line_7;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line_10;
    QFrame *line_11;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *soli;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QTableWidget *CargaUsuariosSoli;
    QPushButton *enviarSoli;
    QFrame *line_17;
    QFrame *line_18;
    QFrame *line_19;
    QFrame *line_20;
    QFrame *line_21;
    QTableWidget *soliRecibidas;
    QTableWidget *soliEnviadas;
    QPushButton *aceptarSoli;
    QPushButton *rechazarSoli;
    QPushButton *cancelarSoliEnviada;
    QWidget *reportes;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_11;
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
        MainUsuarios->resize(653, 447);
        USUARIO = new QTabWidget(MainUsuarios);
        USUARIO->setObjectName("USUARIO");
        USUARIO->setGeometry(QRect(0, 10, 641, 441));
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
        datosU->setGeometry(QRect(60, 70, 211, 31));
        nombreU = new QLineEdit(buscar);
        nombreU->setObjectName("nombreU");
        nombreU->setGeometry(QRect(260, 130, 311, 31));
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
        apellidoU->setGeometry(QRect(260, 180, 311, 31));
        apellidoU->setFont(font2);
        correoU = new QLineEdit(buscar);
        correoU->setObjectName("correoU");
        correoU->setGeometry(QRect(260, 240, 311, 31));
        correoU->setFont(font2);
        fechaU = new QLineEdit(buscar);
        fechaU->setObjectName("fechaU");
        fechaU->setGeometry(QRect(260, 300, 311, 31));
        fechaU->setFont(font2);
        line_12 = new QFrame(buscar);
        line_12->setObjectName("line_12");
        line_12->setGeometry(QRect(590, 90, 21, 261));
        line_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_12->setFrameShape(QFrame::Shape::VLine);
        line_12->setFrameShadow(QFrame::Shadow::Sunken);
        label_18 = new QLabel(buscar);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(50, 300, 191, 31));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(false);
        label_18->setFont(font3);
        label_19 = new QLabel(buscar);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(150, 180, 91, 31));
        label_19->setFont(font3);
        label_20 = new QLabel(buscar);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(150, 130, 91, 31));
        label_20->setFont(font3);
        label_21 = new QLabel(buscar);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(170, 240, 71, 31));
        label_21->setFont(font3);
        line_13 = new QFrame(buscar);
        line_13->setObjectName("line_13");
        line_13->setGeometry(QRect(260, 80, 341, 20));
        line_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_13->setFrameShape(QFrame::Shape::HLine);
        line_13->setFrameShadow(QFrame::Shadow::Sunken);
        line_14 = new QFrame(buscar);
        line_14->setObjectName("line_14");
        line_14->setGeometry(QRect(20, 340, 581, 20));
        line_14->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_14->setFrameShape(QFrame::Shape::HLine);
        line_14->setFrameShadow(QFrame::Shadow::Sunken);
        line_15 = new QFrame(buscar);
        line_15->setObjectName("line_15");
        line_15->setGeometry(QRect(10, 90, 21, 261));
        line_15->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_15->setFrameShape(QFrame::Shape::VLine);
        line_15->setFrameShadow(QFrame::Shadow::Sunken);
        line_16 = new QFrame(buscar);
        line_16->setObjectName("line_16");
        line_16->setGeometry(QRect(20, 80, 31, 20));
        line_16->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_16->setFrameShape(QFrame::Shape::HLine);
        line_16->setFrameShadow(QFrame::Shadow::Sunken);
        USUARIO->addTab(buscar, QString());
        publi = new QWidget();
        publi->setObjectName("publi");
        label_14 = new QLabel(publi);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(40, 20, 49, 16));
        line = new QFrame(publi);
        line->setObjectName("line");
        line->setGeometry(QRect(240, 0, 21, 381));
        line->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        comboBox_2 = new QComboBox(publi);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(60, 60, 111, 24));
        comboBox_2->setFont(font1);
        pushButton = new QPushButton(publi);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 100, 80, 31));
        pushButton->setFont(font1);
        line_2 = new QFrame(publi);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(220, 30, 21, 121));
        line_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        line_3 = new QFrame(publi);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(10, 140, 221, 20));
        line_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        line_4 = new QFrame(publi);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(100, 20, 131, 20));
        line_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        line_5 = new QFrame(publi);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(10, 20, 21, 20));
        line_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        line_6 = new QFrame(publi);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(0, 30, 21, 121));
        line_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_6->setFrameShape(QFrame::Shape::VLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);
        label_15 = new QLabel(publi);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(30, 200, 151, 16));
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(true);
        label_15->setFont(font4);
        label_16 = new QLabel(publi);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 230, 61, 21));
        QFont font5;
        font5.setPointSize(13);
        font5.setBold(false);
        label_16->setFont(font5);
        comboBox_3 = new QComboBox(publi);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(100, 230, 121, 31));
        comboBox_3->setFont(font1);
        label_17 = new QLabel(publi);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(20, 280, 81, 21));
        label_17->setFont(font5);
        lineEdit = new QLineEdit(publi);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(102, 280, 121, 24));
        lineEdit->setFont(font5);
        pushButton_2 = new QPushButton(publi);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(70, 323, 80, 31));
        pushButton_2->setFont(font1);
        line_7 = new QFrame(publi);
        line_7->setObjectName("line_7");
        line_7->setGeometry(QRect(220, 210, 21, 161));
        line_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_7->setFrameShape(QFrame::Shape::VLine);
        line_7->setFrameShadow(QFrame::Shadow::Sunken);
        line_8 = new QFrame(publi);
        line_8->setObjectName("line_8");
        line_8->setGeometry(QRect(0, 210, 21, 161));
        line_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_8->setFrameShape(QFrame::Shape::VLine);
        line_8->setFrameShadow(QFrame::Shadow::Sunken);
        line_9 = new QFrame(publi);
        line_9->setObjectName("line_9");
        line_9->setGeometry(QRect(10, 360, 221, 20));
        line_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_9->setFrameShape(QFrame::Shape::HLine);
        line_9->setFrameShadow(QFrame::Shadow::Sunken);
        line_10 = new QFrame(publi);
        line_10->setObjectName("line_10");
        line_10->setGeometry(QRect(190, 200, 41, 20));
        line_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_10->setFrameShape(QFrame::Shape::HLine);
        line_10->setFrameShadow(QFrame::Shadow::Sunken);
        line_11 = new QFrame(publi);
        line_11->setObjectName("line_11");
        line_11->setGeometry(QRect(10, 200, 16, 20));
        line_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_11->setFrameShape(QFrame::Shape::HLine);
        line_11->setFrameShadow(QFrame::Shadow::Sunken);
        pushButton_3 = new QPushButton(publi);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(270, 20, 241, 31));
        pushButton_4 = new QPushButton(publi);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(320, 303, 91, 31));
        QFont font6;
        font6.setPointSize(12);
        font6.setBold(true);
        pushButton_4->setFont(font6);
        pushButton_5 = new QPushButton(publi);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(430, 303, 141, 31));
        pushButton_5->setFont(font6);
        pushButton_6 = new QPushButton(publi);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(320, 343, 251, 31));
        pushButton_6->setFont(font6);
        USUARIO->addTab(publi, QString());
        soli = new QWidget();
        soli->setObjectName("soli");
        label_10 = new QLabel(soli);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(50, 10, 81, 31));
        label_11 = new QLabel(soli);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(390, 210, 191, 21));
        label_12 = new QLabel(soli);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 210, 191, 21));
        label_13 = new QLabel(soli);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 240, 181, 21));
        label_13->setStyleSheet(QString::fromUtf8("border-top-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));"));
        CargaUsuariosSoli = new QTableWidget(soli);
        if (CargaUsuariosSoli->columnCount() < 5)
            CargaUsuariosSoli->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        CargaUsuariosSoli->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        CargaUsuariosSoli->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        CargaUsuariosSoli->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        CargaUsuariosSoli->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        CargaUsuariosSoli->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        CargaUsuariosSoli->setObjectName("CargaUsuariosSoli");
        CargaUsuariosSoli->setGeometry(QRect(40, 50, 571, 141));
        CargaUsuariosSoli->setFont(font1);
        enviarSoli = new QPushButton(soli);
        enviarSoli->setObjectName("enviarSoli");
        enviarSoli->setGeometry(QRect(460, 110, 131, 31));
        enviarSoli->setFont(font1);
        line_17 = new QFrame(soli);
        line_17->setObjectName("line_17");
        line_17->setGeometry(QRect(600, 30, 21, 171));
        line_17->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_17->setFrameShape(QFrame::Shape::VLine);
        line_17->setFrameShadow(QFrame::Shadow::Sunken);
        line_18 = new QFrame(soli);
        line_18->setObjectName("line_18");
        line_18->setGeometry(QRect(140, 20, 471, 20));
        line_18->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_18->setFrameShape(QFrame::Shape::HLine);
        line_18->setFrameShadow(QFrame::Shadow::Sunken);
        line_19 = new QFrame(soli);
        line_19->setObjectName("line_19");
        line_19->setGeometry(QRect(20, 190, 591, 20));
        line_19->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_19->setFrameShape(QFrame::Shape::HLine);
        line_19->setFrameShadow(QFrame::Shadow::Sunken);
        line_20 = new QFrame(soli);
        line_20->setObjectName("line_20");
        line_20->setGeometry(QRect(10, 30, 21, 171));
        line_20->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_20->setFrameShape(QFrame::Shape::VLine);
        line_20->setFrameShadow(QFrame::Shadow::Sunken);
        line_21 = new QFrame(soli);
        line_21->setObjectName("line_21");
        line_21->setGeometry(QRect(20, 20, 21, 20));
        line_21->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        line_21->setFrameShape(QFrame::Shape::HLine);
        line_21->setFrameShadow(QFrame::Shadow::Sunken);
        soliRecibidas = new QTableWidget(soli);
        if (soliRecibidas->columnCount() < 2)
            soliRecibidas->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        soliRecibidas->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        soliRecibidas->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        soliRecibidas->setObjectName("soliRecibidas");
        soliRecibidas->setGeometry(QRect(20, 240, 281, 141));
        soliRecibidas->setFont(font1);
        soliEnviadas = new QTableWidget(soli);
        if (soliEnviadas->columnCount() < 2)
            soliEnviadas->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        soliEnviadas->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        soliEnviadas->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        soliEnviadas->setObjectName("soliEnviadas");
        soliEnviadas->setGeometry(QRect(330, 240, 281, 141));
        soliEnviadas->setFont(font1);
        aceptarSoli = new QPushButton(soli);
        aceptarSoli->setObjectName("aceptarSoli");
        aceptarSoli->setGeometry(QRect(170, 280, 91, 31));
        aceptarSoli->setFont(font1);
        rechazarSoli = new QPushButton(soli);
        rechazarSoli->setObjectName("rechazarSoli");
        rechazarSoli->setGeometry(QRect(170, 320, 91, 31));
        rechazarSoli->setFont(font1);
        cancelarSoliEnviada = new QPushButton(soli);
        cancelarSoliEnviada->setObjectName("cancelarSoliEnviada");
        cancelarSoliEnviada->setGeometry(QRect(480, 300, 91, 31));
        cancelarSoliEnviada->setFont(font1);
        USUARIO->addTab(soli, QString());
        reportes = new QWidget();
        reportes->setObjectName("reportes");
        label = new QLabel(reportes);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 231, 31));
        label->setFont(font6);
        label_2 = new QLabel(reportes);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(310, 20, 281, 31));
        label_2->setFont(font6);
        pushButton_11 = new QPushButton(reportes);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(210, 210, 151, 31));
        pushButton_11->setFont(font6);
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

        USUARIO->setCurrentIndex(2);


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
        label_18->setText(QCoreApplication::translate("MainUsuarios", "Fecha de nacimiento:", nullptr));
        label_19->setText(QCoreApplication::translate("MainUsuarios", "Apellidos:", nullptr));
        label_20->setText(QCoreApplication::translate("MainUsuarios", "Nombres:", nullptr));
        label_21->setText(QCoreApplication::translate("MainUsuarios", "Correo:", nullptr));
        USUARIO->setTabText(USUARIO->indexOf(buscar), QCoreApplication::translate("MainUsuarios", "Buscar", nullptr));
        label_14->setText(QCoreApplication::translate("MainUsuarios", "Fecha", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainUsuarios", "Todos", nullptr));

        pushButton->setText(QCoreApplication::translate("MainUsuarios", "Aplicar", nullptr));
        label_15->setText(QCoreApplication::translate("MainUsuarios", "Recorrido limitado", nullptr));
        label_16->setText(QCoreApplication::translate("MainUsuarios", "Orden", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainUsuarios", "Inorden", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainUsuarios", "Preorden", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainUsuarios", "Postoden", nullptr));

        label_17->setText(QCoreApplication::translate("MainUsuarios", "Cantidad", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainUsuarios", "Aplicar", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainUsuarios", "Crear nueva publicaci\303\263n", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainUsuarios", "Comentar", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainUsuarios", "Ver comentarios", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainUsuarios", "Ver \303\241rbol de comentarios", nullptr));
        USUARIO->setTabText(USUARIO->indexOf(publi), QCoreApplication::translate("MainUsuarios", "Publicaciones", nullptr));
        label_10->setText(QCoreApplication::translate("MainUsuarios", "Usuarios", nullptr));
        label_11->setText(QCoreApplication::translate("MainUsuarios", "Solicitudes enviadas", nullptr));
        label_12->setText(QCoreApplication::translate("MainUsuarios", "Solicitudes Recibidas", nullptr));
        label_13->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = CargaUsuariosSoli->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainUsuarios", "Nombres", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = CargaUsuariosSoli->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainUsuarios", "Apellidos", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = CargaUsuariosSoli->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainUsuarios", "Correo", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = CargaUsuariosSoli->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainUsuarios", "Nacimiento", nullptr));
        enviarSoli->setText(QCoreApplication::translate("MainUsuarios", "Enviar solicitud", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = soliRecibidas->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainUsuarios", "Correo", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = soliEnviadas->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainUsuarios", "Correo", nullptr));
        aceptarSoli->setText(QCoreApplication::translate("MainUsuarios", "Aceptar", nullptr));
        rechazarSoli->setText(QCoreApplication::translate("MainUsuarios", "Rechazar", nullptr));
        cancelarSoliEnviada->setText(QCoreApplication::translate("MainUsuarios", "Cancelar", nullptr));
        USUARIO->setTabText(USUARIO->indexOf(soli), QCoreApplication::translate("MainUsuarios", "Solicitudes", nullptr));
        label->setText(QCoreApplication::translate("MainUsuarios", "Fechas con m\303\241s publicacones ", nullptr));
        label_2->setText(QCoreApplication::translate("MainUsuarios", "Publicaciones con m\303\241s comentarios", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainUsuarios", "Generar reportes", nullptr));
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
