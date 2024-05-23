#include <iostream>
#include <memory>

using namespace std;

int main()
{
        // Puntero compartido
        auto a = make_shared<int>(4); // Lo asigno a la memoria
        auto b = a;
        auto c = make_shared<int>(5);

        *b = 6;
        b = c;
        *c = *a;
        a = c;
        cout << *c;

        /*b referencia (direccion de memoria), mientras que *b es el valor (a lo que apunta la direccion de memoria, o b)
        --cout<<*b<<"\n"; Si b es la referencia, accedo al valor de la referencia con el asterisco

        --int c = *b . c es una variable normal con el valor que apunta a b (con su propio espacio de memoria)

        --En los punteros inteligentes la memoria se libera sola
        --En un dibujo gráfico, b(o referencia) es el hilito que lleva de la etiqueta al valor(asterisco) en un propio espacio de memoria*/
        return 0;
}