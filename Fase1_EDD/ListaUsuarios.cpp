#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "ListaUsuarios.h"
#include "Usuarios.h"

#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

int nextPostId = 0; // Variable global para asignar identificadores únicos a las publicaciones


// Definición de las clases Publicacion y Solicitud si no están definidas en otro archivo
struct Publicacion {
    std::string correo;
    std::string contenido;
    std::string fecha;
    std::string hora;
    Publicacion* siguiente;
    Publicacion* anterior;
};

struct Solicitud {
    std::string emisor;
    std::string receptor;
    std::string estado;
    Solicitud* siguiente;
};

ListaU::ListaU() : head(nullptr), solicitudes(nullptr), publicaciones(nullptr) {
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

    Publicacion* publicacionActual = publicaciones;
    while (publicacionActual != nullptr) {
        Publicacion* siguientePublicacion = publicacionActual->siguiente;
        delete publicacionActual;
        publicacionActual = siguientePublicacion;
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

void ListaU::loadUsers() {
    std::ifstream usersFile("Usuarios.json");
    if (!usersFile.is_open()) {
        std::cerr << "Error al abrir el archivo de usuarios: Usuarios.json" << std::endl;
        return;
    }

    json root;
    usersFile >> root;

    for (const auto& userJson : root) {
        User user(
            userJson["nombre"].get<std::string>(),
            userJson["apellido"].get<std::string>(),
            userJson["fechaNacimiento"].get<std::string>(),
            userJson["correo"].get<std::string>(),
            userJson["contraseña"].get<std::string>()
        );
        addUser(user);
    }
    cout << "Usuarios cargados exitosamente.\n";
}

void ListaU::loadRelations() {
    std::ifstream requestsFile("Solicitudes.json");
    if (!requestsFile.is_open()) {
        std::cerr << "Error al abrir el archivo de solicitudes: Solicitudes.json" << std::endl;
        return;
    }

    json root;
    requestsFile >> root;

    for (const auto& requestJson : root) {
        Solicitud* solicitud = new Solicitud{
            requestJson["emisor"].get<std::string>(),
            requestJson["receptor"].get<std::string>(),
            requestJson["estado"].get<std::string>(),
            nullptr
        };

        solicitud->siguiente = solicitudes;
        solicitudes = solicitud;
    }
    cout << "Solicitudes cargadas exitosamente.\n";
}

void ListaU::loadPosts() {
    std::string filePath;
    std::cout << "Ingrese la ruta del archivo JSON de publicaciones: ";
    std::getline(std::cin, filePath);

    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo.\n";
        return;
    }

    nlohmann::json jsonData;
    inputFile >> jsonData;

    for (const auto& post : jsonData) {
        std::string email = post["correo"];
        std::string content = post["contenido"];
        std::string date = post["fecha"];
        std::string time = post["hora"];

        // Asignar un nuevo ID para cada publicación
        Publicacion* newPost = new Publicacion{nextPostId++, email, content, date, time, nullptr, nullptr};
        if (publicaciones == nullptr) {
            publicaciones = newPost;
        } else {
            Publicacion* temp = publicaciones;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = newPost;
            newPost->anterior = temp;
        }
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


void ListaU::createPost(const std::string& email) {
    std::string content, date, time;
    std::cout << "Ingrese el contenido de la publicacion: ";
    std::getline(std::cin, content);
    std::cout << "Ingrese la fecha de la publicacion (YYYY-MM-DD): ";
    std::getline(std::cin, date);
    std::cout << "Ingrese la hora de la publicacion (HH:MM): ";
    std::getline(std::cin, time);

    Publicacion* newPost = new Publicacion{nextPostId++, email, content, date, time, nullptr, nullptr};

    if (publicaciones == nullptr) {
        publicaciones = newPost;
    } else {
        Publicacion* temp = publicaciones;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = newPost;
        newPost->anterior = temp;
    }
    std::cout << "Publicacion creada exitosamente.\n";
}

bool ListaU::deletePost(int postId) {
    Publicacion* current = publicaciones;

    // Buscar la publicación con el postId dado
    while (current != nullptr) {
        if (current->postId == postId) {
            // Ajustar punteros para eliminar el nodo de la lista
            if (current->anterior) {
                current->anterior->siguiente = current->siguiente;
            } else {
                publicaciones = current->siguiente; // Si es el primer nodo
            }
            if (current->siguiente) {
                current->siguiente->anterior = current->anterior;
            }
            delete current; // Liberar la memoria del nodo
            std::cout << "Publicación eliminada exitosamente.\n";
            return true; // Eliminación exitosa
        }
        current = current->siguiente;
    }

    std::cout << "No se encontró una publicación con el ID especificado.\n";
    return false; // No se encontró el postId
}


void ListaU::viewPosts() {
    Publicacion* current = publicaciones;
    while (current != nullptr) {
        std::cout << "Correo: " << current->correo << "\n"
                  << "Contenido: " << current->contenido << "\n"
                  << "Fecha: " << current->fecha << "\n"
                  << "Hora: " << current->hora << "\n"
                  << "----------------------\n";
        current = current->siguiente;
    }
}
