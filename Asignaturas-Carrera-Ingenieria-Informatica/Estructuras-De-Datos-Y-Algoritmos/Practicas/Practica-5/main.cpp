#include <iostream>
#include <fstream>
#include <cstdlib>
#include "graph.h"
#include <array>
#include <vector>

using namespace std;

int main()
{
    string cities{"C:/Users/Diego/OneDrive/Documentos/Practica5EDA/Ciudades.txt"};
    string distances{"C:/Users/Diego/OneDrive/Escritorio/PRACTICA 5 EDA/Distancias.txt"};

    Graph<23> grafo;

    ifstream infile("C:/Users/Diego/OneDrive/Documentos/Practica5EDA/Ciudades.txt");
    string line;
    std::vector<std::string> t_Ciudades = {};
    while (getline(infile, line))
    {
        int separador = line.find(" ");
        string id = line.substr(0, separador);
        int numero = stoi(id);
        string name = line.substr(separador + 1);
        t_Ciudades.push_back(line);

        grafo.add_node(numero, name);
    }

    ifstream infile1("C:/Users/Diego/OneDrive/Escritorio/PRACTICA 5 EDA/Distancias.txt");

    while (getline(infile1, line))
    {

        int separador = line.find(" ");
        string id1 = line.substr(0, separador);
        int origen = stoi(id1);

        int separador2 = line.find(" ", separador + 1);
        string idl2 = line.substr(separador + 1, separador2);
        int destino = stoi(idl2);

        string idl3 = line.substr(separador2 + 1);
        int distance = stoi(idl3);
        grafo.add_edge(origen, destino, distance);
    }

    std::cout << grafo;
    std::cout << "\n";
    std::cout << grafo.are_connected("Barcelona", "Valencia");
    std::cout << "\n";

    std::cout << grafo.num_components();
}
