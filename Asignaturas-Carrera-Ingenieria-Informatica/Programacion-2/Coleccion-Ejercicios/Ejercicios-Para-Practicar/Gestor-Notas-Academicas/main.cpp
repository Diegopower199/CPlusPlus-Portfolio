#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int menu()
{
    std::cout << "Para introducir datos del alumno pulse 1, si quiere parar de introducir datos para obtener los resultados pulse 2: \n";
    char tecla = ' ';
    std::cin >> tecla;
    return tecla;
}

int main()
{
    vector<string> nombresCompletos;
    vector<string> dnis;
    vector<string> correos;
    vector<int> notasParciales;
    vector<int> notasPracticas;
    vector<int> notasParticipacion;
    vector<int> notasTrabajos;
    vector<int> notasExamenF;
    vector<int> notasFinales;

    char tecla = menu();
    std::cin.ignore();

    while (tecla == '1')
    {
        string nombreCompleto, dni, correo;
        int notaParcial, notaPracticas, notaParticipacion, notaTrabajo, notaExamenF, notaFinal;

        std::cout << "\nIntroduce el Nombre y Apellidos: \n";
        std::getline(std::cin, nombreCompleto);
        nombresCompletos.push_back(nombreCompleto);

        std::cout << "Introduce el DNI: \n";
        std::getline(std::cin, dni);
        dnis.push_back(dni);

        std::cout << "Introduce el correo electrónico: \n";
        std::getline(std::cin, correo);
        correos.push_back(correo);

        std::cout << "Introduce la Nota parcial: \n";
        std::cin >> notaParcial;
        notasParciales.push_back(notaParcial);

        std::cout << "Introduce la nota de las prácticas: \n";
        std::cin >> notaPracticas;
        notasPracticas.push_back(notaPracticas);

        std::cout << "Introduce la nota de participación: \n";
        std::cin >> notaParticipacion;
        notasParticipacion.push_back(notaParticipacion);

        std::cout << "Introduce la nota del trabajo: \n";
        std::cin >> notaTrabajo;
        notasTrabajos.push_back(notaTrabajo);

        std::cout << "Introduce la nota del examen final: \n";
        std::cin >> notaExamenF;
        notasExamenF.push_back(notaExamenF);

        std::cout << "Introduce la nota final de la asignatura: \n";
        std::cin >> notaFinal;
        notasFinales.push_back(notaFinal);

        std::cin.ignore();
        std::cout << "No hay más datos de este alumno a introducir. \n\n";
        tecla = menu();
    }

    if (tecla == '2')
    {
        int contador = 0;
        int maximo = 0;
        int minimo = 10;

        for (auto elem : notasFinales)
        {
            if (elem < 5)
            {
                contador++;
            }
            if (elem > maximo)
            {
                maximo = elem;
            }
            if (elem < minimo)
            {
                minimo = elem;
            }
        }

        auto calcularMediaYDesviacion = [](const vector<int> &notas, float &media, float &desviacionTipica)
        {
            float suma = 0;
            for (auto elem : notas)
            {
                suma += elem;
            }
            media = suma / notas.size();

            float sumaDesv = 0;
            for (auto elem : notas)
            {
                sumaDesv += pow(elem - media, 2);
            }
            desviacionTipica = sqrt(sumaDesv / notas.size());
        };

        float notaMediaParciales, desviacionTipicaNotasParciales;
        calcularMediaYDesviacion(notasParciales, notaMediaParciales, desviacionTipicaNotasParciales);

        float notaMediaPracticas, desviacionTipicaNotasPracticas;
        calcularMediaYDesviacion(notasPracticas, notaMediaPracticas, desviacionTipicaNotasPracticas);

        float notaMediaParticipacion, desviacionTipicaNotasParticipacion;
        calcularMediaYDesviacion(notasParticipacion, notaMediaParticipacion, desviacionTipicaNotasParticipacion);

        float notaMediaTrabajo, desviacionTipicaNotasTrabajos;
        calcularMediaYDesviacion(notasTrabajos, notaMediaTrabajo, desviacionTipicaNotasTrabajos);

        float notaMediaExamenF, desviacionTipicaNotasExamenF;
        calcularMediaYDesviacion(notasExamenF, notaMediaExamenF, desviacionTipicaNotasExamenF);

        float notaMediaFinal, desviacionTipicaNotasFinales;
        calcularMediaYDesviacion(notasFinales, notaMediaFinal, desviacionTipicaNotasFinales);

        auto calcularMediana = [](vector<int> &notas)
        {
            sort(notas.begin(), notas.end());
            if (notas.size() % 2 == 0)
            {
                return (notas[notas.size() / 2 - 1] + notas[notas.size() / 2]) / 2.0;
            }
            else
            {
                return static_cast<float>(notas[notas.size() / 2]);
            }
        };

        float medianaParciales = calcularMediana(notasParciales);
        float medianaPracticas = calcularMediana(notasPracticas);
        float medianaParticipacion = calcularMediana(notasParticipacion);
        float medianaTrabajos = calcularMediana(notasTrabajos);
        float medianaExamenF = calcularMediana(notasExamenF);
        float medianaFinales = calcularMediana(notasFinales);

        std::cout << "\n\nFIN DEL PROGRAMA\n\n";

        std::cout << "La media de las notas parciales es: " << notaMediaParciales << "\n";
        std::cout << "La mediana de las notas parciales es: " << medianaParciales << "\n";
        std::cout << "La desviacion tipica de las notas de los parciales es: " << desviacionTipicaNotasParciales << "\n";

        std::cout << "La media de las notas de las practicas es: " << notaMediaPracticas << "\n";
        std::cout << "La mediana de las notas de las practicas es: " << medianaPracticas << "\n";
        std::cout << "La desviacion tipica de las notas de las practicas es: " << desviacionTipicaNotasPracticas << "\n";

        std::cout << "La media de las notas por participación es: " << notaMediaParticipacion << "\n";
        std::cout << "La mediana de las notas por participación es: " << medianaParticipacion << "\n";
        std::cout << "La desviacion tipica de las notas por participación es: " << desviacionTipicaNotasParticipacion << "\n";

        std::cout << "La media de las notas de los trabajos es: " << notaMediaTrabajo << "\n";
        std::cout << "La mediana de las notas de los trabajos es: " << medianaTrabajos << "\n";
        std::cout << "La desviacion tipica de las notas de los trabajos es: " << desviacionTipicaNotasTrabajos << "\n";

        std::cout << "La media de las notas del examen final es: " << notaMediaExamenF << "\n";
        std::cout << "La mediana de las notas del examen final es: " << medianaExamenF << "\n";
        std::cout << "La desviacion tipica de los examenes finales es: " << desviacionTipicaNotasExamenF << "\n";

        std::cout << "La media de las notas finales es: " << notaMediaFinal << "\n";
        std::cout << "La mediana de las notas finales es: " << medianaFinales << "\n";
        std::cout << "La desviacion tipica de las notas finales es: " << desviacionTipicaNotasFinales << "\n\n";

        for (size_t i = 0; i < nombresCompletos.size(); i++)
        {
            std::cout << "La nota final del alumno " << nombresCompletos[i] << " es de: " << notasFinales[i] << "\n";
        }
        std::cout << "\n";

        std::cout << "Han suspendido " << contador << " alumnos \n";
        std::cout << "Han aprobado " << nombresCompletos.size() - contador << " alumnos \n\n";

        std::cout << "La mayor nota final es: " << maximo << "\n";
        std::cout << "La menor nota final es: " << minimo << "\n\n";

        ofstream file;
        file.open("notas.txt");
        for (size_t i = 0; i < nombresCompletos.size(); i++)
        {
            file << nombresCompletos[i] << " ; " << dnis[i] << " ; " << correos[i] << " ; " << notasParciales[i] << " ; " << notasPracticas[i] << " ; " << notasParticipacion[i] << " ; " << notasTrabajos[i] << " ; " << notasExamenF[i] << " ; " << notasFinales[i] << ";\n";
        }
        file.close();
    }

    return 0;
}
