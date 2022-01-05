#include <iostream>
#include "pila.h"

//**********************FUNCIONES LOGICAS**********************

bool esOperando(string i){
	if (i != "+" && i != "-" && i != "*" && i != "/" && i != "^" && i != ")" && i != "("){
		return true;	
	}
	return false;
}

int calcularPrioOperador(string i){
    if (i == "+" || i =="-"){
        return 5;
    }
    else if (i == "*" || i =="/"){
        return 10;
    }
    else if (i == "^"){
        return 15;
        
    }else if(i== "(" || i== ")"){
		return 0;
		
    }else{
    	return -1; //Ninguno, error. Debe entrar en esOperando o en los parentesis.
	}	
}

string calcularPrioGeneral(string operacion){
	Pila *pilaPF= new Pila();
	string posfija="";
	string valorActual="";
	bool valorWhile1;
	bool valorWhile2;
	
	for(int i= 0; i<operacion.size(); i++){ //Recorre el string
		valorWhile2=true; //Declara el valor while 2 en true para posterior uso
		valorActual=operacion[i]; //Valor actual es el char
		if(esOperando(valorActual)){ //Si es un num
			posfija+=valorActual; //Lo une al string final
        }else{
			if(valorActual==")"){ //Si es un parentesis )
				valorWhile1=true; 
				while(valorWhile1){ //Mientras sea true
					string tope=pilaPF->pop()->valor; //El tope es igual al pop
					if(tope=="(" || pilaPF->empty()){ //Si el tope es ( o la pila esta vacia
						valorWhile1=false; //Salga del while
					}else{
						if(calcularPrioOperador(tope)!=0) //Si no es un parentesis 
							posfija+=tope; //Lo une al string final
					}
				}
			}else if(valorActual!="("){ //Si es un parentesis (
				if(pilaPF->empty()) { //Si esta vacia
					pilaPF->push(valorActual); //Push
				}else if(calcularPrioOperador(valorActual) > calcularPrioOperador(pilaPF->tope->valor)){ //Prioridad operacional				
					pilaPF->push(valorActual);
				}else{
					while (valorWhile2){
	                    if(pilaPF->empty()){
	                        pilaPF->push(valorActual);
	                        valorWhile2 = false; //Lo une al string final
	                    }else if(calcularPrioOperador(valorActual) > calcularPrioOperador(pilaPF->tope->valor)){ //Prioridad operacional
							pilaPF->push(valorActual);
							valorWhile2 = false; //Lo une al string final
	                    }
	                    else{
	                        posfija+=pilaPF->pop()->valor; //Lo une al string final
	                    }
					}
				}
			}else{
				pilaPF->push(valorActual); //Push a la pila si no es ni (), ni #
			}
		}
	}
	while(!pilaPF->empty()){
		string tope=pilaPF->pop()->valor;
		posfija+=tope;
	}
	return posfija;		
}

//**********************MAIN**********************

int main(int argc, char** argv) {
	cout<<"Sistema para convertir expresiones infijas en postfijas"<<endl;
	cout<<"Por favor escriba su operacion matematica sin espacios: ";
	string operacion;
	cin>>operacion;
	cout<<endl;
	string posfija=calcularPrioGeneral(operacion);
	cout<<"Su expresion postfija: "<<posfija<<endl;
}

