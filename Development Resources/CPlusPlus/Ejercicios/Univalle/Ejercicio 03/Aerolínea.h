#include <iostream>
#include <vector>
#include "Avión.h"

using namespace std;

class Aerolinea {
    private:
        string nombre, nit, sede;
        vector<Pasajero> pasajerosAerolinea;
        vector<Avion> avionesAerolinea;
    public:
    // Constructor
    Aerolinea(): nombre (""), nit(""), sede("") {};
    Aerolinea(string nombre, string nit, string sede):
    nombre(nombre), nit(nit), sede(sede) {};

    // Métodos
    void addPasajero(Pasajero p);
    void deletePasajero(string id);
    void addAvion(Avion a);
    void deleteAvion(string numVuelo);
    void imprimirDatosPasajeros();
    void imprimirDatosAviones();
    void imprimirPasajerosPorTipo();
    void imprimirCantidadPasajerosPorVuelo();
    void imprimirDatos();
    void imprimirResumenGeneral();
    void imprimirPasajeros();
};

void Aerolinea::addPasajero(Pasajero p) {
    pasajerosAerolinea.push_back(p);
}

void Aerolinea::deletePasajero(string id) {
    for (int i = 0; i < pasajerosAerolinea.size(); i++) {
        if (pasajerosAerolinea[i].getId() == id) {
            pasajerosAerolinea.erase(pasajerosAerolinea.begin() + i);
            cout << "Pasajero eliminado" << endl;
        }
    }
}

void Aerolinea::addAvion(Avion a) {
    avionesAerolinea.push_back(a);
}

void Aerolinea::deleteAvion(string numVuelo) {
    for (int i = 0; i < avionesAerolinea.size(); i++) {
        if (avionesAerolinea[i].getNumVuelo() == numVuelo) {
            avionesAerolinea.erase(avionesAerolinea.begin() + i);
            cout << "Avión eliminado" << endl;
        }
    }
}

void Aerolinea::imprimirDatosPasajeros() {
    cout << "Pasajeros: " << endl;
    cout << "Id\tNombre\tTipo de pasajero" << endl;
    for (int i = 0; i < pasajerosAerolinea.size(); i++) {
        cout << pasajerosAerolinea[i].getId() << "\t" << pasajerosAerolinea[i].getNombre() << "\t" << pasajerosAerolinea[i].getTipoViajero() << endl;
    }
}

void Aerolinea::imprimirDatosAviones() {
    cout << "Aviones: " << endl;
    cout << "Vuelo \tSillas - Turista\tSillas - Ejecutiva" << endl;
    for (int i = 0; i < avionesAerolinea.size(); i++) {
        cout << avionesAerolinea[i].getNumVuelo() << "\t" << avionesAerolinea[i].getNumSillasTurista() << "\t" << avionesAerolinea[i].getNumSillasEjecutiva() << endl;
    }
}

void Aerolinea::imprimirPasajerosPorTipo() {
    cout << "Pasajeros en clase turista:" << endl;
    cout << "Id\t|Nombre\t|Vuelo\t|Tipo de viajero\t|Número de silla" << endl;
    for (int i = 0; i < avionesAerolinea.size(); i++) {
        avionesAerolinea[i].imprimirTurista();
    }
    cout << "Pasajeros en clase ejecutiva:" << endl;
    cout << "Id\t|Nombre\t|Vuelo\t|Tipo de viajero\t|Número de silla" << endl;
    for (int i = 0; i < avionesAerolinea.size(); i++) {
        avionesAerolinea[i].imprimirEjecutiva();
    }
}

void Aerolinea::imprimirCantidadPasajerosPorVuelo() {
    for (int i = 0; i < avionesAerolinea.size(); i++) {
        cout << "Vuelo " << avionesAerolinea[i].getNumVuelo() << "| Sillas turista: " << avionesAerolinea[i].getNumSillasTurista() << "| Sillas ejecutiva: " << avionesAerolinea[i].getNumSillasEjecutiva() << " | Pasajeros: " << avionesAerolinea[i].cantidadPasajeros() << endl;
    }
}

void Aerolinea::imprimirDatos() {
    for (int i = 0; i < avionesAerolinea.size(); i++) {
        avionesAerolinea[i].imprimirDatos();
        cout << "-------------------------" << endl;
    }
}

void Aerolinea::imprimirResumenGeneral() {
    cout << "Aerolínea: " << nombre << endl;
    cout << "NIT: " << nit << endl;
    cout << "Sede: " << sede << endl;
    imprimirDatosAviones();
    imprimirDatosPasajeros();
}