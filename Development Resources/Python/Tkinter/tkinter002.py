"""
Esta interfaz permite calcular la suma, el producto
o la división entre dos números ingresados por el usuario.
"""

# Importar la librería
from tkinter import *

# Funcionalidades

def suma():
    # Obtener los valores
    valor_a = int(e_num_a.get())
    valor_b = int(e_num_b.get())

    # Realizar los cálculos
    resultado = valor_a + valor_b

    # Mostrar los resultados
    e_resultado.delete(0, END)
    e_resultado.insert(0, resultado)

def producto():
    # Obtener los valores
    valor_a = int(e_num_a.get())
    valor_b = int(e_num_b.get())

    # Realizar los cálculos
    resultado = valor_a * valor_b

    # Mostrar los resultados
    e_resultado.delete(0, END)
    e_resultado.insert(0, resultado)

def division():
    # Obtener los valores
    valor_a = int(e_num_a.get())
    valor_b = int(e_num_b.get())

    # Realizar los cálculos
    resultado = valor_a / valor_b

    # Mostrar los resultados
    e_resultado.delete(0, END)
    e_resultado.insert(0, resultado)

# Crear la ventana
ventana = Tk()
# Modificar las dimensiones de la ventana
ventana.geometry("200x300")

# Crear los componentes

# Etiquetas
l_num_a = Label(ventana, text="Número a")
l_num_b = Label(ventana, text="Número b")
l_resultado = Label(ventana, text="Resultado")

# Entradas
e_num_a = Entry(ventana, width=10)
e_num_b = Entry(ventana, width=10)
e_resultado = Entry(ventana, width=20)

# Botones
b_suma = Button(ventana, text="+", command=suma)
b_producto = Button(ventana, text="*", command=producto)
b_division = Button(ventana, text="/", command=division)

# Empaquetar los componentes en la ventana
l_num_a.pack(pady=5)
e_num_a.pack(pady=5)
l_num_b.pack(pady=5)
e_num_b.pack(pady=5)
l_resultado.pack(pady=5)
e_resultado.pack(pady=5)
b_suma.pack(pady=5)
b_producto.pack(pady=5)
b_division.pack(pady=5)

# Muestra todo en pantalla y responde a la entrada
# del usuario hasta que el programa termina
ventana.mainloop()