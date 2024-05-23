#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cout << "Introduce una cadena de texto: " << std::endl;
    std::string textoUsuario = "";
    std::getline(std::cin, textoUsuario);
    std::vector<std::string> palabras = {};
    std::string word = "";
    for (auto elem : textoUsuario)
    {
        if (elem != ' ')
        {
            word.push_back(elem);
        }
        else
        {
            palabras.push_back(word);
            word.clear();
        }
    }
    palabras.push_back(word);

    for (auto elem : palabras)
    {

        if (elem.front() == 'a' || elem.front() == 'e' || elem.front() == 'i' || elem.front() == 'o' || elem.front() == 'u')
        {
            if (elem.back() == 'a' || elem.back() == 'e' || elem.back() == 'i' || elem.back() == 'o' || elem.back() == 'u')
            {
                std::cout << elem << "\n";
            }
        }
    }
}
