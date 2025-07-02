#include "contactos.h"

// Implementación de funciones
void leerCorreo(correo &c, string u, string d) {
    c.user = u;
    c.domain = d;
}

void leerContacto(contactoEmail &c, string n, char s, int e, correo em) {
    c.nom = n;
    c.sex = s;
    c.edad = e;
    c.email = em;
}

void imprimeContacto(contactoEmail &c) {
    cout << "Nombre: " << c.nom << endl;
    cout << "Sexo: " << c.sex << endl;
    cout << "Edad: " << c.edad << endl;
    cout << "Email: " << c.email.user << "@" << c.email.domain << endl;
}