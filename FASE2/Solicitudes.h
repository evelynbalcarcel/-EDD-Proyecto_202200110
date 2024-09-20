#ifndef SOLICITUDES_H
#define SOLICITUDES_H

#include <iostream>
#include <stack>
#include <list>
#include <string>

using namespace std;

class SolicitudesU {
public:
    string correo;
    stack<string> solicitudesRecibidas; // Pila para solicitudes recibidas
    list<string> solicitudesEnviadas;   // Lista para solicitudes enviadas

    // Método para obtener las solicitudes recibidas
    const stack<string>& getSolicitudesRecibidas() const {
        return solicitudesRecibidas;
    }

    // Método para obtener las solicitudes enviadas
    const list<string>& getSolicitudesEnviadas() const {
        return solicitudesEnviadas;
    }
};

class Solicitud {
public:
    string emisor;
    string receptor;
    string estado;
    Solicitud* siguiente;
};

#endif // SOLICITUDES_H
