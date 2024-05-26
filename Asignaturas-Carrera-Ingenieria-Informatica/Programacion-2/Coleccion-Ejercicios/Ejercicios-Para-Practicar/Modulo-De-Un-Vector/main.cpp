#include <iostream>
#include <functional>
#include <vector>
#include <math.h>
using namespace std;

int main()
{

  function<float(vector<float>)> modulo = [](vector<float> v)
  {
    float suma{0};
    for (auto elem : v)
    {
      suma += elem * elem;
    }
    return sqrt(suma);
  };

  return 0;
}