#ifndef EMPRESA_H
#define EMPRESA_H

#include "Correspondencia.h"
#include <iostream>

class Empresa 
{
private:
    Correspondencia correspondencias[50];
    int cantidadCorrespondencias;

public:
    Empresa();
    void ingresarCorrespondencia();
    void totalCorrespondenciaPorTipo();
    void correspondenciaPorBarrio();
};
#else
class Empresa;
#endif