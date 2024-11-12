#include <iostream>
#include "Persona.h"

using namespace std;

int main() {
    Persona sara, pedro("10200300", "Pedro Perez");
    sara.setId("18100200");
    sara.setNombre("Sara Fernandez");

    cout << "Persona 1" << endl;
    cout << "Identificación: " << sara.getId() << endl;
    cout << "Nombre: " << sara.getNombre() << endl;

    cout << "Persona 2" << endl;
    cout << "Identificación: " << pedro.getId() << endl;
    cout << "Nombre: " << pedro.getNombre() << endl;

    return 0;
}