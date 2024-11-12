#ifndef Animal_H
#define Animal_H

using namespace std;

class Animal {
    protected:
        string nombre;
    public:
        // Constructores
        Animal(): nombre("") {}
        Animal(string nombre):
            nombre(nombre) {}
        
        // getters
        string getNombre();

        // setters
        void setNombre(string nombre);

        // Procesos
        virtual void imprimirDatos() = 0;
};

string Animal::getNombre() { return nombre; }

void Animal::setNombre(string nombre) { this->nombre = nombre; }

#else
    class Animal;
#endif