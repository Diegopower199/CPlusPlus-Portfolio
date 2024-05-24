#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>

using namespace std;

class Matriz
{
public:
    Matriz();

    vector<vector<float>> pedirMatriz(int filas, int columnas);
    void mostrarMatriz(vector<vector<float>> matriz);

    vector<vector<float>> add(vector<vector<float>> matriz1, vector<vector<float>> matriz2);
    vector<vector<float>> multiply(int m1_f, int m1_c, int m2_f, int m2_c, vector<vector<float>> m1, vector<vector<float>> m2);
    float adjunto(vector<vector<float>> m1, int m1_f1, int m1_c1);
    float determinante(vector<vector<float>> m1, int m1_f1);

    vector<vector<float>> calcularMatrizAdjunta(vector<vector<float>> matriz, int numFilas, int numColumnas);
    vector<vector<float>> calcularMatrizTranspuesta(vector<vector<float>> matriz, int numFilas, int numColumnas);
    vector<vector<float>> calcularMatrizInversa(vector<vector<float>> matriz, vector<vector<float>> matrizAdjuntaTranspuesta, int numFilas, int numColumnas);

private:
    int filas;
    int columnas;
    vector<vector<float>> mat;
};

#endif
