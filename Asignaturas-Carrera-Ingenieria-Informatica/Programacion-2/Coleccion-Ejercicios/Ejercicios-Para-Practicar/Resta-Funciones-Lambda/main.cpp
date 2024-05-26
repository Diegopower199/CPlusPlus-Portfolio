#include <iostream>
#include <functional>
using namespace std;

int main()
{

  function<float(float, float)> resta = [](float a, float b)
  {
    return a - b;
  };

  cout << resta(1, 2);
  return 0;
}