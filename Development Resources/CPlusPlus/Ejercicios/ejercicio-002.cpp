/* 1. Escribe un programa que lea de la entrada estándar el precio de un producto
y muestre en la salida estándar el precio del producto al aplicarle el IVA. */

#include <iostream>

using namespace std;

int main() {

    int precio_producto;
    float iva = 0.19, precio_final = 0;

    cout << "Digite el precio del producto: "; cin >> precio_producto;

    precio_final = (precio_producto * 0.19) + precio_producto;

    cout << "El precio final del producto con IVA es de: $" << precio_final << endl;

    return 0;

}