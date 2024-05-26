#include "contacto.h"

using namespace std;

int main()
{
    bool condicion = true;
    int accion;
    string nombre, apellido, telefono, email, fecha;
    Agenda agenda;

    while (condicion)
    {
        cout << "1.\tAdd Contacto\n"
             << "2.\tEliminar Contacto\n"
             << "3.\tBuscar Contacto por Nombre y Apellido\n"
             << "4.\tBuscar Contacto por Fecha\n"
             << "5.\tListar Agenda\n"
             << "6.\tListar Birthdays\n"
             << "7.\tAcabar Programa\n"
             << "Elige una accion: ";
        cin >> accion;

        while (accion < 1 || accion > 7)
        {
            cout << "Accion no valida, por favor elija una correcta: ";
            cin >> accion;
        }

        cout << endl;
        switch (accion)
        {
        case 1:
            cout << "Introduzca el Nombre del contacto a añadir: ";
            cin >> nombre;
            cout << "Introduzca el Apellido del contacto a añadir: ";
            cin >> apellido;
            cout << "Introduzca el Telefono del contacto a añadir: ";
            cin >> telefono;
            cout << "Introduzca el Email del contacto a añadir: ";
            cin >> email;
            cout << "Introduzca la Fecha de nacimiento del contacto a añadir en formato dd/mm/aaaa: ";
            cin >> fecha;
            try
            {
                auto contacto = make_shared<Contacto>(nombre, apellido, telefono, email, fecha);
                agenda.insertar(contacto);
            }
            catch (const string &msg)
            {
                cout << msg << endl;
            }
            break;
        case 2:
            cout << "Introduzca el Nombre del contacto a eliminar: ";
            cin >> nombre;
            cout << "Introduzca el Apellido del contacto a eliminar: ";
            cin >> apellido;
            agenda.borrar(nombre, apellido);
            break;
        case 3:
            cout << "Introduzca el Nombre del contacto a buscar: ";
            cin >> nombre;
            cout << "Introduzca el Apellido del contacto a buscar: ";
            cin >> apellido;
            if (auto contacto = agenda.findNom(nombre, apellido))
            {
                cout << *contacto;
            }
            break;
        case 4:
            cout << "Introduzca la fecha del contacto a buscar en formato dd/mm/aaaa: ";
            cin >> fecha;
            if (auto contacto = agenda.findAge(fecha))
            {
                cout << *contacto;
            }
            break;
        case 5:
            cout << agenda;
            break;
        case 6:
            cout << "Introduzca la fecha del contacto a buscar en formato dd/mm/aaaa: ";
            cin >> fecha;
            if (auto contacto = agenda.print(fecha))
            {
                cout << *contacto;
            }
            break;
        case 7:
            condicion = false;
            break;
        }
    }

    return 0;
}
