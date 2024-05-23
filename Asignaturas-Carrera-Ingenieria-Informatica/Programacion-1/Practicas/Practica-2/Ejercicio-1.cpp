#include <iostream>
#include <string>

int main()
{

    std::string texto;

    std::cout << "Introduce un texto por teclado: ";
    getline(std::cin, texto);

    std::cout << "El texto introducido es: " << texto << std::endl;

    for (int i = 0; i < texto.size(); i++)
    {
        switch (texto.at(i))
        {
        case '1':
            std::cout << texto.at(i) << std::endl;
            if (i + 1 < texto.size())
            {
                i = i + 1;
            }
            else
            {
                std::cout << "Superado tamaño del texto" << std::endl;
                i = texto.size();
            }

            break;
        case '2':
            std::cout << texto.at(i) << std::endl;
            if (i + 2 < texto.size())
            {
                i = i + 2;
            }
            else
            {
                std::cout << "Superado tamaño del texto" << std::endl;
                i = texto.size();
            }

            break;
        case '3':
            std::cout << texto.at(i) << std::endl;
            if (i + 3 < texto.size())
            {
                i = i + 3;
            }
            else
            {
                std::cout << "Superado tamaño del texto" << std::endl;
                i = texto.size();
            }

            break;
        default:
            std::cout << texto.at(i) << std::endl;
        }
    }

    return 0;
}