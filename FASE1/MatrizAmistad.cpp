//MatrizAmistad.cpp
#include "MatrizAmistad.h"

MatrizAmistad::MatrizAmistad() {}

MatrizAmistad::~MatrizAmistad() {
    for (auto& fila : filas) {
        delete fila.second;
    }
}

void MatrizAmistad::agregarAmistad(const std::string& nombre1, const std::string& nombre2) {
    if (!esAmigo(nombre1, nombre2)) {
        if (filas.find(nombre1) == filas.end()) {
            filas[nombre1] = new Nodo(nombre1);
        }
        if (columnas.find(nombre2) == columnas.end()) {
            columnas[nombre2] = new Nodo(nombre2);
        }
        filas[nombre1]->amigos[nombre2] = columnas[nombre2];
        columnas[nombre2]->amigos[nombre1] = filas[nombre1];
    }
}

bool MatrizAmistad::esAmigo(const std::string& nombre1, const std::string& nombre2) {
    if (filas.find(nombre1) != filas.end() && filas[nombre1]->amigos.find(nombre2) != filas[nombre1]->amigos.end()) {
        return true;
    }
    return false;
}

bool MatrizAmistad::sonAmigos(const std::string& email1, const std::string& email2) {
    int index1 = getIndex(email1);
    int index2 = getIndex(email2);
    if (index1 == -1 || index2 == -1) {
        return false; // Si alguno de los correos no existe, no son amigos
    }
    return matrizAmistades[index1][index2];
}

int MatrizAmistad::getIndex(const std::string& email) {
    // Implementa la lógica para obtener el índice basado en el email
    // Esto depende de cómo estés manejando los índices en la matriz de amistad
     return 0;
}