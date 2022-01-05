#include <iostream>

using namespace std;

struct Nodo{
	int dato; //Puedo poner la estructura que quiera, no sólo int. Ejemplo: Estudiante *e, Cliente *C, con muchos campos.
	//Puntero sig
	Nodo *siguiente; //Guarda posiciones de memoria, debe apuntar a un nodo de la lista, incluso a sí mismo o NULL.
	
	Nodo(){
		dato=0;
		siguiente=NULL;
		
	} //Nodo n; pide un espacio en memoria para la variable con el constructor por defecto.
	
	Nodo(int _dato){
		dato=_dato;
		siguiente=NULL;		
	}
	Nodo(int _dato, Nodo *_nodoSiguiente){
		dato=_dato;
		siguiente= _nodoSiguiente;
	}
	void Imprimir(){
		cout<<"|"<<dato<<"| ->";
	}	
};

struct ListaSimple{
	Nodo *primerNodo;
	Nodo *ultimoNodo;
	
	ListaSimple(){
		primerNodo=ultimoNodo=NULL;
	}
	
	void insertarAlFinal2(int dato);
	int apariciones(int dato);
	ListaSimple* Invertida();
	Nodo* eliminarAlInicio();
	Nodo* eliminarAlFinal();

	void insertarAlFinal(int dato);
	int largoLista();
	bool estaAhi(int _dato); //Return true si el dato esta en la lista.
	int sumatoria(); //La suma de todos los números de la lista.
	int contarPares(); //La cantidad de números pares de la lista.
	double promedio(); //Retorna el promedio simple de los elementos de la lista. CASTEO.
	bool esPar(int _dato);
	bool isEmpty();
	void insertarInicio(int _dato);
	void imprimirLista();
	void enlazarNodo(Nodo *nodo);
	void insertarPos(int pos, int _dato);
	Nodo* eliminarEnPos(int pos);

};
	
