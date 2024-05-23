#include <iostream>
#include <vector>
#include <memory>
#include "contacto.h"
#include "funciones.h"
#include "agenda.h"
#include <functional>

void forEach(std::vector<std::shared_ptr<Contacto>> p, std::function<void(std::shared_ptr<Contacto>)> op)
{
    for (auto elem : p)
    {
        op(elem);
    }
}

using namespace std;

int main()
{

    Listado<Contacto> listaPersonas;
    bool condicion = true;
    int accion;
    std::string nombre;
    string claveParaHacerCosas = nombre;
    std::string primerApellido;
    std::string telefono;
    std::string correoElectronico;
    std::string fechaNacimiento;

    while (condicion == true)
    {
        cout << "1.\tAñadir Persona\n"
             << "2.\tEliminar Persona\n"
             << "3.\tBuscar un contacto por nombre y primer apellido\n"
             << "4.\tMostrar un contacto por pantalla\n"
             << "5.\tMostrar por pantalla los contactos que cumplen años en una fecha metida por teclado en formato dd/mm/aaaa\n"
             << "6.\tMostrar por pantalla todos los contactos de la agenda\n"
             << "7.\tAcabar Programa\n"
             << "\nElige una accion:";
        cin >> accion;
        while (accion < 1 || accion > 7)
        {
            cout << "Accion no valida: ";
            cin >> accion;
        }

        cout << "\n";
        switch (accion)
        {
        case 1:

            std::cout << "Introduzca nombre, primer apellido, telefono, correo electronico y fecha de nacimiento: ";
            std::cin >> nombre >> primerApellido >> telefono >> correoElectronico >> fechaNacimiento;
            claveParaHacerCosas = nombre;
            cout << "\n";
            try
            {
                auto a = std::make_shared<Agenda<Contacto>>(Agenda<Contacto>(claveParaHacerCosas, Contacto{nombre, primerApellido, telefono, correoElectronico, fechaNacimiento}));
                listaPersonas.insertar(a);
            }
            catch (string e)
            {
                cout << e << "\n";
            }
            break;

        case 2:
            try
            {
                cout << "Introduce el nombre de la persona a borrar:";
                cin >> claveParaHacerCosas;
                cout << "\n";
                listaPersonas.eliminar(claveParaHacerCosas);
            }
            catch (string e)
            {
                cout << e << "\n";
            }
            break;

        case 3:
            try
            {
                cout << "Introduce el nombre y apellido de la persona que deseas buscar:";
                std::cin >> claveParaHacerCosas;
                auto encontrada = listaPersonas.find([=](std::shared_ptr<Agenda<Contacto>> a)
                                                     { return a->getClave() == claveParaHacerCosas; });
                if (encontrada)
                    cout << *encontrada << "\n";
                else
                    cout << "Persona no encontrada\n";
            }
            catch (string e)
            {
                cout << e << "\n";
            }
            break;

        case 4:
            try
            {
                cout << "Introduce el nombre de la persona que deseas buscar:";
                cin >> claveParaHacerCosas;
                auto encontrada = listaPersonas.find([=](std::shared_ptr<Agenda<Contacto>> a)
                                                     { return a->getClave() == claveParaHacerCosas; });
                if (encontrada)
                    cout << *encontrada << "\n";
                else
                    cout << "Persona no encontrada\n";
            }
            catch (string e)
            {
                cout << e << "\n";
            }
            break;

        case 5:

            try
            {
                std::cout << "Introduzca la edad que desea buscar: ";
                std::string fechaNacimientoCoincidente;
                std::cin >> fechaNacimientoCoincidente;
            }
            catch (string e)
            {
                cout << e << "\n";
            }

            break;

        case 6:
            cout << listaPersonas;
            break;
        case 7:
            condicion = false;
            break;
        }
    }
    cout << "Hasta luego!" << "\n";

    return 0;
}
