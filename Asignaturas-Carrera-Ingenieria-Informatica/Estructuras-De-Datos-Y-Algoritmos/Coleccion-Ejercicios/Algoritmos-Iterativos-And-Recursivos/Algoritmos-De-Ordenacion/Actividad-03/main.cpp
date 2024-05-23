#include <iostream>
#include <vector>

using namespace std;

// Función que imprime los elementos del vector
void print(const vector<float> & elements){
    for(auto e: elements){
        cout<< e << " ";
    }
    cout<<"\n";
}

// Método de ordenamiento de la burbuja (bubble sort)
void bubble_sort(vector<float> & elements){
    for ( int i = 0; i < elements.size()-1; i++){
        bool any_swap = false;
        cout << "Interation: " << i << "\n";
        for ( int k = 0; k < elements.size()-1; k++){
            cout << elements[k] << " > " << elements[k+1] << " ? " << (elements[k] > elements[k+1] ? "true" : "false") <<"\n";
            if ( elements[k] > elements[k+1] ){
                swap( elements[k], elements[k+1]);
                any_swap = true;
            }
        }
        if(!any_swap){
            break;
        }
    }
}

// Método de selección (selection  sort)
void selection_sort(vector<float> & elements){
    for ( int i = 0; i < elements.size()-1; i++){
        cout << "Iteration: " << i << "\n";
        int indexMin = i;
        for ( int k = 0; k < elements.size()-1; k++){
            cout << elements[k] << " > " << elements[k+1] << " ? " << (elements[k] > elements[k+1] ? "true" : "false") <<"\n";
            if ( elements[k] < elements[indexMin]){
                indexMin = k;
            }
        }
        swap(elements[i], elements[indexMin]);
    }
}

// A function to merge two ordered lists
std::vector<float> merge(const std::vector<float>& lhs,
                       const std::vector<float>& rhs)
{
    std::vector<float> ret;
    auto left_iterator = 0.0;
    auto right_iterator = 0.0;

    // Iterate the two vectors at the same time, adding the lowest element
    while (left_iterator != lhs.size() && right_iterator != rhs.size()) {
        if (lhs[left_iterator] < rhs[right_iterator]) {
            ret.push_back(lhs[left_iterator]);
            left_iterator++;
        }
        else {
            ret.push_back(rhs[right_iterator]);
            right_iterator++;
        }
    }

    // Add remaining elements
    for (int i=left_iterator; i<lhs.size(); i++) {
        ret.push_back(lhs[i]);
    }
    for (int i=right_iterator; i<rhs.size(); i++) {
        ret.push_back(rhs[i]);
    }
    return ret;
}

// Ordenamiento por mezcla (merge sort)
vector<float> merge_sort(const vector<float> & elements){
    cout << "merge sort: ";
    print(elements);
    // Check for base/trivial case
    if ( elements.size() <= 1){
        return elements;
    }else{
        // Split the vector in two
        auto middle = elements.size()/2;
        vector<float> left{elements.begin(), elements.begin() + middle};
        vector<float> right{elements.begin() + middle, elements.end()};

        // Aply merge sort to each of them
        left = merge_sort(left);
        right = merge_sort(right);

        // Merge those two (already) ordered vectors
        return merge(left, right);
    }
}

// A function that merge two ordered lists
float partition(vector<float> & elements, int left_index, int right_index){
    auto pivot = elements[left_index];
    int i = left_index;
    int j = right_index;

    while(true){
        while ( elements[i] <= pivot && i <= j ) ++i;
        while ( elements[j] > pivot ) --j;
        if( i >= j ) break;
        swap(elements[i], elements[j]);
    }
    swap(elements[left_index], elements[j]);
    return j;
}

// Ordenamiento rápido (quick sort)
void quick_sort(vector<float> & elements, int left_index, int right_index){
    cout << "Quick sort: ";
    print(elements);
    // Checks for base/trivial case
    if ( left_index >= right_index ){
        return;
    }else{
        // Compute the pivot
        int pivot_index = partition(elements, left_index, right_index);

        // Aply quick-sort to both sides (pivot is already in place)
        quick_sort(elements, left_index, right_index-1);
        quick_sort(elements, pivot_index+1, right_index);
    }
}

int main(){
    // Aquí tenemos nuestro vector incial
    vector<float> elements{1.2,3.4,5.6};
    cout << "Vector incial " << "\n";
    print(elements);
    cout << "\n---\n";

    // Método de ordenacion de la burbuja
    bubble_sort(elements);
    cout << "\nBubble sort: \n";
    print(elements);
    cout << "\n---\n";

    // Método de selección
    selection_sort(elements);
    cout << "\nSelection sort: \n";
    print(elements);
    cout << "\n---\n";

    // Ordenamiento por mezcla
    merge_sort(elements);
    cout << "\nMerge sort: \n";
    print(elements);
    cout << "\n---\n";

    // Ordenamiento rápido
    quick_sort(elements, 0, elements.size()-1);
    cout << "\nQuick sort: \n";
    print(elements);
    cout << "\n---\n";
}
