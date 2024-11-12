#include <iostream>
#include "Gato.h"
#include "Perro.h"

using namespace std;

int main() {
    Gato g("minino");
    Perro p("trosky");

    cout << "------------------------------" << endl;
    g.imprimirDatos();
    cout << "------------------------------" << endl;
    p.imprimirDatos();
    cout << "------------------------------" << endl;
}