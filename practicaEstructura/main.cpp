//Monica ALfaro Parrales. Carnet: 2020132572

#include "estructuras.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ListaRombo *l=new ListaRombo();
	cout<<"~~~Lista Rombo~~~"<<endl;
	l->imprimirLista();
	l->borrarAuxiliar("Hola");
	l->insertarAuxiliar("A");
	l->insertarPrincipal(15);
	l->insertarAuxiliar("B");
	l->insertarPrincipal(9);
	l->insertarAuxiliar("C");
	l->insertarPrincipal(10);
	l->insertarPrincipal(19);
	l->insertarPrincipal(56);
	l->insertarAuxiliar("D");
	l->insertarAuxiliar("E");
	l->insertarPrincipal(32);
	l->insertarPrincipal(11);
	l->imprimirLista();
	NodoAux *n=l->borrarAuxiliar("B");
	cout<<endl<<"El nodo borrado fue: ";
	n->imprimirAux();
	l->imprimirLista();
	NodoAux *n2=l->borrarAuxiliar("Aut");
	cout<<endl<<"El nodo borrado fue: ";
	n2->imprimirAux();
	l->insertarAuxiliar("M");
	l->insertarPrincipal(86);
	l->imprimirLista();
	NodoAux *n3=l->borrarAuxiliar("D");
	cout<<endl<<"El nodo borrado fue: ";
	n3->imprimirAux();
	l->imprimirLista();
	
	return 0;
}
