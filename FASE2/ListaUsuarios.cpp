#include "ListaUsuarios.h"
#include "Usuarios.h"
#include "mainusuarios.h"
#include "MainPrincipal.h"
#include <QDebug>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

using namespace std;

// Constructor
ListaU::ListaU() : head(nullptr) {}

// Método para registrar un nuevo usuario
void ListaU::registerUser() {
    string firstName, lastName, email, password, birthDate;

    cout << "Nombres: ";
    getline(cin, firstName);
    cout << "Apellidos: ";
    getline(cin, lastName);
    cout << "Fecha de nacimiento: ";
    getline(cin, birthDate);
    cout << "Correo electronico: ";
    getline(cin, email);

    if (findUser(email)) {
        cout << "El correo ya esta registrado.\n";
        return;
    }

    cout << "Contrasena: ";
    getline(cin, password);

    // Crear un nuevo usuario y agregarlo a la lista
    User newUser(firstName, lastName, birthDate, email, password);
    addUser(newUser);
    cout << "Usuario registrado exitosamente.\n";
}

// Método para iniciar sesión
bool ListaU::login(const std::string& email, const std::string& password) {
    Node* userNode = findUser(email);
    if (userNode && userNode->user.getPassword() == password) {
        return true; // Inicio de sesión exitoso
    }
    return false; // Usuario o contraseña incorrectos
}


// Método para eliminar una cuenta
bool ListaU::deleteAccount(const std::string& email, const std::string& password) {
    Node** current = &head;

    while (*current) {
        if ((*current)->user.getEmail() == email && (*current)->user.getPassword() == password) {
            Node* temp = *current;
            *current = (*current)->next;
            delete temp;
            return true; // Cuenta eliminada con éxito
        }
        current = &((*current)->next);
    }

    return false; // Cuenta no encontrada
}

// Método para agregar un usuario a la lista
void ListaU::addUser(const User& user) {
    Node* newNode = new Node{user, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Método para buscar un usuario en la lista por su email
ListaU::Node* ListaU::findUser(const std::string& email) {
    Node* current = head;
    while (current) {
        if (current->user.getEmail() == email) {
            return current;
        }
        current = current->next;
    }
    return nullptr;  // Usuario no encontrado
}

//carga de Usuarios
void ListaU::jsonUsuaios(string text){
    // Convierte el string en un objeto JSON
    json jsonObj = json::parse(text);

    for (const auto& usuarioData : jsonObj) {
        // Verificación de campos
        if (usuarioData.contains("nombres") &&
            usuarioData.contains("apellidos") &&
            usuarioData.contains("fecha_de_nacimiento") &&
            usuarioData.contains("correo") &&
            usuarioData.contains("contrasena")) {

            string firstName = usuarioData["nombres"];
            string lastName = usuarioData["apellidos"];
            string birthDate = usuarioData["fecha_de_nacimiento"];
            string email = usuarioData["correo"];
            string password = usuarioData["contrasena"];

            // Verificar si el usuario ya existe
            if (findUser(email)) {
                qDebug() << "Usuario con correo " << QString::fromStdString(email) << " ya existe.";
            } else {
                // Crear un nuevo usuario y agregarlo a la lista
                User newUser(firstName, lastName, birthDate, email, password);
                addUser(newUser);  // Añadir a la lista de usuarios
                qDebug() << "Usuario con correo " << QString::fromStdString(email) << " agregado correctamente.";
            }
        } else {
            qDebug() << "Error: Carga Invalida\n";
        }
    }

    qDebug() << "Usuarios cargados exitosamente.";
}

