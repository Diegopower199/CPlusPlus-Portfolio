#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main()
{

  function<float(vector<float>)> media = [](vector<float> v)
  {
    float suma{0};
    for (auto elem : v)
    {
      suma += elem;
    }
    return suma / v.size();
  };

  function<float(vector<float>)> max = [](vector<float> v)
  {
    float max{-9999999};
    for (auto elem : v)
    {
      if (max < elem)
        max = elem;
    }

    return max;
  };

  function<float(function<float(vector<float>)>, vector<vector<float>>)> suma = [](function<float(vector<float>)> f, vector<vector<float>> vv)
  {
    float lasuma{0};
    for (auto v : vv)
    {
      lasuma += f(v);
    }
    return lasuma;
  };

  cout << suma(media, {{3, 4}, {5, 1}, {7, 5}}) << "\n";
  cout << suma(max, {{3, 4}, {5, 1}, {7, 5}}) << "\n";

  return 0;
}