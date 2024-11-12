#include <iostream>
#include <vector>
#include "Abogado.h"

using namespace std;

class Empresa {
    private:
        string nombre, nit;
        vector<Abogado> abogados;
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
        Abogado& buscarAbogadoPorId(string id);
        void generarInforme();
        void buscarAbogadoPorCaso(string numCaso);
};

string Empresa::getNombre() { return nombre; }
string Empresa::getNit() { return nit; }

void Empresa::setNombre(string nombre) { this->nombre = nombre; }
void Empresa::setNit(string nit) { this->nit = nit; }

void Empresa::imprimirDatos() {
    cout << "| " << nombre << " | " << nit << " |" << endl;
}

void Empresa::addAbogado(Abogado a) {
    abogados.push_back(a);
}

Abogado& Empresa::buscarAbogadoPorId(string id) {
    for (int i = 0; i < abogados.size(); i++) {
        if (abogados[i].getId() == id) {
            return abogados[i];
        }
    }
    throw runtime_error("Abogado no encontrado");
}

void Empresa::generarInforme() {
    cout << "*********************" << endl;
    cout << "INFORME GENERAL" << endl;
    cout << "\n| Nombre | NIT |" << endl;
    imprimirDatos();
    cout << "" << endl;
    for (int i = 0; i < abogados.size(); i++) {
        cout << "Abogado:" << endl;
        abogados[i].imprimirCasos();
    }
    cout << "*********************" << endl;
}

void Empresa::buscarAbogadoPorCaso(string numCaso) {
    for (int i = 0; i < abogados.size(); i++) {
        abogados[i].buscarAbogadoPorCaso(numCaso);
        if (abogados[i].buscarAbogadoPorCaso(numCaso) == 1) {
            abogados[i].imprimirCasos();
        }
    }
}