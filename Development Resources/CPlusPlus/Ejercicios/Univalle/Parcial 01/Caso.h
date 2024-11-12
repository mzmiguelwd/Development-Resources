#include <iostream>

using namespace std;

class Caso {
    private:
        string numCaso, numIdCliente, nombreCliente;

    public:
        // Constructores
        Caso(): numCaso(""), numIdCliente(""), nombreCliente("") {};
        Caso(string numCaso, string numIdCliente, string nombreCliente):
        numCaso(numCaso), numIdCliente(numIdCliente), nombreCliente(nombreCliente) {};

        // getters
        string getNumCaso();
        string getNumIdCliente();
        string getNombreCliente();

        // setters
        void setNumCaso(string numCaso);
        void setNumIdCliente(string numIdCliente);
        void setNombreCliente(string nombreCliente);

        // Procesos
        void imprimirDatos();
};

string Caso::getNumCaso() { return numCaso; }
string Caso::getNumIdCliente() { return numIdCliente; }
string Caso::getNombreCliente() { return nombreCliente; }

void Caso::setNumCaso(string numCaso) { this->numCaso = numCaso; }
void Caso::setNumIdCliente(string numIdCliente) { this->numIdCliente = numIdCliente; }
void Caso::setNombreCliente(string nombreCliente) { this->nombreCliente = nombreCliente; }

void Caso::imprimirDatos() {
    cout << "Número de caso: " << numCaso << endl;
    cout << "Id del cliente: " << numIdCliente << endl;
    cout << "Nombre del cliente: " << nombreCliente << endl;
}