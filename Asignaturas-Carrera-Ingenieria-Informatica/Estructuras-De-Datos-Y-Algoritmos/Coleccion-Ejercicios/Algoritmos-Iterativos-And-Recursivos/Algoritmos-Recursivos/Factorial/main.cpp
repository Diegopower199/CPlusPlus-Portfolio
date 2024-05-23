#include <iostream>
#include <math.h>
using namespace std;

int factorial(int n)
{
 if(n == 0)
 {
     return 1;
 }
 return n*factorial(n-1);
}

int main()
{
    int n = 4;
    int result = factorial(4);
    cout<<"Factorial de "<<n <<" : "<<result<<"\n";
}
