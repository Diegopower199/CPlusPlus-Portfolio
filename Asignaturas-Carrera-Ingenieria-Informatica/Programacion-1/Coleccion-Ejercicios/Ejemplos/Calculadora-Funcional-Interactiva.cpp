#include <iostream>
#include <functional>

using namespace std;

int main()
{
    function<float(float, float)> suma = [](float a, float b)
    {
        return a + b;
    };

    function<float(float, float)> resta = [](float a, float b)
    {
        return a - b;
    };

    function<void(function<float(float, float)> f, float a, float b)> print = [](function<float(float, float)> f, float a, float b)
    {
        cout << f(a, b) << endl;
    };

    cout << "Primer caso: " << suma(1, 2) << endl;
    print(suma, 3, 4);  // -> 7
    print(resta, 3, 4); // -> -1
    return 0;
}
