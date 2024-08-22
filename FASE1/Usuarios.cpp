#include "Usuarios.h"
#include <iostream>

User::User(const std::string& firstName, const std::string& lastName, const std::string& birthDate, const std::string& email, const std::string& password)
    : firstName(firstName), lastName(lastName), birthDate(birthDate), email(email), password(password) {}

std::string User::getEmail() const {
    return email;
}

std::string User::getPassword() const {
    return password;
}

std::string User::getFirstName() const {
    return firstName;
}

std::string User::getLastName() const {
    return lastName;
}
std::string User::getBirthDate() const {
    return this->birthDate; // Suponiendo que 'birthDate' es un atributo de tipo 'std::string'
}

void User::printInfo() const {
    std::cout << "Nombre: " << firstName << " " << lastName << std::endl;
    std::cout << "Fecha de nacimiento: " << birthDate << std::endl;
    std::cout << "Correo electronico: " << email << std::endl;
}
