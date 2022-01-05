#include "lista.h"

int main(int argc, char *argv[])
{
	ListaDoble * clientes = new ListaDoble(); //lista creada pn es null
	Cliente * ptPaco = new Cliente(1, "Paco", 10000);
	clientes->insertarAlInicio(ptPaco);
	clientes->insertarAlInicio(new Cliente(2, "Hugo", 5000));
	clientes->insertarAlInicio(new Cliente(3, "Luisa", 12000));
	clientes->insertarAlInicio(new Cliente(4, "Paula", 9000));
	/*
		usando el puntero ptPaco que es el ultimo de la lista
		de clientes, insertare 3 hijos. Esta forma lo insertara
		pero no es lo correcto, debe hacerse un procedimiento
		que dado un cliente y las informacion de hijos, inserte
		ese hijo al cliente
	*/
	ptPaco->hijos->insertar(new Hijo(1,"Paco Jr", 10));
	ptPaco->hijos->insertar(new Hijo(2,"Paquita", 8));
	ptPaco->hijos->insertar(new Hijo(3,"Paquete", 6));

	clientes->insertarHijo("Paco", 4,"Paquinha", 11);
	clientes->insertarHijo("Luisa", 4,"Luisita", 11);
	clientes->insertarHijo("Paula", 4,"Paulie", 11);


	clientes->insertarHobby(1, "Paquinha", new Hobby("tennis", 2));
	clientes->insertarHobby(1, "Paquinha", new Hobby("PS4", 4));
	clientes->insertarHobby(1, "Paco Jr", new Hobby("futbol", 6));
	clientes->insertarHobby(1, "Paco Jr", new Hobby("tennis", 8));
	clientes->insertarHobby(1, "Paco Jr", new Hobby("PS4", 8));
	clientes->insertarHobby(1, "Paquita", new Hobby("tennis", 9));
	clientes->insertarHobby(1, "Paquita", new Hobby("ajedrez", 3));
	clientes->insertarHobby(1, "Paquete", new Hobby("tennis", 3));
	clientes->insertarHobby(3, "Luisita", new Hobby("tennis", 2));
	clientes->insertarHobby(3, "Luisita", new Hobby("futbol", 2));
	clientes->insertarHobby(4, "Paulie", new Hobby("tennis", 5));
	

/*	clientes->buscar("Luisa")->cliente->hijos->primerNodo->hijo->hobbies->insertar(new Hobby("tennis", 2));
	ptPaco->hijos->primerNodo->hijo->hobbies->insertar(new Hobby("tennis", 2));
	ptPaco->hijos->primerNodo->hijo->hobbies->insertar(new Hobby("futbol", 2));
	ptPaco->hijos->primerNodo->hijo->hobbies->insertar(new Hobby("ajedrez", 2));
	ptPaco->hijos->primerNodo->siguiente->hijo->hobbies->insertar(new Hobby("ajedrez", 2));
	ptPaco->hijos->primerNodo->siguiente->hijo->hobbies->insertar(new Hobby("PS4", 2));
	ptPaco->hijos->primerNodo->siguiente->hijo->hobbies->insertar(new Hobby("ajedrez", 2));
	ptPaco->hijos->primerNodo->siguiente->siguiente->hijo->hobbies->insertar(new Hobby("PS4", 2));
	ptPaco->hijos->primerNodo->siguiente->siguiente->hijo->hobbies->insertar(new Hobby("ajedrez", 2));
	ptPaco->hijos->primerNodo->siguiente->siguiente->siguiente->hijo->hobbies->insertar(new Hobby("PS4", 2));
*/	//cout <<"-------------------------------"<<endl;
	ptPaco->hijos->getDistinctHobbies()->imprimir();
	// imprime los clientes
	clientes->imprimir();
	/*
	cout << "PROMEDIO ES: " << clientes->getAverageFrequency("tennis") << endl;
	cout << "PROMEDIO ES: " << clientes->getAverageFrequency("ajedrez") << endl;
	cout << "PROMEDIO ES: " << clientes->getAverageFrequency("PS4") << endl;
	cout << "PROMEDIO ES: " << clientes->getAverageFrequency("futbol") << endl;
	*/
    system("PAUSE");
    return EXIT_SUCCESS; 
}










