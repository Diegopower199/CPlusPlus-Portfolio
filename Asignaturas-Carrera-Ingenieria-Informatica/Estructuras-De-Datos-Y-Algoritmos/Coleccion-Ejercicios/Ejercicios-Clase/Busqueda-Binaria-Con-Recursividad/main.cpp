#include <iostream>
#include <vector>

std::vector<int> slice(std::vector<int> values, int begin, int end)
{
    if (begin >= end)
    {
        return std::vector<int>{};
    }
    return std::vector<int>(values.begin() + begin, values.begin() + end);
}

bool binary_search(std::vector<int> values, int value_to_find)
{
    if (values.empty())
    {
        return false;
    }
    int middle = values.size() / 2;
}

int main()
{
    std::vector<int> values{1, 3, 5, 8, 13};
    bool found = binary_search(values, 8);
    if (found)
    {
        std::cout << "Element found" << std::endl;
    }
    else
    {
        std::cout << "Element not found" << std::endl;
    }
}