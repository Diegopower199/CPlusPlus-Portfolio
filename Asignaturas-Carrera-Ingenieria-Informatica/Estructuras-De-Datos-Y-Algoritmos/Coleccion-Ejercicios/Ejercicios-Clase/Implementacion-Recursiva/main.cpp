#include <iostream>
#include <string>

void print(std::string word)
{
    if (word.length() == 0)
    {
        return;
    }
    std::cout << word[0];
    print(word.substr(1));
}

int main()
{
    print("Recursion!");
    return 0;
}
