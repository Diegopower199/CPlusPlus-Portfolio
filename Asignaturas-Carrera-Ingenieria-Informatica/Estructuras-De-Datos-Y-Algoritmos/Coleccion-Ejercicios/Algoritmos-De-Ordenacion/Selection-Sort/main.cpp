#include <iostream>
#include <vector>
#include <algorithm>

void selection_sort(std::vector<int> &elements)
{
    for (int i = 0; i < elements.size(); i++)
    {
        int indexMin = i;
        for (int k = i + 1; k < elements.size(); k++)
        {
            if (elements[k] < elements[indexMin])
            {
                indexMin = k;
            }
        }
        std::swap(elements[i], elements[indexMin]);
    }
}

int main()
{
    std::vector<int> elements = {5, 3, 8, 4, 2};
    selection_sort(elements);
    for (int element : elements)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    return 0;
}
