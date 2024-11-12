#include <iostream>

using namespace std;

class Pasajero {
    private:
        string id, nombre, tipoViajero;
        int numSilla;
    public:
        // Constructores
        Pasajero(): id(""), nombre(""), tipoViajero(""), numSilla(0) {};
        Pasajero(string id, string nombre, string tipoViajero, int numSilla):
        id(id), nombre(nombre), tipoViajero(tipoViajero), numSilla(numSilla) {};

        // getters
        string getId();
        string getNombre();
        string getTipoViajero();
        int getNumSilla();

        // setters
        void setId(string id);
        void setNombre(string nombre);
        void setTipoViajero(string tipoViajero);
        void setNumSilla(int numSilla);
};

string Pasajero::getId() { return id; }
string Pasajero::getNombre() { return nombre; }
string Pasajero::getTipoViajero() { return tipoViajero; }
int Pasajero::getNumSilla() { return numSilla; }

void Pasajero::setId(string id) { this->id = id; }
void Pasajero::setNombre(string nombre) { this->nombre = nombre; }
void Pasajero::setTipoViajero(string tipoViajero) { this->tipoViajero = tipoViajero; }
void Pasajero::setNumSilla(int numSilla) { this->numSilla = numSilla; }