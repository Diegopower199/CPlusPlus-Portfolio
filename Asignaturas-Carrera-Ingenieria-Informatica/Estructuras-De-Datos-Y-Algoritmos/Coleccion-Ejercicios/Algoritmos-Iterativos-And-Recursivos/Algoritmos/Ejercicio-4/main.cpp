#include <iostream>
#include <string>
using namespace std;

constexpr int factor_temporal = 3;

string message_dream(string word, int level)
{
    if(level == 0)
    {
        return word;
    }else{
        string ret;
        for(auto elem:word)
        {
            for(auto i = 0; i<factor_temporal; i++)
            {
                ret.push_back(elem);
            }
        }
        return message_dream(ret, level -1);
    }
}

int main()
{
    cout<<"Realidad: "<<message_dream("hi!", 0) << "\n";
    cout<<"Nivel 1 : "<<message_dream("hi!", 1) << "\n";
    cout<<"Nivel 2 : "<<message_dream("hi!", 2) << "\n";
}
