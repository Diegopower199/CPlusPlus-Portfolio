#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// REFERENCIA QUE SOLO EXISTE DENTRO DEL AMBITO DE LA VARIABLE. NO PUEDE HABER VARIOS PUNTEROS APUNTANDO A LA MISMA REFERENCIA

int main()
{

    auto MiTexto = make_unique<string>("Hola a todos"); // Creo el puntero (MiTexto) de tipo string, cuyo valor o contenido es "Hola a todos"
    cout << *MiTexto << "\n";                           // Accedo al valor del puntero (string)

    // EJEMPLO 1
    vector<unique_ptr<int>> v;
    auto p = make_unique<int>(21);

    v.push_back(p);                    // Error. Estamos haciendo una copia de p y eso no es posible.
    v.push_back(make_unique<int>(21)); // Forma correcta

    // EJEMPLO 2
    vector<unique_ptr<int>> v2;
    v2.push_back(make_unique<int>(21));
    v2.push_back(make_unique<int>(22));
    v2.push_back(make_unique<int>(23));

    for (auto elem : v) // Error. Al iterar estamos haciendo una copia de cada elemento
    {
        cout << *elem << "\n";
    }

    for (auto const &elem : v) // Forma correcta, pues estoy accediendo a la referencia
    {
        cout << *elem << "\n";
    }
}
