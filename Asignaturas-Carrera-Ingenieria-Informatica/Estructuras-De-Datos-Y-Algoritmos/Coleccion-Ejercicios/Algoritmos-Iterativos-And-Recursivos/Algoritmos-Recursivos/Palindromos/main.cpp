#include <iostream>
#include <vector>

using namespace std;

string remove_blanks(string word){
   string word_2;
   for(char elem: word){
       if(elem != ' '){
           word_2.push_back(elem);
       }
   }
   return word_2;
}

bool palindrome(string word){
    char primera = word.front(); char ultima = word.back();
    if(word.length() <=  1)
    {
        return true;
    }else{
        if(primera == ultima){
                return palindrome(word.substr(1, word.length()-2));
        }else{
            return false;
        }
    }
}

bool is_palindrome(string word){
    string word_blanks_removed = remove_blanks(word);
    return palindrome(word_blanks_removed);
}

int main(){
    vector<string> phrases{{"","A","AA", "ana", "anna", "amadaladama", "cualquiercosa", "cualquiercos", "amad a la dama", "ana lava lana", "ana no lava lana"}};
    for(auto word: phrases){
        cout<< word << " ? " << is_palindrome(word) <<"\n";
    }
}
