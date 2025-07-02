#include "contactos.h"

int main() {
    int n = 0, op, New, x;
    string nom, user, domain, Dom;
    char sex, Mo;
    int edad;
    correo email;
    contactoEmail cont, lista[100];

    do {
        system("cls");
        cout << "Menu de opciones -------------------------" << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Reescribir contacto" << endl;
        cout << "3. Mostrar lista de contactos" << endl;
        cout << "4. Mostrar lista de contactos por dominio" << endl;
        cout << "5. Eliminar un contacto" << endl;
        cout << "0. Salir" << endl;
        cout << "Elige una opcion: "; cin >> op;

        switch(op) {
            case 1:
                cout << "Ingrese los datos de un usuario:" << endl;
                cin.ignore();
                cout << "Nombre: "; getline(cin, nom);
                cout << "Sexo (M/F): "; cin >> sex;
                cout << "Edad: "; cin >> edad;
                cout << "Correo:" << endl;
                cout << "\tUsuario: "; cin >> user;
                cout << "\tDominio: "; cin >> domain;

                leerCorreo(email, user, domain);
                leerContacto(cont, nom, sex, edad, email);
                lista[n++] = cont;
                system("pause");
                break;

            case 2:
                cout << "Numero de contacto a modificar: ";
                cin >> New;
                cin.ignore();
                cout << "Nuevo nombre: "; getline(cin, lista[New-1].nom);
                cout << "Nuevo sexo: "; cin >> lista[New-1].sex;
                cout << "Nueva edad: "; cin >> lista[New-1].edad;
                cout << "Nuevo correo:" << endl;
                cout << "\tUsuario: "; cin >> lista[New-1].email.user;
                cout << "\tDominio: "; cin >> lista[New-1].email.domain;
                system("pause");
                break;

            case 3:
                for(int i = 0; i < n; i++) {
                    cout << "Contacto #" << i+1 << endl;
                    imprimeContacto(lista[i]);
                    cout << endl;
                }
                system("pause");
                break;

            case 4:
                x = 0;
                cout << "Dominio a filtrar: "; cin >> Dom;
                for(int i = 0; i < n; i++) {
                    if(lista[i].email.domain == Dom) {
                        cout << "---------------------------" << endl;
                        imprimeContacto(lista[i]);
                        x++;
                    }
                }
                if(x == 0)
                    cout << "No se encontraron resultados." << endl;
                else
                    cout << "Se encontraron (" << x << ") contactos." << endl;
                system("pause");
                break;

            case 5:
                int Pos;
                cout << "¿Qué contacto desea eliminar?" << endl;
                for(int i = 0; i < n; i++) {
                    cout << "Contacto #" << i+1 << " "; imprimeContacto(lista[i]);
                }
                cout << "Ingrese el número: "; cin >> Pos;
                for(int i = Pos - 1; i < n - 1; i++) {
                    lista[i] = lista[i+1];
                }
                n--;
                break;

            case 0:
                cout << "¿Está seguro de salir? (S/N): ";
                cin >> Mo;
                if (Mo == 'S') {
                    cout << "Sigamos" << endl;
                    op = -1;
                    system("pause");
                } else {
                    cout << "Registro de contactos cerrado." << endl;
                }
                break;

            default:
                cout << "Opcion no valida!" << endl;
                op = -1;
                system("pause");
        }

    } while(op != 0);

    return 0;
}