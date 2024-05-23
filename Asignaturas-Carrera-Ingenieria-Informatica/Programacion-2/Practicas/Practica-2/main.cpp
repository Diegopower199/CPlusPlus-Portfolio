#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    float a, b, c, d, e, f, g, h, i;
    cout << "Introduce 9 numeros: ";
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;

    shared_ptr<Matrix> mat1 = make_shared<Matrix>(array<float, 9>{a, b, c, d, e, f, g, h, i});

    cout << *mat1;
    cout << "Introduce otros 9 numeros: r";
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;

    shared_ptr<Matrix> mat2 = make_shared<Matrix>(array<float, 9>{a, b, c, d, e, f, g, h, i});

    auto suma = add(mat1, mat2);

    cout << *suma;
}
