#include <iostream>
#include <vector.h>

using namespace std;

int main()
{
    // Pedimos los datos del vec1
    float a, b, c;
    cout << "Vector 1 " << "\n\n";
    cout << "X: ";
    cin >> a;
    cout << "Y: ";
    cin >> b;
    cout << "Z: ";
    cin >> c;
    Vector v1{a, b, c};

    // Pedimos los datos del vec2
    float d, e, f;
    cout << "\nVector 2 " << "\n\n";
    cout << "X: ";
    cin >> d;
    cout << "Y: ";
    cin >> e;
    cout << "Z: ";
    cin >> f;
    Vector v2{d, e, f};

    // Calculos
    cout << "\nModulo vec1: ";
    cout << v1.getModule(v1) << "\n";
    cout << "\nModulo vec2: ";
    cout << v2.getModule(v2) << "\n";
    cout << "\nSuma: ";
    cout << v1 + v2;
    cout << "\nResta: ";
    cout << v1 - v2;
    cout << "\nMult: ";
    cout << v1 * v2;

    if (v1 == v2)
        cout << "\nSon el mismo vector!";
    else
        cout << "\nNo son el mismo vector" << endl;
}
