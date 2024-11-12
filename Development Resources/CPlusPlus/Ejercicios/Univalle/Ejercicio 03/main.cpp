/*
Integrantes:
Sebastian Niño - 2420488
Juan Manjarrez - 2415330
Andres Lenis - 2419620
*/

#include <iostream>
#include "Aerolínea.h"

using namespace std;

int main() {
    
    int opcion;
    string tipoDeSilla, buscarId;
    
    Aerolinea aerolinea("Alfonso Bonilla", "12345", "Cali");

    // Creamos 6 pasajeros.
    Pasajero pasajero1("123", "Juan", "turista", 12);
    Pasajero pasajero2("234", "Ana", "ejecutiva", 45);
    Pasajero pasajero3("345", "Carlos", "turista", 36);
    Pasajero pasajero4("456", "Carolina", "ejecutiva", 95);
    Pasajero pasajero5("567", "Miguel", "turista", 1);
    Pasajero pasajero6("678", "Sara", "ejecutiva", 4);

    // Creamos 3 aviones.
    Avion avion1("AA123", 100, 20);
    Avion avion2("BB234", 50, 5);
    Avion avion3("CC345", 120, 30);
    
    // Agregamos los pasajeros a su avión correspondiente.
    avion1.addPasajero(pasajero1);
    avion1.addPasajero(pasajero2);
    avion2.addPasajero(pasajero3);
    avion2.addPasajero(pasajero4);
    avion3.addPasajero(pasajero5);
    avion3.addPasajero(pasajero6);

    // Agregamos los pasajeros a la aerolínea.
    aerolinea.addPasajero(pasajero1);
    aerolinea.addPasajero(pasajero2);
    aerolinea.addPasajero(pasajero3);
    aerolinea.addPasajero(pasajero4);
    aerolinea.addPasajero(pasajero5);
    aerolinea.addPasajero(pasajero6);

    // Agregamos los aviones a la aerolinea.
    aerolinea.addAvion(avion1);
    aerolinea.addAvion(avion2);
    aerolinea.addAvion(avion3);

    do {
        // Mostrar el menú de opciones.
        cout << "--- Menú ---" << endl;
        cout << "1. Imprimir pasajeros dependiendo del tipo de silla." << endl;
        cout << "2. Mostrar la silla que le corresponde a un pasajero dependiendo de su id." << endl;
        cout << "3. Imprimir pasajeros agrupados por tipo de viajero." << endl;
        cout << "4. Mostrar los datos de un pasajero de acuerdo a su id." << endl;
        cout << "5. Mostrar un listado con todos los datos de los pasajeros organizados por vuelo." << endl;
        cout << "6. Lista de los datos de los aviones y la cantidad de pasajeros por vuelo." << endl;
        cout << "7. Imprimir resumen general de la aerolínea." << endl;
        cout << "8. Salir." << endl;
        
        // Pedir al usuario que elija una opción.
        cout << "Seleccione una opción: "; cin >> opcion;
        
        // Ejecutar la acción correspondiente a la acción seleccionada.
        switch(opcion) {
            case 1:
                cout << "*****************" << endl;
                cout << "Has seleccionado la opción 1" << endl;
                // Imprimir pasajeros dependiendo del tipo de silla.
                cout << "Digite (turista) o (ejecutiva): "; cin >> tipoDeSilla;
                cout << "-------------------------" << endl;
                avion1.imprimirPasajerosPorTipo(tipoDeSilla);
                cout << "-------------------------" << endl;
                avion2.imprimirPasajerosPorTipo(tipoDeSilla);
                cout << "-------------------------" << endl;
                avion3.imprimirPasajerosPorTipo(tipoDeSilla);
                cout << "-------------------------" << endl;
                break;
            case 2:
                cout << "*****************" << endl;
                cout << "Has seleccionado la opción 2" << endl;
                // Mostrar la silla que le corresponde a un pasajero dependiendo de su id.
                cout << "Digite un id: "; cin >> buscarId;
                cout << "Mostrar la silla que le corresponde a un pasajero dependiendo de su id:" << endl;
                cout << "-------------------------" << endl;
                cout << "Id\t|Vuelo\t|Número de silla" << endl;
                avion1.imprimirSillaPorId(buscarId);
                avion2.imprimirSillaPorId(buscarId);
                avion3.imprimirSillaPorId(buscarId);
                cout << "-------------------------" << endl;
                break;
            case 3:
                cout << "*****************" << endl;
                cout << "Has seleccionado la opción 3" << endl;
                // 5. Imprimir pasajeros agrupados por tipo de viajero.
                cout << "-------------------------" << endl;
                cout << "Imprimir pasajeros agrupados por tipo." << endl;
                cout << "-------------------------" << endl;
                aerolinea.imprimirPasajerosPorTipo();
                break;
            case 4:
                cout << "*****************" << endl;
                cout << "Has seleccionado la opción 4" << endl;
                // 6. Mostrar los datos de un pasajero de acuerdo a su id.
                cout << "-------------------------" << endl;
                cout << "Digite un id: "; cin >> buscarId;
                cout << "Mostrar los datos de un pasajero de acuerdo a su id" << endl;
                cout << "-------------------------" << endl;
                cout << "Id\t|Nombre\t|Vuelo\t|Tipo de viajero\t|Número de silla" << endl;
                avion1.imprimirDatosPorId(buscarId);
                avion2.imprimirDatosPorId(buscarId);
                avion3.imprimirDatosPorId(buscarId);
                break;
            case 5:
                cout << "*****************" << endl;
                cout << "Has seleccionado la opción 5" << endl;
                // 7. Mostrar un listado con todos los datos de los pasajeros organizados por vuelo.
                cout << "-------------------------" << endl;
                cout << "Mostrar un listado con todos los datos de los pasajeros organizados por vuelo." << endl;
                cout << "-------------------------" << endl;
                aerolinea.imprimirDatos();
                break;
            case 6:
                cout << "*****************" << endl;
                cout << "Has seleccionado la opción 6" << endl;
                // 8. Lista de los datos de los aviones y la cantidad de pasajeros por vuelo.
                cout << "-------------------------" << endl;
                cout << "Lista de los datos de los aviones y la cantidad de pasajeros por vuelo." << endl;
                cout << "-------------------------" << endl;
                aerolinea.imprimirCantidadPasajerosPorVuelo();
                break;
            case 7:
                cout << "*****************" << endl;
                cout << "Has seleccionado la opción 7" << endl;
                // 9. Imprimir resumen general de la aerolínea.
                cout << "-------------------------" << endl;
                cout << "Imprimir resumen general de la aerolínea." << endl;
                cout << "-------------------------" << endl;
                aerolinea.imprimirResumenGeneral();
                break;
            case 8:
                cout << "*****************" << endl;
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, intenta de nuevo." << endl;
                break;
        }
    } while (opcion != 8);
    
    return 0;
}