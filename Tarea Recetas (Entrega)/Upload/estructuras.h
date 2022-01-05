//Mónica Alfaro Parrales. Carnet: 2020132572

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <string>

using namespace std; 

struct Ingrediente{
    string nombreI;
    string unidadMedida;
    double cantidad;

    Ingrediente(){
        nombreI="";
        unidadMedida="";
        cantidad=0.0;
    }

    Ingrediente(string nombreIng, string unidadM, double cantidadIng){
        nombreI=nombreIng;
        unidadMedida=unidadM;
        cantidad=cantidadIng;
    }
    void imprimirIngrediente();
};

struct Receta{
    string nombreR;
    double porciones;
    Ingrediente arregloIngredientes[50];
    int cantidadIngredientes=0;

    Receta(){
        nombreR="";
        porciones=0.0;
    }

    Receta(string nombreRec, double porcionesRec){
        nombreR=nombreRec;
        porciones=porcionesRec;
    }

    void agregarReceta(Ingrediente *ingrediente1);
    void imprimirReceta();
    int buscarIngrediente(string nombreIngresado);
    

};

struct BaseDatos{
    Receta arregloRecetas[1000];
    int cantidadRecetas=0;
    
    BaseDatos(){
	}

    //Funciones del menu:
    void agregarRecetasMenu();
    void buscarRecetasMenu();
    void eliminarRecetasMenu();
    void imprimirRecetasMenu();
    void modificarNombreRMenu();
    void modificarCantidadIMenu();
    void agregarIngredienteMenu();
    int menuBaseDatos();

    //Metodos del Struct BaseDatos:
    void agregarRecetaBD(Receta *recetaBD);
    void imprimirBaseDatos();
    int buscarReceta(string nombreIngresado);
    void borrarReceta(string nombreIngresado);
    void modificarNombreR(string nuevoNombre, int posicion);
    void modificarCantidadI(int cantidadIng, int posicion, int posicion2);
    

};
