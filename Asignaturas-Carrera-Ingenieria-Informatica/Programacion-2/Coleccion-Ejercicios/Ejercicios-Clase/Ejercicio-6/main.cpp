#include <iostream>
#include <vector>
#include <memory>
#include "figura.h"
#include "cuadrado.h"
#include "trianguloequilatero.h"
#include "circulo.h"
#include "elipse.h"
#include "pentagonoregular.h"

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
        cout << "e \tMeter Elipse\n";
        cout << "circulo \tMeter Circulo\n";
        cout << "pentagono \tMeter Pentagono Regular\n";
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
            cout << "\nIntroduce base: ";
            float base;
            cin >> base;
            try
            {
                figuras.push_back(std::make_unique<TrianguloEquilatero>(TrianguloEquilatero{base}));
            }
            catch (string e)
            {
                cout << e << "\n";
            }
        }

        else if (option == "e")
        {
            cout << "\nIntroduce semieje1 y semieje2: ";
            float semieje1, semieje2;
            cin >> semieje1 >> semieje2;
            try
            {
                figuras.push_back(std::make_unique<Elipse>(Elipse{semieje1, semieje2}));
            }
            catch (string e)
            {
                cout << e << "\n";
            }
        }

        else if (option == "circulo")
        {
            cout << "\nIntroduce radio: ";
            float radio;
            cin >> radio;
            try
            {
                figuras.push_back(std::make_unique<Circulo>(Circulo{radio}));
            }
            catch (string e)
            {
                cout << e << "\n";
            }
        }

        else if (option == "pentagono")
        {
            cout << "\nIntroduce lado y apotema: ";
            float lado, apotema;
            cin >> lado >> apotema;
            try
            {
                figuras.push_back(std::make_unique<Pentagono_Regular>(Pentagono_Regular{lado, apotema}));
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
