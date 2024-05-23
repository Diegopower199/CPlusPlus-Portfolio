/*--------- CLASES EN C++ - INTRODUCCIÓN ------------
La programación orientada a objetos (POO) es una metodología que busca simplificar el desarrollo y la reutilización de un código
Su idea principal consiste en agrupar la información y los métodos que acceden o modifican dicha información*/

#include <iostream>

using namespace std;

class Person
{
public:
    // Variables miembro -> name (string), age (int)
    string name;
    int age;

    /*Métodos -> setName -> función que no devuelve nada (void) y recibe un string como parámetro
                 setAge -> función que no devuelve nada (void) y recibe un int como parámetro
                 getName -> función que devuelve un string y no recibe ningun parametro. CONST == no modifica los datos de la clase
                 getAge -> función que devuelve un int y no recibe ningun parametro. CONST == no modifica los datos de la clase
                 print -> no devuelve nada y no recibe ningun parámetro CONST == no modifica los datos de la clase */

    void setName(string const &n);
    void setAge(int a);

    string getName() const;
    int getAge() const;
    void print() const;

}; // Lo unico que hemos hecho ha sido declarar la clase ,indicar que funciones y que miembros tiene, pero no hemos indicado qué estan haciendo

// UNA VEZ DECLARADA LA CLASE DEBEMOS DEFINIRLA: IMPLEMENTAR CADA UNA DE LAS FUNCIONES MIEMBRO

int main()
{

    void Person::setName(string const &n)
    {
        name = n;
    }

    void Person::setAge(int a)
    {
        age = a;
    }

    string Person::getName() const
    {
        return name;
    }

    int Person::getAge() const
    {
        return age;
    }

    void Person::print() const
    {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
    }

    // Una clase es un  tipo de dato, definido por el programador, que puede ser utilizado en el programa como cualquier otro tipo de dato
}
