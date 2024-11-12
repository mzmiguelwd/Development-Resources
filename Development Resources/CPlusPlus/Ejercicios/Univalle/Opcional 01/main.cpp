#include <iostream>
#include "Empresa.h"

using namespace std;

int main() {
    int opcion;
    string especialidad;

    Empresa firma("Abogados UNIVALLE", "0194832");

    // Creamos 10 casos.
    Caso caso1("1", "C01", "Carlos");
    Caso caso2("2", "C02", "Sandra");
    Caso caso3("3", "C03", "Emerson");
    Caso caso4("4", "C04", "Sofia");
    Caso caso5("5", "C05", "Vanesa");
    Caso caso6("6", "C06", "Catalina");
    Caso caso7("7", "C07", "Carolina");
    Caso caso8("8", "C08", "Isabella");
    Caso caso9("9", "C09", "Sara");
    Caso caso10("10", "C10", "Danna");

    // Creamos 4 abogados.
    Abogado abogado1("A01", "Juan", "1234567", "juanabogado@gmail.com", "Penal");
    Abogado abogado2("A02", "Natalia", "2345678", "nataliabogada@gmail.com", "Laboral");
    Abogado abogado3("A03", "Diana", "3456789", "dianaabogada@gmail.com", "Administrativo");
    Abogado abogado4("A04", "Miguel", "4567890", "miguelabogado@gmail.com", "Penal");

    // Asignamos casos a los abogados.
    abogado1.addCaso(caso1);
    abogado1.addCaso(caso2);
    abogado1.addCaso(caso3);
    abogado2.addCaso(caso4);
    abogado2.addCaso(caso5);
    abogado2.addCaso(caso6);
    abogado3.addCaso(caso7);
    abogado3.addCaso(caso8);
    abogado4.addCaso(caso9);
    abogado4.addCaso(caso10);

    // Agregar abogados a la firma.
    firma.addAbogado(abogado1);
    firma.addAbogado(abogado2);
    firma.addAbogado(abogado3);
    firma.addAbogado(abogado4);

    do {
        // Mostrar el menú de opciones.
        cout << "\n--- Menú ---" << endl;
        cout << "1. Imprimir los datos de los abogados y la cantidad de casos asignados." << endl;
        cout << "2. Mostrar los datos de los abogados clasificados por especialidad legal." << endl;
        cout << "3. Desplegar la especialidad legal más común en la firma." << endl;
        cout << "4. Salir." << endl;

        // Pedir al usuario que seleccione una opción.
        cout << "Seleccione una opción: "; cin >> opcion;

        // Ejecutar la acción correspondiente a la acción seleccionada.
        switch (opcion) {
        case 1:
            cout << "Has seleccionado la opción 1.\n" << endl;
            firma.imprimirAbogadosCasos();
            break;
        case 2:
            cout << "Has seleccionado la opción 2.\n" << endl;
            cout << "Digite la especialidad que desea clasificar (Laboral), (Penal), (Administrativo): "; cin >> especialidad;
            firma.imprimirAbogadosPorEspecialidad(especialidad);
            break;
        case 3:
            cout << "Has seleccionado la opción 3.\n" << endl;
            cout << "************************************************" << endl;
            firma.especialidadMasComun();
            cout << "************************************************" << endl;
            break;
        case 4:
            cout << "Has seleccionado la opción 4.\n" << endl;
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, intenta de nuevo." << endl;
            break;
        }
    } while (opcion != 4);

    return 0;
}