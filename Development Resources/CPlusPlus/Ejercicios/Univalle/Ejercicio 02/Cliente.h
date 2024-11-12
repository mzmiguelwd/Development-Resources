#include <iostream>

using namespace std;

class Cliente {
    private:
        string id, nombre, telefono;
    public:
        // Constructores
        Cliente(): id(""), nombre(""), telefono("") {};
        Cliente(string id, string nombre, string telefono):
        id(id), nombre(nombre), telefono(telefono) {};
        
        // getters
        string getID();
        string getNombre();
        string getTelefono();
        
        // setters
        void setID(string id);
        void setNombre(string nombre);
        void setTelefono(string telefono);
};

string Cliente::getID() { return id; }
string Cliente::getNombre() { return nombre; }
string Cliente::getTelefono() { return telefono; }

void Cliente::setID(string id) { this->id = id; }
void Cliente::setNombre(string nombre) { this->nombre = nombre; }
void Cliente::setTelefono(string telefono) { this->telefono = telefono; }