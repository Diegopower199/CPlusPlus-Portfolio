#include <iostream>

using namespace std;
#include "agenda.h"

int main()
{
    Registro agenda;

    string nombre, primerApellido, segundoApellido, fijo, movil;
    Animal aux;
    short opcion = 1;

    while (opcion >= 0)
    {
        switch (opcion)
        {

        case 0:
            return 0;

        case 1:
            cout << "( 2 ) Anadir contacto." << endl;
            cout << "( 3 ) Buscar contacto." << endl;
            cout << "( 0 ) Salir." << endl;
            cin >> opcion;
            break;

        case 2:
            cout << "Introduce nombre: ";
            cin >> nombre;
            cout << "Introduce primer apellido: ";
            cin >> primerApellido;
            cout << "Introduce segundo apellido: ";
            cin >> segundoApellido;
            cout << "Introduce telefono movil: ";
            cin >> movil;
            cout << "Introduce telefono fijo: ";
            cin >> fijo;
            if (agenda.anadirContacto(nombre, primerApellido, segundoApellido, movil, fijo))
            {
                cout << "Contaco anadido correctamente." << endl;
            }
            else
            {
                cout << "El contacto ya existia y no ha sido anadido" << endl;
            }
            opcion = 1;
            break;

        case 3:
            cout << "Introduce nombre: ";
            cin >> nombre;
            cout << "Introduce primer apellido: ";
            cin >> primerApellido;
            cout << "Introduce segundo apellido: ";
            cin >> segundoApellido;

            if (agenda.buscarContacto(nombre, primerApellido, segundoApellido, aux))
            {
                cout << "Contacto encontrado: " << endl;
                aux.print();

                cout << "Que deseaa hacer: " << endl;
                cout << "( 4 ) Eliminar contacto." << endl;
                cout << "( 5 ) Modificar contacto." << endl;
                cout << "( 1 ) Volver al menu inicial." << endl;
                cout << "( 0 ) Salir." << endl;
                cin >> opcion;
            }
            else
            {
                cout << "Contacto no encontrado" << endl;
                opcion = 1;
            }

            break;

        case 4:
            if (agenda.eliminarContacto(nombre, primerApellido, segundoApellido))
            {
                cout << "Contacto eliminado correctamente." << endl;
            }
            else
            {
                cout << "No se ha podido eliminar el contacto" << endl;
            }

            opcion = 1;
            break;

        case 5:
            if (agenda.buscarContacto(nombre, primerApellido, segundoApellido, aux))
            {
                cout << "Introduce telefono movil: ";
                cin >> movil;
                cout << "Introduce telefono fijo: ";
                cin >> fijo;
                agenda.modificarContacto(nombre, primerApellido, segundoApellido, movil, fijo);
                cout << "Contacto modificado con exito" << endl;
            }
            else
            {
                cout << "No se ha podido modificar el contacto" << endl;
            }
            opcion = 1;
            break;
        default:
            opcion = 0;
        }
    }
    return 0;
}