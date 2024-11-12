#include <iostream>
#include "Empleado.h"

using namespace std;

class EmpleadoOcasional: public Empleado {
    protected:
        int horasTrabajadas;
    public:
        // Constructores
        EmpleadoOcasional(): Empleado("", "", 0), horasTrabajadas(0) {}
        EmpleadoOcasional(string id, string nombre, int salario, int horas):
            Empleado(id, nombre, salario), horasTrabajadas(horas) {}

        // getters
        int getHorasTrabajadas();
        int getTotalAPagar();

        // setters
        void setHorasTrabajadas(int horas);

        // Procesos
        void imprimirDatos() override;
};

int EmpleadoOcasional::getHorasTrabajadas() { return horasTrabajadas; }
int EmpleadoOcasional::getTotalAPagar() {
    return (getSalario() / 160) * horasTrabajadas;
}

void EmpleadoOcasional::setHorasTrabajadas(int horas) { horasTrabajadas = horas; }

void EmpleadoOcasional::imprimirDatos() {
    Empleado::imprimirDatos();
    cout << "Horas trabajadas: " << getHorasTrabajadas() << endl;
    cout << "Total a pagar: " << getTotalAPagar() << endl;
}