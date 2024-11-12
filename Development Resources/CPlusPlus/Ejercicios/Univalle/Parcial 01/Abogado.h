#include <iostream>
#include <vector>
#include "Caso.h"

using namespace std;

class Abogado {
    private:
        string id, nombre, telefono, correo, especialidad;
        vector<Caso> casosAbogado;
    public:
        // Constructores
        Abogado(): id(""), nombre(""), telefono(""), correo(""), especialidad("") {};
        Abogado(string id, string nombre, string telefono, string correo, string especialidad):
        id(id), nombre(nombre), telefono(telefono), correo(correo), especialidad(especialidad) {};

        // getters
        string getId();
        string getNombre();
        string getTelefono();
        string getCorreo();
        string getEspecialidad();

        // setters
        void setId(string id);
        void setNombre(string nombre);
        void setTelefono(string telefono);
        void setCorreo(string correo);
        void setEspecialidad(string especialidad);

        // Procesos
        void imprimirDatos();
        void addCaso(Caso c);
        void imprimirCasos();
        int buscarAbogadoPorCaso(string numCaso);
};

string Abogado::getId() { return id; }
string Abogado::getNombre() { return nombre; }
string Abogado::getTelefono() { return telefono; }
string Abogado::getCorreo() { return correo; }
string Abogado::getEspecialidad() { return especialidad; }

void Abogado::setId(string id) { this->id = id; }
void Abogado::setNombre(string nombre) { this->nombre = nombre; }
void Abogado::setTelefono(string telefono) { this->telefono = telefono; }
void Abogado::setCorreo(string correo) { this->correo = correo; }
void Abogado::setEspecialidad(string especialidad) { this->especialidad = especialidad; }

void Abogado::imprimirDatos() {
    cout << "Id: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Correo: " << correo << endl;
    cout << "Especialidad: " << especialidad << endl;
}

void Abogado::addCaso(Caso c) {
    casosAbogado.push_back(c);
}

void Abogado::imprimirCasos() {
    for (int i = 0; i < casosAbogado.size(); i++) {
        cout << "" << endl;
        casosAbogado[i].imprimirDatos();
    }
}

int Abogado::buscarAbogadoPorCaso(string numCaso) {
    int aux;
    for (int i = 0; i < casosAbogado.size(); i++) {
        if (casosAbogado[i].getNumCaso() == numCaso) {
            aux = 1;
            return aux;
        }
    }
    return 0;
}