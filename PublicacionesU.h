
#ifndef PUBLICACIONESU_H
#define PUBLICACIONESU_H

#include <iostream>
#include <string> // Incluye la biblioteca de cadenas
#include "PublicacionesU.h"  // Incluye el archivo de publicaciones si es necesario

class PublicacionesU {
private:
    class Publicacion {
    public:
        int id;
        std::string email;
        std::string content;
        std::string date;
        std::string time;
        Publicacion* next; // Puntero para la lista enlazada

        Publicacion(int id, const std::string& email, const std::string& content, const std::string& date, const std::string& time);
    };

    static Publicacion* posts; // Puntero a la lista de publicaciones
    static int nextPostId; // Variable para el siguiente ID de publicación

public:
    static void viewPosts();  //ver publicaciones 
    static void createPost(const std::string& email); // Crear publicación
    static bool deletePost(int postId); // Eliminar publicación
};

#endif // PUBLICACIONESU_H
