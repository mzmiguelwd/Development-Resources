#include <iostream>

using namespace std;

class Caso {
    private:
        string numero, idCliente, nombreCliente;
    public:
        // Constructores
        Caso(): numero(""), idCliente(""), nombreCliente("") {};
        Caso(string numero, string idCliente, string nombreCliente):
        numero(numero), idCliente(idCliente), nombreCliente(nombreCliente) {};
        // getters
        string getNumero();
        string getIdCliente();
        string getNombreCliente();
        // setters
        void setNumero(string numero);
        void setIdCliente(string idCliente);
        void setNombreCliente(string nombreCliente);
        // Procesos
        void imprimirDatos();
};

string Caso::getNumero() { return numero; }
string Caso::getIdCliente() { return idCliente; }
string Caso::getNombreCliente() { return nombreCliente; }

void Caso::setNumero(string numero) { this->numero = numero; }
void Caso::setIdCliente(string idCliente) { this->idCliente = idCliente; }
void Caso::setNombreCliente(string nombreCliente) { this->nombreCliente = nombreCliente; }

void Caso::imprimirDatos() {
    cout << "| " << numero << " | " << idCliente << " | " << nombreCliente << " |" << endl;
}