#ifndef MAINPRINCIPAL_H
#define MAINPRINCIPAL_H
#include "ListaUsuarios.h"

#include <QMainWindow>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainPrincipal;
}
QT_END_NAMESPACE

class MainPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    MainPrincipal(QWidget *parent = nullptr);
    ~MainPrincipal();

private slots:
    void on_iniciosesion_clicked();
    void on_registrarse_clicked();
    void on_informacion_clicked();
    void on_salir_clicked();
    void on_INTERFAZ_currentChanged(int index);


private:
    Ui::MainPrincipal *ui;

    ListaU listaUsuarios; // Instancia de ListaU


};
#endif // MAINPRINCIPAL_H
