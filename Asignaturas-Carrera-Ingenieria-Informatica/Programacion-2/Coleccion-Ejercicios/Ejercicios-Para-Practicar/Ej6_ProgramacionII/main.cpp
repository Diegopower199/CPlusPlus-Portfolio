#include <iostream>
#include "persona.h"
#include "funciones.h"
#include <memory>

using namespace std;

int main()
{
    try
    {
        vector<shared_ptr<Persona>> lista;
        lista.push_back(make_shared<Persona>(Persona{"Guillermo", 19, "12345678K"}));
        lista.push_back(make_shared<Persona>(Persona{"Diego", 23, "33333333K"}));
        lista.push_back(make_shared<Persona>(Persona{"Javier", 19, "22222222K"}));

        shared_ptr<Persona> found = find<shared_ptr<Persona>>(lista, [](shared_ptr<Persona> p) -> bool
                                                              { return (p->getDni() == "22222222K"); });

        if (found.get())
        {
            cout << found->getNombre() << "\n";
        }
    }
    catch (string e)
    {
        cout << e << "\n";
    }

    return 0;
}
