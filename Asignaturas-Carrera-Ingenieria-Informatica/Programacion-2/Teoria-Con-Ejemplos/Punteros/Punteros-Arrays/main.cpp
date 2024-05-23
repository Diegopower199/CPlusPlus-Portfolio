#include <iostream>
#include <memory>
#include <array>

int main()
{
    std::shared_ptr<std::array<int, 3>> la;
    std::shared_ptr<int> a = std::make_shared<int>();

    for (int pos = 0; pos < 4; pos++)
    {
        std::shared_ptr<int> a = std::make_shared<int>();
        std::cin >> a;
    }
}
