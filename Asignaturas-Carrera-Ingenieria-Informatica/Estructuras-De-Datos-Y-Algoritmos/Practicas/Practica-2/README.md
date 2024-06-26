Práctica II - La discoteca
==========================




En los tiempos anteriores al COVID-19 la gente acudía a unos lugares llamados discotecas. En
ocasiones había que esperar largas colas para poder entrar y, a veces, cuando ya te iba a
llegar el turno se acercaban unas personas y quien estaba delante decía la temida 
frase: _"Vienen conmigo"_.

En este ejercicio se debe implementar una clase `Queue` con los métodos correspondientes
a una cola y, además, un método `sneak_in(const TipoDato& contact, Queue& friends)` que
utilizaremos para colar **en orden** a los `friends` justo detrás del elemento `contact`
(sólo si el _contacto_ está en la cola).

A continuación se muestran las interfaces de las clases que deben utilizarse, **recuerda
que estas interfaces no pueden modificarse**:

 * Para la clase `Queue` que representa una cola:

    ```cpp
    /* Queue.h */

    class Queue {
        public:
            Queue();

            int size() const;
            bool empty() const;

            Persona& front() const;
            Persona& back() const;

            void push(const Persona& dato);
            void pop();

            // This function adds the queue of 'friends' after the 'contact' (if found)
            void sneak_in(const Persona& contact, Queue& friends);

        protected:
            std::shared_ptr<ElementListaDoble> _front = nullptr;
            std::shared_ptr<ElementListaDoble> _back = nullptr;
    };
    ```

 * La clase `ElementListaDoble`:

    ```cpp
    /* ElementoListaDoble.h */

    class ElementListaDoble {
        public:
            // Members
            Persona dato;
            std::shared_ptr<ElementListaDoble> next = nullptr;
            std::shared_ptr<ElementListaDoble> prev = nullptr;
        public:
            // Constructor 
            ElementListaDoble(const Persona& dato_);
    };
    ```

 * La clase `Persona` representará a las personas en la cola:

    ```cpp
    /* Persona.h */

    class Persona {
        public:
            Persona(const std::string& name, const std::string& dni, int gender);

            const std::string& get_name() const;
            int get_gender() const;
            const std::string& get_dni() const;
            bool operator==(const Persona& other) const;
        private:
            int gender; 
            std::string name;
            std::string dni;
    };
    ```

   El sexo está representado por la variable `gender`, a efectos de esta
   práctica sólo se considerará el valor `0` (masculino) y `1` (femenino).

   La clase `Persona` proporciona un método
   `operator==` que nos permitirá comparar o buscar personas. El método
   `bool operator==(const Persona& other) const` devolverá `true` cuando
   dos personas sean idénticas (mismo valor de todos sus atributos).


Con las clases anteriores debe ser posible implementar un programa como
el siguiente:

```cpp
int main() {
    // Manuel is going today to Joy Slava, he is waiting for some friends
    Persona manuel{"Manuel", "dni-manuel", 0};

    // Create the queue for the disco
    Queue joy_eslava;
    joy_eslava.push(Persona{"Sergio", "dni-sergio", 0});
    joy_eslava.push(manuel);
    joy_eslava.push(Persona{"Leticia", "dni-leticia", 1});
    // ...

    // Create the queue with Manuel's friends
    Queue friends;
    friends.push(Persona{"Miguel", "dni-miguel", 0});
    friends.push(Persona{"Samuel", "dni-samuel", 0});
    friends.push(Persona{"Raquel", "dni-raquel", 1});

    // Sneak in
    joy_eslava.sneak_in(manuel, friends);

    // Check the queue is the expected one: print size and names
    std::cout << "Joy Slava, people waiting: " << joy_eslava.size() << std::endl;
}
```


El guardarropa
--------------


A medida que la gente entra en la discoteca va dejando sus abrigos _apilados_ en 
el guardarropa. En este lugar hay un guardarropa para mujeres y otro para hombres,
y sólo se anota el nombre del dueño.

Escribir una función que reciba la `Queue` de personas esperando para entrar, y dos
instancias de una pila `Wardrobe`. En función del sexo de las personas, debe anotarse
en la pila correspondiente el nombre de su dueño.

```cpp
void wardrobe(Queue& joy_slava, Wardrobe& men, Wardrobe& women); 
```

La clase `Wardrobe` (y auxiliares) tendrá la siguiente interfaz:

```cpp
/* Wardrobe.h */

class WardrobeElement {
    public:
        // Members
        std::string owner;
        std::shared_ptr<WardrobeElement> next = nullptr;
    public:
        // Constructor 
        WardrobeElement(const std::string& owner);
};

class Wardrobe {
    public:
        Wardrobe();

        int size() const;
        bool empty() const;

        void push(const std::string& dato);
        void pop();
        std::string& top() const;
    protected:
        std::shared_ptr<WardrobeElement> front = nullptr;
};

void wardrobe(Queue& joy_slava, Wardrobe& men, Wardrobe& women); 
```


¡Redada!
--------


Parece que la policía está buscando a algunas personas. Se están acercando
a los diferentes locales y preguntando a la gente que está haciendo cola.
Llevan con ellos una lista de DNIs, ¡se están llevando gente a
comisaría!

Deberá implementarse una función que acepte la `Queue` de personas y un
`std::vector<std::string>` con los DNIs de las personas que están
buscando. La función devolverá otra `Queue` con la personas de la cola
original que **no aparezcan en la lista de DNIs (debe respectarse el orden
de la cola original)**.


```cpp
/* Police.h */
Queue police_raid(Queue joy_slava, const std::vector<std::string>& dnis);
```


Control de aforo
----------------


Por último, el dueño de la discoteca tiene curiosidad por saber cuáles
son los nombres que más se repiten entre la juventud del momento. Para
ello quiere contar el número de veces que aparece cada uno de los nombres.

Se implementará una función que acepte la `Queue` de personas y que
devuelva un contador de tipo _lista_ (`NameCounter`) cuyos elementos contengan
el nombre y el número de apariciones de cada nombre en la cola original.

```cpp
NameCounter count_names(Queue& joy_slava);
```

Las clases involucradas en esta función tendrán la siguiente interfaz:

```cpp
/* NameCounter.h */

struct NameCount {
    int repeats;
    std::string name;
};

class ElementListaSimple {
    public:
        NameCount dato;
        std::shared_ptr<ElementListaSimple> next = nullptr;
    public:
        ElementListaSimple(const NameCount& dato_);
};

class NameCounter {
    public:
        NameCounter();

        void add_name(const std::string& name);
        void sort();
        void for_each(std::function<void (const NameCount&)> action) const;
    protected:
        std::shared_ptr<ElementListaSimple> front = nullptr;
};

NameCounter count_names(Queue& joy_slava);
```

**La clase `NameCounter` debe implementarse a imagen y semejanza de una lista enlazada (`LinkedList`)**, 
aunque sólo cuenta con tres métodos que deberán implementarse obligatoriamente:
 * `void add_name(const std::string& name)`: añade un nuevo elemento (`NameCount`) a 
   lista si el `name` no estaba aún. En caso de que ya existiera simplemente incrementará
   en una unidad el número de `repeats`.
 * `void sort();`: ordena los elementos de la lista en función del número de repeticiones,
   el nombre más repetido será el primer elemento mientras que los menos repetidos estarán
   al final.
 * `void for_each(std::function<void (const NameCount&)> action) const;`: una función que
   nos permite recorrer los elementos de la lista en orden, al tiempo que se ejecuta la
   función `action` sobre cada uno de ellos.

En este mismo fichero `NameCounter.h` aparece la función `count_names` a la que se
llamará para crear la instancia de `NameCounter` a partir de la `Queue` de personas.

