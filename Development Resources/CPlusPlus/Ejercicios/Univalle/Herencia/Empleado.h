#include <iostream>
#include "Persona.h"

using namespace std;

class Empleado: public Persona {
    protected:
        int salario;
    public:
        // Constructores
        Empleado(): Persona("", ""), salario(0) {}
        Empleado(string id, string nombre, int salario):
            Persona(id, nombre), salario(salario) {}
        
        // getters
        int getSalario();

        // setters
        void setSalario(int salario);

        // Procesos
        void imprimirDatos() override;
};

int Empleado::getSalario() { return salario; }

void Empleado::setSalario(int salario) { this->salario = salario; }

void Empleado::imprimirDatos() {
    Persona::imprimirDatos();
    cout << "Salario: " << this->salario << endl;
}