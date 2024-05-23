Práctica III - Árboles binarios de búsqueda
===========================================



Base de datos de empleados
--------------------------

Se pide implementar una base de datos con los empleados de una empresa, para
ello se utilizará un **árbol binario de búsqueda**. Los empleados están
representados por la siguiente clase:

```cpp
/* Empleado.h */

class Empleado {
    public:
        Empleado(int id, bool is_boss);

        int get_id() const;
        bool is_boss() const;

        bool operator<(const Empleado& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Empleado& empleado);
    private:
        int id_;
        bool is_boss_;
};

std::ostream& operator<<(std::ostream& os, const Empleado& empleado);
```

El identificador del empleado (`id_`) es único para cada empleado en la empresa y
será el único elemento a considerar como **criterio de ordenación y/o de igualdad**.
El miembro `is_boss_` identifica si el empleado pertenece a la dirección de la
empresa o no.

Para implementar la base de datos se utilizarán las siguientes clases, **con las
interfaces que se explicitan a continuación**:

```cpp
/* Database.h */

class ElementoArbolBinario {
    public:
        // Members
        Empleado dato;
        std::shared_ptr<ElementoArbolBinario> left = nullptr;
        std::shared_ptr<ElementoArbolBinario> right = nullptr;
    public:
        // Constructor 
        ElementoArbolBinario(const Empleado& dato_) : dato{dato_} {};
};


class BinarySearchTree {
    private:
        std::shared_ptr<ElementoArbolBinario> root = nullptr;
 
    public:
        BinarySearchTree();  // Creates empty tree

        void push(const Empleado&);

        int size() const; // Number of nodes
        void for_each(std::function<void (Empleado&)> action) const;  // Visit all the nodes
        const Empleado& find(int id) const; // Return the employee with the given id
};
```

La clase `BinarySearchTree` se **implementará como un árbol binario de búsqueda**, con
las siguientes funciones:
 * `BinarySearchTree()`: el constructor de la clase, inicializa un árbol vacío.
 * `void push(const Empleado&)`: inserta un empleado en su posición correspondiente del
 árbol según su `id`. Cada identificador es único y nunca se insertarán dos empleados
 con el mismo identificador.
 * `int size() const`: devuelve el número de empleados en la base de datos.
 * `void for_each(std::function<void (Empleado&)> action) const` recorre todos los nodos
 del árbol y ejecuta la función `action` con cada uno de los empleados almacenados.
 * `const Empleado& find(int id) const`: busca en el árbol el empleado cuyo identificador
 es igual a `id` y lo devuelve (**la búsqueda debe aprovechar la estructura ordenada del
 árbol binario de búsqueda**). Siempre se buscará un `id` existente, no es necesario considerar
 el caso en que el empleado no se encuentre en la base de datos.


Empleados y managers
--------------------

La empresa ha crecido y recursos humanos ha decidido generar dos bases de datos diferentes,
una con los empleados rasos (`is_boss_` con valor `false`) y otra con los jefes (`is_boss_`
con valor `true`). 

Partiendo de la base de datos anterior implementada con la clase `BinarySearchTree` se pide
implementar la siguiente función:

```cpp
/* FilterDatabase.h */

void filter_database(const BinarySearchTree& all, BinarySearchTree& employees, BinarySearchTree& managers);

```

La función `filter_database` recibe varios parámetros:
 * `const BinarySearchTree& all`: es la base de datos que contiene todos los empleados.
 * `BinarySearchTree& employees`: es una base de datos vacía que deberá rellenarse con los empleados
 que no sean jefes.
 * `BinarySearchTree& managers`: es una base de datos vacía que deberá rellenarse con los
 empleados que sí sean jefes.

Recuerda que **sólo puedes utilizar las funciones que están disponibles en las interfaces
de las clases**, no deberás añadir ninguna función adicional.


Operaciones en árboles
----------------------

En este ejercicio no tendrás que escribir ni una sola línea de código. Se deberá entregar un
documento en el que se vayan realizando lo siguientes pasos:

1. Dibujar el árbol binario de búsqueda que se crea al introducir los siguientes números en orden:
`10`, `8`, `15`, `12`, `20`, `9` y `14`. Deberá dibujarse el árbol después de introducir
cada uno de los nodos (7 dibujos).
1. En otro dibujo, indicar los nodos que se visitan para buscar el nodo `14`. Razonar por
escrito sobre la complejidad que tiene esta operación.
1. Eliminar el nodo `9`. Razonar por escrito sobre la complejidad de esta operación.
2. Eliminar los nodos `8` y `20`. Dibujar el árbol resultante.
3. En otro dibujo, indicar los nodos que se vistan para buscar el nodo `14`. Razonar por
escrito sobre la complejidad que tiene esta operación. ¿A qué otra estructura de datos
se parece el árbol después de este último paso? ¿Qué complejidad tenía la operación
de búsqueda en esa otra estructura? ¿Qué ha pasado con el árbol? 


Expresiones matemáticas
-----------------------

Una expresión matemática es un conjunto de operandos (números y letras) y operadores 
(suma, resta, logaritmo,...). Algunos operadores requieren dos operandos como la
suma o la multiplicación y otros sólo uno como el factorial o el logaritmo.

Las expresiones matemáticas pueden expresarse en notación infija (los operadores
aparecen entre sus operandos) o postfija (los operandos preceden a los operadores). La
notación infija es la notación a la que estamos acostumbrados, como `2 * 3 + 4`, y en
ocasiones necesita hacer uso de los paréntesis para indicar el orden de las operaciones,
`2 * (3 + 4)`. La notación postfija, por el contrario, no necesita paréntesis para
desambiguar, `2 3 4 + *`, y por eso es muy habitual en ciertos dominios. Puedes leer 
más sobre notación postfija en la [Wikipedia](https://es.wikipedia.org/wiki/Notaci%C3%B3n_polaca_inversa).

En cualquier caso, independientemente de como se escriba, la expresión matemática es
la que es. Se puede **utilizar un árbol binario** para almacenar una expresión matemática
(cada operador y operando ocupará un nodo, **los paréntesis se descartan**) y **utilizar 
el recorrido en profundidad in-orden para recuperar la notación infija** y **el recorrido 
en profundidad post-orden para recuperar la notación postfija**.

![Ejemplo de árbol con expresión matemática](../images/rpn.png)

En este ejercicio se pide crear el árbol binario para las siguientes expresiones matemáticas:
 * `(2 * (3 + 4) - 10) / 2`
 * `- 3 * log (2 + 5)`

Deberá **implementarse una clase que represente un árbol binario** donde el contenido de los
nodos sea una cadena de texto con el operando u operador correspondiente. La clase implementará
**dos métodos que permitan recorrer el árbol en profundidad in-order y post-order** para
imprimir el contenido de los nodos y recuperar la representación infija y postfija de las
expresiones.

Entregables para este ejercicio:
 * Los ficheros necesarios con la implementación del árbol binario.
 * El dibujo de los árboles binarios correspondientes a ambas expresiones.
 * Dos ficheros `main1.cpp` y `main2.cpp` que contengan el código utilizado para
   crear los árboles correspondientes a cada una de las expresiones e imprimirlas, p. ej.:

   ```cpp
   /* mainX.cpp */
   
   #include "...."
   
   int main() {
       // Expresion "3 + 4"
       MiArbol arbol{"+"};
       arbol.add_left(MiArbol{"3"});
       arbol.add_right(MiArbol{"4"});
   
       // Notación infija
       arbol.dfs_inorder([](const std::string& token) {
           std::cout << token << " ";
       });
   
       // Notación postfija
       arbol.dfs_postorder([](const std::string& token) {
           std::cout << token << " ";
       });
   }
   ```

