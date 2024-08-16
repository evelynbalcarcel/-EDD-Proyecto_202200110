#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include "ListaUsuarios.h"
#include "Usuarios.h"
#include "PublicacionesU.h"

#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

// Definición de las clases Publicacion y Solicitud si no están definidas en otro archivo
struct Solicitud {
    std::string emisor;
    std::string receptor;
    std::string estado;
    Solicitud* siguiente;
};

ListaU::ListaU() : head(nullptr), solicitudes(nullptr){
}

ListaU::~ListaU() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    Solicitud* solicitudActual = solicitudes;
    while (solicitudActual != nullptr) {
        Solicitud* siguienteSolicitud = solicitudActual->siguiente;
        delete solicitudActual;
        solicitudActual = siguienteSolicitud;
    }

}

bool ListaU::login(const string& email, const string& password) {
    Node* userNode = findUser(email);
    if (userNode && userNode->user.getPassword() == password) {
        return true;
    }
    return false;
}

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
    
    User newUser(firstName, lastName, birthDate, email, password);
    addUser(newUser); // Asegúrate de que esto agregue el usuario correctamente
    cout << "Usuario registrado.\n";
}

bool ListaU::deleteAccount(const string& email, const string& password) {
    Node** current = &head;
    while (*current) {
        if ((*current)->user.getEmail() == email && (*current)->user.getPassword() == password) {
            Node* temp = *current;
            *current = (*current)->next;
            delete temp;
            return true;
        }
        current = &((*current)->next);
    }
    return false;
}

void ListaU::addUser(const User& user) {
    Node* newNode = new Node{user, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

ListaU::Node* ListaU::findUser(const string& email) {
    Node* current = head;
    while (current != nullptr) {
        if (current->user.getEmail() == email) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

bool ListaU::enviarSolicitud(const std::string& remitente, const std::string& destinatario) {
    Node* remitenteNode = findUser(remitente);
    Node* destinatarioNode = findUser(destinatario);

    if (!remitenteNode || !destinatarioNode) {
        cout << "Usuario no encontrado." << endl;
        return false;
    }

    // Verificar si ya existe una solicitud pendiente
    Solicitud* current = solicitudes;
    while (current != nullptr) {
        if (current->emisor == remitente && current->receptor == destinatario && current->estado == "pendiente") {
            cout << "Ya existe una solicitud pendiente." << endl;
            return false;
        }
        current = current->siguiente;
    }

    // Crear nueva solicitud
    Solicitud* nuevaSolicitud = new Solicitud{remitente, destinatario, "pendiente", solicitudes};
    solicitudes = nuevaSolicitud;
    cout << "Solicitud enviada." << endl;
    return true;
}

bool ListaU::aceptarSolicitud(const std::string& remitente, const std::string& destinatario) {
    Solicitud* current = solicitudes;
    while (current != nullptr) {
        if (current->emisor == remitente && current->receptor == destinatario && current->estado == "pendiente") {
            current->estado = "aceptada";
            cout << "Solicitud aceptada." << endl;
            return true;
        }
        current = current->siguiente;
    }
    cout << "No se encontró una solicitud pendiente de este usuario." << endl;
    return false;
}

bool ListaU::rechazarSolicitud(const std::string& remitente, const std::string& destinatario) {
    Solicitud* current = solicitudes;
    while (current != nullptr) {
        if (current->emisor == remitente && current->receptor == destinatario && current->estado == "pendiente") {
            current->estado = "rechazada";
            cout << "Solicitud rechazada." << endl;
            return true;
        }
        current = current->siguiente;
    }
    cout << "No se encontró una solicitud pendiente de este usuario." << endl;
    return false;
}

// --------------------------cargar usuarios----------------------------------------
void ListaU::loadUsers() {
    std::string filePath;
    std::cout << "Ingrese la ruta del archivo de usuarios (Usuarios.json): ";
    std::getline(std::cin, filePath);

    std::ifstream usersFile(filePath);
    if (!usersFile.is_open()) {
        std::cerr << "Error al abrir el archivo de usuarios: " << filePath << std::endl;
        return;
    }
    // Leer el contenido del archivo en una cadena
    std::string fileContent((std::istreambuf_iterator<char>(usersFile)), std::istreambuf_iterator<char>());
    // Mostrar el contenido del archivo en la consola
    std::cout << "Contenido del archivo:\n" << fileContent << std::endl;

    // Volver al inicio del archivo para procesar el JSON
    usersFile.clear();
    usersFile.seekg(0, std::ios::beg);

    json root;
    try {
        usersFile >> root;
    } catch (json::parse_error& e) {
        std::cerr << "Error al parsear el archivo de usuarios: " << e.what() << std::endl;
        return;
    }

    for (const auto& userJson : root) {
        try {
            if (userJson.contains("nombre") && userJson.contains("apellido") && 
                userJson.contains("fecha_nacimiento") && userJson.contains("correo") && 
                userJson.contains("contrasena")) {

                User user(
                    userJson["nombre"].get<std::string>(),
                    userJson["apellido"].get<std::string>(),
                    userJson["fecha_nacimiento"].get<std::string>(),
                    userJson["correo"].get<std::string>(),
                    userJson["contrasena"].get<std::string>()
                );
                addUser(user);
            } else {
                std::cerr << "Error: faltan claves en el objeto JSON: " << userJson << std::endl;
            }
        } catch (json::type_error& e) {
            std::cerr << "Error de tipo al procesar el archivo de usuarios: " << e.what() << std::endl;
        }
    }
    std::cout << "Usuarios cargados exitosamente.\n";
}
//----------------------Cargar solicitues/ relaciones desde admin-----------------------
void ListaU::loadRelations() {
    std::string filePath;
    std::cout << "Ingrese la ruta del archivo de solicitudes (Solicitudes.json): ";
    std::getline(std::cin, filePath);

    std::ifstream requestsFile(filePath);
    if (!requestsFile.is_open()) {
        std::cerr << "Error al abrir el archivo de solicitudes: " << filePath << std::endl;
        return;
    }

    // Leer el contenido del archivo en una cadena
    std::string fileContent((std::istreambuf_iterator<char>(requestsFile)), std::istreambuf_iterator<char>());
    // Mostrar el contenido del archivo en la consola
    std::cout << "Contenido del archivo:\n" << fileContent << std::endl;

    // Volver al inicio del archivo para procesar el JSON
    requestsFile.clear();
    requestsFile.seekg(0, std::ios::beg);

    json root;
    try {
        requestsFile >> root;
    } catch (json::parse_error& e) {
        std::cerr << "Error al parsear el archivo de solicitudes: " << e.what() << std::endl;
        return;
    }

    for (const auto& requestJson : root) {
        try {
            if (requestJson.contains("emisor") && requestJson.contains("receptor") && 
                requestJson.contains("estado")) {

                Solicitud* solicitud = new Solicitud{
                    requestJson["emisor"].get<std::string>(),
                    requestJson["receptor"].get<std::string>(),
                    requestJson["estado"].get<std::string>(),
                    nullptr
                };

                solicitud->siguiente = solicitudes;
                solicitudes = solicitud;
            } else {
                std::cerr << "Error: faltan claves en el objeto JSON: " << requestJson << std::endl;
            }
        } catch (json::type_error& e) {
            std::cerr << "Error de tipo al procesar el archivo de solicitudes: " << e.what() << std::endl;
        }
    }
    std::cout << "Solicitudes cargadas exitosamente.\n";
}

//--------------------------Carga de publicaciones admin----------------------------
void ListaU::loadPosts() {
    std::string filePath;
    std::cout << "Ingrese la ruta del archivo JSON de publicaciones: ";
    std::getline(std::cin, filePath);

    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo.\n";
        return;
    }
    // Leer el contenido del archivo en una cadena
    std::string fileContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    // Mostrar el contenido del archivo en la consola
    std::cout << "Contenido del archivo:\n" << fileContent << std::endl;

    // Volver al inicio del archivo para procesar el JSON
    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);


    nlohmann::json jsonData;
    inputFile >> jsonData;

    for (const auto& post : jsonData) {
        std::string email = post["correo"];
        std::string content = post["contenido"];
        std::string date = post["fecha"];
        std::string time = post["hora"];
       
    }

    std::cout << "Publicaciones cargadas exitosamente.\n";
}


void ListaU::manageUsers() {
    // Implementar la gestión de usuarios si es necesario
}

void ListaU::generateReports() {
    // Implementar la generación de reportes si es necesario
}

void ListaU::viewProfile(const string& email) {
    Node* userNode = findUser(email);
    if (userNode) {
        userNode->user.printInfo();
    } else {
        cout << "Usuario no encontrado.\n";
    }
}

void ListaU::viewRequests() {
    string email;
    cout << "Ingrese su correo: ";
    getline(cin, email);

    Node* userNode = findUser(email);
    if (!userNode) {
        cout << "Usuario no encontrado.\n";
        return;
    }

    Solicitud* current = solicitudes;
    bool found = false;
    while (current != nullptr) {
        if (current->receptor == email && current->estado == "pendiente") {
            cout << "Solicitud de: " << current->emisor << " - Estado: " << current->estado << endl;
            found = true;
        }
        current = current->siguiente;
    }

    if (!found) {
        cout << "No tiene solicitudes pendientes.\n";
    }
}

void ListaU::viewFriends() {
    string email;
    cout << "Ingrese su correo: ";
    getline(cin, email);

    Node* userNode = findUser(email);
    if (!userNode) {
        cout << "Usuario no encontrado.\n";
        return;
    }

    Solicitud* current = solicitudes;
    bool found = false;
    while (current != nullptr) {
        if ((current->receptor == email || current->emisor == email) && current->estado == "aceptada") {
            string amigo = (current->receptor == email) ? current->emisor : current->receptor;
            cout << "Amigo: " << amigo << endl;
            found = true;
        }
        current = current->siguiente;
    }

    if (!found) {
        cout << "No tiene amigos agregados.\n";
    }
}

// Aquí deberías tener la instancia de PublicacionesU
PublicacionesU publicaciones;

void ListaU::viewPosts() {
    publicaciones.viewPosts();
}

void ListaU::createPost(const string& email) {
    publicaciones.createPost(email);
}

bool ListaU::deletePost(int postId) {
    return publicaciones.deletePost(postId);
}
