#ifndef USUARIOS_H
#define USUARIOS_H

#include <string>
#include <iostream>
#include <string>

using namespace std;

class User {
public:
    User(const string& firstName,
         const string& lastName,
         const string& birthDate,
         const string& email,
         const string& password);

    // Getters
    string getFirstName() const;
    string getLastName()  const;
    string getBirthDate() const;
    string getEmail()     const;
    string getPassword()  const;

    // Setters
    void setFirstName(const string& firstName);
    void setLastName(const   string& lastName);
    void setBirthDate(const string& birthDate);
    void setEmail(const string& email);
    void setPassword(const string& password);

private:
    string firstName;
    string lastName;
    string birthDate;
    string email;
    string password;
};

#endif // USUARIOS_H
