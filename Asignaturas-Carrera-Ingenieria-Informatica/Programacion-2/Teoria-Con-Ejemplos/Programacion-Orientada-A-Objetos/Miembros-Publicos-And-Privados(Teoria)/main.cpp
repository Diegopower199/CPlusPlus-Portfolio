#include <iostream>
#include <functional>
#include <string>
#include <stdlib.h>
#include "conio.h"

using namespace std;

// Existen dos tipos de miembros. Unos para realizar operaciones internas (miembros privados) y otros que queremos que los programadores usen (miembros públicos)
// Las variables m iembro de una clase deben ser siempre privadas

class Person{
    // private variables -> no se puede acceder a ella desde la instancia. No la podemos "llamar" en el main por así decirlo
    private:

    string name;
    int age;

    public:
    void setName(string const & n);
    void setAge(int a);

    string getName() const;
    int getAge() const;
    void print() const;

};

int main()
{
    // Para acceder a una variable privada, emepleamos las funciones get y set correspondientes

    /* El tener una variable privada o no, nos interesa para tener un mayor control sobre ellas, por ejemplo no podemos tener una edad negativa
    Esto se puede evitar con una variable privada*/

    Person person1;

    string n;
    cout<<"¿Cuál es tu nombre: ?"; cin>> n;

    person1.setName(n);

    cout<<"Hola "<< person1.getName() << "\n";
}
