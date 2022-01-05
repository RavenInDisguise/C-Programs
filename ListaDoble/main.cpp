#include "estructuras.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ListaDoble * l = new ListaDoble();
	
	l->insertarAlInicio (1);
	l->insertarAlFinal(6);
	l->insertarAlFinal(8);
	l->insertarAlFinal(13);
	l->insertarAlFinal(50);
	l->imprimir();
	l->insertarPos(3,666);
	
	l->imprimir();
	l->borrarPos(4);
	//l->borrarAlInicio();
	//l->borrarAlFinal();
	

	l->imprimir();	
	//l->imprimirInverso();	
	return 0;
}
