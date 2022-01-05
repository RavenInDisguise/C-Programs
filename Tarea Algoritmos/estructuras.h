#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <sstream>

using namespace std;


// estructura nodo para lista simple
struct Nodo{
	string dato; //Puedo poner la estructura que quiera, no sólo int. Ejemplo: Estudiante *e, Cliente *C, con muchos campos.
	//Puntero sig
	Nodo *siguiente; //Guarda posiciones de memoria, debe apuntar a un nodo de la lista, incluso a sí mismo o NULL.
	
	Nodo(){
		dato="";
		siguiente=NULL;
		
	} //Nodo n; pide un espacio en memoria para la variable con el constructor por defecto.
	
	Nodo(string _dato){
		dato=_dato;
		siguiente=NULL;		
	}
	Nodo(string _dato, Nodo *_nodoSiguiente){
		dato=_dato;
		siguiente= _nodoSiguiente;
	}
	void Imprimir(){
		cout<<"|"<<dato<<"| ->";
	}	
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

struct ListaSimple{
	Nodo *primerNodo;
	Nodo *ultimoNodo;
	
	ListaSimple(){
		primerNodo=ultimoNodo=NULL;
	}
	
	void insertarAlFinal2(string dato);
	int apariciones(string dato);
	ListaSimple* Invertida();
	Nodo* eliminarAlInicio();
	Nodo* eliminarAlFinal();

	void insertarAlFinal(string dato);
	int largoLista();
	bool estaAhi(string _dato); //Return true si el dato esta en la lista.
	bool isEmpty();
	void insertarInicio(string _dato);
	void imprimirLista();
	void enlazarNodo(Nodo *nodo);
	void insertarPos(int pos, string _dato);
	Nodo* eliminarEnPos(int pos);

};



