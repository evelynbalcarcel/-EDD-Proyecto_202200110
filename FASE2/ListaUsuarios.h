#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H

#include <iostream>
#include <vector>
#include <string>
#include "Usuarios.h"

class ListaU
{
public:
    ListaU(); // Constructor

    struct Node {
        User user;
        Node* next;
    };

    Node* head; // Cabeza de la lista enlazada de usuarios
    Node* findUser(const std::string& email);

    // Métodos principales
    void registerUser();
    bool login(const std::string& email, const std::string& password);
    bool deleteAccount(const std::string& email, const std::string& password);
    void addUser(const User& user);

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
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string password;
    std::string birthDate;
};

#endif // LISTAUSUARIOS_H
