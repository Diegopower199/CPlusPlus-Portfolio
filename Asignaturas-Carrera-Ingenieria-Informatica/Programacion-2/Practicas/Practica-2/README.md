# Practica 2

Se desea realizar una clase para operar con matrices de dimensión 3x3.
 
Se pide
 
1. Crear la clase Matrix que permita albergar matrices de 3x3

2. Crear un constructor que no reciba parámetros y que inicialice todos los elementos de la matriz a 0.

3. Crear un constructor que reciba un array de 9 elementos por parámetro y que inicialice la matriz según estos 9 elementos, en el orden fila1 columna1 , fila 1 columna 2, fila 1 columna 3, fila 2 columna 1, etc. Por ejemplo, este array {1, 0, 0, 2, 1, 0, 0 , 0, 1} crearía la siguiente matriz
| 1   0   0 |
| 2   1   0 |
| 0   0   1 |
 
4. Crear un método miembro get(row, col) que devuelva el elemento de la fila row, y columna col. Esta función debe lanzar una excepción si se intenta acceder a un elemento fuera de los límites de la matriz.
 
5. Crear un método miembro set(row, col, value) se ponga el elemento row, col con el valor value. Esta función debe lanzar una excepción si se intenta acceder a un elemento fuera de los límites de la matriz.
 
6. Crear un método miembro print que muestre por pantalla la matriz.
 
7. Crear un método miembro determinant que devuelva el determinante de la matriz.
 
8. Crear una función global add que reciba dos punteros a matrices y devuelva un puntero con la suma de ambas matrices.
 
9. Crear un programa que realice lo siguiente:
 
  - Pedir al usuario 2 matrices y crear dos variables puntero a matriz.

  - Sumar ambas matrices usando la función global add

  - Mostrar por pantalla la matriz suma.

  - Mostrar por pantalla el determinante de la suma.