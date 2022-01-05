//Autora: Mónica Alfaro Parrales. 

#include <cstdlib>
#include <iostream>

using namespace std;

struct Cliente{
    string nombre;
    double salario;
    int cantidadHijos;
    int edad;
    double deuda;

    Cliente(){
        nombre="";
        salario=0.0;
        cantidadHijos=0;
        edad=0;
        deuda=0.0;
    }

    Cliente(string nom, double sal, int canthi, int ed, double deu){
        nombre=nom;
        salario=sal;
        cantidadHijos=canthi;
        edad=ed;
        deuda=deu;
    } 

    void imprimir(){
        cout<<"El cliente de nombre: "<<nombre<<". Salario: "<<salario<<". Cantidad de hijos: "<<cantidadHijos<<
        ". Edad: "<<edad<<". Deuda: "<<deuda<<endl;  
    }
};

struct Empresa{
    string nombre;
    int cantidadClientes=0;
    Cliente cartera[100];

    Empresa(){
        nombre="";
    }

    Empresa(string nom){
        nombre=nom;
    }

    void agregarCliente(Cliente *cliente1){
        cartera[cantidadClientes]= *cliente1;
        cantidadClientes++;
    }

    void imprimirEmpresa(){
        cout<<"Empresa de nombre: "<<nombre<<", con sus clientes: "<<endl;
        if(cantidadClientes==0){
            cout<<"Lamentablemente no hay clientes."<<endl;
        }else
            for (int i=0; i<cantidadClientes; i++){
                cartera[i].imprimir();
            }
    }

    void modificarDeuda(double cambio){
        if(cambio>0){
            cout<<"Clientes con deuda modificada por "<<cambio<<": "<<endl;
            for (int i=0; i<cantidadClientes; i++){
                cartera[i].deuda*=cambio;
                cartera[i].imprimir();
            }
        }else
            cout<<"No es posible modificar una deuda por un número menor o igual a 0."<<endl;
    }

    Cliente *buscarCliente(string nombreClient){
        for (int i=0; i<cantidadClientes; i++){
            if(cartera[i].nombre==nombreClient){
                cout<<"El cliente fue encontrado: "<<endl;
                return &cartera[i];
            }
        }
    cout<<"El cliente no fue encontrado."<<endl;
    return NULL;
    }
        
};

int main(int argc, char *argv[])
{
    //Crear empresa:
     Empresa *emp= new Empresa("IBM");

     //Crear 10 clientes distintos:
     Cliente *client1= new Cliente("Juan Perez", 200000.0, 2, 47, 3000.0);
     Cliente *client2= new Cliente("Valeria Garcia", 500000.0, 1, 57, 36000.0);
     Cliente *client3= new Cliente("Monica Alfaro", 600000.0, 0, 34, 78000.0);
     Cliente *client4= new Cliente("Gilberth Rodriguez", 600000.0, 3, 43, 450000.0);
     Cliente *client5= new Cliente("Jorge Hernandez", 500000.0, 2, 36, 100000.0);
     Cliente *client6= new Cliente("Pablo Ramirez", 51000.0, 1, 33, 44500.0);
     Cliente *client7= new Cliente("Allan Alfaro", 250000.0, 2, 64, 0.0);
     Cliente *client8= new Cliente("Patricia Parrales", 300000.0, 2, 61, 100000.0);
     Cliente *client9= new Cliente("Marcela Valencia", 340000.0, 0, 43, 567000.0);
     Cliente *client10= new Cliente("Lucy Mendez", 90000.0, 5, 56, 450000.0);

    //Agregar 10 clientes a la empresa:
     emp->agregarCliente(client1);
     emp->agregarCliente(client2);
     emp->agregarCliente(client3);
     emp->agregarCliente(client4);
     emp->agregarCliente(client5);
     emp->agregarCliente(client6);
     emp->agregarCliente(client7);
     emp->agregarCliente(client8);
     emp->agregarCliente(client9);
     emp->agregarCliente(client10);

    //Métodos:

    //Imprimir empresa:
     emp->imprimirEmpresa();
     cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
     //Modificar deudas:
     emp->modificarDeuda(0.95);
     cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
     emp->modificarDeuda(1.95);
     cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
     emp->modificarDeuda(0.0);
     cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
     //Buscar clientes:
     Cliente *b=emp->buscarCliente("Monica Alfaro");
     if(b!=NULL){
         b->imprimir();
     }
     cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
     Cliente *c=emp->buscarCliente("Mireya Araya");
     if(c!=NULL){
         c->imprimir();
     }
     cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}