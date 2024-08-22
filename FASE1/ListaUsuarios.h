//ListaUsuarios.h:
#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>
#include <fstream>
#include "Usuarios.h"
#include "MatrizAmistad.h"
#include "PublicacionesU.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

//_______________________________________________________________________________________
class CargaU {
public:
    string nombre;
    string apellido;
    string fechaNacimiento;
    string correo;
    string contrasena;

    CargaU(const string& nombre, const string& apellido, const string& fechaNacimiento, 
           const string& correo, const string& contrasena)
        : nombre(nombre), apellido(apellido), fechaNacimiento(fechaNacimiento), correo(correo), contrasena(contrasena) {}

    string getEmail() const { return correo; }
    string getName() const { return nombre + " " + apellido; }

    void printInfo() const {
        cout << "Nombre: " << nombre << " " << apellido << endl;
        cout << "Correo: " << correo << endl;
        cout << "Fecha de Nacimiento: " << fechaNacimiento << endl;
    }
};

class CargaP {
public:
    string email;
    string content;
    string date;
    string time;

    CargaP(const string& email, const string& content, const std::string& date, const std::string& time)
        : email(email), content(content), date(date), time(time) {}
};
struct Solicitud {
    string emisor;
    string receptor;
    string estado;
    Solicitud* siguiente;
};

//_______________________________________________________________________________________
class SolicitudesU {
public:
    string correo;
    stack<string> solicitudesRecibidas; // Pila para solicitudes recibidas
    list<string> solicitudesEnviadas;   // Lista para solicitudes enviadas
};

// Clase principal para manejar usuarios y solicitudes
class ListaU {  

public:
    struct Node {
        CargaU user;
        Node* next;
        Node* prev;

        Node(const User& user, Node* next = nullptr, Node* prev = nullptr)
            : user(CargaU(user.getFirstName(), user.getLastName(), user.getBirthDate(), user.getEmail(), user.getPassword())), next(next), prev(prev) {}
    };
    ListaU();
    ~ListaU();
    friend void userMenu(ListaU&, const std::string&);

    void registerUser();
    bool login(const string& email, const string& password);
    bool deleteAccount(const string& email, const string& password);
    void addUser(const User& user);
    Node* findUser(const std::string& email);
    
    bool enviarSolicitud(const std::string& remitente, const std::string& destinatario);
    bool rechazarSolicitud(const std::string& remitente, const std::string& destinatario);
    bool aceptarSolicitud(const std::string& remitente, const std::string& destinatario);

    void viewRequests();
    void viewFriends();
    void viewPosts(const std::string& email);
    void createPost(const std::string& email);
    bool deletePost(int postId);

    void loadUsers();
    void loadRelations();
    void loadPosts(PublicacionesU& publicacionesU);
    void manageUsers();
    void generateReports();
    void viewProfile(const string& email);

private:
    
    MatrizAmistad matrizAmistad; 
    vector<SolicitudesU> usuarios; // Vector para almacenar los usuarios con sus solicitudes
    vector<CargaU> users;  // Para almacenar usuarios
    vector<CargaP> postsP; // Para almacenar publicaciones 
    Node* head;
    Node* tail;
    Solicitud* solicitudes;

};


#endif // LISTAUSUARIOS_H