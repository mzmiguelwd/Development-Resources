import tkinter as tk

# Función que actualiza la etiqueta
def actualizar_texto():
    etiqueta.config(text="Texto actualizado")

# Crear la ventana principal
root = tk.Tk()
root.title("Actualización en respuesta a un botón")

# Crear una etiqueta
etiqueta = tk.Label(root, text="Texto inicial", font=("Helvetica", 16))
etiqueta.pack(pady=20)

# Crear un botón que actualiza la etiqueta cuando se presiona
boton = tk.Button(root, text="Actualizar texto", command=actualizar_texto)
boton.pack(pady=20)

# Ejecutar el bucle principal
root.mainloop()