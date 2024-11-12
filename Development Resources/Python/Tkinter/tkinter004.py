"""
Esta interfaz permite calcular el área y el perímetro
de un rectángulo de acuerdo al valor de la base y la
altura ingresada por el usuario.
"""

# Importar la librería
from tkinter import *

# Funcionalidades

def calcular():
    # Obtener los valores
    base = int(e_base.get())
    altura = int(e_altura.get())

    # Realizar los calculos
    area = base * altura
    perimetro = (2*base) + (2*altura)

    # Mostrar los resultados
    e_area.delete(0, END)
    e_area.insert(0, area)
    e_perimetro.delete(0, END)
    e_perimetro.insert(0, perimetro)

# Crear la ventana
ventana = Tk()
# Modificar las dimensiones de la ventana
ventana.geometry("200x300")

# Crear los componentes

# Etiquetas
l_base = Label(ventana, text="Base")
l_altura = Label(ventana, text="Altura")
l_area = Label(ventana, text="Área")
l_perimetro = Label(ventana, text="Perímetro")

# Entradas
e_base = Entry(ventana, width=20)
e_altura = Entry(ventana, width=20)
e_area = Entry(ventana, width=20)
e_perimetro = Entry(ventana, width=20)

# Botones
b_calcular = Button(ventana, text="Calcular valores", command=calcular)

# Empaquetar los componentes en la ventana
l_base.pack(pady=5)
e_base.pack(pady=5)
l_altura.pack(pady=5)
e_altura.pack(pady=5)
b_calcular.pack(pady=5)
l_area.pack(pady=5)
e_area.pack(pady=5)
l_perimetro.pack(pady=5)
e_perimetro.pack(pady=5)

# Muestra todo en pantalla y responde a la entrada
# del usuario hasta que el programa termina
ventana.mainloop()