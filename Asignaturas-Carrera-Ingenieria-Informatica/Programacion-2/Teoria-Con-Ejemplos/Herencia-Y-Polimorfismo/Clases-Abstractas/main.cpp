#include <iostream>

// Clase abstracta porque tiene una funcion virtual pura
class Figura
{
public:
    Figura(){};

    // -> Se utilizan cuando no tiene sentido implementarla en la clase Padre, pero queremos que se implemente en las hijas
    virtual float getArea() const = 0; // Funcion virtual pura. Se diferencia por el const = 0;
};

int main()
{
    Figura fig; // ERROR, no se puede crear una variable de una clase abstracta
    std::cout << "Hello world!\n";
}
