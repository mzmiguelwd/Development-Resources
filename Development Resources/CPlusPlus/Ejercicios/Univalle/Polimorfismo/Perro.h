#include <iostream>
#include "Animal.h"

using namespace std;

class Perro: public Animal {
    public:
        // Constructores
        Perro(string nombre): Animal(nombre) {}

        // Procesos
        void imprimirDatos() {
            cout << "Perro: " << getNombre() << endl;
            cout << "Ladra" << endl;
        }
};