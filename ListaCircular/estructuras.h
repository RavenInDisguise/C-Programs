#include <cstdlib>
#include <iostream>

using namespace std;


struct Nodo{
	int dato;
	Nodo * siguiente;
	Nodo * anterior;
	
	Nodo(int d)
	{
		dato = d;
		siguiente = anterior = NULL;
	}
	
	Nodo()
	{
		dato = 0;
		siguiente = anterior = NULL;
	}
	
	void imprimir ()
	{
		cout << dato << " ";
	}
};

struct ListaCircular{
	Nodo * primerNodo;

	
	ListaCircular(){ 
		primerNodo = NULL;
	}	
	
	bool isEmpty(){
		return primerNodo == NULL;
	}
	int largoLista(){
		Nodo *temp1=primerNodo;
		Nodo *temp2=primerNodo;
		if(primerNodo->siguiente==primerNodo){
			return 1;
		}else{
			int cantidad=0;
			while(temp1!=temp2){
				temp2=temp2->siguiente;
				cantidad++;
			}
		return cantidad+1;
	}
}
	
	void insertarAlFinal(int _dato){
		Nodo *n1=new Nodo(_dato);
		if(isEmpty()){
			primerNodo=n1;
			primerNodo->siguiente=primerNodo;
			primerNodo->anterior=primerNodo;
		}else{
			n1->siguiente=primerNodo;
			n1->anterior=primerNodo->anterior;
			primerNodo->anterior->siguiente=n1;
			primerNodo->anterior=n1;
				
		}
		
	}

	
	// IMPRIMIR LISTA
	void imprimir()
	{
		if (primerNodo != NULL){
			
			Nodo * tmp = primerNodo;
			do{
				tmp->imprimir();
				tmp = tmp->siguiente;
			}while(tmp!=primerNodo);
			cout << endl;
		}
	}
	
	//Buscar
	Nodo * buscar(int _dato)
	{
		if (primerNodo != NULL){
			
			Nodo * tmp = primerNodo;
			do{
				if (tmp->dato == _dato)
					return tmp;
				tmp = tmp->siguiente;
			}while(tmp!=primerNodo);
			
		}
		return NULL;
	}


	
	
}; 



