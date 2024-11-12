#include "Correspondencia.h"
Correspondencia::Correspondencia()
{
    codigo = 0;
    nombre = "";
    barrio = "";
    tipo = "";
}

Correspondencia::Correspondencia(int cod, string nom, string bar, string tip) 
{
    codigo = cod;
    nombre = nom;
    barrio = bar;
    tipo = tip;
}

int Correspondencia::getCodigo()
{
    return codigo;
}

string Correspondencia::getNombre() 
{
    return nombre;
}

string Correspondencia::getBarrio() 
{
    return barrio;
}

string Correspondencia::getTipo()
{
    return tipo;
}