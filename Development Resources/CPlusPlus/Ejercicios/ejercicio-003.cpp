/* 1. Realice eun programa que lea de la entrada estándar los siguientes datos
de una persona:

    Edad: dato de tipo entero.
    Sexo: dato de tipo caracter.
    Altura en metros: dato de tipo real.

Tras leer los datos, el programa debe mostrarlos en la salida estándar. */

#include <iostream>

using namespace std;

int main() {
    
    int edad;
    char sexo[10];
    float altura;
    
    cout << "Digite su edad: "; cin >> edad;
    cout << "Digite su sexo: "; cin >> sexo;
    cout << "Digite su altura en metros: "; cin >> altura;
    
    cout << "\nLa edad ingresada es: " << edad << endl;
    cout << "El sexo ingresado es: " << sexo << endl;
    cout << "La altura ingresada es: " << altura << endl;
    
    return 0;
    
}

/* 2. Ejecute el programa del ejercicio anterior con entradas erróneas
y observe los resultados. Por ejemplo, introduzca un dato de tipo
caracter cuando se espera un dato de tipo entero. */