#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> & elements){
    for(auto elem: elements){
        cout<< elem << ", ";
    }
    cout<<"\n";
}

// A function to merge two ordered lists
int partition(vector<int> & elements, int left_index, int right_index){
    auto pivot = elements[left_index];
    int i = left_index;
    int j = right_index;

    while(true){
        while(elements[i] <= pivot && i <= j) ++i;
        while(elements[j] > pivot) --j;
        if( i >= j ) break;
        swap(elements[i], elements[j]);
    }
    swap(elements[left_index], elements[j]);
    return j;
}

// Quick-sort algorithmn
void quick_sort(vector<int>&elements, int left_index, int right_index){
    cout<<"Quick sort: ";
    print(elements);
    // Check for base/trivial case
    if(left_index >= right_index){
        return;
    }else{
        // Compute the pivot
        int pivot_index = partition(elements, left_index, right_index);

        // Aply quick-sort to both sides (pivot is alrady in place)
        quick_sort(elements, left_index, right_index-1);
        quick_sort(elements, pivot_index+1, right_index);
    }
}
int main(){
    vector<int> elements{9,8,7,6,5,4,3,2,1};
    cout<<"Vector incial" << "\n";
    print(elements);
    cout << "\n---\n";
    quick_sort(elements, 0, elements.size()-1);
    cout<<"\nOrden final:\n";
    print(elements);
    cout << "\n---\n";
}
