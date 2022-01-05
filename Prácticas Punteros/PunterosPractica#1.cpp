#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout<<"Parte 1:"<<endl;
    int *r=NULL;
    int q=12;
    //int w=NULL; Error 1: No se debe asignar NULL a un entero.

    if(r==NULL)
        cout<<"Valor inicial de r: "<<r<<endl; //Realmente es NULL.
    cout<<"Valor inicial de q: "<<q<<endl;

    float *s;
    float *y;
    float x;

    //cout<<x<<endl; Valor inicial de x, ya que no se le asignó un valor, guarda cualquier float de la memoria.

    x=6.23;
    q=34;

    //s=&q; Error 2: No se puede asignar el tipo float a un puntero y asignarle la dirección de un entero.
    r=&q;
    y=&x;

    *r=13;
    x=2.5;
    *y=5.2; 

    cout<<"Dirección de y: "<<y<<endl;
    cout<<"O sea la dirección de x: "<<&x<<endl;
    cout<<"Valor final de r: "<<r<<endl;
    cout<<"O sea la dirección de q: "<<&q<<endl;
    cout<<"Valor final de q: "<<q<<endl;
    cout<<"Valor final de x: "<<x<<endl;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    cout<<" "<<endl;
    cout<<"Parte 2:"<<endl;

    int *r2=NULL;
    int p=88;
    if(r2==NULL)
        cout<<"Valor de r2: "<<r2<<endl; //Realmente es NULL.
    cout<<"Valor de p: "<<p<<endl; 

    r2=&p;
    cout<<"Dirección de r2: "<<r2<<endl; 
    cout<<"O sea la dirección de p: "<<&p<<endl;

    *r2=30;
    cout<<"Cambio en el contenido de r2, o sea en el valor del entero p: "<<*r2<<endl;
    cout<<"Valor de p: "<<p<<endl;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    cout<<" "<<endl;
    cout<<"Parte 3:"<<endl;

    int s2=1820;
    int *t=&s2;
    int **h=&t; //Puntero a un puntero, por eso doble asterisco. 
    int *w=NULL;

    cout<<"Valor de s2: "<<s2<<endl;
    cout<<"Valor de t: "<<t<<endl;
    cout<<"O sea la dirección de s2: "<<&s2<<endl;
    cout<<"Valor de h: "<<h<<endl;
    cout<<"O sea la dirección de t: "<<&t<<endl;
    if(w==NULL)
        cout<<"Valor de w: "<<w<<endl; //Realmente es NULL;
}