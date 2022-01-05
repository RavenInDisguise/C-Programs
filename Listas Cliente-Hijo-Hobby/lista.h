#include <cstdlib>
#include <iostream>
using namespace std;



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
		cout <<nombre<<"\t[" << cantidad <<"]"<< endl;
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

	// returns a new ListaHobbies with just distinct hobbies of children
	// I: none, the referenced list
	// O: ListaSimpleHobbies
	
	ListaSimpleHobbies* getDistinctHobbies(){
		NodoHijo *temp=primerNodo;
		NodoHobby *temp2=temp->hijo->hobbies->primerNodo;
		ListaSimpleHobbies *lsh=new ListaSimpleHobbies();
		
		while(temp!=NULL){
			while(temp2!=NULL){
				if(lsh->exists(temp2->hobby->nombre)){
					temp2=temp2->siguiente;
				}else{
					Hobby *h1=new Hobby(temp2->hobby->nombre,temp2->hobby->cantidad);
					lsh->insertar(h1);
					temp2=temp2->siguiente;
				}	
			}
			
		   temp=temp->siguiente;
		}
		return lsh;
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
		//ListaSimpleHobbies * distinctHobbies = hijos->getDistinctHobbies();
		cout << "Cliente #" << id << ":\t" << nombre;
		cout << "\tSalario: " << salario <<endl;
		//cout << "Hobbies distintos: " << distinctHobbies->largo() <<endl;
		//distinctHobbies->imprimir();
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
	
	int getAverageFrequency(string _hobby){
		
	}
	
	/*
		recorre una lista de clientes actualizando las estadistica 
		del hobby de todos los hijos de cada cliente
	*/

	
	// creates a stats and send it as pointer to acumulate
	// the statistics

  
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



