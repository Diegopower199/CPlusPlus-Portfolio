#include <iostream>
#include <vector>

std::string remove_blanks(std::string word)
{
    return word;
}

bool is_palindrome(std::string word)
{
    return false;
}

int main()
{
    std::vector<std::string> phrases{{"ana", "yo soy", "isaac no ronca asi"}};
    for (auto word : phrases)
    {
        word = remove_blanks(word);
        std::cout << word << "? " << is_palindrome(word) << std::endl;
    }
}

/*
ana --> true
soy yo --> false
isaac no ronca asi --> true
*/