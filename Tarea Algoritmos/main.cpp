#include "estructuras.h"
#include "listas.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int prioridadOperac(char c)
{
switch(c)    {
	case '^':
		return 6;
		break;
	case '*':
		return 5;
		break;
	case '/':
		return 4;
		break;
	case '+':
		return 3;
		break;
	case '-':
		return 2;
		break;
	default:
		return 1;
	}
}
	

void algPostfijo(string operacion){
	stringstream ss;
	string s;
	char c;
	Pila *pilaOperadores=new Pila();
	//ListaSimple *listaOrdenada=new listaSimple();
	
	for(int i=0 ; i<operacion.size();i++){
		if(pilaOperadores->empty()){
			ss<<operacion[i];
			ss>>s;
			pilaOperadores->push(s);
			continue;
		}else if((operacion[i] == '+') || (operacion[i] == '-') 
				|| (operacion[i] == '*') || (operacion[i] == '/') 
				|| (operacion[i] == '^')|| (operacion[i] == '(') 
				|| (operacion[i] == ')')){
		
			s=pilaOperadores->tope->dato;
			char *cstr = &s[0];
			char valor=*cstr;
			
			if(operacion[i]==')'){
				ss<<operacion[i];
				ss>>s;
				pilaOperadores->push(s)
				
			}else if(operacion[i]==')'){
				//Otra funcion
			}
			if(prioridadOperac(operacion[i])<prioridadOperac(valor)){
				
				
			}
{
			}
		}
		}
	}

  
	
int main(int argc, char** argv) {
	string operacion;
	cout<<"Ingrese la operacion infija, por favor: ";getline(cin, operacion);
	algPostfijo(operacion);
 
    return (0);
}
  
