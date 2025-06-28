#include<iostream>
using namespace std;

struct correo{
    string user;
    string domain;
};

struct contactoEmail{
    string nom;
    char sex;
    int edad;
    correo email;
};

void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);

int main(){
    int n, op,New,x;
    string nom, user, domain,Dom;
    char sex,Mo;
    int edad;
    correo email;
    contactoEmail cont, lista[100];
    n = 0;
    do{
        system("cls");
        cout<<"Menu de opciones -------------------------"<<endl;
        cout<<"1. Agregar contacto"<<endl;
        cout<<"2. Reescribir contacto"<<endl;
        cout<<"3. Mostrar lista de contactos"<<endl;  
        cout<<"4. Mostrar lista de contactos por dominio"<<endl; 
        cout<<"5. Eliminar un contacto"<<endl; 
        cout<<"0. Salir"<<endl;
        cout<<"Elige una opcion: "; cin>>op;
        switch(op){
            case 1:
                cout<<"Ingrese los datos de un usuario: "<<endl;
                cin.ignore();
                cout<<"Ingrese el nombre del contacto: "; getline(cin,nom);
                cout<<"Ingrese el sexo (M/F): "; cin>>sex;
                cout<<"Ingrese la edad: "; cin>>edad;
                cout<<"Ingrese el correo electronico (usuario@dominio): "<<endl;
                cout<<"\tIngrese el usuario: "; cin>>user;
                cout<<"\tIngrese el dominio: "; cin>>domain;
                
                leerCorreo(email,user,domain);
                leerContacto(cont,nom,sex,edad,email);
                //imprimeContacto(cont);

                lista[n] = cont;
                n++;
                system("pause");
                break;
            case 2:
                cout<<"Ingrese el Numero que decea Modificar: ";
                cin>>New;
                cout<<"Ingrese el Nuevo nombre del contacto: "; 
                cin.ignore();
                getline(cin,lista[New-1].nom);
                cout<<"Ingrese el Nuevo sexo (M/F): ";cin>>lista[New-1].sex;
                cout<<"Ingrese la Nueva edad: ";cin>>lista[New-1].edad;
                cout<<"Ingrese el Nuevo correo electronico(usuario@dominio): "<<endl; 
                cout<<"\tIngrese el Nuevo usuario: ";cin>>lista[New-1].email.user;
                cout<<"\tIngrese el Nuevo dominio: ";cin>>lista[New-1].email.domain; 
                cout<<endl;
                system("pause");
                break;
            case 3:
                for(int i = 0; i < n; i++){
                    cout<<"Contacto #"<<i+1<<endl;
                    imprimeContacto(lista[i]);
                    cout<<endl;
                }
                system("pause");
                break;
            case 4: 
                x=0;
                cout<<"Ingrese el dominio al flitrar: ";
                cin>>Dom; 
                for(int i=0; i<n; i++){
                    if(lista[i].email.domain==Dom){
                        cout<<"---------------------------"<<endl; 
                        imprimeContacto(lista[i]);
                        cout<<endl; 
                        x++;  
                    }   
                }
                if(x==0){
                    cout<<"No se encontraron resultados"<<endl;
                }
                else{
                    cout<<"Se encontraron"<<"("<<x<<")"<<"contactos"<<endl;
                }
                cout<<endl;  
                system("pause");
                break;
            case 5: 
                int Pos; 
                cout<<"¿Que contacto decea eliminar?"<<endl; 
                for(int i = 0; i < n; i++){
                    cout<<"Contacto #"<<i+1<<"   "; imprimeContacto(lista[i]);
                    cout<<endl; 
                }
                cout<<"Ingrese el contacto que decea eleiminar: ";
                cin>>Pos; 
                for(int i=0; i<n; i++){
                    lista[i]=lista[i+1];
                }
                n--;
                break;
            case 0: 
                cout<<"Esta seguro de salir? (S/N): "<<endl; 
                cout<<"S. Seguir"<<endl; 
                cout<<"N. Salir"<<endl; 
                cout<<"Elige un opcion: ";
                cin>>Mo;
                switch(Mo){
                    case 'S':
                    cout<<"Sigamos"<<endl; 
                    system("pause");
                    op=-1;
                    break;

                    case 'N':
                    cout<<"Regitro de contactos cerrado";
                    break;  
                }
                break;
            default:
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                op=-1;
                break;
        }
    } while(op!=0);
    return 0;
}

void leerContacto(contactoEmail &c, string n, char s, int e, correo em){
    c.nom = n;
    c.sex = s;
    c.edad = e;
    c.email = em;
}

void leerCorreo(correo &c, string u, string d){
    c.user = u;
    c.domain = d;
}

void imprimeContacto(contactoEmail &c){
    cout<<"Nombre: "<<c.nom<<endl;
    cout<<"Sexo: "<<c.sex<<endl;
    cout<<"Edad: "<<c.edad<<endl;
    cout<<"Email: "<<c.email.user<<"@"<<c.email.domain<<endl;
}
