#include "listas.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	/*
	Nodo *nodo1=new Nodo();
	Nodo *nodo2=new Nodo(8);
	Nodo *nodo3=new Nodo(8, nodo2);
	nodo1->Imprimir();
	nodo2->Imprimir();
	nodo3->Imprimir();
	*/
	
	ListaSimple *l= new ListaSimple();
	
	//Insertar nodos al inicio
	l->insertarInicio(10);
	l->insertarInicio(8);
	l->insertarInicio(7);
	l->insertarInicio(3);
	l->insertarInicio(1);
	l->insertarInicio(10);
	l->insertarInicio(10);
	
	//Insertar nodos al final
	l->insertarAlFinal(55);
	l->insertarAlFinal(-2);
	l->insertarAlFinal(5);
	l->insertarAlFinal2(33);
	l->insertarAlFinal2(31);
	
	//Invertir lista
	l->Invertida()->imprimirLista();
	
	//Cantidad de apariciones de un dato
	//cout<<l->apariciones(5)<<endl;
	
	//Lista 
	//l->imprimirLista();
	
	//Eliminar al final
	l->eliminarAlFinal();
	
	//l->imprimirLista();
	
	l->insertarPos(2,666);
	l->imprimirLista();
	
	l->eliminarEnPos(5);
	l->eliminarEnPos(88);
	l->eliminarEnPos(-2);
	l->imprimirLista();
	
	Nodo *eliminado=l->eliminarEnPos(6);
	cout<<"Se eliminó: "<<eliminado->dato<<endl;
	l->imprimirLista();
	//l->eliminarAlInicio();
	
	/*
	l->imprimirLista();
	cout<<endl<<"El largo de la lista es: "<<l->largoLista()<<endl;
	string valor="Si";
	if(l->estaAhi(2)!=1){
		valor="No";
	}
	cout<<"El dato "<<2<<" esta en la lista? "<<valor<<endl;
	cout<<"La sumatoria de la lista: "<<l->sumatoria()<<endl;
	cout<<"La cantidad de pares es: "<<l->contarPares()<<endl;
	cout<<"El promedio es: "<<l->promedio()<<endl;
	return 0;
	*/
}
