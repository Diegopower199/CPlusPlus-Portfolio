#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int> &elements, int left_index, int right_index)
{
    auto pivot = elements[left_index];
    int i = left_index, j = right_index;

    while (true)
    {
        while (elements[i] <= pivot && i <= j)
            ++i;
        while (elements[j] > pivot)
            --j;
        if (i >= j)
            break;
        std::swap(elements[i], elements[j]);
    }
    std::swap(elements[left_index], elements[j]);
    return j;
}

void quickSort(std::vector<int> &v, int inicio, int final)
{
    if (inicio >= final)
    {
        return;
    }
    else
    {
        int pivot_index = partition(v, inicio, final);
        quickSort(v, inicio, pivot_index - 1);
        quickSort(v, pivot_index + 1, final);
    }
}

int main()
{
    std::vector<int> elements = {5, 3, 8, 4, 2};
    quickSort(elements, 0, elements.size() - 1);
    for (int element : elements)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    return 0;
}
