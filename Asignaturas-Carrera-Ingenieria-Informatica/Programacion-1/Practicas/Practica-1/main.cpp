#include <iostream>
#include <vector>
#include <array>

int main()
{

    // Apartado 1

    std::string texto{""};
    std::cout << "Introduce un texto: \n";
    getline(std::cin, texto);

    // Apartado 2
    std::vector<int> posA;
    std::vector<int> posE;
    std::vector<int> posI;
    std::vector<int> posO;
    std::vector<int> posU;

    int pos{0};
    for (auto elem : texto)
    {
        if (elem == 'a')
            posA.push_back(pos);
        else if (elem == 'e')
            posE.push_back(pos);
        else if (elem == 'i')
            posI.push_back(pos);
        else if (elem == 'o')
            posO.push_back(pos);
        else if (elem == 'u')
            posU.push_back(pos);

        pos++;
    }

    std::cout << "La vocal a se encuentra en las posiciones: ";
    for (auto elem : posA)
    {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    std::cout << "La vocal e se encuentra en las posiciones: ";
    for (auto elem : posE)
    {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    std::cout << "La vocal i se encuentra en las posiciones: ";
    for (auto elem : posI)
    {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    std::cout << "La vocal o se encuentra en las posiciones: ";
    for (auto elem : posO)
    {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    std::cout << "La vocal u se encuentra en las posiciones: ";
    for (auto elem : posU)
    {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // Apartado 3
    std::array<unsigned long, 5> repeticiones = {posA.size(), posE.size(), posI.size(), posO.size(), posU.size()};
    std::array<char, 5> vocales{'a', 'e', 'i', 'o', 'u'};
    int max{0};
    int vocal{0};

    pos = 0;
    for (auto elem : repeticiones)
    {
        if (elem > max)
        {
            vocal = pos;
            max = elem;
        }
        pos++;
    }

    std::cout << "La vocal que más veces aparece es la " << vocales.at(vocal) << ". Aparece " << repeticiones.at(vocal) << " veces.\n";

    // Apartado 4
    std::string texto_sin_vocales{""};
    for (auto elem : texto)
    {
        if (elem != 'a' && elem != 'e' && elem != 'i' && elem != 'o' && elem != 'u')
        {
            texto_sin_vocales.push_back(elem);
        }
    }

    std::cout << "El texto sin vocales es: " << texto_sin_vocales << "\n";

    // Apartado 5
    std::string texto_en_mins{""};
    for (auto elem : texto)
    {
        texto_en_mins.push_back(tolower(elem));
    }

    std::cout << "El texto en minúsuculas es: " << texto_en_mins << "\n";

    return 0;
}