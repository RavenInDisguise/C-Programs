#include <iostream>
using namespace std;

struct Nodo {
       Nodo* siguiente;// puntero para enlazar nodos
       string valor;// constructor

       Nodo(string dato)
       {
            valor = dato; // asigna los datos
            siguiente = NULL; // sig es null
       }
       
      void imprimir();

};
struct Pila {
       // solo con pN es suficiente
       Nodo *tope;

       Pila()
       {
            tope = NULL;
       }

       // encabezados de funcion
       void push (string dato);
       Nodo* pop (void);
       Nodo* peek(void);
       bool empty(void);
       void imprimir(void);
};

