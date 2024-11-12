#include <iostream>
#include "Empresa.h"

using namespace std;

int main() {
    Empresa empresa;
    string opcion;
    Correspondencia c;

    while (true) {
        cout << "\n*** MENU ***" << endl;
        cout << "1. Ingresar correspondencia." << endl;
        cout << "2. Mostrar el total de correspondencias por tipo." << endl;
        cout << "3. Mostrar correspondencias por barrio." << endl;
        cout << "4. Salir del programa." << endl;
        cout << "Seleccione una opción: "; getline(cin, opcion);

        if (opcion == "1") {
            empresa.ingresarCorrespondencia(c);
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