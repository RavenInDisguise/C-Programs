#include <iostream>

using namespace std; //Librerías básicas como un print en consola

/*
Buenas tardes, my dudes. :)
*/

int main(int argc, char** argv) { //Comentario de prueba

    cout << "Hola Mundo " << 1 << endl; //Se concantenan prints con <<
    if (argc < 1){
        cout << "No tengo argumentos" << endl;
    } else {
        cout << "Tengo argumentos: " << endl;
        cout << argv [0] << endl;
    }
    cout << argc << endl;
    cout << 1+1 << endl;

    system("pause");

    return 0;
}