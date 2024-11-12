# Se crea una matriz.
matrix = [[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]]

# Este bloque permite acceder a cada fila que compone la matriz
# e imprimirla por pantalla.
for row in matrix:
    print(row)

for i in range(3):
    print(matrix[i])

# Este bloque permite acceder a cada elemento de cada fila que
# compone la matriz e imprimirlo por pantalla.
for row in matrix:
    for element in row:
        print(element)

for i in range(3):
    for j in range(3):
        print(matrix[i][j])

# Este bloque permite imprimir los elementos de la matriz en
# formato matriz. El parámetro end=" " agrega un espacio al
# final de cada impresión y además evita que se realice un
# salto de línea.
for row in matrix:
    for element in row:
        print(element, end=" ")
    print()

for i in range(3):
    for j in range(3):
        print(matrix[i][j], end=" ")
    print()

# Crear una matriz de un mismo elemento.
matrix = [[0 for c in range(3)] for f in range(3)]

# Mostrar en pantalla la matriz creada anteriormente.
for i in range(3):
    print(matrix[i])