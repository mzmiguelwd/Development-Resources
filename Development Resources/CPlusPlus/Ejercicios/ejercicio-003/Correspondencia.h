#ifndef CORRESPONDENCIA_H
#define CORRESPONDENCIA_H
#include <string>
using namespace std;
class Correspondencia {
    private:
    int codigo;
    string nombre;
    string barrio;
    string tipo;

    public:
    Correspondencia();
    Correspondencia(int cod, string nom, string bar, string tip);
    int getCodigo();
    string getNombre();
    string getBarrio();
    string getTipo();
};

#else
class Correspondencia;
#endif