# Importar la librería
from tkinter import *

# Crear la matriz
resultados = [[0 for c in range(3)] for f in range(4)]

resultados[0][0] = 1
resultados[1][0] = 2
resultados[2][0] = 3
resultados[3][0] = 4

resultados[0][1] = 5
resultados[1][1] = 6
resultados[2][1] = 7
resultados[3][1] = 8

resultados[0][2] = 9
resultados[1][2] = 1
resultados[2][2] = 2
resultados[3][2] = 3

# Mostrar la matriz en consola
for i in range(4):
    print(resultados[i])

# Funcionalidades

def estadisticas():
    resultado = 0

    # Obtener los valores
    a = e_sedes.get()
    b = e_candidatos.get()

    # Realizar los cálculos
    
    if (a == "1" and b == "1"):
        resultado = resultados[0][0]
    elif (a == "2" and b == "1"):
        resultado = resultados[1][0]
    elif (a == "3" and b == "1"):
        resultado = resultados[2][0]
    elif (a == "4" and b == "1"):
        resultado = resultados[3][0]
    elif (a == "5" and b == "1"):
        resultado = 0
        for i in range(4):
            resultado += resultados[i][0]
    elif (a == "1" and b == "2"):
        resultado = resultados[0][1]
    elif (a == "2" and b == "2"):
        resultado = resultados[1][1]
    elif (a == "3" and b == "2"):
        resultado = resultados[2][1]
    elif (a == "4" and b == "2"):
        resultado = resultados[3][1]
    elif (a == "5" and b == "2"):
        resultado = 0
        for i in range(4):
            resultado += resultados[i][1]
    elif (a == "1" and b == "3"):
        resultado = resultados[0][2]
    elif (a == "2" and b == "3"):
        resultado = resultados[1][2]
    elif (a == "3" and b == "3"):
        resultado = resultados[2][2]
    elif (a == "4" and b == "3"):
        resultado = resultados[3][2]
    elif (a == "5" and b == "3"):
        resultado = 0
        for i in range(4):
                resultado += resultados[i][2]
    elif (a == "1" or a == "2" or a == "3" or a == "4"):
        a = int(a)
        for i in range(3):
            resultado += resultados[a-1][i]
    elif (a == "5"):
        for i in range(3):
            for j in range(4):
                resultado += resultados[j][i]
        
    # Mostrar los resultados
    e_resultados.delete(0, END)
    e_resultados.insert(0, resultado)

# Crear la ventana
ventana = Tk()
# Modificar las dimensiones de la ventana
ventana.geometry("300x520")

# Crear los componentes

# Etiquetas
l_sedes = Label(ventana, text="Sedes")
l_cali = Label(ventana, text="1. Cali")
l_palmira = Label(ventana, text="2. Palmira")
l_yumbo = Label(ventana, text="3. Yumbo")
l_pacifico = Label(ventana, text="4. Pacifico")
l_todas = Label(ventana, text="5. Todas")
l_candidatos = Label(ventana, text="Candidatos")
l_pepito = Label(ventana, text="1. Pepito")
l_anita = Label(ventana, text="2. Anita")
l_brayan = Label(ventana, text="3. Brayan")
l_decoracion1 = Label(ventana, text="----------------------------------------")
l_decoracion2 = Label(ventana, text="----------------------------------------")
l_decoracion3 = Label(ventana, text="----------------------------------------")

# Entradas
e_sedes = Entry(ventana, width=20)
e_candidatos = Entry(ventana, width=20)
e_resultados = Entry(ventana, width=20)

# Botones
b_votos = Button(ventana, text="Consultar votos", command=estadisticas)

# Empaquetar los componenetes en la ventana
l_decoracion1.pack()
l_sedes.pack(pady=5)
e_sedes.pack(pady=5)
l_cali.pack(pady=5)
l_palmira.pack(pady=5)
l_yumbo.pack(pady=5)
l_pacifico.pack(pady=5)
l_todas.pack(pady=5)
l_decoracion2.pack()
l_candidatos.pack(pady=5)
e_candidatos.pack(pady=5)
l_pepito.pack(pady=5)
l_anita.pack(pady=5)
l_brayan.pack(pady=5)
l_decoracion3.pack()
b_votos.pack(pady=5)
e_resultados.pack(pady=5)

# Muestra todo en pantalla y responde a la entrada
# del usuario hasta que el programa termina
ventana.mainloop()