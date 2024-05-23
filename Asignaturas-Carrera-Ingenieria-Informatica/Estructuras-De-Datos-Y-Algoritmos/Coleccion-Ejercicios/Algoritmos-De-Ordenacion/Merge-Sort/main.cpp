#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> merge(const std::vector<int> &lhs, const std::vector<int> &rhs)
{
    std::vector<int> ret;
    auto left_iterator = 0;
    auto right_iterator = 0;

    while (left_iterator != lhs.size() && right_iterator != rhs.size())
    {
        if (lhs[left_iterator] < rhs[right_iterator])
        {
            ret.push_back(lhs[left_iterator]);
            left_iterator++;
        }
        else
        {
            ret.push_back(rhs[right_iterator]);
            right_iterator++;
        }
    }
    for (int i = left_iterator; i < lhs.size(); i++)
    {
        ret.push_back(lhs[i]);
    }
    for (int i = right_iterator; i < rhs.size(); i++)
    {
        ret.push_back(rhs[i]);
    }
    return ret;
}

std::vector<int> merge_sort(const std::vector<int> &elements)
{
    if (elements.size() <= 1)
    {
        return elements;
    }
    else
    {
        auto middle = elements.size() / 2;
        std::vector<int> left{elements.begin(), elements.begin() + middle};
        std::vector<int> right{elements.begin() + middle, elements.end()};

        left = merge_sort(left);
        right = merge_sort(right);

        return merge(left, right);
    }
}

int main()
{
    std::vector<int> elements = {5, 3, 8, 4, 2};
    std::vector<int> sorted_elements = merge_sort(elements);
    for (int element : sorted_elements)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    return 0;
}
