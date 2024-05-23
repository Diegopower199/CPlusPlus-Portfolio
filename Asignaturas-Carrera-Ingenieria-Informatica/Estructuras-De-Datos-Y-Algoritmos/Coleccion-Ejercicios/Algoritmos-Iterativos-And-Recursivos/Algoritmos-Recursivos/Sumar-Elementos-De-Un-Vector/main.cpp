#include <iostream>
#include <vector>

using namespace std;

int accumulate(int sum, vector<int> values){
    if(values.empty()){
        return sum;
    }else{
        return sum + values.at(0) + accumulate(vector<int>(values.begin()+1, values.end()));
    }

}

int main(){
    vector<int> values{1,3,5,8,13};
    int sum = accumulate(0, values);
    cout<< "sum: " << sum << "\n";
}
