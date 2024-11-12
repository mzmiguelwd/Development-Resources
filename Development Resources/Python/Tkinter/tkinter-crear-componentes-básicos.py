# Importar la librería.
from tkinter import *

# Crear la ventana.
ventana = Tk()
# Modificar el título de la ventana.
ventana.title("Inicio")
# Modificar el tamaño de la ventana.
ventana.geometry("380x120+50+50")
# Deshablitar la posibilidad de cambiar el tamaño de la ventana.
ventana.resizable(False, False)

# Crear los componentes.

# Crear etiquetas.
l_etiqueta1 = Label(ventana, text="Etiqueta #1")
l_etiqueta2 = Label(ventana, text="Etiqueta #2")
l_etiqueta3 = Label(ventana, text="Etiqueta #3")

# Crear entradas.
e_entrada1 = Entry(ventana, width=20)
e_entrada2 = Entry(ventana, width=20)
e_entrada3 = Entry(ventana, width=20)

# Crear botones.
b_boton1 = Button(ventana, text="Botón #1")
b_boton2 = Button(ventana, text="Botón #2")
b_boton3 = Button(ventana, text="Botón #3")

# Empaquetar los componentes en la ventana.
l_etiqueta1.place(x=20, y=20, width=100, height=20)
e_entrada1.place(x=20, y=50, width=100, height=20)
b_boton1.place(x=20, y=80, width=100, height=20)
l_etiqueta2.place(x=140, y=20, width=100, height=20)
e_entrada2.place(x=140, y=50, width=100, height=20)
b_boton2.place(x=140, y=80, width=100, height=20)
l_etiqueta3.place(x=260, y=20, width=100, height=20)
e_entrada3.place(x=260, y=50, width=100, height=20)
b_boton3.place(x=260, y=80, width=100, height=20)

# Ejecuta el bucle principal.
ventana.mainloop()