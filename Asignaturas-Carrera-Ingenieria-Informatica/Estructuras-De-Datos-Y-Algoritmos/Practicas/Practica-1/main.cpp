#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

// Apartado 1
bool es_par(int num)
{

    if (num == 0)
    {
        return true;
    }
    else if (num == 1)
    {
        return false;
    }
    else
    {
        return es_par(num - 2);
    }
}

// Apartado 2
int cociente(int dividendo, int divisor)
{
    if (divisor > dividendo)
    {
        return 0;
    }
    else
    {
        return 1 + cociente(dividendo - divisor, divisor);
    }
}
// Apartado 3
int resto(int dividendo, int divisor)
{
    if (dividendo < divisor)
    {
        return dividendo;
    }
    else
    {
        return resto(dividendo - divisor, divisor);
    }
}

// Apartado 4
bool es_multiplo(int num, int divisor)
{
    if (num < divisor)
    {
        return false;
    }
    else if (num == divisor)
    {
        return true;
    }
    else
    {
        return es_multiplo(num - divisor, divisor);
    }
}

// Apartado 5
int mcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        mcd(b, a % b);
    }
}

// Apartado 6
int sum(int N)
{
    if (N == 0)
    {
        return 0;
    }
    else
    {
        return N + sum(N - 1);
    }
}

// Apartado 7
int sum_pares(int N)
{
    if (N == 2)
    {
        return 2;
    }
    else if (N % 2 == 0)
    {
        return N + sum_pares(N - 2);
    }
    else if (N % 2 == 1)
    {
        return sum_pares(N - 1);
    }
}

// Apartado 8
int sum_impares(int N)
{
    if (N == 1)
    {
        return 1;
    }
    else if (N % 2 == 0)
    {
        return sum_impares(N - 1);
    }
    else if (N % 2 == 1)
    {
        return N + sum_impares(N - 2);
    }
}

// Apartado 9
string invertir1(const string &input)
{
    if (input.size() <= 1)
    {
        return input;
    }
    else
    {
        std::string ret{input.back(), 1};
        return ret + invertir1(input.substr(0, input.size() - 1));
    }
}

// Apartado 10
int invertir(int num)
{
    return 0;
    if (num > 9)
    {
        int ud = num % 10;
        return ud * 10 + invertir(num / 10);
    }
    else
    {
        return num;
    }
}

// Apartado 11
string num2binary(int num)
{
    if (num == 0)
    {
        return "0";
    }
    else if (num == 1)
    {
        return "1";
    }
    else
    {
        string here = (num % 2 == 0) ? "0" : "1";
        return num2binary(num / 2) + here;
    }
}

// Apartado 12
bool equal(const vector<int> &lhs, const vector<int> &rhs)
{

    if (lhs.empty() || rhs.empty())
    {
        return lhs.empty() && rhs.empty();
    }
    else
    {
        auto lhs_rest = vector<int>{lhs.begin() + 1, lhs.end()};
        auto rhs_rest = vector<int>{rhs.begin() + 1, rhs.end()};
        return lhs.at(0) == rhs.at(0) && equal(lhs_rest, rhs_rest);
    }
}

// Apartado 13
bool _equal_array(const array<int, 100> &lhs, const array<int, 100> &rhs, int i, int j)
{
    if (i >= j)
    {
        return true;
    }
    else
    {
        return (lhs[i] == rhs[i]) && _equal_array(lhs, rhs, i + 1, j);
    }
}
bool _equal_matrix(const std::array<std::array<int, 100>, 100> &lhs, const std::array<std::array<int, 100>, 100> &rhs, int i, int j)
{
    if (i >= j)
    {
        return true;
    }
    else
    {
        return _equal_array(lhs[i], rhs[i], 0, 100) && _equal_matrix(lhs, rhs, i + 1, j);
    }
}

// Apartado 14
int _sumdiv(int num, int x)
{
    if (x == 1)
    {
        return 1;
    }
    if (es_multiplo(num, x))
    {
        return x + _sumdiv(num, x - 1);
    }
    else
    {
        return _sumdiv(num, x - 1);
    }
}

bool is_perfect(int num)
{

    if (num == 1)
    {
        return false;
    }
    else
    {
        return _sumdiv(num, num / 2) == num;
    }
}

// Apartado 15
void _bubble_sort_recursive(std::vector<int> &values, int last)
{
    if (last != 0)
    {
        for (int k = 0; k < last; k++)
        {
            if (values[k] > values[k + 1])
            {
                swap(values[k], values[k + 1]);
            }
        }
        _bubble_sort_recursive(values, last - 1);
    }
}
void bubble_sort_recursive(std::vector<int> &values)
{
    if (values.size() > 1)
    {
        _bubble_sort_recursive(values, values.size() - 1);
    }
}

// Algoritmo 1
bool _greater_than(const std::string &lhs, const std::string &rhs)
{

    if (lhs.length() == rhs.length())
    {
        return lhs > rhs;
    }
    else
    {
        return lhs.length() > rhs.length();
    }
}

int partition(std::vector<std::string> &elements, int left_index, int right_index)
{
    auto pivot = elements.at(left_index);
    int i = left_index, j = right_index;

    while (true)
    {
        while (_greater_than(pivot, elements.at(i)) && i < j)
            ++i;
        while (_greater_than(elements.at(j), pivot))
            --j;
        if (i >= j)
            break;
        std::swap(elements.at(i), elements.at(j));
    }
    std::swap(elements.at(left_index), elements.at(j));
    return j;
}
void _quicksort_string(std::vector<std::string> &values, int left_index, int right_index)
{
    if (left_index >= right_index)
    {
        return;
    }
    else
    {

        int pivot_index = partition(values, left_index, right_index);

        _quicksort_string(values, left_index, pivot_index - 1);
        _quicksort_string(values, pivot_index + 1, right_index);
    }
}

// Algoritmo 2
struct Point
{
    float x, y;
};

bool _greater_than(Point lhs, Point rhs, float origin_x, float origin_y)
{

    auto lhs_distance = pow(lhs.y - origin_y, 2) + pow(lhs.x - origin_x, 2);
    auto rhs_distance = pow(rhs.y - origin_y, 2) + pow(rhs.x - origin_x, 2);
    return lhs_distance > rhs_distance;
}

void sort_by_distance(std::vector<Point> &values, float origin_x, float origin_y)
{

    if (values.empty())
    {
        return;
    }

    for (int i = 0; i < values.size() - 1; i++)
    {
        for (int k = 0; k < values.size() - 1; k++)
        {
            if (_greater_than(values[k], values[k + 1], origin_x, origin_y))
            {
                std::swap(values[k], values[k + 1]);
            }
        }
    }
}

int main()
{
    cout << es_par(12) << "\n";
    cout << cociente(12, 2) << "\n";
    cout << resto(12, 3) << "\n";
    cout << es_multiplo(12, 6) << "\n";
    cout << mcd(12, 6) << "\n";
    cout << sum(5) << "\n";
    cout << sum_pares(12) << "\n";
    cout << sum_impares(12) << "\n";
    cout << invertir1("amor") << "\n";
    cout << invertir(125) << "\n";
    cout << num2binary(12) << "\n";
}
