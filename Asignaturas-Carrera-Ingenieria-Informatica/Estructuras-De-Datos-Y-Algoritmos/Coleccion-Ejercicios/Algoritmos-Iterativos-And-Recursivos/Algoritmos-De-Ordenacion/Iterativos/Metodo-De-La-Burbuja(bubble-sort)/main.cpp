#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& elements){
    for(int i = 0; i<elements.size()-1; i++){
        bool any_swap = false;
        cout<<"Iteration: "<< i << "\n";
        for(int k = 0; k<elements.size()-1; k++){
            cout<< elements[k] << " > " << elements[k+1] << " ? " << (elements[k] > elements[k+1] ? "true": "false") <<"\n";
            if(elements[k] > elements[k+1]){
                swap(elements[k], elements[k+1]);
                any_swap = true;
            }
        }
        if(!any_swap){
            break;
        }
    }
}

int main(){
    vector<int> elements{9,8,7,6,5,4,3,2,1};
    cout<<"Vector inicial: " << "\n";
    for(auto elem: elements){
        cout<< elem <<", ";
    }
    cout<<"\n---\n";
    bubble_sort(elements);
    cout<<"\nOrden final: " << "\n";
    for(auto elem: elements){
        cout<< elem <<", ";
    }
    cout<< "\n---\n";
}
