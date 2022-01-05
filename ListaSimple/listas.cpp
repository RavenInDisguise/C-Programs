#include "listas.h"

void ListaSimple::insertarInicio(int _dato){
	if(isEmpty()){
		ultimoNodo=primerNodo= new Nodo(_dato); //Cuando hay un sólo elemento el último y el primero es el mismo.
	}else{
		
		/*
		//1
		Nodo *nuevo= new Nodo(_dato);
		nuevo->siguiente= primerNodo;
		primerNodo= nuevo;
		*/
		
		//2
		Nodo *nuevo= new Nodo(_dato, primerNodo);
		primerNodo=nuevo;
		
		
		//3
		//primerNodo=new Nodo(_dato, primerNodo);
		
		
	}
}

void ListaSimple::insertarAlFinal(int dato){
	if(isEmpty()){
		ultimoNodo=primerNodo= new Nodo(dato); //Cuando hay un sólo elemento el último y el primero es el mismo.
	}else{
		ultimoNodo->siguiente=new Nodo(dato); //UN sig deje de apuntar nulo, ahora apunte al nuevo nodo.
		ultimoNodo=ultimoNodo->siguiente; //UN deje de apuntar al viejo ultimo, apunte al nuevo ultimo que recien agregue. 		
	}
}

void ListaSimple::insertarAlFinal2(int dato){
	if(isEmpty()){
		ultimoNodo=primerNodo=new Nodo(dato);
	}
	Nodo *temp=primerNodo;
	while(temp->siguiente!=NULL){ //Hasta que temporal sea NULL.
		temp=temp->siguiente; //Avanzo
	}
	temp->siguiente=new Nodo(dato);
}

bool ListaSimple::isEmpty(){
	return primerNodo==NULL;	
}

void ListaSimple::imprimirLista(){
	Nodo *temp=primerNodo;
	while(temp!=NULL){ //Hasta que temporal sea NULL.
		temp->Imprimir(); //Imprimo
		temp=temp->siguiente; //Avanzo
	}
	
	cout<<endl;
}

int ListaSimple::largoLista(){
	int cantidad=0;
	Nodo *temp=primerNodo;
	while(temp!=NULL){
		cantidad++;
		temp=temp->siguiente;
	}
	return cantidad;
}

bool ListaSimple::estaAhi(int _dato){
	Nodo *temp=primerNodo;
	while(temp!=NULL){
		if(temp->dato==_dato){
			return true;
		}
		temp=temp->siguiente;
	}
	return false;
}

int ListaSimple::sumatoria(){
	int suma=0;
	int _dato;
	Nodo *temp=primerNodo;
	while(temp!=NULL){
		_dato=temp->dato;
		suma+=_dato;
		temp=temp->siguiente;
	}
	return suma;
}

bool ListaSimple::esPar(int _dato){
	if(_dato%2==0){
		return true;
	}
	return false;
}

int ListaSimple::contarPares(){
	int _dato;
	int cantidad=0;
	Nodo *temp=primerNodo;
	while(temp!=NULL){
		_dato=temp->dato;
		if(esPar(_dato)){
			cantidad++;
		}
		temp=temp->siguiente;
	}
	return cantidad;
} 

double ListaSimple::promedio(){
	double promedio;
	int largo=largoLista();
	if(largo>0){
		int suma=sumatoria();
		promedio=(double)(suma)/largo;
		return promedio;
	}
	return 0.0;
}

ListaSimple* ListaSimple::Invertida(){
	ListaSimple *l2=new ListaSimple();
	
	Nodo *temp=primerNodo;
	
	while(temp!=NULL){
		l2->insertarInicio(temp->dato);
		temp=temp->siguiente;
	}	
	return l2;
}

int ListaSimple::apariciones(int _dato){
	int cantidad=0;
	if(largoLista()>0){
		Nodo *temp=primerNodo;
		while(temp!=NULL){
			if(temp->dato==_dato){
				cantidad++;
			}	
		temp=temp->siguiente;
		}
	}
	return cantidad;
}

Nodo* ListaSimple::eliminarAlInicio(){
	//Codigo del profe
	if(isEmpty()){
		return NULL;
	}
	else{
		
		Nodo *borrado=primerNodo;
		primerNodo=primerNodo->siguiente;
		borrado->siguiente=NULL;
		if(primerNodo==NULL){
			ultimoNodo=primerNodo; //****
		}
		return borrado;
	}
	
	//Mi codigo
	/*
		if(primerNodo==NULL){
			return NULL;
		}
		else if(primerNodo->siguiente==NULL){
				Nodo *temp=primerNodo;
				primerNodo=primerNodo->siguiente;
				ultimoNodo=primerNodo; 
				return temp;
		} else{
				Nodo *temp=primerNodo;
				primerNodo=primerNodo->siguiente;
				temp->siguiente=NULL; //Desligo el primer elemento de la lista.
				return temp; 
		}
	*/
			
}

Nodo* ListaSimple::eliminarAlFinal(){
	if(isEmpty()){
		return NULL;
	}else if(primerNodo->siguiente==NULL){
		Nodo *borrado=primerNodo;
		primerNodo=ultimoNodo=NULL;
		return borrado;
	}else{
		Nodo *temp=primerNodo;
		while(temp->siguiente->siguiente!=NULL){ //No se va a caer porque arriba pregunto si tiene más de un elemento.
			temp=temp->siguiente;
		}
		ultimoNodo=temp;
		temp=temp->siguiente;
		ultimoNodo->siguiente=NULL;
		return temp;
	}	
}

void ListaSimple::enlazarNodo(Nodo *_nodo){
	if(_nodo!=NULL){
		if(primerNodo==NULL){
			ultimoNodo=primerNodo=_nodo;
			
		}else{
			_nodo->siguiente=primerNodo;
			primerNodo=_nodo;
			
		}
}
	
}

void ListaSimple::insertarPos(int pos, int _dato){
	
	if (pos <= 0){
		insertarInicio(_dato);
	}else if (pos >= largoLista()){
		insertarAlFinal(_dato);
	}else{
		Nodo * tmp = primerNodo;
		for (int i = 1; i<pos;i++){
			tmp = tmp->siguiente;
		}
		// acá temporal esta antes de donde debo insertar
		Nodo * nuevo = new Nodo(_dato);
		nuevo->siguiente = tmp->siguiente;
		tmp->siguiente = nuevo;
	} 

	/*
	Nodo *nodo2=new Nodo(_dato);
	int contador=0;
	if(isEmpty()){
		primerNodo=ultimoNodo=nodo2; 	
	}else if(primerNodo->siguiente==NULL){
		if(pos>0){
			primerNodo->siguiente=nodo2;	
		}else{
			nodo2->siguiente=primerNodo;
		}
	}else{
		Nodo *temp=primerNodo;
		if(pos>largoLista()){
			ultimoNodo->siguiente=nodo2;
		}else{
			while(contador<pos-1){
				temp=temp->siguiente;
				contador++;
			}
			Nodo *temp2=temp->siguiente->siguiente;
			temp->siguiente=nodo2;
			nodo2->siguiente=temp2;
		}
	}
	*/
}

Nodo* ListaSimple::eliminarEnPos(int pos){
	Nodo *borrado=NULL;
	if (pos<=0){
		borrado=eliminarAlInicio();
	}else if(pos>=largoLista()){
		borrado=eliminarAlFinal();
	
	}else{
		Nodo *temp=primerNodo;
		for(int i=1; i<pos; i++){
			temp=temp->siguiente;
		}
		borrado=temp->siguiente;
		temp->siguiente=temp->siguiente->siguiente;	
	}
	return borrado;
}


//TAREA MORAL: Borrar en posicion 
	
	

			






