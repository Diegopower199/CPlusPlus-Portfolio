#include <iostream>
#include <functional>

int main()
{
  std::function<float(float, float)> suma = [](float a, float b)
  {
    return a + b;
  };

  std::function<float(float, float)> resta = [](float a, float b)
  {
    return a - b;
  };

  std::function<void(std::function<float(float, float)>,
                     float,
                     float)>
      print =
          [](std::function<float(float, float)> f, float a, float b)
  {
    std::cout << f(a, b) << "\n";
  };

  print(suma, 3, 4);
  print(resta, 3, 4);

  std::cout << suma(1, 2);
  return 0;
}