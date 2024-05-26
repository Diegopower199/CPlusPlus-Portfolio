#include <iostream>
#include <functional>
using namespace std;

int main()
{

  function<float(float, float)> suma = [](float a, float b)
  {
    return a + b;
  };

  cout << suma(1, 2);
  return 0;
}