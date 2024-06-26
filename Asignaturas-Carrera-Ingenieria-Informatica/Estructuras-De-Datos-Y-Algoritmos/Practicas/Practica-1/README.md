Práctica I
==========

Recursividad
------------

Se propone implementar las siguientes funciones utilizando **funciones recursivas**:

1. Paridad de un número mediante restas (recursividad simple).

   ```cpp
   bool es_par(int num);
   ```

1. Calcular el cociente de una división entera

   ```cpp
   int cociente(int dividendo, int divisor);
   ```

1. Calcular el resto de una división entera

   ```cpp
   int resto(int dividendo, int divisor);
   ```

1. Implementar una función `es_multiplo` que devuelva si un número `num` es o no divisible por otro número `divisor`

   ```cpp
   bool es_multiplo(int num, int divisor);
   ```

1. Implementar una función que calcule el máximo común divisor aplicando el [algoritmo de Euclides](https://es.wikipedia.org/wiki/Algoritmo_de_Euclides). Justifica y razona su orden de complejidad

   ```cpp
   int mcd(int a, int b);
   ```

1. Sumatorio de los números del `1` al `N` (incluido):

   ```cpp
   int sum(int N);
   ```

1. Sumatorio de los números **pares** del `1` al `N` (incluido):

   ```cpp
   int sum_pares(int N);
   ```

1. Sumatorio de los números **impares** del `1` al `N` (incluido):

   ```cpp
   int sum_impares(int N);
   ```

1. Implementar una función que invierta un `std::string` que recibe como argumento:

   ```cpp
   std::string invertir(const std::string& input);
   ```

1. Implementar una función que invierta los dígitos de un número entero. De manera que si el número es `521` el algoritmo debe devolver `125`:

   ```cpp
   int invertir(int num);
   ```

1. Representa en binario un número entero sin signo:

   ```cpp
   std::string num2binary(int num);
   ```

1. Implementar una función que indique si dos vectores pasados como argumento son iguales:

   ```cpp
   bool equal(const std::vector<int>& lhs, const std::vector<int>& rhs);
   ```

1. Implementar una función que indique si dos matrices pasadas como argumento son iguales

   ```cpp
   bool equal(const std::array<std::array<int, 100>, 100>& lhs, 
              const std::array<std::array<int, 100>, 100>& rhs);
   ```

1. Función que determine si un número es [perfecto](https://es.wikipedia.org/wiki/N%C3%BAmero_perfecto).

   ```cpp
   bool is_perfect(int num);
   ```

1. Implementar el método de ordenación de la burbuja de manera recursiva

   ```cpp
   void bubble_sort_recursive(std::vector<int>& values);
   ```

Algoritmos
----------

Implementar los siguientes algoritmos:

1. Utilizar el algoritmo **Quicksort** para ordenar un vector de cadenas según la longitud de cada palabra (las más cortas delante). A igual longitud, utilizar el orden lexicográfico.

   ```cpp
   void quicksort_strings(std::vector<std::string>& values);
   ```

1. Dado un vector de estructuras, donde cada estructura almacena las coordenadas `x` e `y` de un punto, implementar una función que ordene los elementos según su distancia
a otro punto dado como argumento:

   ```cpp
   struct Point { float x, y; };
   void sort_by_distance(std::vector<Point>& values, float origin_x, float origin_y);
   ```




bool es_par(int num) {
   // Implementation
   return false;
}

int cociente(int dividendo, int divisor) {
   // Implementation
   return -1;
}

// ..
```
