#include "Empresa.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Empresa empresa;
    string opcion;

    while (true) {
        cout << "\n*** MENU ***" << endl;
        cout << "1. Ingresar correspondencia" << endl;
        cout << "2. Mostrar total de correspondencia por tipo" << endl;
        cout << "3. Mostrar correspondencia por barrio" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        getline(cin, opcion);

        if (opcion == "1") {
            empresa.ingresarCorrespondencia();
        } else if (opcion == "2") {
            empresa.totalCorrespondenciaPorTipo();
        } else if (opcion == "3") {
            empresa.correspondenciaPorBarrio();
        } else if (opcion == "4") {
            break;
        } else {
            cout << "Opción no válida." << endl;
        }
    }

    return 0;
}
