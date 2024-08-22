## Explicación del archivo main.cpp

El archivo `main.cpp` utiliza varias inclusiones (`#include`) para traer funcionalidades y declarar dependencias. A continuación se describen las inclusiones utilizadas:

```cpp
#include <iostream> //Permite el uso de las funciones de entrada y salida estándar, como cout y cin.

#include <string> // Proporciona la funcionalidad para manejar cadenas de caracteres (std::string).

#include <locale.h> //Se utiliza para configurar la localización, permitiendo manejar adecuadamente caracteres especiales 

#include "ListaUsuarios.h" //Incluye la definición de la clase ListaU que gestiona la lista de usuarios.

#include "Usuarios.h" //Declara la clase User, que representa a cada usuario individualmente.

#include "PublicacionesU.h" //Declara la clase PublicacionesU, que gestiona las publicaciones de los usuarios.

#include "MatrizAmistad.h" //Declara la clase PublicacionesU, que gestiona las publicaciones de los usuarios.

```


int main() Función Principal
La función main es el punto de entrada del programa y controla el flujo principal de ejecución.

Descripción
ListaU listaUsuarios;: Se instancia la lista de usuarios.
do-while loop: Controla la interfaz principal del programa, permitiendo al usuario seleccionar opciones como iniciar sesión, registrarse, obtener información o salir.
adminMenu y userMenu: Se llaman según el tipo de usuario que inicia sesión.

Función userMenu
La función userMenu controla las opciones disponibles para el usuario normal, tales como la gestión de su perfil, solicitudes de amistad, publicaciones y reportes.

Descripción
Gestión del Perfil: Permite al usuario ver su perfil o eliminar su cuenta.
Gestión de Solicitudes: Ver, aceptar o rechazar solicitudes de amistad.
Gestión de Publicaciones: Ver, crear o eliminar publicaciones.
Generación de Reportes: Permite al usuario generar reportes sobre su actividad.
Función adminMenu
La función adminMenu está diseñada para que el administrador tenga control sobre la gestión de usuarios, relaciones y publicaciones, además de generar reportes.

Descripción
Carga de Datos: Cargar usuarios, relaciones de amistad y publicaciones desde archivos externos.
Gestión de Usuarios: Eliminar usuarios.
Generación de Reportes: Generar reportes sobre el uso del sistema.
