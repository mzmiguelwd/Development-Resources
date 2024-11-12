/* 1. La calificación final de un estudiante es la media ponderada de tres notras:
La nota de prácticas que cuenta un 30% del total, la nota teórica que cuenta un
60% y la nota de participación que cuenta el 10% restante. Escriba un programa que
lea de la entrada estándar las tres notas de un alumno y escriba en la primera
salida estándar su nota final. */

#include <iostream>

using namespace std;

int main() {
    
    float nota1, nota2, nota3, x = 0;
    
    cout << "Ingrese la nota de prácticas (30%): "; cin >> nota1;
    cout << "Ingrese la nota teórica (60%): "; cin >> nota2;
    cout << "Ingrese la nota de participación (10%): "; cin >> nota3;
    
    x = (nota1*0.3) + (nota2*0.6) + (nota3*0.1);
    
    cout << "La calificación final ponderada del estudiante es: " << x << endl;
    
    return 0;
    
}