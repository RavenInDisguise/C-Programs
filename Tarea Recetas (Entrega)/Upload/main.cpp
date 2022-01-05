//Mónica Alfaro Parrales. Carnet: 2020132572

#include "estructuras.h"


//~~~~~~~~~~~~~~~~~~~METODOS~~~~~~~~~~~~~~~~~~~

//***Ingrediente***

void Ingrediente::imprimirIngrediente(){
    cout<<nombreI<<": "<<cantidad<<" "<<unidadMedida<<endl;
}

//***Receta***

void Receta::agregarReceta(Ingrediente *ingrediente1){
    arregloIngredientes[cantidadIngredientes]=*ingrediente1;
    cantidadIngredientes++;
}

void Receta::imprimirReceta(){
        cout<<"\n"<<"Nombre de la receta: "<<nombreR<<endl;
        cout<<"Cantidad de porciones: "<<porciones<<endl;
        cout<<endl<<"Ingredientes: "<<endl;
        for (int i=0; i<cantidadIngredientes;i++){
            arregloIngredientes[i].imprimirIngrediente();
        }
        cout<<endl;
        cout<<"-------------------------------------------"<<endl;
}

int Receta::buscarIngrediente(string nombreIngresado){
    if(cantidadIngredientes>0){
        for (int i=0; i<cantidadIngredientes;i++){
            string valorArreglo=arregloIngredientes[i].nombreI;
            transform(valorArreglo.begin(), valorArreglo.end(),valorArreglo.begin(), ::toupper);
            transform(nombreIngresado.begin(), nombreIngresado.end(),nombreIngresado.begin(), ::toupper);
            if(valorArreglo==nombreIngresado){
                return i;
            }
        }
     }
     return -1;
}

//***Base de datos de recetas***

void BaseDatos::agregarRecetaBD(Receta *recetaBD){
        arregloRecetas[cantidadRecetas]=*recetaBD;
        cantidadRecetas++;
}

void BaseDatos::imprimirBaseDatos(){
    if(cantidadRecetas>0){
        for (int i=0; i<cantidadRecetas;i++){
            arregloRecetas[i].imprimirReceta();
        }
    }else{
        cout<<"Ups! No hay recetas almacenadas."<<endl;
    }
}

int BaseDatos::buscarReceta(string nombreIngresado){
    if(cantidadRecetas>0){
        for (int i=0; i<cantidadRecetas;i++){
            string valorArreglo=arregloRecetas[i].nombreR;
            transform(valorArreglo.begin(), valorArreglo.end(),valorArreglo.begin(), ::toupper);
            transform(nombreIngresado.begin(), nombreIngresado.end(),nombreIngresado.begin(), ::toupper);
            if(valorArreglo==nombreIngresado){
                return i;
            }
        }
     }
     return -1;
}

void BaseDatos::borrarReceta(string nombreIngresado){
    int posicion=buscarReceta(nombreIngresado);
    if(posicion!=-1){
    	arregloRecetas[posicion].imprimirReceta();
        for(int i=posicion;i<cantidadRecetas-1;i++){
            arregloRecetas[i]=arregloRecetas[i+1];
        }
        cantidadRecetas--;
        cout<<endl<<"Receta eliminada."<<endl;
    }else{    
        cout<<endl<<"Ups! La receta no pudo ser encontrada."<<endl; 
    }           
}

void BaseDatos::modificarNombreR(string nombreNuevo, int posicion){
        arregloRecetas[posicion].nombreR=nombreNuevo;
}

void BaseDatos::modificarCantidadI(int cantidadIng, int posicion, int posicion2){
    
        arregloRecetas[posicion].arregloIngredientes[posicion2].cantidad=cantidadIng;
}

//***Metodos del menu***

void BaseDatos::agregarRecetasMenu(){
    //Variables para la receta:
    string nombreR;
    double porciones;
    int cantidadIngredientes;
    //Variables para los ingredientes:
    string nombreI;
    string unidadMedida;
    double cantidadPeso;
    int cantidadRecetas=0;

    cout<<"~~Agregar receta~~"<<endl;
    cout<<"Ingrese el nombre de la receta: "; cin.ignore(); getline(cin,nombreR);
    
    int valor=buscarReceta(nombreR);
    if(valor==-1){
        cout<<"Ingrese las porciones de la receta: "; cin>>porciones; 
        cout<<"Cuantos ingredientes desea agregar? "; cin>>cantidadIngredientes;
        Receta *receta=new Receta(nombreR, porciones);
        if(0<cantidadIngredientes && cantidadIngredientes<51){
		
	        for(int i=1; i<=cantidadIngredientes; i++){
	            cout<<endl<<"~~Agregar ingrediente numero "<<i<<" a la receta~~"<<endl;
	            cout<<""<<endl;
	            cout<<"Ingrese el nombre del ingrediente: "; cin.ignore(); getline(cin,nombreI);
	            int valor2=receta->buscarIngrediente(nombreI);
	            if(valor2==-1){ 
	                cout<<"Ingrese la unidad de medida del ingrediente: "; getline(cin, unidadMedida);
	                cout<<"Ingrese la cantidad a utilizar del ingrediente: "; cin>>cantidadPeso;
	                receta->agregarReceta(new Ingrediente(nombreI,unidadMedida,cantidadPeso));
	            }else{
	                cout<<endl<<"Ups! Ese ingrediente ya existe. "<<endl;        
	            }
	        }
	      	agregarRecetaBD(receta);
	        cout<<endl<<"Receta agregada."<<endl;
		}else{
			cout<<endl<<"Debe ingresar minimo un ingrediente y maximo 50."<<endl;
		}
    }else{
        cout<<endl<<"Ups! La receta ya existe.";
    }
}

void BaseDatos::buscarRecetasMenu(){
    string nombreRBuscar;

    cout<<"~~Buscar receta~~"<<endl;
    cout<<"Ingrese el nombre de la receta que desea buscar: "; cin.ignore(); getline(cin,nombreRBuscar);
    
    if(buscarReceta(nombreRBuscar)==-1){
        cout<<endl<<"Ups! La receta no pudo ser encontrada."<<endl;
	}else{
		int valor=buscarReceta(nombreRBuscar);
    	arregloRecetas[valor].imprimirReceta();
	}
}

void BaseDatos::eliminarRecetasMenu(){
    string nombreRBuscar;

    cout<<"~~Eliminar receta~~"<<endl;
    cout<<"Ingrese el nombre de la receta que desea eliminar: "; cin.ignore(); getline(cin,nombreRBuscar);   
    borrarReceta(nombreRBuscar);
}

void BaseDatos::imprimirRecetasMenu(){
    cout<<"~~Imprimir recetario~~"<<endl;  
    imprimirBaseDatos(); 
}

void BaseDatos::modificarNombreRMenu(){
    string nombreRBuscar;
    string nombreNuevo;
    
	cout<<"~~Modificar nombre de una receta~~"<<endl;  
	cout<<"Ingrese el nombre de la receta que desea modificar: "; cin.ignore(); getline(cin,nombreRBuscar);
	int valor1=buscarReceta(nombreRBuscar); 
    if(valor1!=-1){ 
		cout<<"Ingrese el nombre nuevo de la receta: "; getline(cin,nombreNuevo);     
   		int valor2=buscarReceta(nombreNuevo); 
   		if(valor2==-1){
			modificarNombreR(nombreNuevo, valor1);
        	cout<<endl<<"Nombre de receta modificado."<<endl;
     	}else{
     		cout<<endl<<"Ups! Ese nombre de receta ya existe."<<endl;
		}
    }else{
        cout<<endl<<"Ups! La receta no pudo ser encontrada."<<endl;
    }
}

void BaseDatos::modificarCantidadIMenu(){
     string nombreRBuscar;
     string nombreIBuscar;
     int cantidadPeso;

     cout<<"~~Modificar cantidad de un ingrediente~~"<<endl;  
     cout<<"Ingrese el nombre de la receta que posee el ingrediente que desea modificar: "; cin.ignore(); getline(cin,nombreRBuscar); 
     int valor=buscarReceta(nombreRBuscar); 
     if(valor!=-1){
	     cout<<"Ingrese el nombre del ingrediente que desea modificar: "; getline(cin,nombreIBuscar);  
	     int valor2=arregloRecetas[valor].buscarIngrediente(nombreIBuscar);
	     if(valor2!=-1){
	     	cout<<"Ingrese la cantidad a utilizar del ingrediente: "; cin>>cantidadPeso; 
	     	modificarCantidadI(cantidadPeso, valor, valor2);
	     	cout<<endl<<"Cantidad del ingrediente modificada."<<endl;
		 }else{
		 	cout<<endl<<"Ups! El ingrediente no pudo ser encontrado."<<endl;
		 }
	     
 	}else{
 		cout<<endl<<"Ups! La receta no pudo ser encontrada."<<endl;
	 }
}

void BaseDatos::agregarIngredienteMenu(){
    string nombreRBuscar;
    string nombreIBuscar;
    //Variables para los ingredientes:
    string nombreI;
    string unidadMedida;
    double cantidadPeso;

    cout<<"~~Agregar ingrediente a una receta~~"<<endl;  
    cout<<"Ingrese el nombre de la receta a la que desea agregarle el ingrediente: "; cin.ignore(); getline(cin,nombreRBuscar); 
    int valor=buscarReceta(nombreRBuscar);
    if(valor!=-1){
    	cout<<"Ingrese el nombre del ingrediente: "; getline(cin,nombreI); 
    	int valor2=arregloRecetas[valor].buscarIngrediente(nombreI);
    	if(valor2==-1){
    		cout<<"Ingrese la unidad de medida del ingrediente: "; getline(cin, unidadMedida);
		    cout<<"Ingrese la cantidad a utilizar del ingrediente: "; cin>>cantidadPeso;
		    arregloRecetas[valor].agregarReceta(new Ingrediente(nombreI,unidadMedida,cantidadPeso));
		    cout<<endl<<"Ingrediente agregado."<<endl;
		}else{
			cout<<endl<<"Ups! Ese ingrediente ya existe."<<endl;
		}
	    
	}else{
		cout<<endl<<"Ups! La receta no pudo ser encontrada."<<endl;
	}   
}

int BaseDatos::menuBaseDatos(){
    int opcion;

    do{
        system("cls"); 
        cout<<"~~Menu~~"<<endl;
        cout<<"1.Agregar receta"<<endl
        <<"2.Buscar receta"<<endl
        <<"3.Borrar receta"<<endl
        <<"4.Imprimir todas las recetas"<<endl
        <<"5.Modificar nombre de una receta"<<endl
        <<"6.Modificar cantidad de un ingrediente de una receta"<<endl
        <<"7.Agregar ingrediente a una receta"<<endl
        <<"8.Salir."<<endl<<endl;
        cout<<"Ingrese una opcion del menu: "; cin>>opcion;

        switch(opcion){
            case 1:
                agregarRecetasMenu();
                system("pause>nul");
            break;
            case 2:
                buscarRecetasMenu();
                system("pause>nul");

            break;
            case 3:
                eliminarRecetasMenu();
                system("pause>nul");

            break;
            case 4:
                imprimirRecetasMenu();
                system("pause>nul");
            break;
            case 5:
                modificarNombreRMenu();
                system("pause>nul");
            break;
            case 6:
                modificarCantidadIMenu();
                system("pause>nul");
            break;
            case 7:
                agregarIngredienteMenu();
                system("pause>nul");
            break;
        }
    }while(opcion!=8);
    return 0;
}

//~~~~~~~~~~~~~~~~~~~MAIN~~~~~~~~~~~~~~~~~~~

int main(int argc, char *argv[])
{
	BaseDatos *recetario=new BaseDatos();
	recetario->menuBaseDatos();
}

