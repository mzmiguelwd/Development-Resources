from tkinter import *

operacion = ""

def limpiar():
    global operacion
    operacion = ""
    e_pantalla.delete(0, END)

def escribe0():
    global operacion
    operacion += "0"
    e_pantalla.delete(0, END)
    e_pantalla.insert(0, operacion)

def escribe1():
    global operacion
    operacion += "1"
    e_pantalla.delete(0, END)
    e_pantalla.insert(0, operacion)

def escribe2():
    global operacion
    operacion += "2"
    e_pantalla.delete(0, END)
    e_pantalla.insert(0, operacion)

def escribe3():
    global operacion
    operacion += "3"
    e_pantalla.delete(0, END)
    e_pantalla.insert(0, operacion)

def escribe4():
    global operacion
    operacion += "4"
    e_pantalla.delete(0, END)
    e_pantalla.insert(0, operacion)

def escribe5():
    global operacion
    operacion += "5"
    e_pantalla.delete(0, END)
    e_pantalla.insert(0, operacion)

def escribe6():
    global operacion
    operacion += "6"
    e_pantalla.delete(0, END)
    e_pantalla.insert(0, operacion)

def escribe7():
    global operacion
    operacion += "7"
    e_pantalla.delete(0, END)
    e_pantalla.insert(0, operacion)

def escribe8():
    global operacion
    operacion += "8"
    e_pantalla.delete(0, END)
    e_pantalla.insert(0, operacion)

def escribe9():
    global operacion
    operacion += "9"
    e_pantalla.delete(0, END)
    e_pantalla.insert(0, operacion)

def escribe_mas():
    global operacion
    operacion += " + "
    e_pantalla.delete(0, END)
    e_pantalla.insert(0, operacion)

def calcular():
    global operacion
    resultado = 0
    lista_a_sumar = operacion.split(" + ")
    for i in lista_a_sumar:
        a = int(i)
        resultado += a
    e_pantalla.delete(0, END)
    e_pantalla.insert(0, resultado)

ventana = Tk()
ventana.geometry("300x300")

e_pantalla = Entry(ventana, width=300)

b_1 = Button(ventana, text="1", command=escribe1)
b_2 = Button(ventana, text="2", command=escribe2)
b_3 = Button(ventana, text="3", command=escribe3)
b_4 = Button(ventana, text="4", command=escribe4)
b_5 = Button(ventana, text="5", command=escribe5)
b_6 = Button(ventana, text="6", command=escribe6)
b_7 = Button(ventana, text="7", command=escribe7)
b_8 = Button(ventana, text="8", command=escribe8)
b_9 = Button(ventana, text="9", command=escribe9)
b_0 = Button(ventana, text="0", command=escribe0)
b_mas = Button(ventana, text="+", command=escribe_mas)
b_clear = Button(ventana, text="Clear", command=limpiar)
b_enter = Button(ventana, text="Enter", command=calcular)

e_pantalla.place(x=20, y=20, width=110, height=40)
b_1.place(x=20, y=70, width=30, height=30)
b_2.place(x=60, y=70, width=30, height=30)
b_3.place(x=100, y=70, width=30, height=30)
b_4.place(x=20, y=110, width=30, height=30)
b_5.place(x=60, y=110, width=30, height=30)
b_6.place(x=100, y=110, width=30, height=30)
b_7.place(x=20, y=150, width=30, height=30)
b_8.place(x=60, y=150, width=30, height=30)
b_9.place(x=100, y=150, width=30, height=30)
b_0.place(x=60, y=190, width=30, height=30)
b_mas.place(x=100, y=190, width=30, height=30)
b_clear.place(x=20, y=230, width=50, height=30)
b_enter.place(x=80, y=230, width=50, height=30)

ventana.mainloop()