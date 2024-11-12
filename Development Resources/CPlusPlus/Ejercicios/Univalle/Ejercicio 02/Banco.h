#include <iostream>
#include <vector>
#include "Cuenta.h"

using namespace std;

class Banco {
    private:
        vector<Cuenta> cuentas;
        vector<Cliente> clientes;
    public:
        // Constructor
        Banco() {};

        // Métodos
        void addCuenta(Cuenta c);
        void deleteCuenta(string num);
        void addCliente(Cliente c);
        void addClientes(Cliente c1, Cliente c2);
        void addClientesCuenta(Cliente c);
        void deleteCliente(string id);
        void imprimirDatosClientes();
        void imprimirDatosCuentas();
        double calcularPromedio();
        void imprimirDatos();
};

void Banco::addCuenta(Cuenta c) {
    cuentas.push_back(c);
}

void Banco::deleteCuenta(string num) {
    for (int i = 0; i < cuentas.size(); i++) {
        if (cuentas[i].getNumero() == num) {
            cuentas.erase(cuentas.begin() + i);
            cout << "Cuenta eliminada" << endl;
        }
    }
}

void Banco::addCliente(Cliente c) {
    clientes.push_back(c);
}

void Banco::addClientes(Cliente c1, Cliente c2) {
    clientes.push_back(c1);
    clientes.push_back(c2);
}

void Banco::addClientesCuenta(Cliente c) {
    clientes.push_back(c);
}

void Banco::deleteCliente(string id) {
    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i].getID() == id) {
            clientes.erase(clientes.begin() + i);
            cout << "Cliente eliminado" << endl;
        }
    }
}

void Banco::imprimirDatosClientes() {
    cout << "Clientes: " << endl;
    cout << "ID\tNombre\tTeléfono" << endl;
    for (int i = 0; i < clientes.size(); i++) {
        cout << clientes[i].getID() << "\t" << clientes[i].getNombre() << "\t" << clientes[i].getTelefono() << endl;
    }
}

void Banco::imprimirDatosCuentas() {
    cout << "Cuentas: " << endl;
    cout << "Número\tSaldo" << endl;
    for (int i = 0; i < cuentas.size(); i++) {
        cout << cuentas[i].getNumero() << "\t" << cuentas[i].getSaldo() << endl;
    }
}

double Banco::calcularPromedio() {
    double suma = 0;
    for (int i = 0; i < cuentas.size(); i++) {
        suma += cuentas[i].getSaldo();
    }
    return suma / cuentas.size();
}

void Banco::imprimirDatos() {
    cout << "Datos completos:" << endl;
    for (int i = 0; i < cuentas.size(); i++) {
        cuentas[i].imprimirDatos();
        cout << "------------------------" << endl;
    }
}