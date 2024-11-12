#include <iostream>
#include "EmpleadoOcasional.h"

using namespace std;

int main() {
    Persona juan, ana("1010", "Ana Maria");
    Empleado andres, fernanda("1011", "Maria Fernanda", 2500);
    EmpleadoOcasional luis, andrea("1012", "Andrea Rodriguez", 2600, 15);

    cout << "-----------------------------" << endl;
    juan.imprimirDatos();
    cout << "-----------------------------" << endl;
    ana.imprimirDatos();
    cout << "-----------------------------" << endl;
    andres.imprimirDatos();
    cout << "-----------------------------" << endl;
    fernanda.imprimirDatos();
    cout << "-----------------------------" << endl;
    luis.imprimirDatos();
    cout << "-----------------------------" << endl;
    andrea.imprimirDatos();
    cout << "-----------------------------" << endl;
}