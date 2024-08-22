#include <iostream>
#include <string>
#include <locale.h>
#include "ListaUsuarios.h"
#include "Usuarios.h"
#include "PublicacionesU.h"
#include "MatrizAmistad.h"

using json = nlohmann::json;
using namespace std;

void adminMenu(ListaU& listaUsuarios);
void userMenu(ListaU& listaUsuarios, const string& email);
PublicacionesU publicaciones;

int main() {
    ListaU listaUsuarios;
    
    // Agregar Usuario Administrador 
    listaUsuarios.addUser(User("Admin", "Admin", "01-01-1970", "admin@gmail.com", "EDD2S2024"));

    int option;    
    string email, password;
    
    do {
        cout << "\n------ INTERFAZ PRINCIPAL ------\n";
        cout << "1. Iniciar sesion\n";
        cout << "2. Registrarse\n";
        cout << "3. Informacion\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> option;
        cin.ignore(); // Para consumir el salto de línea después de ingresar la opción

        switch (option) {
            case 1:
                cout << "Correo electronico: ";
                getline(cin, email);
                cout << "Contrasena: ";
                getline(cin, password);
                if (listaUsuarios.login(email, password)) {
                    if (email == "admin@gmail.com" && password == "EDD2S2024") {
                        cout << " ____________________________________________\n";
                        cout << "|Inicio de sesion como administrador exitoso.|\n";
                        cout << "|____________________________________________|\n";
                        adminMenu(listaUsuarios);
                    } else {
                        cout << "Inicio de sesion exitoso.\n";
                        userMenu(listaUsuarios, email);
                    }
                } else {
                    cout << "Correo o contrasena incorrectos.\n";
                }
                break;
            case 2:
                listaUsuarios.registerUser();
                break;
            case 3:
                cout << "Informacion sobre la aplicacion...\n";
                break;
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (option != 4);

    return 0;
}

void userMenu(ListaU& listaUsuarios, const std::string& email) {
    MatrizAmistad& matrizAmistad = listaUsuarios.matrizAmistad;  // Acceder directamente a la matriz de amistad
    
    
    int option;
    do {
        cout << "\n--- MODULO USUARIO ---\n";
        cout << "1. Perfil\n";        
        cout << "2. Solicitudes\n";        
        cout << "3. Publicaciones\n";        
        cout << "4. Reportes\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opciOn: ";
        cin >> option;
        cin.ignore(); // Para consumir el salto de línea después de ingresar la opción

        switch (option) {
            case 1: {
                cout << "_______Perfil_______\n";
                cout << "1. Ver perfil\n";
                cout << "2. Eliminar cuenta\n";
                char subOption;
                cin >> subOption;
                cin.ignore(); // Para consumir el salto de línea después de ingresar la opción
                if (subOption == '1') {
                    listaUsuarios.viewProfile(email);
                } else if (subOption == '2') {
                    string password;
                    cout << "Contrasena: ";
                    getline(cin, password);
                    if (listaUsuarios.deleteAccount(email, password)) {
                        cout << "Cuenta eliminada.\n";
                        return; // Salir del menú usuario
                    } else {
                        cout << "Error al eliminar la cuenta.\n";
                    }
                } else {
                    cout << "Opcion no valida.\n";
                }
                break;
            }
            case 2: {
                cout << "_______Solicitudes_______\n";
                cout << "1. Ver solicitudes\n";
                cout << "2. Enviar solicitud\n";
                int reqOption;
                cin >> reqOption;
                cin.ignore(); // Para consumir el salto de línea después de ingresar la opción
                if (reqOption == 1) {
                    listaUsuarios.viewRequests();
                    cout << "1. Aceptar solicitud\n";
                    cout << "2. Rechazar solicitud\n";
                    int action;
                    cin >> action;
                    cin.ignore(); // Para consumir el salto de línea después de ingresar la opción
                    if (action == 1) {
                        string remitente;
                        cout << "Ingrese el correo del remitente: ";
                        getline(cin, remitente);
                        if (listaUsuarios.aceptarSolicitud(remitente, email)) {
                            cout << "Solicitud aceptada.\n";
                        } else {
                            cout << "Error al aceptar la solicitud.\n";
                        }
                    } else if (action == 2) {
                        string remitente;
                        cout << "Ingrese el correo del remitente: ";
                        getline(cin, remitente);
                        if (listaUsuarios.rechazarSolicitud(remitente, email)) {
                            cout << "Solicitud rechazada.\n";
                        } else {
                            cout << "Error al rechazar la solicitud.\n";
                        }
                    } else {
                        cout << "Opcion no valida.\n";
                    }
                } else if (reqOption == 2) {
                    string destinatario;
                    cout << "Ingrese el correo del destinatario: ";
                    getline(cin, destinatario);
                    if (listaUsuarios.enviarSolicitud(email, destinatario)) {
                        cout << "Solicitud enviada.\n";
                    } else {
                        cout << "Error al enviar la solicitud.\n";
                    }
                } else {
                    cout << "Opcion no valida.\n";
                }
                break;
            }
            // Asumiendo que `publicaciones` es una instancia global o pasada a la función
            case 3: {
                int pubOption;
                do {
                    cout << "_______Publicaciones_______\n";
                    cout << "1. Ver todas\n";
                    cout << "2. Crear\n";
                    cout << "3. Eliminar\n";
                    cout << "4. Regresar\n";
                    cin >> pubOption;
                    cin.ignore(); // Para consumir el salto de línea después de ingresar la opción

                    if (pubOption == 1) {
                        publicaciones.viewPosts(email, matrizAmistad);  // Pasar el email del usuario actual y la matriz de amistades
                    } else if (pubOption == 2) {
                        publicaciones.createPost(email);  // Crear una publicación para el usuario actual
                    } else if (pubOption == 3) {
                        int postId;
                        cout << "Ingrese el ID de la publicación a eliminar: "; // El conteo empieza en 0
                        cin >> postId;
                        cin.ignore(); // Para consumir el salto de línea después de ingresar la opción
                        if (publicaciones.deletePost(postId)) {
                            cout << "Publicación eliminada.\n";
                        } else {
                            cout << "Error al eliminar la publicación.\n";
                        }
                    } else if (pubOption != 4) {
                        cout << "Opción no válida.\n";
                    }
                } while (pubOption != 4);
                break;
            }
            case 4:
                listaUsuarios.generateReports();
                break;
            case 5:
                cout << "Saliendo del menu usuario.\n";
                cout << "___________________________\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (option != 5);
}

void adminMenu(ListaU& listaUsuarios) {
    int option;
    do {
        cout << "\n------ MODULO ADMINISTRADOR ------\n";
        cout << "1. Cargar usuarios\n";
        cout << "2. Cargar relaciones\n";
        cout << "3. Cargar publicaciones\n";
        cout << "4. Gestionar usuarios\n";
        cout << "   a. Eliminar usuarios\n";
        cout << "5. Reportes\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> option;
        cin.ignore(); // Para consumir el salto de línea después de ingresar la opción

        switch (option) {
            case 1:
                listaUsuarios.loadUsers();
                break;
            case 2:
                listaUsuarios.loadRelations();
                break;
            case 3:
                
                listaUsuarios.loadPosts(publicaciones);
                break;
            case 4:
                cout << "_______Gestionar usuarios_______\n";
                cout << "1. Eliminar usuarios\n";
                cout << "Seleccione una opcion: ";
                char subOption;
                cin >> subOption;
                cin.ignore(); // Para consumir el salto de línea después de ingresar la opción
                if (subOption == '1') {
                    string email, password;
                    cout << "Ingrese el correo del usuario a eliminar: ";
                    getline(cin, email);
                    cout << "Ingrese la contrasena del usuario a eliminar: ";
                    getline(cin, password);
                    if (listaUsuarios.deleteAccount(email, password)) {
                        cout << "Usuario eliminado correctamente.\n";
                    } else {
                        cout << "Error al eliminar el usuario.\n";
                    }
                } else {
                    cout << "Opcion no valida.\n";
                }
                break;
            case 5:
                listaUsuarios.generateReports();
                break;
            case 6:
                cout << "Saliendo del modulo administrador...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (option != 6);
}
