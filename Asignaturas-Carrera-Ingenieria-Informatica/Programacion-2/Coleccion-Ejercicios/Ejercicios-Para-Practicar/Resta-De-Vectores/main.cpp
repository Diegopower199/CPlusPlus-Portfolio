#include <iostream>
#include <functional>
#include <vector>
#include <math.h>
using namespace std;

int main()
{

  function<float(vector<float>)> resta = [](vector<float> v)
  {
    float resta{v.at(0)};
    for (int i = 1; i < v.size(); i++)
    {
      resta -= v.at(i);
    }
    return resta;
  };

  return 0;
}