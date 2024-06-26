
Todos los caminos conducen a Roma
=================================

Sin lugar a dudas, uno de los legados más importante del Imperio Romano
ha sido su [red de calzadas](https://www.rtve.es/television/20210128/ingenieria-romana-vuelve-2-nuevos-capitulos/2069341.shtml).
Las calzadas unían las principales ciudades
del Imperio y se expandían a medida que las legiones avanzaban conquistando
territorios vecinos. 

Múltiples [estudios](https://web.econ.ku.dk/pabloselaya/papers/RomanRoads.pdf)
han establecido una relación de causalidad entre la red
de calzadas del Imperio Romano, las redes de comunicaciones actuales y la
prosperidad de los territorios en Europa.

Gestionar esta red de comunicaciones, comunicar las nuevas ciudades, conectar
las zonas aisladas,... ha sido, desde entonces, una prioridad de los 
diferentes gobernantes, estados y administraciones.


Antigüedad: las calzadas
------------------------

En la antigüedad los cartógrafos sólo contaban con los testimonios de viajeros y
comerciantes para dibujar sus mapas. Gracias a estos testimonios podía crearse
un listado de ciudades y conocer la distancia entre ellas.

Deberá construirse un grafo de calzadas a partir de dos ficheros de texto. El
primer fichero es un listado con las ciudades de un territorio:

**Ciudades.txt**
```txt
0 Coruña
1 Oviedo
2 Bilbao
3 Vigo
4 Valladolid
5 Zaragoza
6 Barcelona
7 Gerona
8 Madrid
9 Badajoz
10 Albacete
11 Valencia
12 Jaén
13 Murcia
14 Sevilla
15 Granada
16 Cádiz
17 Palma de Mallorca
18 Ceuta
19 Santa Cruz de Tenerife
20 Icod de los Vinos
21 Los Cristianos
22 Manacor
```

El segundo fichero contiene las distancias entre las ciudades del fichero anterior,
estas conexiones se indican con los índices de las ciudades de origen y destino y
la distancia en kilómetros entre ellas. 

**Distancias.txt**
```txt
19 20 59
19 21 76
20 21 54
17 22 54
0 3 171
0 4 455
3 4 356
4 2 280
1 2 304
4 8 193
2 8 395
8 5 325
2 5 324
5 6 296
6 7 100
9 8 403
12 8 335
8 10 251
10 11 191
11 6 349
10 13 150
13 11 241
16 14 125
14 12 242
14 15 256
12 15 99
15 13 278
```

Deberán implementarse las clases y métodos necesarios para crear este **grafo etiquetado**,
así como proporcionarse un fichero `main1.cpp` que permita leer los fichero implicados y
construir el grafo de ciudades:

**main1.cpp**
```cpp
#include <iostream>
#include "Graph.h"

int main() {
    // Path to the files with the information
    std::string cities{"path/to/Ciudades.txt"};
    std::string distances{"path/to/Distancias.txt"};

    // Build the graph using the information from the files
    Graph<23> graph;
    ...

    // Override operator<< for your class
    std::cout << graph;
}
```

**Nota.-** Los ficheros de `Ciudades.txt` y `Distancias.txt` podrían encontrarse
en otras ubicaciones en tu caso, adapta las rutas como sea necesario.


Edad Media: rutas comerciales
-----------------------------

Tras la caída del Imperio Romano sobrevino un período de dislocación de las
antiguas provincias romanas, los territorios se encerraron en si mismos y se 
perdieron los mapas que permitían conocer las ciudades que estaban en otras
zonas del Imperio. Los viajes de larga distancia eran auténticas aventuras. 

Vuestro programa deberá implementar una función que acepte dos ciudades y
devuelva si están o no comunicadas por alguna calzada. Por ejemplo, dadas las ciudades
_Palma de Mallorca_ y _Manacor_ devolverá `true`, para las ciudades _Oviedo_ y _Valencia_
también devolverá `true`, sin embargo para la pareja _Ceuta_ y _Sevilla_
deberá devolver `false`.

```cpp
template <int N>
class Graph {
    public:
        /* ... */
        bool are_connected(std::string city1, std::string city2) const;
};
```


Modernidad: territorios de ultramar
-----------------------------------

La Edad Moderna es la época de los grandes viajes y los descubrimientos, las
monarquías se extienden por ultramar y los nuevos estados comenzarán a tener
ciudades que ya no están conectadas por las viejas calzadas romanas.

En este apartado deberéis implementar un algoritmo que le permita a los reyes
absolutistas saber el número de islas que están bajo su soberanía. 

Deberéis implementar una función que devuelva **el número de componentes de
vuestro grafo** de carreteras. Por ejemplo, en el caso de un territorio como el
formado por la Península y las Islas Canarias devolverá `2`, si consideráramos
también Baleares devolvería `3` y con Ceuta el total sería `4`. 

```cpp
template <int N>
class Graph {
    public:
        /* ... */
        int num_components() const;
};
```

Edad Contemporánea: vertebración del territorio
-----------------------------------------------

Conforme nos acercamos a nuestra era la prioridad de los Estados comienza a ser
mejorar la red de carreteras existentes y tender nuevas redes como el ferrocarril
o la telefonía. Idealmente estas nuevas redes deberían cubrir todo el territorio
y unir cada par de ciudades entre ellas, pero los recursos son escasos y habrá que
priorizar.

Implementaréis un **algoritmo adecuado para resolver este problema**. Vuestro algoritmo
deberá buscar la manera de conectar todas las ciudades de un grafo minimizando el
coste, es decir, minimizando el número de kilómetros de cable telefónico que
deben tenderse.

Para poder hacer este apartado tendréis que añadir algunas conexiones adicionales a
vuestro fichero `Distancias.txt`:

```txt
16 18 14
16 19 1413
11 17 275 
```

La función que implementéis en vuestra clase `Graph` para implementar este algoritmo
deberá devolver el grafo resultado y, además, tendréis que implementar una función que
permita saber el número de kilómetros total de cable telefónico que habrá que
utilizar.

```cpp
template <int N>
class Graph {
    public:
        /* ... */
        Graph<N> telephone() const;
        int sum_kilometers() const;
};
```

Gracias a estos métodos deberías ser capaz de implementar un `main2.cpp` parecido
al que sigue:

```cpp
#include <iostream>
#include "Graph.h"

int main() {
    // Path to the files with the information
    std::string cities{"path/to/Ciudades.txt"};
    std::string distances{"path/to/DistanciasExtendidas.txt"};

    // Build the graph using the information from the files
    Graph<23> graph;
    ...

    // Show original graph
    std::cout << graph;

    // Now compute the telephone infrastructure
    auto telephoneNetwork = graph.telephone();
    std::cout << "We will need " << telephoneNetwork.sum_kilometers();
    std::cout << " kilometers of wire.\n";
}
```
