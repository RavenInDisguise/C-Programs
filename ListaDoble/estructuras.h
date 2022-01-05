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
	
	Nodo(int d, Nodo * _sig, Nodo * _ant)
	{
		dato = d;
		siguiente = _sig;
		anterior = _ant;
	}
	
	void imprimir ()
	{
		cout << "<- |" << dato << "| ->";
	}
};

struct ListaDoble{
	Nodo * primerNodo;
	Nodo * ultimoNodo;
	
	ListaDoble(){ 
		primerNodo = ultimoNodo = NULL;
	}	
	
	bool isEmpty(){
		return primerNodo == NULL;
	}
	
	void insertarAlInicio (int _dato){
		if (isEmpty())
			primerNodo = ultimoNodo = new Nodo (_dato);
		else{
			Nodo * nuevo = new Nodo(_dato);
			nuevo->siguiente = primerNodo;
			primerNodo->anterior = nuevo;
			primerNodo = nuevo;
		}
	}

	void insertarAlFinal (int _dato){
		if (isEmpty())
			primerNodo = ultimoNodo = new Nodo (_dato);
		else{
			Nodo * nuevo = new Nodo(_dato);
			nuevo->anterior = ultimoNodo;
			ultimoNodo->siguiente = nuevo;
			ultimoNodo = nuevo;
		}
	}
	
	
	void imprimir()
	{
		Nodo * tmp = primerNodo;
		while (tmp != NULL)
		{
			tmp->imprimir();
			tmp = tmp->siguiente; 		
		}
		cout <<endl;
	}
	
	void imprimirInverso()
	{
		Nodo * tmp = ultimoNodo;
		while (tmp != NULL)
		{
			tmp->imprimir();
			tmp = tmp->anterior; 		
		}
		cout <<endl;
	}

		Nodo * borrarAlInicio(){
		Nodo *borrado=primerNodo;
		if (primerNodo != NULL){		
			if(primerNodo==ultimoNodo){
				primerNodo=ultimoNodo=NULL;
			}else{
				primerNodo=primerNodo->siguiente;
				borrado->siguiente=NULL;
				primerNodo->anterior=NULL; //Necesario despegar el nuevo primer nodo del viejo.
			}
			return borrado;
		}
	}
	
	Nodo * borrarAlFinal(){
		Nodo *borrado=ultimoNodo;
		if (ultimoNodo != NULL){		
			if(primerNodo==ultimoNodo){
				primerNodo=ultimoNodo=NULL;
			}else{
				ultimoNodo=ultimoNodo->anterior;
				borrado->anterior=NULL;
				ultimoNodo->siguiente=NULL; //Necesario despegar el nuevo primer nodo del viejo.
			}
			return borrado;
		}
	}
	
	int largo(){
	int contador = 0;
	Nodo * tmp = primerNodo;
	while (tmp != NULL){
		contador++;
		tmp = tmp->siguiente;
	}
	return contador;	
}
	
	void insertarPos(int pos, int _dato){
	
		if(pos<=0){
			insertarAlInicio(_dato);
		}else if(pos>=largo()){
			insertarAlFinal(_dato);
		}else{
			Nodo *temp=primerNodo;
			for(int i=1; i<pos; i++){
				temp=temp->siguiente;
			}
			Nodo *n1=new Nodo(_dato);
			n1->siguiente=temp->siguiente;
			temp->siguiente->anterior=n1;
			temp->siguiente=n1;
			n1->anterior=temp;
			
		}
	}
	
	Nodo *borrarPos(int pos){
		
		if(pos<=0){
			return borrarAlInicio();
		}else if(pos>=largo()){
			return borrarAlFinal();
		}else{
			Nodo *temp=primerNodo;
			for(int i=1; i<pos; i++){
				temp=temp->siguiente;
			}
			Nodo *borrado=temp->siguiente;
			temp->siguiente=temp->siguiente->siguiente;
			temp->siguiente->anterior=temp;
			borrado->siguiente=borrado->anterior=NULL;
			return borrado;
			
		}
	}
	
}; 
