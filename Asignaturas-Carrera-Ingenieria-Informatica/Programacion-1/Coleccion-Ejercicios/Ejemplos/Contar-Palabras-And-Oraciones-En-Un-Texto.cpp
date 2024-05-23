#include <iostream>
#include <vector>

int main()
{
    // Apartado 1: Contar palabras
    std::string texto = "El texto te dice esto, por lo que. Haz algo importante";
    std::vector<std::string> palabras;
    std::string palabra = "";
    int contadorPalabras = 0;

    for (auto elem : texto)
    {
        if (elem != ' ' && elem != ',' && elem != '.')
        {
            palabra.push_back(elem);
        }
        else
        {
            if (!palabra.empty())
            {
                palabras.push_back(palabra);
                palabra = "";
                contadorPalabras++;
            }
        }
    }

    if (!palabra.empty())
    {
        palabras.push_back(palabra); // Guardar la última palabra
        contadorPalabras++;
    }

    std::cout << "El numero de palabras es: " << contadorPalabras << std::endl;

    // Apartado 2: Contar oraciones
    texto = "El texto. te dice esto, por lo que. Haz algo importante";
    std::vector<std::string> oraciones;
    std::string oracion = "";
    int contadorOraciones = 0;

    for (auto elem : texto)
    {
        oracion.push_back(elem);
        if (elem == '.' || elem == ',')
        {
            oraciones.push_back(oracion);
            contadorOraciones++;
            oracion = "";
        }
    }

    if (!oracion.empty())
    {
        oraciones.push_back(oracion); // Guardar la última oración si no termina en punto o coma
        contadorOraciones++;
    }

    std::cout << "El numero de oraciones es: " << contadorOraciones << std::endl;

    return 0;
}
