#include <iostream>
#include <vector>

using namespace std;

void print(const vector<float> & elements){
    for(auto e: elements){
        cout<< e << " ";
    }
    cout<<"\n";
}

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

std::vector<float> merge(const std::vector<float>& lhs,
                       const std::vector<float>& rhs)
{
    std::vector<float> ret;
    auto left_iterator = 0.0;
    auto right_iterator = 0.0;

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

    for (int i=left_iterator; i<lhs.size(); i++) {
        ret.push_back(lhs[i]);
    }
    for (int i=right_iterator; i<rhs.size(); i++) {
        ret.push_back(rhs[i]);
    }
    return ret;
}

vector<float> merge_sort(const vector<float> & elements){
    cout << "merge sort: ";
    print(elements);

    if ( elements.size() <= 1){
        return elements;
    }else{

        auto middle = elements.size()/2;
        vector<float> left{elements.begin(), elements.begin() + middle};
        vector<float> right{elements.begin() + middle, elements.end()};

        left = merge_sort(left);
        right = merge_sort(right);

        return merge(left, right);
    }
}

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

void quick_sort(vector<float> & elements, int left_index, int right_index){
    cout << "Quick sort: ";
    print(elements);
    if ( left_index >= right_index ){
        return;
    }else{
        int pivot_index = partition(elements, left_index, right_index);

        quick_sort(elements, left_index, right_index-1);
        quick_sort(elements, pivot_index+1, right_index);
    }
}

int main(){
    vector<float> elements{1.2,3.4,5.6};
    cout << "Vector incial " << "\n";
    print(elements);
    cout << "\n---\n";

    bubble_sort(elements);
    cout << "\nBubble sort: \n";
    print(elements);
    cout << "\n---\n";

    selection_sort(elements);
    cout << "\nSelection sort: \n";
    print(elements);
    cout << "\n---\n";

    merge_sort(elements);
    cout << "\nMerge sort: \n";
    print(elements);
    cout << "\n---\n";

    quick_sort(elements, 0, elements.size()-1);
    cout << "\nQuick sort: \n";
    print(elements);
    cout << "\n---\n";
}
