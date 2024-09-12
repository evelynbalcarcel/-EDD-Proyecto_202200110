#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H

#include <iostream>
#include <vector>
#include <string>
#include "Usuarios.h"

using namespace std;

class ListaU
{
public:
    ListaU(); // Constructor

/*
    struct Node {
        User user;
        Node* next;
    };
*/
    struct AVLNode {
        User user;
        AVLNode* left;
        AVLNode* right;
        int height;
    };

    AVLNode* root;  // Raíz del árbol AVL
    AVLNode* findUser(const std::string& email);

    // Métodos principales
    void registerUser();
    bool login(const std::string& email, const std::string& password);
    //bool deleteAccount(const std::string& email, const std::string& password);
    AVLNode* deleteNode(AVLNode* root, const std::string& email);
    void addUser(const User& user);

    void jsonUsuaios(string text);

    // Setters
    void setFirstName(const std::string& firstName) { this->firstName = firstName; }
    void setLastName(const std::string& lastName) { this->lastName = lastName; }
    void setEmail(const std::string& email) { this->email = email; }
    void setPassword(const std::string& password) { this->password = password; }
    void setBirthDate(const std::string& birthDate) { this->birthDate = birthDate; }

    // Getters
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getEmail() const { return email; }
    std::string getPassword() const { return password; }
    std::string getBirthDate() const { return birthDate; }

private:
    // Métodos AVL
    int getHeight(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* insert(AVLNode* node, const User& user);
    AVLNode* minValueNode(AVLNode* node);
    //AVLNode* deleteNode(AVLNode* root, const std::string& email);

    std::string firstName;
    std::string lastName;
    std::string email;
    std::string password;
    std::string birthDate;
};

#endif // LISTAUSUARIOS_H
