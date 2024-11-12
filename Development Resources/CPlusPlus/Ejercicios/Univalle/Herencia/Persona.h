#include <iostream>

using namespace std;

class Persona {
    protected:
        string id, nombre;
    public:
        // Constructores
        Persona(): id(""), nombre("") {}
        Persona(string id, string nombre):
            id(id), nombre(nombre) {}
        
        // getters
        string getId();
        string getNombre();

        // setters
        void setId(string id);
        void setNombre(string nombre);

        // Procesos
        virtual void imprimirDatos();
};

string Persona::getId() { return id; }
string Persona::getNombre() { return nombre; }

void Persona::setId(string id) { this->id = id; }
void Persona::setNombre(string nombre) { this->nombre = nombre; }

void Persona::imprimirDatos() {
    cout << "Id: " << this->id << endl;
    cout << "Nombre: " << this->nombre << endl;
}