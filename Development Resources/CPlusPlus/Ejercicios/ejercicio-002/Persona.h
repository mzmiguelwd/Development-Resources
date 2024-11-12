#include <iostream>
#include <string>

using namespace std;

class Persona {
    private:
        string id, nombre;

    public:
        // Constructores
        Persona(): id(""), nombre("") {};
        Persona(string id, string nombre):
        id(id), nombre(nombre) {};

        // getters
        string getId();
        string getNombre();

        // setters
        void setId(string id);
        void setNombre(string nombre);

        // Procesos
};

string Persona::getId() { return id; }
string Persona::getNombre() { return nombre; }

void Persona::setId(string id) { this->id = id; }
void Persona::setNombre(string nombre) { this->nombre = nombre; }