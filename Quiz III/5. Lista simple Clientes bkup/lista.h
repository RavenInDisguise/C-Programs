//Mónica Alfaro Parrales. Carnet: 2020132572 :)

#include <cstdlib>
#include <iostream>
using namespace std;

// Prototipos de estructuras
// es la declaracion de estas estructuras
struct HobbyStatistics{
	string name;
	int hobbiersCount;
	int frequencySum;

	HobbyStatistics (){
		hobbiersCount = 0;
		frequencySum = 0;
	}
	HobbyStatistics (string n){
		hobbiersCount = 0;
		frequencySum = 0;
		name = n;
	}
	
	double average(){
		if (hobbiersCount > 0)
			return (double)frequencySum/hobbiersCount;
		return 0.0;
		
	}
};

struct Hobby;
struct NodoHobby;
struct ListaSimpleHobbies;
struct Hijo;
struct NodoHijo;
struct ListaSimple;
struct Cliente;
struct Nodo;
struct ListaDoble;

// BEGIN: Hobby------------------------------------------------------
// TAD
struct Hobby{
	string nombre;
	int cantidad; // veces por semana
	
	Hobby (string _nombre, int _cantidad){
		nombre = _nombre;
		cantidad = _cantidad;
	}
	// imprime la informacion de un hijo
	void imprimir(){
		cout <<nombre<<"\t(" << cantidad <<")"<< endl;
	}
};

// nodo para la lista simple Hobby
struct NodoHobby{
	Hobby * hobby;
	NodoHobby * siguiente;
	
	NodoHobby(Hobby * _hobby){
		hobby = _hobby;
		siguiente = NULL;
	}
};


// lista simple de hobby
struct ListaSimpleHobbies{
	NodoHobby * primerNodo, *ultimoNodo;
	ListaSimpleHobbies (){
		primerNodo = ultimoNodo = NULL;
	}
	
	//imprimir lista de hobbies
	void imprimir(){
		NodoHobby *tmp = primerNodo;
		cout << "****** HOBBIES ******"	<<endl;	
		// mientras tmp no sea nulo, avanza
		while (tmp != NULL)
		{
		   tmp->hobby->imprimir();
		   tmp = tmp->siguiente;
		}
 		cout << endl;
	}

	//frequency
	int getFrequencySum(string nombre){
		int result = 0;
		NodoHobby *tmp = primerNodo;
		// mientras tmp no sea nulo, avanza
		while (tmp != NULL)
		{
			if (tmp->hobby->nombre == nombre && tmp->hobby->cantidad > 0)
				result += tmp->hobby->cantidad;
 		   tmp = tmp->siguiente;
		}
 		return result;
	}
		
	

	//exists
	bool exists(string nombre){
		NodoHobby *tmp = primerNodo;
		// mientras tmp no sea nulo, avanza
		while (tmp != NULL)
		{
			if (tmp->hobby->nombre == nombre)
				return true;
 		   tmp = tmp->siguiente;
		}
 		return false;
	}
	
	NodoHobby* buscar(string nombre){
		NodoHobby *tmp = primerNodo;
		// mientras tmp no sea nulo, avanza
		while (tmp != NULL)
		{
			if (tmp->hobby->nombre == nombre)
				return tmp;
 		   tmp = tmp->siguiente;
		}
 		return NULL;
	}
	
	//imprimir lista de hobbies
	int largo(){
		NodoHobby *tmp = primerNodo;
		int counter = 0;
		// mientras tmp no sea nulo, avanza
		while (tmp != NULL)
		{
			counter++;
 		   tmp = tmp->siguiente;
		}
 		return counter;
	}


	void insertar(Hobby * hobby)
	{
		// si no hay elementos
		if (primerNodo == NULL)
		{
			// ambos apuntan al nuevo en memoria
			ultimoNodo = primerNodo = new NodoHobby(hobby);
		}
		else
		{
			NodoHobby *nuevo = new NodoHobby(hobby);
			nuevo->siguiente = primerNodo;
			primerNodo = nuevo; 
		}
	}
};
// END: Hobby------------------------------------------------------

// TAD Hijo
struct Hijo{
	int id;
	string nombre;
	int edad;
	ListaSimpleHobbies * hobbies; // no olvidar
	
	Hijo (int _id, string _nombre, int _edad){
		id = _id;
		nombre = _nombre;
		edad = _edad;
		hobbies = new ListaSimpleHobbies(); // no olvidar
	}
	// imprime la informacion de un hijo
	void imprimir(){
		cout <<"\t\tIdentificacion de Hijo "<< id <<"\t"<<nombre<<"\t\tEdad:" << edad << endl;
		hobbies->imprimir();
	}
};

// nodo para la lista simple
struct NodoHijo{
	Hijo * hijo;
	NodoHijo * siguiente;
	
	NodoHijo(Hijo * _hijo){
		hijo = _hijo;
		siguiente = NULL;
	}
};

// lista simple de hijos
struct ListaSimple{
	NodoHijo * primerNodo, *ultimoNodo;

	ListaSimple (){
		primerNodo = ultimoNodo = NULL;
	}
	
	void imprimir();
	void insertar(Hijo*);	
	
	// busca un hijo por nombre. Retorna null si no lo encuentra
	NodoHijo * buscar(string nombre){
		NodoHijo * tmp = primerNodo;
		while (tmp!= NULL){
			if (tmp->hijo->nombre == nombre)
				return tmp;
			tmp = tmp->siguiente;
		}
		return NULL;
	}

	/*
		recorre una lista de hijos actualizando las estadistica del hobby de todos los hijos
	*/
	HobbyStatistics * getHobbyFrequency(string nombreHobby, HobbyStatistics * stats){
		//ERROR HobbyStatistics * stats = new  HobbyStatistics();
		NodoHijo * tmp = primerNodo;
		int freqHijo = 0;
		while (tmp!= NULL){
			freqHijo = tmp->hijo->hobbies->getFrequencySum(nombreHobby);
			if (freqHijo>0){
				stats->hobbiersCount++;	
				stats->frequencySum += freqHijo;
			}
			tmp = tmp->siguiente;
		}
		return stats;
	}
	
	// returns a new ListaHobbies with just distinct hobbies of children
	// I: none, the referenced list
	// O: ListaSimpleHobbies
	 ListaSimpleHobbies * getDistinctHobbies (){
	 	// new List to be returned
		ListaSimpleHobbies * listaHobbies = new ListaSimpleHobbies();
		NodoHijo * tmp = primerNodo; // first child
		while (tmp!=NULL){ // all the Hijos
			// for each Hijo tmp, a while for hobbies
			NodoHobby * actual = tmp->hijo->hobbies->primerNodo; 
			while (actual != NULL){ // for each hobby actual
				// si no esta el hobbie en la lista
				if (!listaHobbies->exists(actual->hobby->nombre)){
					// lo inserta en la lista
					listaHobbies->insertar(new Hobby(actual->hobby->nombre,0));
				}
				actual = actual->siguiente;
			}
			tmp = tmp->siguiente;
		}
		return listaHobbies;
	}
	//********FUNCIÓN MONICA********
	int frecuenciaHobbies(int n){
		int frecuencia=0;
		NodoHijo *temp=primerNodo;
		while(temp!=NULL){
			if(temp->hijo->hobbies->largo()>n){
				frecuencia+=1;
			}
			temp=temp->siguiente;
		}
		return frecuencia;
	}
	//********FUNCIÓN MONICA********
	bool exists(string nombre){
		NodoHijo *tmp = primerNodo;
		while (tmp != NULL)
		{
			if (tmp->hijo->nombre == nombre)
				return true;
 		   tmp = tmp->siguiente;
		}
 		return false;
	}
};

// struct Cliente
struct Cliente{
	int id;
	string nombre;
	int salario;
	ListaSimple * hijos;

	// Constructores
	Cliente(){
		id = 0;		nombre = "";	salario = 0;
		hijos = new ListaSimple ();
	}
	
	Cliente(int inID, string inNombre, int inSalario){
		id = inID;
		nombre = inNombre ;
		salario = inSalario;
		hijos = new ListaSimple ();
	}
	// Imprimir los datos del cliente	
	void imprimir (){
		ListaSimpleHobbies * distinctHobbies = hijos->getDistinctHobbies();
		cout << "Cliente #" << id << ":\t" << nombre;
		cout << "\tSalario: " << salario <<endl;
		cout << "Hobbies distintos: " << distinctHobbies->largo() <<endl;
		distinctHobbies->imprimir();
		cout <<endl;
		hijos->imprimir();
		cout <<"-----------------------------"<<endl<<endl;
	}
	
};

// estructura nodo para lista simple
struct Nodo {
       //int dato; // parte de datos
       Cliente * cliente;
       Nodo* siguiente;// puntero para enlazar nodos
       Nodo* anterior;
       
       Nodo(){
       	cliente = NULL;
       	siguiente = anterior = NULL;
	   }
       // constructor
       Nodo(Cliente * inCliente) {
         cliente = inCliente; // asigna los datos
         siguiente = anterior = NULL; // sig es null       
       }
       
       Nodo (int inID, string inNombre, int inSalario){
       		siguiente = anterior = NULL;
       		cliente = new Cliente (inID, inNombre, inSalario);
	   }
};

//Lista doblemente enlazada para clientes
struct ListaDoble {
       // solo con pN es suficiente
       Nodo *primerNodo, *ultimoNodo;
       // constructor
       ListaDoble()
       {
           primerNodo = ultimoNodo = NULL;
       }
       
  //----------------------------------------------
    void insertarAlInicio (Cliente * cliente)
    {
            // si no hay elementos
       if (primerNodo == NULL)
       {
        // ambos apuntan al nuevo en memoria
         primerNodo = new Nodo(cliente);
         ultimoNodo = primerNodo; 
         // ambos apuntan al nuevo               
       }
       else{
         Nodo *nuevo = new Nodo(cliente);
         nuevo->siguiente = primerNodo;
         primerNodo ->anterior = nuevo;
         primerNodo = nuevo; 
      }            
  }// fin metodo

  //----------------------------------------------  
  void imprimir(){
     Nodo *tmp = primerNodo;

     while (tmp != NULL){
       tmp->cliente->imprimir(); // metodo de imprimir un cliente
       tmp = tmp->siguiente;
     }
     cout << endl;
  }// fin metodo imprimir
  
  //----------------------------------------------
  // largo de una lista
  int largo(){
	int i = 0;
	Nodo * temp = primerNodo;
	
	while (temp!=NULL){
		i++;
		temp = temp->siguiente;
	}
	return i;
  }   
	  
	// funcion que inserta un nodo nuevo al final de la lista
	// entradas: el dato a guardar
	// salidas: no tiene
	void insertarAlFinal (Cliente * cliente)
	{
	     // si no hay elementos
	     if (primerNodo == NULL)
	     {
	         // ambos apuntan al nuevo en memoria
	         primerNodo = new Nodo(cliente);
	         ultimoNodo = primerNodo; // ambos apuntan al nuevo               
	     }
	     else
	     {
	         Nodo *nuevo = new Nodo(cliente);
	         ultimoNodo->siguiente = nuevo;
	         nuevo->anterior = ultimoNodo;
	         ultimoNodo = nuevo;
	     }
	}
  
  	Nodo * buscar(string nombre){
  			Nodo * tmp = primerNodo;
  			while (tmp!= NULL){
  				if (tmp->cliente->nombre == nombre)
				  return tmp;
				tmp = tmp ->siguiente;	
			}
			return NULL;
	}
	
	void insertarHijo (string father, int childId, string childName, int childAge){
		Nodo * buscado = buscar(father);
		if (buscado!=NULL)
			buscado->cliente->hijos->insertar(new Hijo(childId,childName,childAge));
	}
	
  	Nodo * buscarPorId(int id){
  			Nodo * tmp = primerNodo;
  			while (tmp!= NULL){
  				if (tmp->cliente->id == id)
				  return tmp;
				tmp = tmp ->siguiente;	
			}
			return NULL;
	}
		
	// insertar hobby: busca al cliente por id, busca al hijo por nombre, inserta hobby
	void insertarHobby(int idCliente, string nombreHijo, Hobby* hobby){
		Nodo * clienteBuscado = buscarPorId (idCliente);
		if (clienteBuscado != NULL){
			NodoHijo * hijoBuscado = clienteBuscado->cliente->hijos->buscar(nombreHijo);
			if (hijoBuscado != NULL){
				hijoBuscado->hijo->hobbies->insertar(hobby);
			}
		}
	}
	
	
	/*
		recorre una lista de clientes actualizando las estadistica 
		del hobby de todos los hijos de cada cliente
	*/
	HobbyStatistics * getCustomersHobbyFrequency(string nombreHobby, HobbyStatistics * stats){
		Nodo * tmp = primerNodo;
		while (tmp!= NULL){
			tmp->cliente->hijos->getHobbyFrequency(nombreHobby, stats);
			tmp = tmp->siguiente;
		}
		return stats;
	}
	
	// creates a stats and send it as pointer to acumulate
	// the statistics
	double getAverageFrequency (string nombreHobby){
		HobbyStatistics * stats = new  HobbyStatistics(nombreHobby);
		getCustomersHobbyFrequency(nombreHobby, stats);
		cout <<"Count: "<<stats->hobbiersCount <<"  FREQUENCY sum: " << stats->frequencySum << endl;	
		return stats->average();
	}
	
	//********FUNCIÓN MONICA********
	int cantidadHijosConHobbies(int n){
		int frecuenciaTotal=0;
		Nodo *temp=primerNodo;
		while(temp!=NULL){
			frecuenciaTotal+=temp->cliente->hijos->frecuenciaHobbies(n); //Función en ListaSimple
			temp=temp->siguiente;
		}
		return frecuenciaTotal;
	}
	
	//********FUNCIÓN MONICA********
	int modificarFrecuencia(string nombreCliente, string nombreHijo, string nombreHobby, int frecuencia){
		Nodo * clienteBuscado = buscar (nombreCliente);
		if (clienteBuscado != NULL){
			NodoHijo *hijoBuscado = clienteBuscado->cliente->hijos->buscar(nombreHijo);
			if (hijoBuscado != NULL){
				NodoHobby *hobbyBuscado=hijoBuscado->hijo->hobbies->buscar(nombreHobby); 
				if(hobbyBuscado != NULL){
					hobbyBuscado->hobby->cantidad+=frecuencia;
					return hobbyBuscado->hobby->cantidad;
				}
			}
		}
		return -1;	
	}
	
	//********FUNCIÓN MONICA********
	ListaSimple * distinctHijos (){
		ListaSimple  *listaHijos = new ListaSimple();
		Nodo *temp=primerNodo;
		while (temp!=NULL){ 
			NodoHijo *temp_hijo = temp->cliente->hijos->primerNodo; 
			while (temp_hijo!=NULL){ 
				if (!listaHijos->exists(temp_hijo->hijo->nombre)){ //Función en ListaSimple
					listaHijos->insertar(new Hijo(0,temp_hijo->hijo->nombre,0));
				}
				temp_hijo= temp_hijo->siguiente;
			}
			temp = temp->siguiente;
		}
		return listaHijos;
	}
	
  
   // encabezados de funcion
   //void insertarAlInicio (int dato);
   Nodo* borrarAlInicio(void);
   //void imprimir(void);
   //void insertarAlFinal(int dato);
   Nodo* borrarAlFinal(void);
   //int largo (void);//
   void insertarEnPosicion(int dato, int pos);
   void borrarEnPosicion(int pos);
};



