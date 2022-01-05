#include "estructuras.h"

void ListaRombo::insertarPrincipal(int _dato){

	NodoPrinc *n1=new NodoPrinc(_dato);
	NodoAux *temp;
	NodoAux *aux=new NodoAux("Aut");
	if(isEmpty()){
		primerNodo=n1;
	}else if(primerNodo->arriba==NULL && primerNodo->abajo==NULL){
		primerNodo->arriba=aux;
		temp=primerNodo->arriba;
		temp->siguiente=n1;
	}else{
		if(primerNodo->arriba!=NULL){
			temp=primerNodo->arriba;
		}else{
			temp=primerNodo->abajo;
		}
		while(temp->siguiente!=NULL){
			if(temp->siguiente->arriba!=NULL){
				temp=temp->siguiente->arriba;
			}else if(temp->siguiente->abajo!=NULL){
				temp=temp->siguiente->abajo;
			}else{
				temp->siguiente->arriba=aux;
				temp=temp->siguiente->arriba;
				break;
			}
		}
		temp->siguiente=n1;
	}
}

void ListaRombo::insertarAuxiliar(string _datoStr){
	
	NodoAux *n1=new NodoAux(_datoStr); 
	NodoPrinc *temp=primerNodo;
	if(isEmpty()){
		cout<<"Por favor, ingrese un nodo principal antes del auxiliar."<<endl;
	}else{
		while((temp->arriba!=NULL) || (temp->abajo!=NULL)){
			if(temp->arriba!=NULL && temp->abajo!=NULL){
				temp=temp->arriba->siguiente;
			}else if(temp->abajo==NULL){
				temp->abajo=n1;
				n1->siguiente=temp->arriba->siguiente;
				break;
			}else if(temp->arriba==NULL){
				temp->arriba=n1;
				n1->siguiente=temp->abajo->siguiente;
				break;
			}
		}
		if(temp->arriba==NULL && temp->abajo==NULL){
			temp->arriba=n1;
			n1->siguiente=temp->arriba->siguiente;
	   }
	}
}

NodoAux* ListaRombo::borrarAuxiliar(string _datoStr){
	
	if(isEmpty() || (primerNodo->arriba == NULL && primerNodo->abajo == NULL)) {
		cout<<"No puede eliminar un auxiliar, ya que la lista no posee ninguno."<<endl;
		return NULL;
	}else{
		NodoPrinc *temp=primerNodo;
		NodoAux *nodoBorrado=new NodoAux();
		while((temp->arriba!=NULL) || (temp->abajo!=NULL)){
			if(temp->arriba!=NULL && temp->arriba->datoStr==_datoStr && temp->abajo!=NULL){
				temp->arriba->siguiente=NULL;
				nodoBorrado=temp->arriba;
				temp->arriba=NULL;
				break;
			}else if(temp->abajo!=NULL && temp->abajo->datoStr==_datoStr && temp->arriba!=NULL){
				temp->abajo->siguiente=NULL;
				nodoBorrado=temp->abajo;
				temp->abajo=NULL;
				break;
			}else if(temp->arriba!=NULL){
				temp=temp->arriba->siguiente;
			}else{
				temp=temp->abajo->siguiente;
			}
		}
		return nodoBorrado;
	}
}

void ListaRombo::imprimirLista(){
	if(isEmpty()){
		cout<<"No hay lista que imprimir."<<endl;
		
	}else{
		cout<<endl<<"Su lista: "<<endl;
		cout<<endl;
		imprimirNAuxArr();
		cout<<endl;
		imprimirPrinc();
		cout<<endl;
		imprimirNAuxAb();
		cout<<endl;
	}
}

void ListaRombo::imprimirNAuxArr(){
	NodoPrinc *temp=primerNodo;
	while(temp->arriba!=NULL || temp->abajo!=NULL){
		if(temp->arriba!=NULL){
			cout<<"     ";
			temp->arriba->imprimirAux();
			temp=temp->arriba->siguiente;
		}else{
			cout<<"          ";
			temp=temp->abajo->siguiente;
		}
	}
}

void ListaRombo::imprimirPrinc(){
	NodoPrinc *temp=primerNodo;
	temp->imprimir();
	while(temp->arriba!=NULL || temp->abajo!=NULL){
		if(temp->arriba!=NULL){
			cout<<"      ";
			temp->arriba->siguiente->imprimir();
			
			temp=temp->arriba->siguiente;
		}else{
			cout<<"      ";
			temp->abajo->siguiente->imprimir();
			temp=temp->abajo->siguiente;
		}
	}
}

void ListaRombo::imprimirNAuxAb(){
	NodoPrinc *temp=primerNodo;
	while(temp->arriba!=NULL || temp->abajo!=NULL){
		if(temp->abajo!=NULL){
			cout<<"      ";
			temp->abajo->imprimirAux();
			temp=temp->abajo->siguiente;	
		}else{
			cout<<"          ";
			temp=temp->arriba->siguiente;
		}
	}
}

bool ListaRombo::isEmpty(){
	return primerNodo==NULL;
}

