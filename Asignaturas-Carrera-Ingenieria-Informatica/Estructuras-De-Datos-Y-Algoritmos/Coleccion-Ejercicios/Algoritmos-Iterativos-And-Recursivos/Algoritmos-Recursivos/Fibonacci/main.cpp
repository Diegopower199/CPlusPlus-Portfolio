#include <iostream>

using namespace std;

int fibonacci(int index){
    if(index == 0 || index == 1){
        return 1;
    }else{
        return fibonacci(index - 2) + fibonacci(index -1);
    }
}

int main(){
    int n_terms = 8;
    for(int i = 0; i< n_terms; i++){
        cout<< fibonacci(i) <<", ";
    }
}
