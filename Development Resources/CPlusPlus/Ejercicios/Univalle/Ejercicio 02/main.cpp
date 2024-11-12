#include <iostream>
#include "Banco.h"

using namespace std;

int main() {
    Banco banco;
    Cliente adrian("Adrian", "Rodriguez", "12345678");
    Cliente juan("Juan", "Perez", "87654321");
    banco.addClientes(adrian, juan);
    Cuenta cta1("12345", 100000);
    Cuenta cta2("67890", 50000);
    cta1.addCliente(adrian);
    cta1.addCliente(juan);
    cta1.imprimirDatos();
    cta2.addCliente(adrian);
    cta2.realizarConsignacion(150000);
    cta2.realizarRetiro(15000);
    banco.addCuenta(cta1);
    banco.addCuenta(cta2);
    
    cout << "1------------------------" << endl;
    cta2.imprimirDatos();
    
    cout << "2------------------------" << endl;
    banco.imprimirDatosClientes();
    
    cout << "3------------------------" << endl;
    banco.imprimirDatosCuentas();
    
    cout << "4------------------------" << endl;
    cout << "Promedio de saldos: " << banco.calcularPromedio() << endl;
    
    cout << "5------------------------" << endl;
    banco.imprimirDatos();
}