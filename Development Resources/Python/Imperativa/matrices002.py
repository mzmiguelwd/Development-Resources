"""
edades = [12, 15, 8]
nombres = [""]

print("hola")
otro = [None for i in range(5)]
print(otro)
una_variable = "María"
otro[1] = una_variable
print(otro)
"""

"""
Realice un programa que encueste a sus compañeros acerca de su gusto musical.
Al final, indique cuál es el género más votado y la cantidad de votos total
y del género ganador.
"""

def encuesta(cantidad):
    votos = [0]*3
    for i in range(0, cantidad):
        print("La lista de géners es:\n 1. Rock\n 2. Pop\n 3. Opera")
        gusto_musical = int(input("Digite el numeral de su género favorito: "))
        votos[gusto_musical-1] += 1

    if (votos[0] > votos[1] and votos[0] > votos[2]):
        print("El género ganador es ROCK")
    elif (votos[1] > votos[0] and votos[1] > votos[2]):
        print("El género ganador es POP")
    elif (votos[2] > votos[0] and votos[2] > votos[1]):
        print("El género ganador es OPERA")
    else:
        print("No hay ganador")

    print("Votos totales: " + str(votos[0] + votos[1] + votos[2]))
    print("Votos Rock: " + str(votos[0]))
    print("Votos Pop: " + str(votos[1]))
    print("Votos Opera: " + str(votos[2]))

encuesta(5)