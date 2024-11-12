"""
Esta interfaz permite calcular la suma o la
resta de dos valores ingresados por el usuario.
"""

# Importar la librería
from tkinter import *

# Funcionalidades

def suma():
    # Obtener los valores
    valor_a = int(e_valor_a.get())
    valor_b = int(e_valor_b.get())

    # Realizar los cálculos
    resultado = valor_a + valor_b

    # Mostrar los resultados
    e_resultado.delete(0, END)
    e_resultado.insert(0, resultado)

def resta():
    # Obtener los valores
    valor_a = int(e_valor_a.get())
    valor_b = int(e_valor_b.get())

    # Realizar los cálculos
    resultado = valor_a - valor_b

    # Mostrar los resultados
    e_resultado.delete(0, END)
    e_resultado.insert(0, resultado)

# Crear la ventana
ventana = Tk()
# Modificar las dimensiones de la ventana
ventana.geometry("200x280")

# Crear los componentes

# Etiquetas
l_valor_a = Label(ventana, text="Valor a")
l_valor_b = Label(ventana, text="Valor b")
l_resultado = Label(ventana, text="Resultado")

# Entradas
e_valor_a = Entry(ventana, width=20)
e_valor_b = Entry(ventana, width=20)
e_resultado = Entry(ventana, width=20)

# Botones
b_a_mas_b = Button(ventana, text="a + b", command=suma)
b_a_menos_b = Button(ventana, text="a - b", command=resta)

# Empaquetar los componentes en la ventana
l_valor_a.pack(pady=5)
e_valor_a.pack(pady=5)
l_valor_b.pack(pady=5)
e_valor_b.pack(pady=5)
b_a_mas_b.pack(pady=5)
b_a_menos_b.pack(pady=5)
l_resultado.pack(pady=5)
e_resultado.pack(pady=5)

# Muestra todo en pantalla y responde a la entrada
# del usuario hasta que el programa termina
ventana.mainloop()