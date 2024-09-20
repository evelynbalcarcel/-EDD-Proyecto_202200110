#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <list>
#include <algorithm>
#include <fstream>
#include "Usuarios.h"
#include "Solicitudes.h"

using namespace std;

class ListaU
{
public:
    ListaU(); // Constructor

    Solicitud* solicitudesU;  // Lista enlazada de solicitudes

//--------- Nodo de comentario ---------
    struct Comentario {
        string correo;
        string comentario;
        string fecha;
        string hora;
        Comentario* siguiente;
    };


//-------- Nodo de publicacion --------
    struct Publicacion {
        string correo;
        string contenido;
        string fecha;
        string hora;
        Comentario* comentarios; // Lista de comentarios
        Publicacion* siguiente;
    };
/*
    struct Node {
        User user;
        Node* next;
    };
*/
//------- Nodo para el arbol AVL -------
    struct AVLNode {
        User user;
        AVLNode* left;
        AVLNode* right;
        int height;
    };

    AVLNode* root;  // Raíz del árbol AVL
    AVLNode* findUser(const string& email);

    // Métodos principales
    void registerUser();
    bool login(const string& email, const string& password);
    //bool deleteAccount(const std::string& email, const std::string& password);
    AVLNode* deleteNode(AVLNode* root, const string& email);
    void addUser(const User& user);
    bool enviarSolicitud(const   string& emisor,   const string& receptor);
    bool cancelarSolicitud(const string& receptor, const string& emisor);


    void jsonUsuaios(string text);
    void jsonSolicitudes(string text);
    void jsonPublicaciones(string text);

    // Setters
    void setFirstName(const string& firstName) { this->firstName = firstName; }
    void setLastName( const string& lastName)  { this->lastName = lastName; }
    void setEmail(    const string& email)     { this->email = email; }
    void setPassword( const string& password)  { this->password = password; }
    void setBirthDate(const string& birthDate) { this->birthDate = birthDate; }

    // Getters
    string getFirstName() const { return firstName; }
    string getLastName()  const { return lastName; }
    string getEmail()     const { return email; }
    string getPassword()  const { return password; }
    string getBirthDate() const { return birthDate; }


    // Método para obtener las solicitudes de un usuario por su email
    SolicitudesU* getSolicitudesU(const std::string& correo) {
        for (auto& usuario : usuarios) {
            if (usuario.correo == correo) {
                return &usuario;
            }
        }
        return nullptr; // Retorna nullptr si no encuentra al usuario
    }

private:
    // Métodos AVL
    int getHeight(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* insert(AVLNode* node, const User& user);
    AVLNode* minValueNode(AVLNode* node);
    //AVLNode* deleteNode(AVLNode* root, const std::string& email);

    string firstName;
    string lastName;
    string email;
    string password;
    string birthDate;

    Publicacion* publicaciones; // Lista de publicaciones
    vector<SolicitudesU> usuarios; // Vector para almacenar los usuarios con sus solicitudes
};

#endif // LISTAUSUARIOS_H
