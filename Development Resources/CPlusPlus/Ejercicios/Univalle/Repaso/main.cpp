#include <iostream>
#include "Empresa.h"

using namespace std;

int main() {
    int opcion;
    string numCaso, id, nuevoTelefono, nuevoCorreo, nuevaEspecialidad;
    
    Empresa firma("Abogados UNIVALLE", "0194832");
    
    // Crear abogados.
    Abogado abogado1("A01", "Juan", "3646347", "juanabogado@gmail.com", "Penal");
    Abogado abogado2("A02", "Camilo", "9879678", "camiloabogado@gmail.com", "Administrativo");
    
    // Agregar abogados a la firma.
    firma.addAbogado(abogado1);
    firma.addAbogado(abogado2);
    
    // Crear casos.
    Caso caso1("1", "20", "Carlitos");
    Caso caso2("2", "24", "Sandra");
    
    // Asignar casos a los abogados.
    firma.buscarAbogadoPorId("A01").addCaso(caso1);
    firma.buscarAbogadoPorId("A02").addCaso(caso2);

    do {
        // Mostrar el menú de opciones.
        cout << "--- Menú ---" << endl;
        cout << "1. Buscar abogado y sus casos por número de caso." << endl;
        cout << "2. Editar los datos de un abogado." << endl;
        cout << "3. Generar un informe integral." << endl;
        cout << "4. Salir." << endl;

        // Pedir al usuario que seleccione una opción.
        cout << "Seleccione una opción: "; cin >> opcion;

        // Ejecutar la acción correspondiente a la acción seleccionada.
        switch (opcion) {
        case 1:
            cout << "Has seleccionado la opción 1." << endl;
            cout << "Digite el número de caso que desea buscar: "; cin >> numCaso;
            firma.buscarAbogadoPorCaso(numCaso);
            break;
        case 2:
            cout << "Has seleccionado la opción 2." << endl;
            cout << "Digite el id del abogado que desea editar los datos: "; cin >> id;
            cout << "Digite el nuevo número de teléfono: "; cin >> nuevoTelefono;
            cout << "Digite el nuevo correo: "; cin >> nuevoCorreo;
            cout << "Digite la nueva especialidad: "; cin >> nuevaEspecialidad;
            firma.buscarAbogadoPorId(id).editarDatos(nuevoTelefono, nuevoCorreo, nuevaEspecialidad);
            break;
        case 3:
            cout << "Has seleccionado la opción 3." << endl;
            firma.generarInforme();
            break;
        case 4:
            cout << "Has seleccionado la opción 4." << endl;
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, intenta de nuevo." << endl;
            break;
        }
    } while (opcion != 4);

    return 0;
}