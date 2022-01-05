#include <iostream>
#include <math.h>
using namespace std;


// algoritmos con numeros
int cantidadDeDigitos(int); // retorna la cantidad de digitos decimales de un numero entero
int soloPares(int); // dado un numero entero, retorna un numero con solo los digitos pares. Si no hay digitos pares, retorna -1. Considere el 0 como par
int sumarDigito(int numero,int digito); // suma el digito a cada uno de los digitos del numero. Si excede la unidades, debe acarrear
// algoritmos con el arreglo
void imprimir (int[], int); // imprimir el arreglo
double promedio (int[], int); // retorna el promedio del arreglo
int maximoElemento (int[], int); // retorna el elemento maximo del arreglo
int masRepetido (int[], int); // retorna el elemento que m�s se repite en el arreglo, en el ejemplo retorna 90. Si mas de uno se repite, retorne cualquiera de ellos
void incrementarPosicion (int[], int, int index); // incrementa en 1 el valor en la posicion index

// MAIN
int main(int argc, char** argv) {
	cout << "Ejercicios" <<	endl;	
	int arreglo[] = {10,20,30,90,100,50,60,80,80,90,90};
	int size = sizeof(arreglo)/sizeof(arreglo[0]); // determina el tama�o del arreglo
	int numero1= 13050056;
	int digito1=7;
	int index=5;
	cout <<"Elementos del arreglo: "<< size <<endl;
	cout << "Cantidad de dígitos en " << numero1<<":" <<cantidadDeDigitos(numero1) <<endl;
	cout << "Cantidad de pares en " << numero1<<":" <<soloPares(numero1) <<endl;
	cout << "Suma de dígito  " << digito1<<": " <<sumarDigito(numero1,digito1) <<endl;
	cout << "Promedio: " << promedio (arreglo, size)<<endl;
	cout << "Máximo elemento: " << maximoElemento(arreglo, size)<<endl;
	cout << "Más repetido: " << masRepetido(arreglo, size)<<endl;
	incrementarPosicion(arreglo,size, index);
	imprimir(arreglo, size);
	
	return 0;
}

int cantidadDeDigitos(int numero){
	int cantidad= 0;
	while(numero!=0){
		cantidad+=1;
		numero=numero/10;
	}
return cantidad;
}

int soloPares(int numero){
	int cantidad=0;
	while(numero!=0){
		numero=numero/10;
		if(numero%2==0)
			cantidad+=1;
	}
	return cantidad;
}

//HELP!
int sumarDigito(int numero,int digito){
	int num=0;
	int numero2=0;
	int contador=0;
	while (numero!=0){
		num=numero%10;
		numero=numero/10;
		num=num+digito;
		if(num>9)
			num=num-10;
		cout<<num<<endl;
		numero2=numero2+(num*pow(10,contador));
		contador+=1;
		/*
		if(num>9){
			num=num-10;
			numero2=num+pow(10,contador);
			numero2=numero2+1;
		}else{
			numero2=num+pow(10,contador);
		}
		contador+=1;
		*/
	}
	return numero2;
}

/*	E: arreglo y cantidad de elementos
*	S: void
*	D: imprime un arreglo			*/
void imprimir (int array[], int size){
	for (int i = 0; i < size; i++ ){
		cout << "i. " << array[i] << endl; 
	}
}

double promedio (int array[], int size){
	double suma=0;
	double promedio=0;
	for (int i = 0; i < size; i++ ){
		suma+=array[i];
	}
	promedio=suma/size;
	return promedio;
}

int maximoElemento (int array[], int size){
	int numMayor=0;
	for (int i = 0; i < size; i++ ){
		if(array[i]>numMayor)
			numMayor=array[i];	
	}
	return numMayor;
}

//HELP!
int masRepetido(int array[], int size){
	int numRepetido=0;
	for (int i = 0; i < size; i++ ){
		
	}	
	return numRepetido;
}

void incrementarPosicion (int array[], int size, int index){
	for (int i = 0; i < size; i++ ){
		if(i+1==index)
		array[i]+=1;
	}
}