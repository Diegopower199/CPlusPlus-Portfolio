#include <iostream>
#include "printjob.h"
#include "printer.h"

using namespace std;

int main()
{
    PrintJob libro1{1619285669, 521, "Cien Años de Soledad"};
    PrintJob libro2{1619285712, 245, "La Metamorfosis"};
    PrintJob libro3{1619286789, 35, "Esperando a Godot"};
    PrintJob libro4{1619286870, 730, "El Señor de los Anillos"};
    PrintJob libro5{1619287123, 2, "Practica IV - Estructuras de datos"};

    Printer libros{2, 999};

    std::vector<PrintJob> allJobs = {};
    std::vector<PrintJob> impresora = {};

    allJobs.push_back(libro1);
    allJobs.push_back(libro2);
    allJobs.push_back(libro3);
    allJobs.push_back(libro4);
    allJobs.push_back(libro5);

    allJobs = libros.priorityQueueBubble_sort(allJobs);

    bool almacenamientoImpresora = false;

    almacenamientoImpresora = libros.push(allJobs.at(0), almacenamientoImpresora);

    if (almacenamientoImpresora == true)
    {
        impresora.push_back(allJobs.at(0));
    }
    almacenamientoImpresora = libros.push(allJobs.at(1), almacenamientoImpresora);
    if (almacenamientoImpresora == true)
    {
        impresora.push_back(allJobs.at(1));
    }
    almacenamientoImpresora = libros.push(allJobs.at(2), almacenamientoImpresora);
    if (almacenamientoImpresora == true)
    {
        impresora.push_back(allJobs.at(2));
    }

    for (auto elem : impresora)
    {
        std::cout << elem << "\n";
    }

    std::cout << impresora.size() << "\n";
}
