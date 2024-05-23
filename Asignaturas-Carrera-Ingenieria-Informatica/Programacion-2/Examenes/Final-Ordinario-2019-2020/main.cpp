#include <iostream>

#include "Listado.h"

using namespace std;

int main()
{
    Listado<Persona> listaPersonas;
    bool condicion = true;
    int accion, nacimiento;
    string clave;
    string nombre;
    string telefono;

    while (condicion == true)
    {
        cout << "1.\tAñadir Persona\n"
             << "2.\tEliminar Persona\n"
             << "3.\tBuscar Persona\n"
             << "4.\tListar\n"
             << "5.\tAcabar Programa\n"
             << "\nElige una accion:";
        cin >> accion;
        while (accion < 1 || accion > 5)
        {
            cout << "Accion no valida: ";
            cin >> accion;
        }

        cout << "\n";
        switch (accion)
        {
        case 1:
            cout << "Introduce la clave para la persona:";
            cin >> clave;
            cout << "Introduce el nombre de la persona:";
            cin >> nombre;
            cout << "Introduce el año de nacimiento de la persona:";
            cin >> nacimiento;
            cout << "Introduce el telefono de la persona:";
            cin >> telefono;
            cout << "\n";
            try
            {
                auto a = std::make_shared<Data<Persona>>(Data<Persona>(clave, Persona{nombre, nacimiento, telefono}));
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
                cout << "Introduce la clave de la persona a borrar:";
                cin >> clave;
                cout << "\n";
                listaPersonas.eliminar(clave);
            }
            catch (string e)
            {
                cout << e << "\n";
            }
            break;
        case 3:
            try
            {
                cout << "Introduce la clave de la persona que deseas buscar:";
                cin >> clave;
                auto encontrada = listaPersonas.find([=](std::shared_ptr<Data<Persona>> a)
                                                     { return a->getClave() == clave; });
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
            cout << listaPersonas;
            break;
        case 5:
            condicion = false;
            break;
        }
    }
    cout << "Hasta luego!" << "\n";

    return 0;
}
