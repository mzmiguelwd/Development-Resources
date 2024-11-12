#include "Empresa.h"
#include <iostream>
#include <string>
using namespace std;

Empresa::Empresa()
{
    cantidadCorrespondencias = 0;
}

void Empresa::ingresarCorrespondencia() {
    if (cantidadCorrespondencias >= 50) {
        cout << "Capacidad maxima alcanzada." << endl;
        return;
    }

    string nombre, barrio, tipo, aux;
    int codigo;

    cout << "Ingrese el nombre del destinatario: ";
    getline(cin, nombre);
    cout << "Ingrese el barrio de destino: ";
    getline(cin, barrio);
    cout << "Ingrese el tipo de correspondencia (comercial, institucional, informal): ";
    getline(cin, tipo);
    cout << "Ingrese el codigo (100-999): ";
    getline(cin, aux);
    codigo = stoi(aux);

    if (nombre == "" or barrio == "" or (codigo < 100 or codigo > 999) or
        (tipo != "comercial" and tipo != "institucional" and tipo != "informal")) {
        cout << "Datos incorrectos. No se pudo ingresar la correspondencia." << endl;
        return;
    }

    for (int i = 0; i < cantidadCorrespondencias; i++) {
        if (correspondencias[i].getCodigo() == codigo) {
            cout << "Ya existe una correspondencia con ese código." << endl;
            return;
        }
    }

    correspondencias[cantidadCorrespondencias++] = Correspondencia(codigo, nombre, barrio, tipo);
    cout << "Correspondencia ingresada exitosamente." << endl;
}

void Empresa::totalCorrespondenciaPorTipo() {
    int comercial = 0, institucional = 0, informal = 0;
    for (int i = 0; i < cantidadCorrespondencias; i++) {
        string tipo = correspondencias[i].getTipo();
        if (tipo == "comercial") {
            comercial++;
        } else if (tipo == "institucional") {
            institucional++;
        } else if (tipo == "informal") {
            informal++;
        }
    }
    cout << "***** La cantidad de correspondencia por tipo *****" << endl;
    cout << "Institucional: " << institucional << endl;
    cout << "Comercial: " << comercial << endl;
    cout << "Informal: " << informal << endl;
}

void Empresa::correspondenciaPorBarrio() {
    string barrio;
    cout << "Ingrese el barrio del que quiere hacer la búsqueda: ";
    getline(cin, barrio);

    int contador = 0;
    cout << "La cantidad de correspondencia del barrio " << barrio << " son: " << endl;
    for (int i = 0; i < cantidadCorrespondencias; i++) {
        if (correspondencias[i].getBarrio() == barrio) {
            cout << correspondencias[i].getCodigo() << " " 
                 << correspondencias[i].getNombre() << " " 
                 << correspondencias[i].getTipo() << endl;
            contador++;
        }
    }
    cout << "Total correspondencias en " << barrio << ": " << contador << endl;
}