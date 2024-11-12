# Importar la librería.
from tkinter import *

# Crear la ventana.
ventana = Tk()
# Modificar el título de la ventana.
ventana.title("Inicio")

# Abrir la ventana en el centro de la pantalla.

# Métodos para obtener el ancho y alto de la pantalla.
ancho_pantalla = ventana.winfo_screenwidth()
alto_pantalla = ventana.winfo_screenheight()

ancho_ventana = 400
alto_ventana = 200

posicion_x = (ancho_pantalla - ancho_ventana) // 2
posicion_y = (alto_pantalla - alto_ventana) // 2

# Modificar el tamaño y el posicionamiento de la ventana.
ventana.geometry(f"{ancho_ventana}x{alto_ventana}+{posicion_x}+{posicion_y}")
# Deshablitar la posibilidad de cambiar el tamaño de la ventana.
ventana.resizable(False, False)

# Ejecuta el bucle principal.
ventana.mainloop()