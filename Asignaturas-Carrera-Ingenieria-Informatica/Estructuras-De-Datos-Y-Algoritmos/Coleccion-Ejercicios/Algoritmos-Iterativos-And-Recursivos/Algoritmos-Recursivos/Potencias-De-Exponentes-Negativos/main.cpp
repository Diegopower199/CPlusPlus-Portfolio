#include <iostream>
#include <math.h>

using namespace std;

double pow(int x, int n){
    if(n == 0){
        return 1;
    }else if (n < 0){
        return (pow(x, n + 1)) * 1/x;
    }
}

int main(){
    cout<<"2^-2 = " << pow(2, -2) <<"\n"; // 0,25
    cout<<"2^-3 = " << pow(2, -3) <<"\n"; // 0,125
}
