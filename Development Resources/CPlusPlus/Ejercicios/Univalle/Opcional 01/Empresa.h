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
        void imprimirAbogadosCasos();
        void imprimirAbogadosPorEspecialidad(string especialidad);
        void especialidadMasComun();
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

void Empresa::imprimirAbogadosCasos() {
    for (int i = 0; i < abogados.size(); i++) {
        cout << "**********************************************************************" << endl;
        abogados[i].imprimirCasos();
    }
}

void Empresa::imprimirAbogadosPorEspecialidad(string especialidad) {
    cout << "Abogados de la especialidad " << especialidad << ":" << endl;
    cout << "| Id | Nombre | Teléfono | Correo | Especialidad |" << endl;
    for (int i = 0; i < abogados.size(); i++) {
        if (abogados[i].getEspecialidad() == especialidad) {
            cout << "| " << abogados[i].getId() << " | " << abogados[i].getNombre() << " | " << abogados[i].getTelefono() << " | " << abogados[i].getCorreo() << " | " << abogados[i].getEspecialidad() << " |" << endl;
        }
    }
}

void Empresa::especialidadMasComun() {
    int cantLaboral = 0, cantPenal = 0, cantAdministrativo = 0;

    for (int i = 0; i < abogados.size(); i++) {
        if (abogados[i].getEspecialidad() == "Penal") {
            cantPenal += 1;
        } else if (abogados[i].getEspecialidad() == "Administrativo") {
            cantAdministrativo += 1;
        } else if (abogados[i].getEspecialidad() == "Laboral") {
            cantLaboral += 1;
        }
    }

    if (cantLaboral > cantPenal && cantLaboral > cantAdministrativo) {
        cout << "La especialidad más común en la firma es: Laboral." << endl;
        cout << "Hay " << cantLaboral << " abogados con esa especialidad." << endl;
    } else if (cantPenal > cantLaboral && cantPenal > cantAdministrativo) {
        cout << "La especialidad más común en la firma es: Penal." << endl;
        cout << "Hay " << cantPenal << " abogados con esa especialidad." << endl;
    } else if (cantAdministrativo > cantLaboral && cantAdministrativo > cantPenal) {
        cout << "La especialidad más común en la firma es: Administrativo." << endl;
        cout << "Hay " << cantAdministrativo << " abogados con esa especialidad." << endl;
    } else if (cantLaboral == cantPenal && cantLaboral > cantAdministrativo) {
        cout << "Las 2 especialidades más comúnes son: Laboral y Penal." << endl;
        cout << "Hay " << cantLaboral << " abogados con cada especialidad respectivamente." << endl;
    } else if (cantLaboral == cantAdministrativo && cantLaboral > cantPenal) {
        cout << "Las 2 especialidades más comúnes son: Laboral y Administrativo." << endl;
        cout << "Hay " << cantLaboral << " abogados con cada especialidad respectivamente." << endl;
    } else if (cantPenal == cantAdministrativo && cantPenal > cantLaboral) {
        cout << "Las 2 especialidades más comúnes son: Penal y Administrativo." << endl;
        cout << "Hay " << cantPenal << " abogados con cada especialidad respectivamente." << endl;
    } else {
        cout << "Las 3 especialidades tienen la misma cantidad de abogados." << endl;
        cout << "Hay " << cantPenal << " abogados en cada especialidad respectivamente." << endl;
    }
}