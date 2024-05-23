#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int> & elements){
    for(int i = 0; i < elements.size(); i++){
        cout<<"Iteracion " << i << "\n";
        int indexMin = i;
        for(int k = i+1; k < elements.size(); k++){
            cout << elements[k] << " < " << elements[indexMin] << " ? " << (elements[k] < elements[indexMin] ? "true": "false") <<"\n";
            if(elements[k] < elements[indexMin]){
                indexMin = k;
            }
        }
        swap(elements[i], elements[indexMin]);
    }
}
int main(){
    vector<int> elements{9,8,7,6,5,4,3,2,1};
    cout<< "Vector inicial" <<"\n";
    for(auto elem: elements){
        cout<< elem << ", ";
    }
    cout<<"\n---\n";
    selection_sort(elements);
    cout<<"\nOrden final:\n";
    for(auto elem: elements){
        cout<< elem << ", ";
    }
    cout<<"\n---\n";
}
