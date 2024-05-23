# PROBLEMA 1 (3 puntos)
 
Los factores de un número entero son todos los números primos menores que él y distintos de 1 y de él mismo, por los que dicho número es divisible (los factores no se repiten).
 
Por ejemplo
  - Los factores del número 10 son el 2 y el 5
  - Los factores del número 15 son el 3 y el 5.
  - Los factores del 30 son el 2, el 3 y el 5
  - El 25 solo tiene un factor: el 5
  - El 8 solo tiene un factor: el 2.
 
Usando funciones de modo oportuno, que tomen y devuelvan los tipos de datos adecuados, realizar un programa que muestre por pantalla los factores de un número que el usuario introduzca por teclado.
 


# PROBLEMA 2 (1.5 puntos)
 
El mínimo común múltiplo de 2 números es el menor número que es divisible por ambos, por ejemplo el mínimo común múltiplo de 2 y 5, es el 10, el mínimo común múltiplo de 8 y 4 es el 8.
 
Usando funciones de modo oportuno, que tomen y devuelvan los tipos de datos adecuados, realizar un programa que muestre por pantalla el mínimo común múltiplo de 2 números que el usuario introduzca por teclado.



# PROBLEMA 3 (1.5 puntos)
 
El máximo común divisor de 2 números es el mayor número que realiza una división entera de ambos, por ejemplo el máximo común divisor de 15 y 10, es el 5
 
Usando funciones de modo oportuno, que tomen y devuelvan los tipos de datos adecuados, realizar un programa que muestre por pantalla el máximo común divisor de 2 números que el usuario introduzca por teclado.
 


# PROBLEMA 4 (4 puntos)
 
Crear una clase Integer que contenga las siguientes características.
1. Alberga un número entero positivo (si se le pasa un número entero que no sea positivo - mayor que 0 - lanzará una excepción).
2. Asigna un valor a través del constructor y de una función setValue()
3. Contiene el método getValue() que devuelve el valor int
4. Contiene el método getFactors() que devuelve los factores de dicho número
5. Contiene el método isPrime() que devuelve verdadero o falso si el número es primo o no.
 
 
Además sobrecargar los operadores * y / de modo que:
  - El producto (*) de dos instancias de Integer devuelve otra instancia de Integer que contiene el mínimo común múltiplo.

La división (/) de dos instancias de Integer devuelve otra instancia de Integer que contiene el máximo común divisor.
