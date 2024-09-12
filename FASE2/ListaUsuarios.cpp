#include "ListaUsuarios.h"
#include "Usuarios.h"
#include "mainusuarios.h"
#include "MainPrincipal.h"
#include <QDebug>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

using namespace std;

// Constructor
ListaU::ListaU() : root(nullptr) {}

// Obtener la altura del nodo
int ListaU::getHeight(AVLNode* node) {
    if (node == nullptr) return 0;
    return node->height;
}

// Obtener el balance del nodo
int ListaU::getBalance(AVLNode* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Rotación a la derecha
ListaU::AVLNode* ListaU::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Rotación a la izquierda
ListaU::AVLNode* ListaU::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Insertar un nuevo usuario en el árbol AVL
ListaU::AVLNode* ListaU::insert(AVLNode* node, const User& user) {
    if (node == nullptr) {
        return new AVLNode{user, nullptr, nullptr, 1};
    }

    // Insertar según el correo alfabéticamente
    if (user.getEmail() < node->user.getEmail()) {
        node->left = insert(node->left, user);
    } else if (user.getEmail() > node->user.getEmail()) {
        node->right = insert(node->right, user);
    } else {
        return node; // No permitir usuarios con el mismo correo
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int balance = getBalance(node);

    // Rotaciones para balancear
    if (balance > 1 && user.getEmail() < node->left->user.getEmail()) {
        return rotateRight(node);
    }

    if (balance < -1 && user.getEmail() > node->right->user.getEmail()) {
        return rotateLeft(node);
    }

    if (balance > 1 && user.getEmail() > node->left->user.getEmail()) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && user.getEmail() < node->right->user.getEmail()) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Método para registrar un nuevo usuario
void ListaU::registerUser() {
    string firstName, lastName, email, password, birthDate;

    cout << "Nombres: ";
    getline(cin, firstName);
    cout << "Apellidos: ";
    getline(cin, lastName);
    cout << "Fecha de nacimiento: ";
    getline(cin, birthDate);
    cout << "Correo electronico: ";
    getline(cin, email);

    if (findUser(email)) {
        cout << "El correo ya esta registrado.\n";
        return;
    }

    cout << "Contrasena: ";
    getline(cin, password);

    // Crear un nuevo usuario y agregarlo a la lista
    User newUser(firstName, lastName, birthDate, email, password);
    addUser(newUser);
    cout << "Usuario registrado exitosamente.\n";
}

// Método para iniciar sesión
bool ListaU::login(const std::string& email, const std::string& password) {
    AVLNode* userAVLNode = findUser(email);
    if (userAVLNode && userAVLNode->user.getPassword() == password) {
        return true; // Inicio de sesión exitoso
    }
    return false; // Usuario o contraseña incorrectos
}

/*
// Método para eliminar una cuenta
bool ListaU::deleteAccount(const std::string& email, const std::string& password) {
    Node** current = &head;

    while (*current) {
        if ((*current)->user.getEmail() == email && (*current)->user.getPassword() == password) {
            Node* temp = *current;
            *current = (*current)->next;
            delete temp;
            return true; // Cuenta eliminada con éxito
        }
        current = &((*current)->next);
    }

    return false; // Cuenta no encontrada
    }
*/

ListaU::AVLNode* ListaU::deleteNode(AVLNode* root, const std::string& email) {
    // Paso 1: Realizar la eliminación estándar de un árbol binario de búsqueda
    if (root == nullptr)
        return root; // El nodo no existe

    // Buscar el nodo que se va a eliminar
    if (email < root->user.getEmail()) {
        root->left = deleteNode(root->left, email);
    } else if (email > root->user.getEmail()) {
        root->right = deleteNode(root->right, email);
    } else {
        // El nodo a eliminar es el actual
        if ((root->left == nullptr) || (root->right == nullptr)) {
            AVLNode* temp = root->left ? root->left : root->right;

            // Nodo sin hijos o con un hijo
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                // Nodo con un hijo
                *root = *temp;
            }
            delete temp;
        } else {
            // Nodo con dos hijos
            AVLNode* temp = minValueNode(root->right);
            root->user = temp->user;
            root->right = deleteNode(root->right, temp->user.getEmail());
        }
    }

    // Si solo tenía un nodo y se eliminó
    if (root == nullptr)
        return root;

    // Paso 2: Actualizar la altura del nodo actual
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Paso 3: Obtener el factor de balance del nodo actual
    int balance = getBalance(root);

    // Paso 4: Balancear el árbol AVL si está desbalanceado

    // Caso Izquierda Izquierda
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    // Caso Izquierda Derecha
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Caso Derecha Derecha
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    // Caso Derecha Izquierda
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Encuentra el nodo con el valor más pequeño en el subárbol (usado para la eliminación de nodos con dos hijos)
ListaU::AVLNode* ListaU::minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

/*
// Método para agregar un usuario a la lista
void ListaU::addUser(const User& user) {
    Node* newNode = new Node{user, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}
*/

// Agregar un usuario
void ListaU::addUser(const User& user) {
    root = insert(root, user);
}

/*
// Método para buscar un usuario en la lista por su email
ListaU::Node* ListaU::findUser(const std::string& email) {
    Node* current = head;
    while (current) {
        if (current->user.getEmail() == email) {
            return current;
        }
        current = current->next;
    }
    return nullptr;  // Usuario no encontrado
}
*/

// Buscar un usuario por correo
ListaU::AVLNode* ListaU::findUser(const std::string& email) {
    AVLNode* current = root;
    while (current != nullptr) {
        if (email == current->user.getEmail()) {
            return current;
        } else if (email < current->user.getEmail()) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr;  // Usuario no encontrado
}

// Carga de usuarios desde JSON
void ListaU::jsonUsuaios(string text) {
    // Convierte el string en un objeto JSON
    json jsonObj = json::parse(text);

    for (const auto& usuarioData : jsonObj) {
        if (usuarioData.contains("nombres") &&
            usuarioData.contains("apellidos") &&
            usuarioData.contains("fecha_de_nacimiento") &&
            usuarioData.contains("correo") &&
            usuarioData.contains("contrasena")) {

            User newUser(usuarioData["nombres"],
                         usuarioData["apellidos"],
                         usuarioData["fecha_de_nacimiento"],
                         usuarioData["correo"],
                         usuarioData["contrasena"]);

            addUser(newUser);
        }
    }

    qDebug() << "Usuarios cargados exitosamente.";
}

