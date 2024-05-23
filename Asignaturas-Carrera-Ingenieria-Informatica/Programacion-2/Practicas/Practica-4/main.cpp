#include <iostream>
#include <memory>
#include "Pair.h"
#include "data.h"
#include "DB.h"

using namespace std;

using namespace std;

int main()
{

    Pair<string, string> nombre{"nombre", "Alberto"};
    Pair<string, string> apellido{"apellido", "valero"};
    Pair<string, string> edad{"edad", "19"};

    Data<string, string> yo;
    yo.push(nombre);
    yo.push(apellido);
    yo.push(edad);

    Pair<string, string> nombre2{"nombre", "Benito"};
    Pair<string, string> apellido2{"apellido", "Camelas"};
    Pair<string, string> edad2{"edad", "19"};

    Data<string, string> benito;
    yo.push(nombre2);
    yo.push(apellido2);
    yo.push(edad2);

    DB<string, string> database;
    database.push(yo);
    database.push(benito);

    auto f_busq = [](Data<string, string> d)
    {
        auto parejas = d.getData();
        for (auto elem : parejas)
        {
            if (elem.getKey() == "edad" && elem.getValue() == "19")
            {
                return true;
            }
        }
        return false;
    };

    auto result = database.find(f_busq);
    auto filtered_result = database.filter(f_busq);

    return 0;
}
