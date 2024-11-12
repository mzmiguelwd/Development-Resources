#include <iostream>
#include "Cliente.h"

using namespace std;

int main() {
    string id, nombre;
    cout << "Ingrese un id: "; cin >> id;
    cin.ignore();
    cout << "Ingrese un nombre: "; getline(cin, nombre);
    Cliente juan, pedro(id, nombre, "10/05/1980", 95, 1.72);
    juan.setId("1010");
    juan.setNombre("Juan Ardila");
    cout << "Datos de Juan" << endl;
    cout << "Id: " << juan.getId() << endl;
    cout << "Nombre: " << juan.getNombre() << endl;
    cout << "Datos de Pedro" << endl;
    cout << "Id: " << pedro.getId() << endl;
    cout << "Nombre: " << pedro.getNombre() << endl;
    cout << "Fecha de nacimiento: " << pedro.getFecNac() << endl;
    cout << "Peso: " << pedro.getPeso() << endl;
    cout << "Estatura: " << pedro.getEstatura() << endl;
    cout << "IMC: " << pedro.calcularIMC() << endl;
    cout << "Nivel de peso: " << pedro.calcularNivelPeso() << endl;
    cout << "Edad: " << pedro.calcularEdad() << endl;
}