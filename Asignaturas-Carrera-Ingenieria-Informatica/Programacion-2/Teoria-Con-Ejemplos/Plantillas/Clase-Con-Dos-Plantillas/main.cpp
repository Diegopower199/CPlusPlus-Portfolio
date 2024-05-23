#include <iostream>
#include <memory>
#include <ostream>
using namespace std;

struct Complejo
{
    float real;
    float imaginaria;
};

template <typename T, typename MOD>
class Vector3
{
    template <typename TN, typename TD>
    friend std::ostream &operator<<(std::ostream &os, Vector3<TN, TD> const &a);

public:
    Vector3(T const &elem1, T const &elem2, T const &elem3);

    // Hacer funciones getter y setter templatizadas

    T getElem(int i) const;
    void print(T const &a, MOD const &b);

    MOD modulo() const;

private:
    T elem1;
    T elem2;
    T elem3;
};

template <typename T, typename MOD>
Vector3<T, MOD>::Vector3(T const &elem1, T const &elem2, T const &elem3) : elem1{elem1}, elem2{elem2}, elem3{elem3}
{
}

template <typename T, typename MOD>
MOD Vector3<T, MOD>::modulo() const
{
    return elem1 * elem1 + elem2 * elem2 + elem3 * elem3;
}

template <>
Complejo Vector3<Complejo, Complejo>::modulo() const
{
}

template <typename T, typename MOD>
T Vector3<T, MOD>::getElem(int i) const
{
    if (i == 1)
    {
        return elem1;
    }
    if (i == 2)
    {
        return elem2;
    }
    if (i == 3)
    {
        return elem3;
    }

    // Si pide cualquier otra cosa lanzas esta excepcion
    throw std::string{"Out of bounds"};
}

template <class T, class Y>
void print(T const &a, Y const &b)
{
    std::cout << a << "\n";
    std::cout << b << "\n";
}

// si quiero imprimir int la funcion general esa me sirve por eso no la particularizo
int main()
{
    Vector3<int, int> a{1, 2, 3};
    Vector3<int, int> b{4, 5, 6};
}
