#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>&elements){
    for(auto elem: elements){
        cout<< elem << ", ";
    }
    cout<<"\n";
}

int partition(vector<int> & elements, int left_index, int right_index){
    auto pivot = elements[left_index];
    int i = left_index;
    int j = right_index;

    while(true){
        while( elements[i] <= pivot && i <= j) ++i;
        while( elements[j] > pivot) --j;
        if( i >= j ) break;
        swap(elements[i], elements[j]);
    }
    swap(elements[left_index], elements[j]);
    return  j;
}

int main(){
    vector<int> elements{9,8,7,6,5,4,3,2,1};

    cout << "elements: ";
    print(elements);
    auto pivot_index = partition(elements, 0, elements.size()-1);
    cout << "Pivot index: " << pivot_index << "\n";
    cout << "partititon: ";
    print(elements);
}
