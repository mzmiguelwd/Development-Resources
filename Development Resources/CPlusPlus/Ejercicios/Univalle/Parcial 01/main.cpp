#include <iostream>
#include "Empresa.h"

using namespace std;

int main() {

    // Creamos la empresa.
    Empresa empresa("Abogados UNIVALLE SA", "00112233");

    // Creamos 5 abogados.
    Abogado abogado1("123", "Juan", "1234567890", "juanabogado@gmail.com", "Penal");
    Abogado abogado2("234", "María", "2345678901", "mariaabogado@gmail.com", "Laboral");
    Abogado abogado3("345", "Camilo", "3456789012", "camiloabogado@gmail.com", "Administrativo");
    Abogado abogado4("456", "Daniela", "4567890123", "danielabogado@gmail.com", "Penal");
    Abogado abogado5("567", "Miguel", "5678901234", "miguelabogado@gmail.com", "Laboral");

    // Creamos 10 casos.
    Caso caso1("12345", "1234", "Carlos");
    Caso caso2("23456", "2345", "Sebastian");
    Caso caso3("34567", "3456", "Andres");
    Caso caso4("45678", "4567", "Emerson");
    Caso caso5("56789", "5678", "Jhon");
    Caso caso6("67890", "6789", "Sofia");
    Caso caso7("78901", "7890", "Vanesa");
    Caso caso8("89012", "8901", "Natalia");
    Caso caso9("90123", "9012", "Isabella");
    Caso caso10("01234", "0123", "Sara");

    // Le asignamos los casos a un abogado.
    abogado1.addCaso(caso1);
    abogado1.addCaso(caso2);
    abogado2.addCaso(caso3);
    abogado2.addCaso(caso4);
    abogado3.addCaso(caso5);
    abogado3.addCaso(caso6);
    abogado4.addCaso(caso7);
    abogado4.addCaso(caso8);
    abogado5.addCaso(caso9);
    abogado5.addCaso(caso10);

    // Agregamos los abogados a la empresa.
    empresa.addAbogado(abogado1);
    empresa.addAbogado(abogado2);
    empresa.addAbogado(abogado3);
    empresa.addAbogado(abogado4);
    empresa.addAbogado(abogado5);

    // Generar un informe integral que abarque los datos de los abogados y de sus casos.
    empresa.generarInforme();

    // Editar los datos de un abogado.
    // Cambiar el id, nombre, telefono, correo y la especialidad.
    cout << "\n******************************************" << endl;
    cout << "Datos abogado1 ANTES de la modificación:\n" << endl;
    abogado1.imprimirDatos();
    cout << "------------------------------------------" << endl;
    cout << "Datos abogado1 DESPUÉS de la modificación:\n" << endl;
    abogado1.setId("789");
    abogado1.setNombre("Antonio");
    abogado1.setTelefono("012348895");
    abogado1.setCorreo("antonioabogado@gmail.com");
    abogado1.setEspecialidad("Administrativo");
    abogado1.imprimirDatos();
    cout << "******************************************" << endl;

    // Buscar la información de un abogado y sus casos asignados.
    cout << "\n******************************************" << endl;
    cout << "La información del abogado que le corresponde el caso es:" << endl;
    empresa.buscarAbogadoPorCaso("01234");
    cout << "******************************************" << endl;
}