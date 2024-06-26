Práctica IV - Trabajos de impresión
===================================


En cualquier oficina la impresora es un recurso compartido entre varias
personas y, por lo tanto, lo podemos considerar un recurso escaso. En el
caso de la oficina que nos ocupa muchas personas van a enviar trabajos
para que se impriman y querrán que _su_ trabajo sea el primero en ser
despachado.

Además las impresoras tienen una memoria bastante limitada por lo que sólo
pueden almacenar un número máximo de páginas a imprimir. 

Vuestro trabajo en esta práctica consistirá en implementar un programa
capaz de decidir el orden en que deben imprimirse los trabajos teniendo en
cuenta las limitaciones de estas impresoras.


Los trabajos de impresión
-------------------------


Los trabajos que se envían a la impresora estarán representados por una
clase que contendrá, al menos, el número de páginas del trabajo y también
la hora en la que se envió:

```cpp
class PrintJob {
    public:
        PrintJob(int timestamp, int pages, const std::string& title);
        int getPages() const;
        bool operator<(const PrintJob&) const;
        bool operator>(const PrintJob&) const;
        bool operator==(const PrintJob&) const;
        friend std::ostream& operator<<(std::ostream& os, const PrintJob& job);
    private:
        int nPages;
        int timestamp;
        std::string title;
};

std::ostream& operator<<(std::ostream& os, const PrintJob& job);
```

La prioridad entre dos trabajos deberá tener en cuenta las siguientes dos
reglas:

 * Un trabajo tiene más prioridad si tiene menor número de páginas.
 * A igual número de páginas, tendrá más prioridad el trabajo que haya sido
   enviado antes.


La impresora
------------


Para implementar la impresora utilizaremos una **cola de prioridad** con
una interfaz ligeramente modificada, además la implementación tendrá que
tener en cuenta las restricciones siguientes:

* el número máximo de elementos en la cola de impresión está limitado.
* el número máximo de páginas en la cola de impresión está limitado.

Ambos parámetros son configurables, y se pasarán en el constructor al instanciar
clase. En todo momento **la impresora deberá respetar estos valores y
nunca podrá ser superado ninguno de ellos**.

Se propone la siguiente interfaz para esta clase (sólo se indican las funciones
públicas, por supuesto deberán añadirse atributos miembros y opcionalmente otras
funciones privadas):

```cpp
class Printer {
    public:
        Printer(int maxNumJobs, int maxNumPages);

        int queueLength() const;
        int queuePages() const;
        bool isEmpty() const;
        bool isFull() const;

        PrintJob next();
        bool push(const PrintJob& dato, bool force = false);
};
```

A continuación se documenta cada uno de los métodos:

* `Printer(int maxNumJobs, int maxNumPages)` es el constructor de la
  clase, recibe como argumento el número máximo de trabajos que pueden 
  estar esperando en la cola (`maxNumJobs`) y el número máximo de páginas
  que puede almacenar la impresora (`maxNumPages`).
* `int queueLength() const`: devuelve el número de trabajos que están 
  esperando en la cola a ser imprimidos.
* `int queuePages() const;`: devuelve el número total de páginas que suman
  todos los trabajos que están en la cola de impresión.
* `bool isEmpty() const`: devuelve `true` si la cola de impresión está
  vacía, en caso contrario devolverá `false`.
* `bool isFull() const`: devuelve `true` si la impresora no puede aceptar
  más trabajos en este momento (bien porque ha alcanzado el número límite
  o bien porque la memoria está llena).
* `PrintJob next()`: este método devuelve el siguiente trabajo que
  debe procesarse (el que tiene máxima prioridad) y **además** lo elimina
  de la cola de trabajos pendientes.
* `bool push(const PrintJob& dato, bool force)`: (Ver apartado siguiente).


Insertar trabajos en la impresora
---------------------------------

Comentamos en este apartado el método `bool push(const PrintJob& dato, bool force)`.

Se trata de la funcionalidad más importante de la impresora: la capacidad
que tiene de aceptar nuevos trabajos. Ante esta operación debes tener siempre
en cuenta las limitaciones en la longitud de la cola y en el número de páginas
que puede almacenar la memoria de la impresora.

Existen dos escenarios posibles:

+ `force=false`: el método tratará de insertar un nuevo trabajo en la cola 
  de impresión y devolverá el valor `true` si ha podido insertarlo (la 
  impresora, **considerando este trabajo**, no superaría los límites impuestos) 
  o `false` en caso de rechazarlo.
+ `force=true`: el trabajo será aceptado por la impresora incluso si para
  ello tiene que **eliminar trabajos con la mínima prioridad** para
  dar cabida a éste que acaba de llegar. En este caso esperamos que la
  función devuelva siempre `true` indicando que ha sido posible insertar
  el trabajo.
  
  Únicamente devolverá `false` si el trabajo supera los límites de memoria
  de la impresora. En este caso no se añadirá este trabajo, y **tampoco
  se eliminará ninguno de los que ya estaban en la cola**.


Los trabajos a imprimir
-----------------------

Los trabajos se leerán de un fichero de texto en el que cada línea contendrá
la información de un trabajo, tal y como se muestra a continuación:

```txt
1619285669 521 Cien Años de Soledad
1619285712 245 La Metamorfosis
1619286789 35 Esperando a Godot
1619286870 730 El Señor de los Anillos
1619287123 2 Práctica IV - Estructuras de datos
...
```

Puedes considerarlo un fichero separado por espacios en el que la primera
palabra es el timestamp, la segunda es el número de páginas y el resto es
el título del trabajo que debe imprimirse.