#include <iostream>
#include <math.h>

using namespace std;

class Cliente {
    private:
        string id, nombre, fecNac;
        double peso, estatura;
    
    public:
        // Constructores
        Cliente(): id(""), nombre(""), fecNac(""), peso(0), estatura(0) {};
        Cliente(string id, string nombre, string fecNac, double peso, double estatura):
        id(id), nombre(nombre), fecNac(fecNac), peso(peso), estatura(estatura) {};
        
        // getters
        string getId();
        string getNombre();
        string getFecNac();
        double getPeso();
        double getEstatura();
        
        // setters
        void setId(string id);
        void setNombre(string nombre);
        void setFecNac(string fecNac);
        void setPeso(double peso);
        void setEstatura(double estatura);
        
        // Métodos
        double calcularIMC();
        string calcularNivelPeso();
        int calcularEdad();
};

string Cliente::getId() { return id; }
string Cliente::getNombre() { return nombre; }
string Cliente::getFecNac() { return fecNac; }
double Cliente::getPeso() { return peso; }
double Cliente::getEstatura() { return estatura; }

void Cliente::setId(string id) { this->id = id; }
void Cliente::setNombre(string nombre) { this->nombre = nombre; }
void Cliente::setFecNac(string fecNac) { this->fecNac = fecNac; }
void Cliente::setPeso(double peso) { this->peso = peso; }
void Cliente::setEstatura(double estatura) { this->estatura = estatura; }

double Cliente::calcularIMC() {
    double imc;
    imc = peso / pow(estatura, 2);
    return imc;
}

string Cliente::calcularNivelPeso() {
    cout << "Esto es una prueba! " << endl;
    double imc = calcularIMC();
    if (imc < 18.5) {
        return "Bajo peso";
    } else if (imc >= 18.5 && imc <= 24.9) {
        return "Normal";
    } else if (imc >= 25 && imc <= 29.9) {
        return "Sobrepeso";
    } else {
        return "Obesidad";
    }
}

int Cliente::calcularEdad() {
    return 0;
}