#include <iostream>

using namespace std;

struct NodoPrin;
struct NodoAux;

struct NodoPrinc{
	int dato; 
	NodoAux *arriba; 
	NodoAux *abajo;
	
	NodoPrinc(){
		dato=0;
		arriba=NULL;
		abajo=NULL;
		
	} 
	
	NodoPrinc(int _dato){
		dato=_dato;
		arriba=NULL;
		abajo=NULL;	
	}
		
	void imprimir(){
		cout<<"|"<<dato<<"|";
	}	
};

struct NodoAux{
	string datoStr; 
	NodoPrinc *siguiente;
	
	NodoAux(){
		datoStr="";
		siguiente=NULL;
	}
	
	NodoAux(string _dato){
		datoStr=_dato;
		siguiente=NULL;	
	}	
		
	void imprimirAux(){
		cout<<"|"<<datoStr<<"|";
	}	
};

struct ListaRombo{
	NodoPrinc *principal;
	NodoPrinc *primerNodo;
	NodoAux *auxiliar;

	ListaRombo(){
		principal=NULL;
		auxiliar=NULL;
		primerNodo=principal;
	}
	
	
	void insertarPrincipal(int _dato);
	void insertarAuxiliar(string _datoStr);
	void imprimirNAuxArr();
	void imprimirPrinc();
	void imprimirNAuxAb();
	void imprimirLista();
	bool isEmpty();
	NodoAux* borrarAuxiliar(string _datoStr);
	


};
