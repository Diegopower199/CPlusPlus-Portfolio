#include <iostream>
#include "numeropositivo.h"

using namespace std;

int main()
{
    float num = 0;
    cout << "Introduce un numero positivo: ";
    cin >> num;
    try
    {
        NumeroPositivo numero{num};
        cout << "Dividirlo por... ";
        cin >> num;
        cout << numero.divideBy(num) << "\n";
        cout << "Multiplicarlo por... ";
        cin >> num;
        cout << numero.multiplyBy(num) << "\n";
        cout << "Sumarle... ";
        cin >> num;
        cout << numero.add(num) << "\n";
    }
    catch (string e)
    {
        cout << e << "\n";
    }
    return 0;
}
