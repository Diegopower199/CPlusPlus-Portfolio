#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int time_dream(int hours, int level)
{
    return hours*pow(2, level);
}

int main()
{
    int hours = 1;
    cout<<"Realidad: "<< time_dream(hours, 0) << "horas" <<"\n";
    cout<<"Nivel 1 : "<< time_dream(hours, 1) << "horas" <<"\n";
    cout<<"Nivel 2 : "<< time_dream(hours, 2) << "horas" <<"\n";
    cout<<"Nivel 3 : "<< time_dream(hours, 3) << "horas" <<"\n";
}
