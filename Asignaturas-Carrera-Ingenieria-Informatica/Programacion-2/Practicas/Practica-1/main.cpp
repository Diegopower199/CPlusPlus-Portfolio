#include <iostream>
#include <vector>
#include <memory>
#include "persona.h"
#include <functional>

using namespace std;

// Funcion find
shared_ptr<Persona> find(vector<shared_ptr<Persona>> const &v, function<bool(shared_ptr<Persona>)> f)
{
    for (auto p : v)
    {
        if (f(p))
            return p;
    }
    return nullptr;
}

// Funcion some
bool some(vector<shared_ptr<Persona>> const &v, function<bool(shared_ptr<Persona>)> f)
{
    auto r = find(v, f);
    return (r != nullptr);
}

int main()
{
    vector<shared_ptr<Persona>> censo;

    for (int i = 0; i < 5; i++)
    {
        cout << "Introduce nombre: ";
        string name;
        getline(cin, name);
        cin.clear();
        cout << "Introduce año de nacimiento: ";
        int birth;
        cin >> birth;
        cout << "Introduce DNI: ";
        string dni;
        cin >> dni;
        cout << "Introduce telefono: ";
        string tel;
        cin >> tel;
        shared_ptr<Persona> pPersona;
        pPersona = make_shared<Persona>();
        pPersona->setDni(dni);
        pPersona->setName(name);
        pPersona->setTel(tel);
        pPersona->setBirth(birth);

        censo.push_back(pPersona);
    }

    auto pepe = find(censo, [](shared_ptr<Persona> p)
                     { return p->getName() == "Pepe"; });

    auto dni = find(censo, [](shared_ptr<Persona> p)
                    { return p->getDni() == "44324243"; });
}
