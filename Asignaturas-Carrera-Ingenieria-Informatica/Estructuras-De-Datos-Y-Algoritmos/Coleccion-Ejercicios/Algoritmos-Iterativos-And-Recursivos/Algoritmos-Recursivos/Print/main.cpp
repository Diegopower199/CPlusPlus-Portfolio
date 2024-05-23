#include <iostream>

using namespace std;

void print(string word){
    // 'hello' = 'h' + 'ello'
    if(word.size() == 0){
        cout<<word;
    }else{
        cout<< word.at(0) << word.substr(1, word.size());
    }
}

int main(){
    print("hello");
}
