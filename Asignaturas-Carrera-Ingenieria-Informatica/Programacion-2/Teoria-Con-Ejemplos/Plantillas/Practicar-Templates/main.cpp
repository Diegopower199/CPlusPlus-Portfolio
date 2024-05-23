#include <iostream>

template <typename T, typename A>
class Hombre
{
public:
    Hombre(T b, A const &c);

    void setNombre(std::string);
    std::string getNombre() const;

    void setEdad(int);
    int getEdad() const;

    void print(T const &a);

private:
    T nombre;
    A edad;
};

template <typename T, typename A>
Hombre<T, A>::Hombre(T nombreIndividual, A const &edadIndividual) : nombre{nombreIndividual}, edad{edadIndividual}
{
}

template <class T, class Y>
void print(Hombre<T, Y> a)
{
    std::cout << a.getEdad() << " " << a.getNombre() << "\n";
}

int main()
{

    Hombre Julio{"Julio", 20};
    Hombre Pepe{"Pepe", 22};
}
