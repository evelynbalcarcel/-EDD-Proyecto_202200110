#include "PublicacionesU.h"
#include <iostream>
#include <string>

using namespace std;

// Inicialización de variables estáticas
PublicacionesU::Publicacion* PublicacionesU::posts = nullptr;
int PublicacionesU::nextPostId = 0;

PublicacionesU::Publicacion::Publicacion(int id, const std::string& email, const std::string& content, const std::string& date, const std::string& time)
    : id(id), email(email), content(content), date(date), time(time), next(nullptr) {}

void PublicacionesU::viewPosts() {
    if (posts == nullptr) {
        cout << "No hay publicaciones disponibles.\n";
        return;
    }

    Publicacion* temp = posts;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << ", Email: " << temp->email << ", Contenido: " << temp->content
             << ", Fecha: " << temp->date << ", Hora: " << temp->time << endl;
        temp = temp->next;
    }
}

void PublicacionesU::createPost(const std::string& email) {
    string content, date, time;
    cout << "Contenido: ";
    getline(cin, content);
    cout << "Fecha (YYYY-MM-DD): ";
    getline(cin, date);
    cout << "Hora (HH:MM): ";
    getline(cin, time);

    Publicacion* newPost = new Publicacion(nextPostId++, email, content, date, time);
    newPost->next = posts;
    posts = newPost;
    cout << "Publicación creada con éxito.\n";
}

bool PublicacionesU::deletePost(int postId) {
    Publicacion* current = posts;
    Publicacion* previous = nullptr;

    while (current != nullptr) {
        if (current->id == postId) {
            if (previous == nullptr) {
                posts = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            cout << "Publicación eliminada con éxito.\n";
            return true;
        }
        previous = current;
        current = current->next;
    }
    cout << "No se encontró la publicación con el ID dado.\n";
    return false;
}
