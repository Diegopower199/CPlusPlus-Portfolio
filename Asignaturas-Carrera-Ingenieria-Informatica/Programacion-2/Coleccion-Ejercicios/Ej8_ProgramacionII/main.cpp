#include <iostream>
#include <vector>
#include <memory>
#include "figura.h"
#include "triangulo.h"
#include "cuadrado.h"

using namespace std;

int main()
{
    vector<unique_ptr<Figura>> figuras;
    string option{"x"};

    while (option != "s")
    {
        cout << "\nQue deseas hacer?\n";
        cout << "c \tMeter Cuadrado\n";
        cout << "t \tMeter Triangulo Equilatero\n";
        cout << "p \tMostrar area y perimetro de todos\n";
        cout << "s \tSalir\n\n";
        cin >> option;

        if (option == "c")
        {
            cout << "\nIntroduce lado: ";
            float lado;
            cin >> lado;
            try
            {
                figuras.push_back(make_unique<Cuadrado>(Cuadrado{lado}));
            }
            catch (string e)
            {
                cout << e << "\n";
            }
        }
        else if (option == "t")
        {
            cout << "\nIntroduce base y altura: ";
            float lado, altura;
            cin >> lado >> altura;
            try
            {
                figuras.push_back(make_unique<Triangulo>(Triangulo{lado, altura}));
            }
            catch (string e)
            {
                cout << e << "\n";
            }
        }
        else if (option == "p")
        {
            for (auto &elem : figuras)
            {
                cout << elem->getTipo() << "\n";
                cout << "Area: " << elem->getArea() << "\n";
                cout << "Perimetro: " << elem->getPerimetro() << "\n";
                cout << "-----------------------\n";
            }
        }
    }

    cout << "\nHasta luego! " << "\n";

    return 0;
}
