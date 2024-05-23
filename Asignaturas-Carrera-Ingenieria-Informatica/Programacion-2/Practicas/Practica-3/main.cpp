#include <iostream>
#include <tiempo.h>

using namespace std;

int main()
{
    Tiempo a, b;
    try
    {
        cout << "Tiempo 1: ";
        cout << "\n";
        cin >> a;
        cout << "\n";
    }
    catch (string e)
    {
        cout << e << endl;
    }

    try
    {
        cout << "Tiempo 2: ";
        cout << "\n";
        cin >> b;
    }
    catch (string e)
    {
        cout << e << endl;
    }

    cout << "\nSuma: ";
    cout << a + b;
    cout << "\nResta: ";
    cout << a - b;

    if (a == b)
        cout << "\nSon iguales";
    else
        cout << "\nNo son iguales" << endl;
}
