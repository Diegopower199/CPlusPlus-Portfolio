#include <iostream>
#include <ostream>
#include <istream>

class Complex
{
    friend Complex operator+(Complex const &c1, Complex const &c2);
    friend Complex operator-(Complex const &c1, Complex const &c2);
    friend Complex operator*(Complex const &c1, Complex const &c2);
    friend std::ostream &operator<<(std::ostream &os, Complex const &c);
    friend bool operator==(Complex const &c1, Complex const &c2);
    friend std::istream &operator>>(std::istream &is, Complex &c);

public:
    Complex() : r{0}, i{0} {}
    Complex(float r, float i) : r{r}, i{i} {}

private:
    float i;
    float r;
};

bool operator==(Complex const &c1, Complex const &c2)
{
    return (c1.r == c2.r && c1.i == c2.i);
}

Complex operator+(Complex const &c1, Complex const &c2)
{
    std::cout << "venga, voy a sumar\n";
    Complex result = {c1.r + c2.r, c1.i + c2.i};

    return result;
}

Complex operator-(Complex const &c1, Complex const &c2)
{
    std::cout << "venga, voy a sumar\n";
    Complex result = {c1.r - c2.r, c1.i - c2.i};

    return result;
}

Complex operator*(Complex const &c1, Complex const &c2)
{
    std::cout << "venga, voy a multiplicar\n";
    Complex result = {c1.r * c2.r - c1.i * c2.i, c1.r * c2.i + c1.i * c2.r};

    return result;
}

std::ostream &operator<<(std::ostream &os, Complex const &c)
{
    os << c.r << " + " << c.i << "*i";
    return os;
}

std::istream &operator>>(std::istream &is, Complex &c)
{
    is >> c.r;
    is >> c.i;
    return is;
}

int main()
{
    int a;
    int b;
    int c;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    Complex com;
    std::cin >> com;

    std::cout << "Primer numero: " << a << "\nSegundo numero: " << b << "\nTercer numero: " << c << "\nEl numero complejo: " << com;
}