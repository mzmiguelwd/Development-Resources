"""
Esta interfaz permite calcular el cuadrado
de un número ingresado por el usuario.
"""

# Importar la librería
from tkinter import *

# Funcionalidades

def calcular_cuadrado():
    # Obtener los valores
    valor_a = int(e_valor_a.get())

    # Realizar los cálculos
    cuadrado = valor_a ** 2

    # Mostrar los resultados
    e_resultado.delete(0, END)
    e_resultado.insert(0, cuadrado)

# Crear la ventana
ventana = Tk()
# Modificar las dimensiones de la ventana
ventana.geometry("200x170")

# Crear los componentes

# Etiquetas
l_valor_a = Label(ventana, text="Valor a")
l_resultado = Label(ventana, text="Resultado")

# Entradas
e_valor_a = Entry(ventana, width=20)
e_resultado = Entry(ventana, width=20)

# Botones
b_potencia = Button(ventana, text="Calcular a^2", command=calcular_cuadrado)

# Empaquetar los componentes en la ventana
l_valor_a.pack(pady=5)
e_valor_a.pack(pady=5)
b_potencia.pack(pady=5)
l_resultado.pack(pady=5)
e_resultado.pack(pady=5)

# Muestra todo en pantalla y responde a la entrada
# del usuario hasta que el programa termina
ventana.mainloop()