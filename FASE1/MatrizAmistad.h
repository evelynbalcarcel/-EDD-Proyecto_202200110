//MareizAmistad.h
#ifndef MATRIZAMISTAD_H
#define MATRIZAMISTAD_H

#include <string>
#include <unordered_map>
#include <vector>

class MatrizAmistad {
private:

    int getIndex(const std::string& email);
    struct Nodo {
        std::string nombre;
        std::unordered_map<std::string, Nodo*> amigos; // Nodos conectados
        Nodo(const std::string& nombre) : nombre(nombre) {}
    };

    std::unordered_map<std::string, Nodo*> filas; // Nombres en filas
    std::unordered_map<std::string, Nodo*> columnas; // Nombres en columnas
    std::vector<std::vector<bool>> matrizAmistades; 
public:
    MatrizAmistad();
    ~MatrizAmistad();

    void agregarAmistad(const std::string& nombre1, const std::string& nombre2);
    bool esAmigo(const std::string& nombre1, const std::string& nombre2);
    bool sonAmigos(const std::string& email1, const std::string& email2);

};

#endif // MATRIZAMISTAD_H
