#include <iostream>
#include <vector>
#include "Abogado.h"

using namespace std;

class Empresa {
    private:
        string nombre, nit;
        vector<Abogado> abogadosEmpresa;
    public:
        // Constructores
        Empresa(): nombre(""), nit("") {};
        Empresa(string nombre, string nit):
        nombre(nombre), nit(nit) {};

        // getters
        string getNombre();
        string getNit();

        // setters
        void setNombre(string nombre);
        void setNit(string nit);

        // Procesos
        void imprimirDatos();
        void addAbogado(Abogado a);
        void generarInforme();
        void buscarAbogadoPorCaso(string numCaso);
};

string Empresa::getNombre() { return nombre; }
string Empresa::getNit() { return nit; }

void Empresa::setNombre(string nombre) { this->nombre = nombre; }
void Empresa::setNit(string nit) { this->nit = nit; }

void Empresa::imprimirDatos() {
    cout << "Nombre: " << nombre << endl;
    cout << "Nit: " << nit << endl;
}

void Empresa::addAbogado(Abogado a) {
    abogadosEmpresa.push_back(a);
}

void Empresa::generarInforme() {
    cout << "********************************" << endl;
    cout << "INFORME GENERAL" << endl;
    cout << "--------------------------------" << endl;
    cout << "*** Datos de la empresa ***" << endl;
    imprimirDatos();
    cout << "--------------------------------" << endl;
    cout << "*** Abogados de la firma ***" << endl;
    cout << "--------------------------------" << endl;
    for (int i = 0; i < abogadosEmpresa.size(); i++) {
        cout << "" << endl;
        abogadosEmpresa[i].imprimirDatos();
        cout << "\nCasos a su cargo: " << endl;
        abogadosEmpresa[i].imprimirCasos();
        cout << "--------------------------------" << endl;
    }
}

void Empresa::buscarAbogadoPorCaso(string numCaso) {
    for (int i = 0; i < abogadosEmpresa.size(); i++) {
        abogadosEmpresa[i].buscarAbogadoPorCaso(numCaso);
        if (abogadosEmpresa[i].buscarAbogadoPorCaso(numCaso) == 1) {
            abogadosEmpresa[i].imprimirDatos();
            abogadosEmpresa[i].imprimirCasos();
        }
    }
}