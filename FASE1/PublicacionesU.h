//PublicacionesU.h
#ifndef PUBLICACIONESU_H
#define PUBLICACIONESU_H
#include <iostream>
#include <string> // Incluye la biblioteca de cadenas
#include <vector> 
#include "MatrizAmistad.h" // Incluir la clase para verificar las amistades

using namespace std;

class PublicacionesU {
public:

    class Publicacion {
    public:
        Publicacion(int id, const std::string& email, const std::string& content, const std::string& date, const std::string& time);
    
        int id;
        string email;
        string content;
        string date;
        string time;      
        Publicacion* next; // Puntero para la lista enlazada
        Publicacion* prev;  // Puntero para la lista doblemente enlazada
    private:
        friend class PublicacionesU;
    };

    
    static int nextPostId; // Variable para el siguiente ID de publicación
    static Publicacion* posts;       

public:
    Publicacion* head; // Puntero a la cabeza de la lista doblemente enlazada
    Publicacion* tail; // Puntero a la cola de la lista doblemente enlazada

    PublicacionesU();
    ~PublicacionesU();

    void addPost(const string& email, const string& content, const string& date, const string& time);
    void viewPosts(const string& email, MatrizAmistad& matrizAmistad); // Mostrar publicaciones considerando la matriz de amistad
    bool deletePost(int postId);
    void createPost(const std::string& email);

};

#endif // PUBLICACIONESU_H
