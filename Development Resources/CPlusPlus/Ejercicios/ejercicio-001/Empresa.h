#include <iostream>
#include <vector>
#include "Correspondencia.h"

using namespace std;

class Empresa {
    private:
        vector<Correspondencia> correspondenciasEmpresa;
    public:
        // Métodos
        void ingresarCorrespondencia(Correspondencia c);
        void totalCorrespondenciaPorTipo();
        void correspondenciaPorBarrio();
};

void Empresa::ingresarCorrespondencia(Correspondencia c) {
    if (correspondenciasEmpresa.size() >= 50) {
        cout << "Capacidad máxima alcanzada." << endl;
        return;
    }

    int codigo;
    string nombre, barrio, tipo, aux;

    cout << "Ingrese el código (100-999): "; getline(cin, aux);
    codigo = stoi(aux);
    cout << "Ingrese el nombre del destinatario: "; getline(cin, nombre);
    cout << "Ingrese el barrio de destino: "; getline(cin, barrio);
    cout << "Ingrese el tipo de correspondencia (comercial, institucional, informal): "; getline(cin, tipo);

    if (nombre == "" or barrio == "" or codigo < 100 or codigo > 999 or (tipo != "comercial" and tipo != "institucional" and tipo != "informal")) {
        cout << "Datos incorrectos. No se pudo ingresar la correspondencia." << endl;
        return;
    }

    for (int i = 0; i < correspondenciasEmpresa.size(); i++) {
        if (correspondenciasEmpresa[i].getCodigo() == codigo) {
            cout << "Ya existe una correspondencia con ese código." << endl;
            return;
        }
    }

    c.setCodigo(codigo);
    c.setNombre(nombre);
    c.setBarrio(barrio);
    c.setTipo(tipo);

    correspondenciasEmpresa.push_back(c);
    cout << "Correspondencia ingresada exitosamente." << endl;
}

void Empresa::totalCorrespondenciaPorTipo() {
    int comercial = 0, institucional = 0, informal = 0;
    for (int i = 0; i < correspondenciasEmpresa.size(); i++) {
        string tipo = correspondenciasEmpresa[i].getTipo();
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
    cout << "Ingrese el barrio del que quiere hacer la búsqueda: "; getline(cin, barrio);

    int contador = 0;
    cout << "La correspondencia del barrio " << barrio << " es: " << endl;
    cout << "código\tnombre\ttipo" << endl;
    for (int i = 0; i < correspondenciasEmpresa.size(); i++) {
        if (correspondenciasEmpresa[i].getBarrio() == barrio) {
            cout << correspondenciasEmpresa[i].getCodigo() << " " << correspondenciasEmpresa[i].getNombre() << " " << correspondenciasEmpresa[i].getTipo() << endl;
            contador++;
        }
    }
    cout << "Total de correspondencias en " << barrio << ": " << contador << endl;
}