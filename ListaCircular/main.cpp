#include "estructuras.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ListaCircular *l = new ListaCircular();
	l->insertarAlFinal(66);
	l->insertarAlFinal(55);
	l->insertarAlFinal(77);
	l->insertarAlFinal(88);
	l->imprimir();
	Nodo *n1=l->buscar(88);
	n1->imprimir();
	return 0;
}
