#include "Usuarios.h"
#include "ListaUsuarios.h"

using namespace std;

User::User(const string& firstName,
           const string& lastName,
           const string& birthDate,
           const string& email,
           const string& password)
    : firstName(firstName), lastName(lastName), birthDate(birthDate), email(email), password(password) {
    solicitudesU = new SolicitudesU(); // Inicializar SolicitudesU
}

SolicitudesU* User::getSolicitudesU() const {
    return solicitudesU;  // Devolver la instancia de SolicitudesU
}

// Getters
std::string User::getFirstName() const {
    return firstName;
}

std::string User::getLastName() const {
    return lastName;
}

std::string User::getBirthDate() const {
    return birthDate;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getPassword() const {
    return password;
}

// Setters
void User::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void User::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void User::setBirthDate(const std::string& birthDate) {
    this->birthDate = birthDate;
}

void User::setEmail(const std::string& email) {
    this->email = email;
}

void User::setPassword(const std::string& password) {
    this->password = password;
}

