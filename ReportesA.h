#ifndef REPORTESA_H
#define REPORTESA_H

#include <string>
#include <vector>
#include "ListaUsuarios.h"
#include "PublicacionesU.h"

class ReportesA {
public:
    static void generateUserReport(const ListaU& listaUsuarios);
    static void generatePostsReport(const ListaU& listaUsuarios);
};

#endif // REPORTESA_H
