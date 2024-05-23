# Practica 3

Se desea crear un programa para trabajar con unidades de tiempo.
Se pide:

1. Crear una clase Tiempo que encapsule  las variables horas, minutos y segundos.
2. Crear los métodos getter/setter necesarios. Dichos métodos deben lanzar una excepción cuando minutos supere el valor 59 y cuando segundos supere el valor 59. En esos casos aparte de lanzar las excepciones indicadas el programa debe sumar 1 a horas o 1 a minutos respectivamente y guardar en minutos o/y en segundos el valor 0 según corresponda.
3. La clase Tiempo debe tener 3 constructores
   1. por defecto (inicializa a 0 las variables de la clase),
   2. por copia
   3. por parámetros(inicialice las variables a partir de los parámetros recibidos)
4. Crear un método en la clase Time que devuelva el total del tiempo almacenado en sus variables en segundos.
5. Sobrecargar >> para poder introducir por teclado las horas, minutos y segundos a almacenar en el objeto usando cin.
6. Sobrecargar << para poder visualizar las horas, minutos y segundos de un objeto
7. Sobrecargar el operador == para poder comparar objetos tiempo fuera de la clase
8. Sobrecargar los operadores +,- para poder operar con objetos tiempo fuera de la clase 
9. Crear un programa que pida al usuario 2 tiempos y muestre por pantalla el resultado de la suma, la resta y la comparación. Dicho programa debe capturar las excepciones creadas y mostrar por pantalla el aviso lanzado por ellas. 