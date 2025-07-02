#ifndef CONTACTO_H
#define CONTACTO_H

#include <iostream>
#include <string>
using namespace std;

// Estructuras
struct correo {
    string user;
    string domain;
};

struct contactoEmail {
    string nom;
    char sex;
    int edad;
    correo email;
};

// Prototipos de funciones
void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);

#endif