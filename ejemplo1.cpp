#include <iostream>
#include <string>
using namespace std; 

struct EMP{
    int num; 
    string nom;
    float ven[12];
	float sal; 
    float S_Ven;
};

int main(){
    EMP EMPLEADOS[100];
    int n; 
    cout<<"Ingrese la cantidad de Trabajadores: ";
    cin>>n;
    for(int i=0; i<n;i++){
        cout<<"Ingrese el numero de vendedor: ";
        cin>>EMPLEADOS[i].num; 
        cout<<"Ingrese el nombre del verndedor: ";
        cin>>EMPLEADOS[i].nom;
        cout<<"Cantidad de ventas: "<<endl; 
        EMPLEADOS[i].S_Ven = 0;
        for(int j=0; j<12;j++){
            cout<<"Mes "<<j+1<<" : ";
            cin>>EMPLEADOS[i].ven[j];
            EMPLEADOS[i].S_Ven=EMPLEADOS[i].S_Ven + EMPLEADOS[i].ven[j];
            
        
        }
        cout<<"Ingrese el salario: "; 
        cin>>EMPLEADOS[i].sal;
        
        int Nu_sal;
        if(EMPLEADOS[i].S_Ven>100){
            Nu_sal=EMPLEADOS[i].sal+(EMPLEADOS[i].sal*0.10);
            cout<<"El empleado N: "<<EMPLEADOS[i].num<<endl;
            cout<<"------por superar el 100 unidades de ventas------"<<endl; 
            cout<<"su salario incremento a: "<<Nu_sal<<endl;
        }
        else{
            cout<<"No supero las 100 unidades de ventas"<<endl;
        }   
    }
    int Val=0;
        float NV_Max=EMPLEADOS[0].S_Ven; 
        for(int i=1; i<n;i++){
            if(EMPLEADOS[i].S_Ven>NV_Max){
                NV_Max=EMPLEADOS[i].S_Ven;
                Val=i; 
            }
        }
    cout<<"---------ENTONCES EL EMPLEADO CON MAYOR VENTAS ANUALES---------"<<endl;
    cout<<"El empleado N: "<<EMPLEADOS[Val].num<<endl; 
    cout<<"De Nombre: "<<EMPLEADOS[Val].nom<<endl; 
    cout<<"Tuvo anualmente un total de "<<EMPLEADOS[Val].S_Ven<<" Ventas anuales"<<endl; 
    return 0; 
}
