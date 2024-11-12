"""
FUNDAMENTOS DE PROGRAMACIÓN IMPERATIVA - GRUPO 81
PROFESORA: DIANA PATRICIA LOZANO
PROYECTO FINAL - INTERFAZ PIZZERÍA
AUTORES:
    ANDRES LENIS - 2419620
    SEBASTIAN NIÑO - 2420488
    JUAN MANJARREZ - 2415330
FECHA: 10 DE JUNIO DE 2024
"""

# Importar la librería
from tkinter import *

inventario = [[0 for c in range(8)] for f in range(2)]

inventario[0][0] = "Masa"
inventario[1][0] = 100 # Cantidad de masa en bodega.
inventario[0][1] = "Salsa"
inventario[1][1] = 100 # Cantidad de salsa en bodega.
inventario[0][2] = "Queso"
inventario[1][2] = 100 # Cantidad de queso en bodega.
inventario[0][3] = "Pepperoni"
inventario[1][3] = 5 # Cantidad de pepperoni en bodega.
inventario[0][4] = "Salami"
inventario[1][4] = 4 # Cantidad de salami en bodega.
inventario[0][5] = "Champiñones"
inventario[1][5] = 3 # Cantidad de champiñones en bodega.
inventario[0][6] = "Pollo"
inventario[1][6] = 2 # Cantidad de pollo en bodega.
inventario[0][7] = "Piña"
inventario[1][7] = 1 # Cantidad de piña en bodega.

ventas = [[0 for c in range(3)] for f in range(7)]

ventas[0][0] = "Lunes"
ventas[0][1] = 0 # Ventas (número de pizzas) del día lunes.
ventas[0][2] = 0 # Ventas (dinero) del día lunes.
ventas[1][0] = "Martes"
ventas[1][1] = 0 # Ventas (número de pizzas) del día martes.
ventas[1][2] = 0 # Ventas (dinero) del día martes.
ventas[2][0] = "Miércoles"
ventas[2][1] = 0 # Ventas (número de pizzas) del día miércoles.
ventas[2][2] = 0 # Ventas (dinero) del día miércoles.
ventas[3][0] = "Jueves"
ventas[3][1] = 0 # Ventas (número de pizzas) del día jueves.
ventas[3][2] = 0 # Ventas (dinero) del día jueves.
ventas[4][0] = "Viernes"
ventas[4][1] = 0 # Ventas (número de pizzas) del día viernes.
ventas[4][2] = 0 # Ventas (dinero) del día viernes.
ventas[5][0] = "Sábado"
ventas[5][1] = 0 # Ventas (número de pizzas) del día sábado.
ventas[5][2] = 0 # Ventas (dinero) del día sábado.
ventas[6][0] = "Domingo"
ventas[6][1] = 0 # Ventas (número de pizzas) del día domingo.
ventas[6][2] = 0 # Ventas (dinero) del día domingo.

i_base = "Masa, Salsa, Queso" # Ingredientes de la pizza base.
t_pe = ", Pepperoni" # Topping 1.
t_sa = ", Salami" # Topping 2.
t_ch = ", Champiñones" # Topping 3.
t_po = ", Pollo" # Topping 4.
t_pi = ", Piña" # Topping 5.
n_pizza = 1 # Número de la pizza que se está armando.
ingredientes = i_base # Esta variable será modificada en el futuro con las adiciones del cliente.
precio_pizza = 20000 # Precio de la pizza base.
cant_toppings = 0 # Contador de la cantidad de toppings de una pizza.
pedido = "Su pizza #" + str(n_pizza) + " es:\n\n" + ingredientes + "\n\nPrecio pizza: $" + str(precio_pizza + (cant_toppings*5000)) # Acumuladora de cada pizza terminada.
pedido_completo = "" # Acumuladora del pedido terminado.
total_pizzas = 0 # Contador cantidad de pizzas ordenadas.
costo_total = 0 # Acumuladora del precio total de la factura.
dia_seleccionado = 0 # Este puntero nos permite almacenar las ventas en un día de la semana en específico.

ventas_unidades_semana = 0
ventas_ingresos_semana = 0

# Esta función permite calcular las unidades de pizza vendidas
# y los ingresos percibidos por dichas ventas en una semana.
def calculo_ventas_semana():
    global ventas_unidades_semana, ventas_ingresos_semana
    ventas_unidades_semana = 0
    ventas_ingresos_semana = 0
    for i in range(7):
        ventas_unidades_semana += ventas[i][1]
        ventas_ingresos_semana += ventas[i][2]

dia_mayores_ingresos = ""
dia_menores_ingresos = ""

# Esta función permite calcular los días en que se tuvieron
# mayores y menores ingresos durante toda la semana.
def calculo_indicadores():
    global dia_mayores_ingresos, dia_menores_ingresos
    dia_mayores_ingresos = ""
    dia_menores_ingresos = ""
    mayores_ingresos = 0
    menores_ingresos = 100000000
    for i in range(7):
        if (ventas[i][2] >= mayores_ingresos):
            mayores_ingresos = ventas[i][2]
            dia_mayores_ingresos = str(ventas[i][0]) + " - Unidades: " + str(ventas[i][1]) + " - Ingresos: " + str(mayores_ingresos)
    
    for i in range(7):
        if (ventas[i][2] < menores_ingresos):
            menores_ingresos = ventas[i][2]
            dia_menores_ingresos = str(ventas[i][0]) + " - Unidades: " + str(ventas[i][1]) + " - Ingresos: " + str(menores_ingresos)

# Estas variables almacenan la disponibilidad de cada topping:
# "(Disponible)" "(Agotado)" / Inicialmente son strings vacíos.
dispo_pepperoni = ""
dispo_salami = ""
dispo_champiñones = ""
dispo_pollo = ""
dispo_piña = ""

# Esta función hace la validación de todos los toppings y les
# asigna el valor de "(Disponible)" o "(Agotado)".
def validar_estado_ingrediente():
    global dispo_pepperoni, dispo_salami, dispo_champiñones, dispo_pollo, dispo_piña

    if (inventario[1][3] > 0):
        dispo_pepperoni = "(Disponible)"
    else:
        dispo_pepperoni = "(Agotado)"

    if (inventario[1][4] > 0):
        dispo_salami = "(Disponible)"
    else:
        dispo_salami = "(Agotado)"

    if (inventario[1][5] > 0):
        dispo_champiñones = "(Disponible)"
    else:
        dispo_champiñones = "(Agotado)"

    if (inventario[1][6] > 0):
        dispo_pollo = "(Disponible)"
    else:
        dispo_pollo = "(Agotado)"

    if (inventario[1][7] > 0):
        dispo_piña = "(Disponible)"
    else:
        dispo_piña = "(Agotado)"

# Ejecutamos la función para establecer la disponibilidad
# de los toppings.
validar_estado_ingrediente()

# Esta función permite reestablecer los valores iniciales
# una vez que se haya terminado el proceso de facturación
# de un usuario en concreto, para poder continuar utilizando
# el programa con un usuario nuevo.
def reestablecer_valores():
    global n_pizza, ingredientes, cant_toppings, pedido, pedido_completo, total_pizzas, costo_total, dia_seleccionado
    dia_seleccionado = 0
    n_pizza = 1
    ingredientes = i_base
    precio_pizza = 20000
    cant_toppings = 0
    pedido = "Su pizza #" + str(n_pizza) + " es:\n\n" + ingredientes + "\n\nPrecio pizza: $" + str(precio_pizza)
    pedido_completo = ""
    total_pizzas = 0
    costo_total = 0

# Este print solo nos sirve como un indicador en consola
# de que el programa ya inició su ejecución.
print("ejecutando...")

# ---------------------------------------------------------------------

# Funcionalidades (inicio).

def ir_inicio_admin():
    ventana_inicio.withdraw()
    ventana_admin.deiconify()

def ir_inicio_cliente():
    ventana_inicio.withdraw()
    ventana_cliente.deiconify()

# Creación de la ventana (inicio).

ventana_inicio = Tk() # Crear la ventana (inicio).
ventana_inicio.title("Inicio") # Modificar el título de la ventana (inicio).
ventana_inicio.geometry("320x150") # Modificar las dimensiones de la ventana (inicio).
ventana_inicio.resizable(False, False) # Deshabilitar la capacidad de cambiar el tamaño de la ventana (inicio).

# Crear los componentes de la ventana (inicio).

# Etiquetas (inicio).
l_bienvenida = Label(ventana_inicio, text="PIZZERÍA UNIVALLE")
l_bienvenida.config(bg="#FFFFFF", fg="#EA1F01")
l_acceder = Label(ventana_inicio, text="Acceder al sistema:")

# Botones (inicio).
b_acceso_admin = Button(ventana_inicio, text="Administrador", command=ir_inicio_admin)
b_acceso_cliente = Button(ventana_inicio, text="Cliente", command=ir_inicio_cliente)

# Posicionar los componentes en la ventana (inicio).
l_bienvenida.place(x=0, y=20, width=320, height=30)
l_acceder.place(x=100, y=60, width=120, height=30)
b_acceso_admin.place(x=20, y=100, width=130, height=30)
b_acceso_cliente.place(x=170, y=100, width=130, height=30)

# ---------------------------------------------------------------------

# Funcionalidades (admin).

def ir_admin_inicio():
    ventana_admin.withdraw()
    ventana_inicio.deiconify()

def consultar_inventario():

    # Funcionalidades (inventario).

    def colores():
        if (inventario[1][0] <= 3):
            l_inventario_masa.config(fg="#EA1F01")
        else:
            l_inventario_masa.config(bg="#F0F0F0")
        if (inventario[1][1] <= 3):
            l_inventario_salsa.config(fg="#EA1F01")
        else:
            l_inventario_salsa.config(bg="#F0F0F0")
        if (inventario[1][2] <= 3):
            l_inventario_queso.config(fg="#EA1F01")
        else:
            l_inventario_queso.config(bg="#F0F0F0")
        if (inventario[1][3] <= 3):
            l_inventario_pepperoni.config(fg="#EA1F01")
        else:
            l_inventario_pepperoni.config(bg="#F0F0F0")
        if (inventario[1][4] <= 3):
            l_inventario_salami.config(fg="#EA1F01")
        else:
            l_inventario_salami.config(bg="#F0F0F0")
        if (inventario[1][5] <= 3):
            l_inventario_champiñones.config(fg="#EA1F01")
        else:
            l_inventario_champiñones.config(bg="#F0F0F0")
        if (inventario[1][6] <= 3):
            l_inventario_pollo.config(fg="#EA1F01")
        else:
            l_inventario_pollo.config(bg="#F0F0F0")
        if (inventario[1][7] <= 3):
            l_inventario_piña.config(fg="#EA1F01")
        else:
            l_inventario_piña.config(bg="#F0F0F0")

    def ir_inventario_admin():
        ventana_inventario.withdraw()
        ventana_admin.deiconify()

    ventana_admin.withdraw()

    # Creación de la ventana (inventario).

    ventana_inventario = Tk() # Crear la ventana (inventario).
    ventana_inventario.title("Inventario") # Modificar el título de la ventana (inventario).
    ventana_inventario.geometry("300x450") # Modificar las dimensiones de la ventana (inventario).
    ventana_inventario.resizable(False, False) # Deshabilitar la capacidad de cambiar el tamaño de la ventana (inventario).

    # Crear los componentes de la ventana (inventario).

    # Etiquetas (inventario).
    l_bienvenida = Label(ventana_inventario, text="PIZZERÍA UNIVALLE")
    l_bienvenida.config(bg="#FFFFFF", fg="#EA1F01")
    l_msj_1 = Label(ventana_inventario, text="Cantidad de ingredientes disponibles en inventario:")
    l_inventario_masa = Label(ventana_inventario, text=inventario[0][0] + " (" + str(inventario[1][0]) + ")")
    l_inventario_salsa = Label(ventana_inventario, text=inventario[0][1] + " (" + str(inventario[1][1]) + ")")
    l_inventario_queso = Label(ventana_inventario, text=inventario[0][2] + " (" + str(inventario[1][2]) + ")")
    l_inventario_pepperoni = Label(ventana_inventario, text=inventario[0][3] + " (" + str(inventario[1][3]) + ")")
    l_inventario_salami = Label(ventana_inventario, text=inventario[0][4] + " (" + str(inventario[1][4]) + ")")
    l_inventario_champiñones = Label(ventana_inventario, text=inventario[0][5] + " (" + str(inventario[1][5]) + ")")
    l_inventario_pollo = Label(ventana_inventario, text=inventario[0][6] + " (" + str(inventario[1][6]) + ")")
    l_inventario_piña = Label(ventana_inventario, text=inventario[0][7] + " (" + str(inventario[1][7]) + ")")
    l_msj_2 = Label(ventana_inventario, text="Los productos en rojo se encuentran escasos,\n(disponibilidad <= 3) reabastecer inmediatamente.")

    # Botones (inventario).
    b_ir_inventario_admin = Button(ventana_inventario, text="Regresar", command=ir_inventario_admin)

    # Posicionar los componentes en la ventana (inventario).
    l_bienvenida.place(x=0, y=20, width=300, height=30)
    l_msj_1.place(x=0, y=60, width=300, height=30)
    l_inventario_masa.place(x=0, y=100, width=300, height=30)
    l_inventario_salsa.place(x=0, y=130, width=300, height=30)
    l_inventario_queso.place(x=0, y=160, width=300, height=30)
    l_inventario_pepperoni.place(x=0, y=190, width=300, height=30)
    l_inventario_salami.place(x=0, y=220, width=300, height=30)
    l_inventario_champiñones.place(x=0, y=250, width=300, height=30)
    l_inventario_pollo.place(x=0, y=280, width=300, height=30)
    l_inventario_piña.place(x=0, y=310, width=300, height=30)
    l_msj_2.place(x=0, y=350, width=300, height=30)
    b_ir_inventario_admin.place(x=100, y=400, width=100, height=30)

    colores()

def consultar_indicadores():

    calculo_indicadores()

    # Funcionaldiades (indicadores).

    def ir_indicadores_admin():
        ventana_indicadores.withdraw()
        ventana_admin.deiconify()

    ventana_admin.withdraw()

    # Creación de la ventana (indicadores).

    ventana_indicadores = Tk() # Crear la ventana (indicadores).
    ventana_indicadores.title("Indicadores") # Modificar el título de la ventana (indicadores).
    ventana_indicadores.geometry("320x290") # Modificar las dimensiones de la ventana (indicadores).
    ventana_indicadores.resizable(False, False) # Deshabilitar la capacidad de cambiar el tamaño de la ventana (indicadores).

    # Crear los componentes de la ventana (indicadores).

    # Etiquetas (indicadores).
    l_bienvenida = Label(ventana_indicadores, text="PIZZERÍA UNIVALLE")
    l_bienvenida.config(bg="#FFFFFF", fg="#EA1F01")
    l_msj_1 = Label(ventana_indicadores, text="Día con MAYORES ingresos de la semana:")
    l_msj_2 = Label(ventana_indicadores, text=dia_mayores_ingresos)
    l_msj_3 = Label(ventana_indicadores, text="Día con MENORES ingresos de la semana:")
    l_msj_4 = Label(ventana_indicadores, text=dia_menores_ingresos)

    # Botones (indicadores).
    b_ir_inventario_admin = Button(ventana_indicadores, text="Regresar", command=ir_indicadores_admin)

    # Posicionar los componentes en la ventana (indicadores).
    l_bienvenida.place(x=0, y=20, width=320, height=30)
    l_msj_1.place(x=0, y=60, width=320, height=30)
    l_msj_2.place(x=0, y=90, width=320, height=30)
    l_msj_3.place(x=0, y=150, width=320, height=30)
    l_msj_4.place(x=0, y=180, width=320, height=30)
    b_ir_inventario_admin.place(x=100, y=240, width=100, height=30)

def consultar_ventas_semana():

    calculo_ventas_semana()

    # Funcionalidades (ventas semana).
    
    def ir_ventas_semana_admin():
        ventana_ventas_semana.withdraw()
        ventana_admin.deiconify()

    ventana_admin.withdraw()

    # Creación de la ventana (ventas semana).

    ventana_ventas_semana = Tk() # Crear la ventana (ventas semana).
    ventana_ventas_semana.title("Ventas semana") # Modificar el título de la ventana (ventas semana).
    ventana_ventas_semana.geometry("320x180") # Modificar las dimensiones de la ventana (ventas semana).
    ventana_ventas_semana.resizable(False, False) # Deshabilitar la capacidad de cambiar el tamaño de la ventana (ventas semana).

    # Crear los componentes de la ventana (ventas semana).

    # Etiquetas (ventas semana).
    l_bienvenida = Label(ventana_ventas_semana, text="PIZZERÍA UNIVALLE")
    l_bienvenida.config(bg="#FFFFFF", fg="#EA1F01")
    l_unidades_semana = Label(ventana_ventas_semana, text="Número de pizzas vendidas en la semana: " + str(ventas_unidades_semana))
    l_ingresos_semana = Label(ventana_ventas_semana, text="Ingresos de la semana: $" + str(ventas_ingresos_semana))

    # Botones (ventas semana).
    b_ir_ventas_semana_admin = Button(ventana_ventas_semana, text="Regresar", command=ir_ventas_semana_admin)

    # Posicionar los componentes en la ventana (ventas semana).
    l_bienvenida.place(x=0, y=20, width=320, height=30)
    l_unidades_semana.place(x=0, y=60, width=320, height=30)
    l_ingresos_semana.place(x=0, y=90, width=320, height=30)
    b_ir_ventas_semana_admin.place(x=100, y=130, width=120, height=30)

def consultar_ventas_dia():

    # Funcionalidades (ventas día).

    def ir_ventas_dia_admin():
        ventana_ventas_dia.withdraw()
        ventana_admin.deiconify()

    ventana_admin.withdraw()

    # Creación de la ventana (ventas día).

    ventana_ventas_dia = Tk() # Crear la ventana (ventas día).
    ventana_ventas_dia.title("Ventas día") # Modificar el título de la ventana (ventas día).
    ventana_ventas_dia.geometry("440x380") # Modificar las dimensiones de la ventana (ventas día).
    ventana_ventas_dia.resizable(False, False) # Deshabilitar la capacidad de cambiar el tamaño de la ventana (ventas día).

    # Crear los componentes de la ventana (ventas día).

    # Etiquetas (ventas día).
    l_bienvenida = Label(ventana_ventas_dia, text="PIZZERÍA UNIVALLE")
    l_bienvenida.config(bg="#FFFFFF", fg="#EA1F01")
    l_encabezado_dia = Label(ventana_ventas_dia, text="Día")
    l_encabezado_pizzas = Label(ventana_ventas_dia, text="Nro. Pizzas")
    l_encabezado_ingresos = Label(ventana_ventas_dia, text="Ingresos")
    l_lu = Label(ventana_ventas_dia, text="Lunes")
    l_uni_lu = Label(ventana_ventas_dia, text=str(ventas[0][1]))
    l_ing_lu = Label(ventana_ventas_dia, text="$" + str(ventas[0][2]))
    l_ma = Label(ventana_ventas_dia, text="Martes")
    l_uni_ma = Label(ventana_ventas_dia, text=str(ventas[1][1]))
    l_ing_ma = Label(ventana_ventas_dia, text="$" + str(ventas[1][2]))
    l_mi = Label(ventana_ventas_dia, text="Miércoles")
    l_uni_mi = Label(ventana_ventas_dia, text=str(ventas[2][1]))
    l_ing_mi = Label(ventana_ventas_dia, text="$" + str(ventas[2][2]))
    l_ju = Label(ventana_ventas_dia, text="Jueves")
    l_uni_ju = Label(ventana_ventas_dia, text=str(ventas[3][1]))
    l_ing_ju = Label(ventana_ventas_dia, text="$" + str(ventas[3][2]))
    l_vi = Label(ventana_ventas_dia, text="Viernes")
    l_uni_vi = Label(ventana_ventas_dia, text=str(ventas[4][1]))
    l_ing_vi = Label(ventana_ventas_dia, text="$" + str(ventas[4][2]))
    l_sa = Label(ventana_ventas_dia, text="Sábado")
    l_uni_sa = Label(ventana_ventas_dia, text=str(ventas[5][1]))
    l_ing_sa = Label(ventana_ventas_dia, text="$" + str(ventas[5][2]))
    l_do = Label(ventana_ventas_dia, text="Domingo")
    l_uni_do = Label(ventana_ventas_dia, text=str(ventas[6][1]))
    l_ing_do = Label(ventana_ventas_dia, text="$" + str(ventas[6][2]))

    # Botones (ventas día).
    b_ir_ventas_dia_admin = Button(ventana_ventas_dia, text="Regresar", command=ir_ventas_dia_admin)

    # Posicionar los componentes en la ventana (ventas día).
    l_bienvenida.place(x=0, y=20, width=440, height=30)
    l_encabezado_dia.place(x=20, y=60, width=120, height=30)
    l_encabezado_pizzas.place(x=160, y=60, width=120, height=30)
    l_encabezado_ingresos.place(x=300, y=60, width=120, height=30)
    l_lu.place(x=20, y=100, width=120, height=30)
    l_uni_lu.place(x=160, y=100, width=120, height=30)
    l_ing_lu.place(x=300, y=100, width=120, height=30)
    l_ma.place(x=20, y=130, width=120, height=30)
    l_uni_ma.place(x=160, y=130, width=120, height=30)
    l_ing_ma.place(x=300, y=130, width=120, height=30)
    l_mi.place(x=20, y=160, width=120, height=30)
    l_uni_mi.place(x=160, y=160, width=120, height=30)
    l_ing_mi.place(x=300, y=160, width=120, height=30)
    l_ju.place(x=20, y=190, width=120, height=30)
    l_uni_ju.place(x=160, y=190, width=120, height=30)
    l_ing_ju.place(x=300, y=190, width=120, height=30)
    l_vi.place(x=20, y=220, width=120, height=30)
    l_uni_vi.place(x=160, y=220, width=120, height=30)
    l_ing_vi.place(x=300, y=220, width=120, height=30)
    l_sa.place(x=20, y=250, width=120, height=30)
    l_uni_sa.place(x=160, y=250, width=120, height=30)
    l_ing_sa.place(x=300, y=250, width=120, height=30)
    l_do.place(x=20, y=280, width=120, height=30)
    l_uni_do.place(x=160, y=280, width=120, height=30)
    l_ing_do.place(x=300, y=280, width=120, height=30)
    b_ir_ventas_dia_admin.place(x=160, y=330, width=120, height=30)

# Creación de la ventana (admin).

ventana_admin = Tk() # Crear la ventana (admin).
ventana_admin.title("Administrador") # Modificar el título de la ventana (admin).
ventana_admin.geometry("320x240") # Modificar las dimensiones de la ventana (admin).
ventana_admin.resizable(False, False) # Deshabilitar la capacidad de cambiar el tamaño de la ventana (admin).

# Crear los componentes de la ventana (admin).

# Etiquetas (admin).
l_bienvenida = Label(ventana_admin, text="PIZZERÍA UNIVALLE")
l_bienvenida.config(bg="#FFFFFF", fg="#EA1F01")
l_consultas_admin = Label(ventana_admin, text="Consultar:")

# Botones (admin).
b_consultar_inventario = Button(ventana_admin, text="Inventario", command=consultar_inventario)
b_consultar_ventas_semana = Button(ventana_admin, text="Ventas de la semana", command=consultar_ventas_semana)
b_consultar_ventas_dia = Button(ventana_admin, text="Ventas por día", command=consultar_ventas_dia)
b_consultar_indicadores = Button(ventana_admin, text="Indicadores", command=consultar_indicadores)
b_ir_admin_inicio = Button(ventana_admin, text="Regresar inicio", command=ir_admin_inicio)

# Posicionar los componentes en la ventana (admin).
l_bienvenida.place(x=0, y=20, width=320, height=30)
l_consultas_admin.place(x=100, y=60, width=120, height=30)
b_consultar_inventario.place(x=20, y=100, width=130, height=30)
b_consultar_indicadores.place(x=170, y=100, width=130, height=30)
b_consultar_ventas_semana.place(x=20, y=140, width=130, height=30)
b_consultar_ventas_dia.place(x=170, y=140, width=130, height=30)
b_ir_admin_inicio.place(x=95, y=190, width=130, height=30)

# Ocultar la ventana (admin) inicialmente.
ventana_admin.withdraw()

# ---------------------------------------------------------------------

# Funcionalidades (cliente).

def ir_cliente_inicio():
    global dia_seleccionado
    # Deseleccionar el día.
    dia_seleccionado = 0
    # Reiniciar los valores de las etiquetas a su estado original.
    b_lunes.config(text="Lunes")
    b_martes.config(text="Martes")
    b_miercoles.config(text="Miércoles")
    b_jueves.config(text="Jueves")
    b_viernes.config(text="Viernes")
    b_sabado.config(text="Sábado")
    b_domingo.config(text="Domingo")
    ventana_cliente.withdraw()
    ventana_inicio.deiconify()

# Las funciones de las líneas 511, 520, 529, 538, 547, 556, 565,
# permiten seleccionar uno de los días disponibles para posteriormente
# almacenar las unidades vendidas y los ingresos percibidos
# en ese día especifico.

def selec_lunes():
    global dia_seleccionado
    if (dia_seleccionado == 0):
        dia_seleccionado = 1
        b_lunes.config(text="Lunes (*)")
    elif (dia_seleccionado == 1):
        dia_seleccionado = 0
        b_lunes.config(text="Lunes")

def selec_martes():
    global dia_seleccionado
    if (dia_seleccionado == 0):
        dia_seleccionado = 2
        b_martes.config(text="Martes (*)")
    elif (dia_seleccionado == 2):
        dia_seleccionado = 0
        b_martes.config(text="Martes")

def selec_miercoles():
    global dia_seleccionado
    if (dia_seleccionado == 0):
        dia_seleccionado = 3
        b_miercoles.config(text="Miércoles (*)")
    elif (dia_seleccionado == 3):
        dia_seleccionado = 0
        b_miercoles.config(text="Miércoles")

def selec_jueves():
    global dia_seleccionado
    if (dia_seleccionado == 0):
        dia_seleccionado = 4
        b_jueves.config(text="Jueves (*)")
    elif (dia_seleccionado == 4):
        dia_seleccionado = 0
        b_jueves.config(text="Jueves")

def selec_viernes():
    global dia_seleccionado
    if (dia_seleccionado == 0):
        dia_seleccionado = 5
        b_viernes.config(text="Viernes (*)")
    elif (dia_seleccionado == 5):
        dia_seleccionado = 0
        b_viernes.config(text="Viernes")

def selec_sabado():
    global dia_seleccionado
    if (dia_seleccionado == 0):
        dia_seleccionado = 6
        b_sabado.config(text="Sábado (*)")
    elif (dia_seleccionado == 6):
        dia_seleccionado = 0
        b_sabado.config(text="Sábado")

def selec_domingo():
    global dia_seleccionado
    if (dia_seleccionado == 0):
        dia_seleccionado = 7
        b_domingo.config(text="Domingo (*)")
    elif (dia_seleccionado == 7):
        dia_seleccionado = 0
        b_domingo.config(text="Domingo")

def ordenar():
    if (dia_seleccionado !=0): # Solamente se ejecuta si hay un día seleccionado.

        ventana_cliente.withdraw()

        validar_estado_ingrediente()

        # Funcionalidades (pedido)

        # Las funciones de las líneas 587, 606, 625, 644, 663,
        # permiten agregar el topping seleccionado por el usuario
        # en caso de que se encuentre disponible.

        def ag_pepperoni():
            global dispo_pepperoni, ingredientes, pedido, cant_toppings
            if (dispo_pepperoni == "(Disponible)"):
                dispo_pepperoni = "(Seleccionado)"
                inventario[1][3] -= 1
                ingredientes += t_pe
                cant_toppings += 1
                pedido = "Su pizza #" + str(n_pizza) + " es:\n\n" + ingredientes + "\n\nPrecio pizza: $" + str(precio_pizza + (cant_toppings*5000))
            elif (dispo_pepperoni == "(Agotado)"):
                dispo_pepperoni = "(Agotado)"
            elif (dispo_pepperoni == "(Seleccionado)"):
                dispo_pepperoni = "(Disponible)"
                inventario[1][3] += 1
                ingredientes = ingredientes.replace(t_pe, "")
                cant_toppings -= 1
                pedido = "Su pizza #" + str(n_pizza) + " es:\n\n" + ingredientes + "\n\nPrecio pizza: $" + str(precio_pizza + (cant_toppings*5000))
            l_dispo_pepperoni.config(text=dispo_pepperoni)
            l_msj_1.config(text=pedido)

        def ag_salami():
            global dispo_salami, ingredientes, pedido, cant_toppings
            if (dispo_salami == "(Disponible)"):
                dispo_salami = "(Seleccionado)"
                inventario[1][4] -= 1
                ingredientes += t_sa
                cant_toppings += 1
                pedido = "Su pizza #" + str(n_pizza) + " es:\n\n" + ingredientes + "\n\nPrecio pizza: $" + str(precio_pizza + (cant_toppings*5000))
            elif (dispo_salami == "(Agotado)"):
                dispo_salami = "(Agotado)"
            elif (dispo_salami == "(Seleccionado)"):
                dispo_salami = "(Disponible)"
                inventario[1][4] += 1
                ingredientes = ingredientes.replace(t_sa, "")
                cant_toppings -= 1
                pedido = "Su pizza #" + str(n_pizza) + " es:\n\n" + ingredientes + "\n\nPrecio pizza: $" + str(precio_pizza + (cant_toppings*5000))
            l_dispo_salami.config(text=dispo_salami)
            l_msj_1.config(text=pedido)

        def ag_champiñones():
            global dispo_champiñones, ingredientes, pedido, cant_toppings
            if (dispo_champiñones == "(Disponible)"):
                dispo_champiñones = "(Seleccionado)"
                inventario[1][5] -= 1
                ingredientes += t_ch
                cant_toppings += 1
                pedido = "Su pizza #" + str(n_pizza) + " es:\n\n" + ingredientes + "\n\nPrecio pizza: $" + str(precio_pizza + (cant_toppings*5000))
            elif (dispo_champiñones == "(Agotado)"):
                dispo_champiñones = "(Agotado)"
            elif (dispo_champiñones == "(Seleccionado)"):
                dispo_champiñones = "(Disponible)"
                inventario[1][5] += 1
                ingredientes = ingredientes.replace(t_ch, "")
                cant_toppings -= 1
                pedido = "Su pizza #" + str(n_pizza) + " es:\n\n" + ingredientes + "\n\nPrecio pizza: $" + str(precio_pizza + (cant_toppings*5000))
            l_dispo_champiñones.config(text=dispo_champiñones)
            l_msj_1.config(text=pedido)

        def ag_pollo():
            global dispo_pollo, ingredientes, pedido, cant_toppings
            if (dispo_pollo == "(Disponible)"):
                dispo_pollo = "(Seleccionado)"
                inventario[1][6] -= 1
                ingredientes += t_po
                cant_toppings += 1
                pedido = "Su pizza #" + str(n_pizza) + " es:\n\n" + ingredientes + "\n\nPrecio pizza: $" + str(precio_pizza + (cant_toppings*5000))
            elif (dispo_pollo == "(Agotado)"):
                dispo_pollo = "(Agotado)"
            elif (dispo_pollo == "(Seleccionado)"):
                dispo_pollo = "(Disponible)"
                inventario[1][6] += 1
                ingredientes = ingredientes.replace(t_po, "")
                cant_toppings -= 1
                pedido = "Su pizza #" + str(n_pizza) + " es:\n\n" + ingredientes + "\n\nPrecio pizza: $" + str(precio_pizza + (cant_toppings*5000))
            l_dispo_pollo.config(text=dispo_pollo)
            l_msj_1.config(text=pedido)

        def ag_piña():
            global dispo_piña, ingredientes, pedido, cant_toppings
            if (dispo_piña == "(Disponible)"):
                dispo_piña = "(Seleccionado)"
                inventario[1][7] -= 1
                ingredientes += t_pi
                cant_toppings += 1
                pedido = "Su pizza #" + str(n_pizza) + " es:\n\n" + ingredientes + "\n\nPrecio pizza: $" + str(precio_pizza + (cant_toppings*5000))
            elif (dispo_piña == "(Agotado)"):
                dispo_piña = "(Agotado)"
            elif (dispo_piña == "(Seleccionado)"):
                dispo_piña = "(Disponible)"
                inventario[1][7] += 1
                ingredientes = ingredientes.replace(t_pi, "")
                cant_toppings -= 1
                pedido = "Su pizza #" + str(n_pizza) + " es:\n\n" + ingredientes + "\n\nPrecio pizza: $" + str(precio_pizza + (cant_toppings*5000))
            l_dispo_piña.config(text=dispo_piña)
            l_msj_1.config(text=pedido)
        
        def ordenar_otra():
            guardar_pedido()
            ventana_pedido.withdraw()
            l_msj_1.config(text=pedido)
            ordenar()

        # Esta función recibe como parámetro un día de la semana,
        # con ese valor determina en qué lugar de la matriz "ventas"
        # almacena las unidades vendidas y los ingresos percibidos.
        def ventas(dia):
            global ventas
            ventas[dia-1][1] += total_pizzas
            ventas[dia-1][2] += costo_total

        def pagar():
            
            # Funcionalidades (pago).

            # Esta función reestablece todos los valores predeterminados
            # y redirige hacia la página de inicio para continuar utilizando
            # el programa.
            def ir_pago_inicio():
                reestablecer_valores()
                validar_estado_ingrediente()
                b_lunes.config(text="Lunes")
                b_martes.config(text="Martes")
                b_miercoles.config(text="Miércoles")
                b_jueves.config(text="Jueves")
                b_viernes.config(text="Viernes")
                b_sabado.config(text="Sábado")
                b_domingo.config(text="Domingo")
                ventana_pago.withdraw()
                ventana_inicio.deiconify()

            ventana_pedido.withdraw()

            guardar_pedido()
            ventas(dia_seleccionado)

            # Creación de la ventana (pago).

            ventana_pago = Tk() # Crear la ventana (pago).
            ventana_pago.title("Pago") # Modificar el título de la ventana (pago).
            ventana_pago.geometry("500x430") # Modificar las dimensiones de la ventana (pago).
            ventana_pago.resizable(False, True) # Deshabilitar la capacidad de cambiar el tamaño de la ventana (pago).

            # Crear los componentes de la ventana (pago).

            # Etiquetas (pago).
            l_bienvenida = Label(ventana_pago, text="PIZZERÍA UNIVALLE")
            l_bienvenida.config(bg="#FFFFFF", fg="#EA1F01")
            l_msj_1_factura = Label(ventana_pago, text="Total de pizzas: " + str(total_pizzas) + "\n\nCosto total: $" + str(costo_total))
            l_msj_2_factura = Label(ventana_pago, text=pedido_completo)

            # Botones (pago).
            b_ir_pago_inicio = Button(ventana_pago, text="Regresar inicio", command=ir_pago_inicio)

            # Posicionar los componentes en la ventana (pago).
            l_bienvenida.place(x=0, y=20, width=500, height=30)
            l_msj_1_factura.place(x=0, y=60, width=500, height=60)
            l_msj_2_factura.place(x=0, y=190, width=500)
            b_ir_pago_inicio.place(x=185, y=140, width=130, height=30)

        # Esta función permite almacenar el pedido de una pizza en
        # la factura general para realizar el proceso de pago posterior.
        def guardar_pedido():
            global precio_pizza, pedido, pedido_completo, total_pizzas, costo_total, n_pizza, cant_toppings, ingredientes, inventario
            inventario[1][0] -= 1
            inventario[1][1] -= 1
            inventario[1][2] -= 1
            precio_pizza = precio_pizza + (cant_toppings*5000)
            pedido = "Su pizza #" + str(n_pizza) + " es:\n\n" + ingredientes + "\n\nPrecio pizza: $" + str(precio_pizza) + "\n\n"
            pedido_completo = pedido_completo + pedido # Agregamos la pizza recientemente creada por el usuario y la guardamos en una factura general.
            total_pizzas += 1 # Contamos la pizza recién creada.
            n_pizza += 1 # Actualizamos el puntero de la pizza en que estamos actualmente.
            costo_total += precio_pizza # Sumamos el precio de la pizza recién creada al costo total de la factura.
            precio_pizza = 20000
            ingredientes = i_base
            cant_toppings = 0
            pedido = "Su pizza #" + str(n_pizza) + " es:\n\n" + ingredientes + "\n\nPrecio pizza: $" + str(precio_pizza)

        # Creación de la ventana (pedido).

        ventana_pedido = Tk() # Crear la ventana (pedido).
        ventana_pedido.title("Pedido") # Modificar el título de la ventana (pedido).
        ventana_pedido.geometry("500x430") # Modificar las dimensiones de la ventana (pedido).
        ventana_pedido.resizable(False, True) # Deshabilitar la capacidad de cambiar el tamaño horizontal de la ventana (pedido).

        # Crear los componentes de la ventana (pedido).

        # Etiquetas (pedido).
        l_bienvenida = Label(ventana_pedido, text="PIZZERÍA UNIVALLE")
        l_bienvenida.config(bg="#FFFFFF", fg="#EA1F01")
        l_msj_1 = Label(ventana_pedido, text=pedido)
        l_dispo_pepperoni = Label(ventana_pedido, text=dispo_pepperoni)
        l_dispo_salami = Label(ventana_pedido, text=dispo_salami)
        l_dispo_champiñones = Label(ventana_pedido, text=dispo_champiñones)
        l_dispo_pollo = Label(ventana_pedido, text=dispo_pollo)
        l_dispo_piña = Label(ventana_pedido, text=dispo_piña)

        # Botones (pedido).
        b_pepperoni = Button(ventana_pedido, text="Pepperoni", command=ag_pepperoni)
        b_salami = Button(ventana_pedido, text="Salami", command=ag_salami)
        b_champiñones = Button(ventana_pedido, text="Champiñones", command=ag_champiñones)
        b_pollo = Button(ventana_pedido, text="Pollo", command=ag_pollo)
        b_piña = Button(ventana_pedido, text="Piña", command=ag_piña)
        b_otra_pizza = Button(ventana_pedido, text="Otra pizza", command=ordenar_otra)
        b_pagar = Button(ventana_pedido, text="Pagar", command=pagar)

        # Posicionar los componentes en la ventana (pedido).
        l_bienvenida.place(x=0, y=20, width=500, height=30)
        l_msj_1.place(x=0, y=60, width=500, height=80)
        b_pepperoni.place(x=150, y=160, width=100, height=30)
        l_dispo_pepperoni.place(x=250, y=160, width=100, height=30)
        b_salami.place(x=150, y=200, width=100, height=30)
        l_dispo_salami.place(x=250, y=200, width=100, height=30)
        b_champiñones.place(x=150, y=240, width=100, height=30)
        l_dispo_champiñones.place(x=250, y=240, width=100, height=30)
        b_pollo.place(x=150, y=280, width=100, height=30)
        l_dispo_pollo.place(x=250, y=280, width=100, height=30)
        b_piña.place(x=150, y=320, width=100, height=30)
        l_dispo_piña.place(x=250, y=320, width=100, height=30)
        b_otra_pizza.place(x=140, y=380, width=100, height=30)
        b_pagar.place(x=260, y=380, width=100, height=30)
    else: # En caso de que no haya un día seleccionado, que el botón no permita hacer nada.
        l_msj_3.config(bg="#FFFFFF")

# Creación de la ventana (cliente).

ventana_cliente = Tk() # Crear la ventana (cliente).
ventana_cliente.title("Cliente") # Modificar el título de la ventana (cliente).
ventana_cliente.geometry("540x330") # Modificar las dimensiones de la ventana (cliente).
ventana_cliente.resizable(False, False) # Deshabiltiar la capacidad de cambiar el tamaño de la ventana (cliente).

# Crear los componentes de la ventana (cliente).

# Etiquetas (cliente).
l_bienvenida = Label(ventana_cliente, text="PIZZERÍA UNIVALLE")
l_bienvenida.config(bg="#FFFFFF", fg="#EA1F01")
l_msj_1 = Label(ventana_cliente, text="Nuestra pizza base tiene un precio de $20000 y consta de:\nMasa, Salsa, Queso")
l_msj_2 = Label(ventana_cliente, text="Además, tenemos una lista de toppings que puedes agregar por un precio de $5000 cada uno:\nPepperoni, Salami, Champiñones, Pollo, Piña")
l_msj_3 = Label(ventana_cliente, text="Selecciona el día en que realizas el pedido (*):")
l_msj_3.config(bg="#FFFFFF")

# Botones (cliente).
b_lunes = Button(ventana_cliente, text="Lunes", command=selec_lunes)
b_martes = Button(ventana_cliente, text="Martes", command=selec_martes)
b_miercoles= Button(ventana_cliente, text="Miércoles", command=selec_miercoles)
b_jueves = Button(ventana_cliente, text="Jueves", command=selec_jueves)
b_viernes = Button(ventana_cliente, text="Viernes", command=selec_viernes)
b_sabado = Button(ventana_cliente, text="Sábado", command=selec_sabado)
b_domingo = Button(ventana_cliente, text="Domingo", command=selec_domingo)
b_comenzar_pedido = Button(ventana_cliente, text="Comenzar pedido", command=ordenar)
b_ir_cliente_inicio = Button(ventana_cliente, text="Regresar inicio", command=ir_cliente_inicio)

# Posicionar los componentes en la ventana (cliente).
l_bienvenida.place(x=0, y=20, width=540, height=30)
l_msj_1.place(x=0, y=60, width=540, height=30)
l_msj_2.place(x=0, y=100, width=540, height=30)
l_msj_3.place(x=140, y=140, width=260, height=30)
b_lunes.place(x=40, y=180, width=100, height=30)
b_martes.place(x=160, y=180, width=100, height=30)
b_miercoles.place(x=280, y=180, width=100, height=30)
b_jueves.place(x=400, y=180, width=100, height=30)
b_viernes.place(x=100, y=220, width=100, height=30)
b_sabado.place(x=220, y=220, width=100, height=30)
b_domingo.place(x=340, y=220, width=100, height=30)
b_comenzar_pedido.place(x=130, y=280, width=130, height=30)
b_ir_cliente_inicio.place(x=280, y=280, width=130, height=30)

# Ocultar la ventana (cliente) inicialmente.
ventana_cliente.withdraw()

# ---------------------------------------------------------------------

# Muestra todo en pantalla y responde a la entrada
# del usuario hasta que el programa termina.
ventana_inicio.mainloop()