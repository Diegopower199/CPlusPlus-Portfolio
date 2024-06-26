#include <iostream>
#include <vector>

int accumulate(int sum, std::vector<int> values)
{
    if (values.empty())
    {
        return sum;
    }
    else
    {
        return accumulate(sum + values[0], std::vector<int>(values.begin() + 1, values.end()));
    }
}

int main()
{
    std::vector<int> values{1, 3, 5, 8, 13};
    int sum = accumulate(0, values);
    std::cout << "sum: " << sum << std::endl;
    return 0;
}
