//Mónica Alfaro Parrales. Carnet: 2020132572 :)

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
	clientes->insertarHijo("Luisa", 5,"Luisita", 11);
	clientes->insertarHijo("Luisa", 6,"Paquita", 15);
	clientes->insertarHijo("Paula", 7,"Paquita", 11);


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
	clientes->insertarHobby(3, "Paquita", new Hobby("ballet", 5));
	clientes->insertarHobby(3, "Paquita", new Hobby("tennis", 9));
	clientes->insertarHobby(3, "Paquita", new Hobby("futbol", 9));
	clientes->insertarHobby(3, "Paquita", new Hobby("ballet", 9));
	clientes->insertarHobby(3, "Paquita", new Hobby("gimnasia", 9));
	clientes->insertarHobby(3, "Paquita", new Hobby("cocina", 9));
	

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
*/	
	cout <<"-------------------------------"<<endl;
	ptPaco->hijos->getDistinctHobbies()->imprimir();
	// imprime los clientes
	clientes->imprimir();
	cout << "PROMEDIO ES: " << clientes->getAverageFrequency("tennis") << endl;
	cout << "PROMEDIO ES: " << clientes->getAverageFrequency("ajedrez") << endl;
	cout << "PROMEDIO ES: " << clientes->getAverageFrequency("PS4") << endl;
	cout << "PROMEDIO ES: " << clientes->getAverageFrequency("futbol") << endl;
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CANTIDAD HIJOS CON HOBBIES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout<<endl<<"----------------------------------------------"<<endl;
	int hobbies=1;
	cout<<"Cantidad de hijos con mas de "<<hobbies<<" hobbies: "<< clientes->cantidadHijosConHobbies(hobbies)<<endl;
	hobbies=3;
	cout<<"Cantidad de hijos con mas de "<<hobbies<<" hobbies: "<< clientes->cantidadHijosConHobbies(hobbies)<<endl;
	cout<<endl<<"----------------------------------------------"<<endl;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MODIFICAR FRECUENCIA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout<<"Valor de frecuencia: "<<clientes->modificarFrecuencia("Paco", "Paco Jr","tennis",15)<<endl;
	cout<<"Valor de frecuencia: "<<clientes->modificarFrecuencia("Paco", "Paco Jr","x",10)<<endl;
	cout<<"Valor de frecuencia: "<<clientes->modificarFrecuencia("x", "Paco Jr","tennis",10)<<endl;
	cout<<"Valor de frecuencia: "<<clientes->modificarFrecuencia("Paco", "x","tennis",10)<<endl;
	cout<<"Valor de frecuencia: "<<clientes->modificarFrecuencia("Luisa", "Luisita","futbol",10)<<endl;
	cout<<endl<<"----------------------------------------------"<<endl;
	clientes->imprimir();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DISTINCT HIJOS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout<<"Hijos distintos en la lista: "<<endl<<endl;
	clientes->distinctHijos()->imprimir();
	
    system("PAUSE");
    return EXIT_SUCCESS; 
}










