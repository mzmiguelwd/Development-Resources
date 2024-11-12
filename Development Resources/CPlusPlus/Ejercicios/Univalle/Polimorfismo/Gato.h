#include <iostream>
#include "Animal.h"

using namespace std;

class Gato: public Animal {
    public:
        // Constructores
        Gato(string nombre): Animal(nombre) {}

        // Procesos
        void imprimirDatos() {
            cout << "Gato: " << getNombre() << endl;
            cout << "Maulla" << endl;
        }
};