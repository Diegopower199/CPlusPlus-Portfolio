#include <iostream>
#include "coordenadas.h"

using namespace std;

int main()
{
    try {
        Coordenadas mv{-1,0,2};
        cout << "hecho";
    } catch (string  e) {
        cout << "error" << e << "\n";
    }
    cout << "fin";
}
