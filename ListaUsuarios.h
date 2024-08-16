// ListaUsuarios.h
#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "Usuarios.h"

#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

class SolicitudesU {
public:
    std::string nombre;
    std::string correo;
    std::vector<std::string> solicitudesEnviadas;
    std::stack<std::string> solicitudesRecibidas;
    int indice; // Atributo para el índice en la matriz

    SolicitudesU(const std::string& nombre, const std::string& correo) 
        : nombre(nombre), correo(correo) {}
};
// Clase principal para manejar usuarios y solicitudes
class ListaU {
private:
    struct Node {
        User user;
        Node* next;
    };
    struct Solicitud {
        std::string emisor;
        std::string receptor;
        std::string estado;
        Solicitud* siguiente;
    };
    
    Node* head;
    Solicitud* solicitudes;


    Node* findUser(const std::string& email);

public:
    ListaU();
    ~ListaU();
    std::vector<SolicitudesU> usuarios;
    bool matrizAmistad[100][100] = { false }; // Máximo 100 usuarios

    bool enviarSolicitud(const std::string& remitente, const std::string& destinatario);
    bool aceptarSolicitud(const std::string& remitente, const std::string& destinatario);
    bool rechazarSolicitud(const std::string& remitente, const std::string& destinatario);
    void addUser(const User& user);
    bool login(const std::string& email, const std::string& password);
    void registerUser();
    bool deleteAccount(const std::string& email, const std::string& password);
    void loadUsers(); // cargar usuarios en el modulo admin
    void loadRelations();
    void loadPosts();
    void manageUsers();
    void generateReports();
    void viewProfile(const std::string& email);
    void viewRequests();
    void sendRequest();
    void viewFriends();
    void viewPosts();
    void createPost(const string& email);
    bool deletePost(int postId);


};

#endif // LISTAUSUARIOS_H