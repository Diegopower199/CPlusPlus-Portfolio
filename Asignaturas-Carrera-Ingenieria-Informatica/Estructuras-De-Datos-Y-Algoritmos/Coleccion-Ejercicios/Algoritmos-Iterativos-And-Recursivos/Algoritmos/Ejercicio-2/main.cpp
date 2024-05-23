#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int time_dream(int hours, int level)
{
    if(level == 0) return hours;
    return 2*time_dream(hours, level -1);
}

string message_dream(string word, int level)
{
    int n_times = time_dream(1, level);
    string ret;
    for(int i = 0; i<n_times; i++)
    {
        ret.push_back(word.at(0));
    }

    return ret;
}

int main()
{
    int hours = 1;
    cout<<"Realidad: "<<message_dream("A",0) <<"\n";
    cout<<"Nivel 1 : "<<message_dream("A",1) <<"\n";
    cout<<"Nivel 2 : "<<message_dream("A",2) <<"\n";
    cout<<"Nivel 3 : "<<message_dream("A",3) <<"\n";
}
