#include <iostream>
#include <vector>
#include "Cliente.h"

using namespace std;

class Cuenta {
    private:
        string numero;
        long saldo;
        vector<Cliente> clientesCuenta;
    public:
        // Constructores
        Cuenta(): numero(""), saldo(0) {};
        Cuenta(string numero, long saldo):
        numero(numero), saldo(saldo) {};

        // getters
        string getNumero();
        long getSaldo();
        
        // setters
        void setNumero(string numero);
        void setSaldo(long saldo);
        
        // Métodos
        void addCliente(Cliente c);
        void imprimirDatos();
        void realizarConsignacion(long cantidad);
        void realizarRetiro(long cantidad);
};

string Cuenta::getNumero() { return numero; }
long Cuenta::getSaldo() { return saldo; }

void Cuenta::setNumero(string numero) { this->numero = numero; }
void Cuenta::setSaldo(long saldo) { this->saldo = saldo; }

void Cuenta::addCliente(Cliente c) {
    clientesCuenta.push_back(c);
}

void Cuenta::imprimirDatos() {
    cout << "Cuenta: " << numero << endl;
    cout << "Saldo: " << saldo << endl;
    cout << "Clientes de la cuenta: " << endl;
    cout << "ID\tNombre\tTeléfono" << endl;
    for (int i = 0; i < clientesCuenta.size(); i++) {
        cout << clientesCuenta[i].getID() << "\t" << clientesCuenta[i].getNombre() << "\t" << clientesCuenta[i].getTelefono() << endl;
    }
}

void Cuenta::realizarConsignacion(long cantidad) {
    saldo += cantidad;
}

void Cuenta::realizarRetiro(long cantidad) {
    saldo -= cantidad;
}