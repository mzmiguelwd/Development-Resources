#include <iostream>
#include <vector>
#include "Caso.h"

using namespace std;

class Abogado {
    private:
        string id, nombre, telefono, correo, especialidad;
        vector<Caso> casos;
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
        void buscarCasoPorNumero(string numero);
        void editarDatos(string nuevoTel, string nuevoCorreo, string nuevaEspecialidad);
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
    cout << "| " << id << " | " << nombre << " | " << telefono << " | " << correo << " | " << especialidad << " |" << endl;
}

void Abogado::addCaso(Caso c) {
    casos.push_back(c);
}

void Abogado::buscarCasoPorNumero(string numero) {
    for (int i = 0; i < casos.size(); i++) {
        if (casos[i].getNumero() == numero) {
            cout << "Caso encontrado para el abogado " << nombre << ":" << endl;
            cout << "| Número caso | Id cliente | Nombre cliente |" << endl;
            casos[i].imprimirDatos();
            return;
        }
    }
    cout << "Caso no encontrado para el abogado " << nombre << endl;
}

void Abogado::editarDatos(string nuevoTelefono, string nuevoCorreo, string nuevaEspecialidad) {
    setTelefono(nuevoTelefono);
    setCorreo(nuevoCorreo);
    setEspecialidad(nuevaEspecialidad);
}

void Abogado::imprimirCasos() {
    cout << "| Id | Nombre | Teléfono | Correo | Especialidad |" << endl; 
    cout << "| " << id << " | " << nombre << " | " << telefono << " | " << correo << " | " << especialidad << " |" << endl;
    cout << "Casos asignados:" << endl;
    cout << "| Número caso | Id Cliente | Nombre Cliente |" << endl;
    for (int i = 0; i < casos.size(); i++) {
        casos[i].imprimirDatos();
        cout << "--------------------------------------------------------" << endl;
    }
}

int Abogado::buscarAbogadoPorCaso(string numCaso) {
    int aux;
    for (int i = 0; i < casos.size(); i++) {
        if (casos[i].getNumero() == numCaso) {
            aux = 1;
            return aux;
        }
    }
    return 0;
}