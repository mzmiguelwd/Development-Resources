#include <iostream>

using namespace std;

class Correspondencia {
    private:
        int codigo;
        string nombre, barrio, tipo;
    public:
        // Constructores
        Correspondencia(): codigo(0), nombre(""), barrio(""), tipo("") {};
        Correspondencia(int codigo, string nombre, string barrio, string tipo):
        codigo(codigo), nombre(nombre), barrio(barrio), tipo(tipo) {};

        // getters
        int getCodigo();
        string getNombre();
        string getBarrio();
        string getTipo();

        // setters
        void setCodigo(int codigo);
        void setNombre(string nombre);
        void setBarrio(string barrio);
        void setTipo(string tipo);

        // Métodos
};

int Correspondencia::getCodigo() { return codigo; }
string Correspondencia::getNombre() { return nombre; }
string Correspondencia::getBarrio() { return barrio; }
string Correspondencia::getTipo() { return tipo; }

void Correspondencia::setCodigo(int codigo) { this->codigo = codigo; }
void Correspondencia::setNombre(string nombre) { this->nombre = nombre; }
void Correspondencia::setBarrio(string barrio) { this->barrio = barrio; }
void Correspondencia::setTipo(string tipo) { this->tipo = tipo; }