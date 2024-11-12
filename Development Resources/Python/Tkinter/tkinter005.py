"""
Esta interfaz permite realizar la conversión
de pesos a dólares, euros o libras.
"""

# Importar la librería
from tkinter import *

# Funcionalidades

def pesos_dolares():
    dolar = 3070

    # Obtener los valores
    pesos = int(e_pesos.get())

    # Realizar los cálculos
    resultado = pesos / dolar

    # Mostrar los resultados
    e_resultado.delete(0, END)
    e_resultado.insert(0, resultado)

def pesos_euros():
    euro = 3406

    # Obtener los valores
    pesos = int(e_pesos.get())

    # Realizar los cálculos
    resultado = pesos / euro

    # Mostrar los resultados
    e_resultado.delete(0, END)
    e_resultado.insert(0, resultado)

def pesos_libras():
    libra = 3824

    # Obtener los valores
    pesos = int(e_pesos.get())

    # Realizar los cálculos
    resultado = pesos / libra

    # Mostrar los resultados
    e_resultado.delete(0, END)
    e_resultado.insert(0, resultado)

# Crear la ventana
ventana = Tk()
# Modificar las dimensiones de la ventana
ventana.geometry("250x230")

# Crear los componentes

# Etiquetas
l_pesos = Label(ventana, text="Valor en pesos")

# Entradas
e_pesos = Entry(ventana, width=20)
e_resultado = Entry(ventana, width=20)

# Botones
b_dolares = Button(ventana, text="Dólares", command=pesos_dolares)
b_euros = Button(ventana, text="Euros", command=pesos_euros)
b_libras = Button(ventana, text="Libras", command=pesos_libras)

# Empaquetar los componentes en la ventana
l_pesos.pack(pady=5)
e_pesos.pack(pady=5)
b_dolares.pack(pady=5)
b_euros.pack(pady=5)
b_libras.pack(pady=5)
e_resultado.pack(pady=5)

# Muestra todo en pantalla y responde a la entrada
# del usuario hasta que el programa termina
ventana.mainloop()