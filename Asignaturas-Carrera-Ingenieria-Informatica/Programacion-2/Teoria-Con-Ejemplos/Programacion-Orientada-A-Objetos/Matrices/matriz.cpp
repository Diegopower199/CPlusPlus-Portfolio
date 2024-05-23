#include "matriz.h"
#include <iostream>
#include <math.h>

using namespace std;

Matriz::Matriz()
{
}

vector<vector<float>> Matriz::pedirMatriz(int filas, int columnas)
{
    float valor;
    vector<vector<float>> matriz;

    for (int i = 0; i < filas; i++)
    {
        vector<float> temp_vector;
        for (int j = 0; j < columnas; j++)
        {
            cout << "Introduce el elemento [" << i + 1 << ", " << j + 1 << "] : ";
            cin >> valor;
            temp_vector.push_back(valor);
        }
        matriz.push_back(temp_vector);
    }
    return matriz;
}

void Matriz::mostrarMatriz(vector<vector<float>> matriz)
{
    for (int i = 0; i < matriz.size(); i++)
    {
        for (int j = 0; j < matriz[i].size(); j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<float>> Matriz::add(vector<vector<float>> matriz1, vector<vector<float>> matriz2)
{
    vector<vector<float>> matrizSuma(matriz1.size(), vector<float>(matriz1[0].size()));

    for (int i = 0; i < matrizSuma.size(); i++)
    {
        for (int j = 0; j < matrizSuma[i].size(); j++)
        {
            matrizSuma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    return matrizSuma;
}

vector<vector<float>> Matriz::multiply(int m1_f, int m1_c, int m2_f, int m2_c, vector<vector<float>> m1, vector<vector<float>> m2)
{
    vector<vector<float>> matrizMultiplicacion(m1_f, vector<float>(m2_c));

    for (int i = 0; i < m1_f; i++)
    {
        for (int j = 0; j < m2_c; j++)
        {
            float suma = 0.0;
            for (int k = 0; k < m1_c; k++)
            {
                suma += m1[i][k] * m2[k][j];
            }
            matrizMultiplicacion[i][j] = suma;
        }
    }
    return matrizMultiplicacion;
}

float Matriz::adjunto(vector<vector<float>> m1, int m1_f1, int m1_c1)
{
    vector<vector<float>> submatriz(m1.size() - 1, vector<float>(m1[0].size() - 1));
    int x = 0;
    int y = 0;
    for (int i = 0; i < m1.size(); i++)
    {
        y = 0;
        for (int j = 0; j < m1[i].size(); j++)
        {
            if (i == m1_f1 || j == m1_c1)
            {
                continue;
            }
            else
            {
                submatriz[x][y] = m1[i][j];
                y++;
            }
        }
        if (i != m1_f1)
        {
            x++;
        }
    }
    return pow(-1, m1_f1 + m1_c1) * determinante(submatriz, m1_f1);
}

float Matriz::determinante(vector<vector<float>> m1, int m1_f1)
{
    float determinante = 0.0;
    if (m1.size() == 1)
    {
        determinante = m1[0][0];
    }
    else
    {
        for (int i = 0; i < m1.size(); i++)
        {
            determinante += m1[m1_f1][i] * adjunto(m1, m1_f1, i);
        }
    }
    return determinante;
}

vector<vector<float>> Matriz::calcularMatrizAdjunta(vector<vector<float>> matriz, int numFilas, int numColumnas)
{
    vector<vector<float>> matrizAdjunta(numFilas, vector<float>(numColumnas));
    for (int i = 0; i < numFilas; i++)
    {
        for (int j = 0; j < numColumnas; j++)
        {
            matrizAdjunta[i][j] = adjunto(matriz, i, j);
        }
    }
    return matrizAdjunta;
}

vector<vector<float>> Matriz::calcularMatrizTranspuesta(vector<vector<float>> matriz, int numFilas, int numColumnas)
{
    vector<vector<float>> matrizTranspuesta(numColumnas, vector<float>(numFilas));
    for (int i = 0; i < numFilas; i++)
    {
        for (int j = 0; j < numColumnas; j++)
        {
            matrizTranspuesta[j][i] = matriz[i][j];
        }
    }
    return matrizTranspuesta;
}

vector<vector<float>> Matriz::calcularMatrizInversa(vector<vector<float>> matriz, vector<vector<float>> matrizAdjuntaTranspuesta, int numFilas, int numColumnas)
{
    vector<vector<float>> matrizInversa(numFilas, vector<float>(numColumnas));
    for (int i = 0; i < numFilas; i++)
    {
        for (int j = 0; j < numColumnas; j++)
        {
            matrizInversa[i][j] = matrizAdjuntaTranspuesta[i][j] / determinante(matriz, 0);
        }
    }
    return matrizInversa;
}
