//PublicacionesU.cpp
#include "PublicacionesU.h"
#include <iostream>
#include <string>
#include "ListaUsuarios.h"


using namespace std;

int PublicacionesU::nextPostId = 0;

PublicacionesU::Publicacion::Publicacion(int id, const std::string& email, const std::string& content, const std::string& date, const std::string& time)
    : id(id), email(email), content(content), date(date), time(time), next(nullptr), prev(nullptr) {}

PublicacionesU::PublicacionesU() : head(nullptr), tail(nullptr) {}

PublicacionesU::~PublicacionesU() {
    Publicacion* current = head;
    while (current != nullptr) {
        Publicacion* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

void PublicacionesU::addPost(const string& email, const string& content, const string& date, const string& time) {
    Publicacion* newPost = new Publicacion(nextPostId++, email, content, date, time);

    if (!head) {
        head = tail = newPost;
    } else {
        tail->next = newPost;
        newPost->prev = tail;
        tail = newPost;
    }

    cout << "Publicacion agregada con exito.\n";
    // Mensaje de depuración
    cout << "Publicacion agregada: ID=" << newPost->id << ", Contenido=" << newPost->content << "\n";
}

void PublicacionesU::createPost(const std::string& email) {
    string content, date, time;
    
    cout << "Contenido: ";
    getline(cin, content);
    cout << "Fecha (YYYY/MM/DD): ";
    getline(cin, date);
    cout << "Hora (HH:MM): ";
    getline(cin, time);

    // Usa la función addPost para agregar la publicación
    addPost(email, content, date, time);
}

void PublicacionesU::viewPosts(const std::string& email, MatrizAmistad& matrizAmistad) {
    if (head == nullptr) { 
        cout << "No hay publicaciones disponibles.\n";
        return;
    }

    Publicacion* current = head;
    bool hasPosts = false;

    while (current != nullptr) {
        // Mensaje de depuración
        cout << "Revisando publicación con ID: " << current->id << "\n";
        
        if (email == current->email || matrizAmistad.sonAmigos(email, current->email)) {
            cout << "ID: " << current->id << "\n"
                 << "Correo: " << current->email << "\n"
                 << "Contenido: " << current->content << "\n"
                 << "Fecha: " << current->date << "\n"
                 << "Hora: " << current->time << "\n\n";
            hasPosts = true;
        }
        current = current->next;
    }

    if (!hasPosts) {
        cout << "No hay publicaciones disponibles para mostrar.\n";
    }

    cout << "Presiona enter para continuar...\n";
    cin.get();
}


bool PublicacionesU::deletePost(int postId) {
    Publicacion* current = head;

    while (current != nullptr) {
        if (current->id == postId) {
            if (current == head) {
                head = head->next;
                if (head) head->prev = nullptr;
            } else if (current == tail) {
                tail = tail->prev;
                if (tail) tail->next = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            cout << "Publicacion eliminada con exito.\n";
            return true;
        }
        current = current->next;
    }

    cout << "No se encontro la publicación con el ID dado.\n";
    return false;
}
