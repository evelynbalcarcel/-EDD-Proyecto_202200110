#ifndef USUARIOS_H
#define USUARIOS_H

#include <string>
#include <iostream>

class User {
public:
    User(const std::string& firstName, 
         const std::string& lastName, 
         const std::string& birthDate, 
         const std::string& email, 
         const std::string& password);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getBirthDate() const;
    std::string getEmail() const;
    std::string getPassword() const;

    void printInfo() const;

private:
    std::string firstName;
    std::string lastName;
    std::string birthDate;
    std::string email;
    std::string password;
};

#endif // USUARIOS_H
