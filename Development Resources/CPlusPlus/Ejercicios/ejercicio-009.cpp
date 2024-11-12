/* 1. Escriba un programa que lea la nota final de cuatro alumnos
y calcule la nota final media de los cuatro alumnos. */

#include <iostream>

using namespace std;

int main() {

    float a, b, c, d, x = 0;
    
    cout << "Ingrese la nota del primer estudiante: "; cin >> a;
    cout << "Ingrese la nota del segundo estudiante: "; cin >> b;
    cout << "Ingrese la nota del tercer estudiante: "; cin >> c;
    cout << "Ingrese la nota del cuarto estudiante: "; cin >> d;
    
    x = (a+b+c+d) / 4;
    
    cout << "La nota final media de los cuatro alumnos es: " << x << endl;

    return 0;
    
}