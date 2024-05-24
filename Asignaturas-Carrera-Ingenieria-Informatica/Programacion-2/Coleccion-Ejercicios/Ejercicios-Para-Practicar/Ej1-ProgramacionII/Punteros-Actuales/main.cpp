#include <iostream>
#include "person.h"
#include "funciones.h"
#include <memory>

using namespace std;

int main()
{

    std::vector<shared_ptr<Person>> listin;

    try
    {
        std::string option{"x"};
        while (option != "q")
        {
            std::cout << "Introduzca una opción: \n";
            std::cout << "a \tAñadir persona\n";
            std::cout << "l \tListar todas las personas\n";
            std::cout << "b \tBuscar una persona por nombre\n";
            std::cout << "le \tListar todas las personas de una determinda edad\n";
            std::cout << "q \tSalir\n";
            std::cin >> option;

            if (option == "a")
            {
                std::cout << "Introduzca nombre, edad y telefono: ";
                std::string nombre, telefono;
                int edad;
                std::cin >> nombre >> edad >> telefono;

                auto p1 = make_shared<Person>(Person{nombre, edad, telefono});

                listin.push_back(p1);
            }
            else if (option == "l")
            {
                forEach(listin, [](std::shared_ptr<Person> p) -> void
                        {
                    std::cout << *p;
                    std::cout << "----------\n"; });
            }
            else if (option == "b")
            {
                std::cout << "Introduzca nombre de la pesona a buscar: ";
                std::string nombre;
                std::cin >> nombre;
                std::shared_ptr<Person> p = find(listin, [&](std::shared_ptr<Person> p) -> bool
                                                 { return p->getNombre() == nombre; });
                if (p)
                    std::cout << *p << "------------\n";
            }
            else if (option == "le")
            {
                std::cout << "Introduzca la edad que desea buscar: ";
                int edad;
                std::cin >> edad;
                std::vector<std::shared_ptr<Person>> result = filter(listin, [&](std::shared_ptr<Person> p) -> bool
                                                                     { return p->getEdad() == edad; });

                forEach(result, [](std::shared_ptr<Person> p) -> void
                        {
                    std::cout << *p;
                    std::cout << "----------\n"; });
            }
        }
    }
    catch (std::string e)
    {
        std::cout << "ERROR: " << e << "\n";
    }

    cout << "Adios, gracias!!" << endl;
    return 0;
}
