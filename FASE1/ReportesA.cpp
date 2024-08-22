#include "ReportesA.h"
#include "ListaUsuarios.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <nlohmann/json.hpp>
#include "PublicacionesU.h"
using namespace std;

static void writeGraphToFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo para escribir: " << filename << endl;
        return;
    }
    file << content;
    file.close();
}

void ReportesA::generateUserReport(const ListaU& listaUsuarios) {
    std::ofstream file("usuarios.dot");
    if (!file.is_open()) {
        std::cerr << "Error al crear el archivo de reporte de usuarios.\n";
        return;
    }

    file << "digraph G {\n";
    file << "    node [shape=rectangle];\n";

    // Agregar nodos para cada usuario
    //for (const auto& user : listaUsuarios.users) {
    //    file << "    \"" << user.getEmail() << "\" [label=\"" << user.getName() << "\"];\n";
    //}

    // Agregar relaciones de amistad
    // Implementa esto según cómo estés gestionando las amistades en tu matriz
    // Ejemplo:
    // for (int i = 0; i < listaUsuarios.users.size(); ++i) {
    //     for (int j = i + 1; j < listaUsuarios.users.size(); ++j) {
    //         if (listaUsuarios.matrizAmistad[i][j]) {
    //             file << "    \"" << listaUsuarios.users[i].getEmail() << "\" -- \"" << listaUsuarios.users[j].getEmail() << "\";\n";
    //         }
    //     }
    // }

    //file << "}\n";
    //ile.close();
}

