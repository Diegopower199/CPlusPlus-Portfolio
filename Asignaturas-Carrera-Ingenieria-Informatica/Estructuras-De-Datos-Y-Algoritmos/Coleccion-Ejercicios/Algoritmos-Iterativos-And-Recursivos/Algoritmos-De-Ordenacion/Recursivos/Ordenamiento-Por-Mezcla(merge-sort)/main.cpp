#include <iostream>
#include <vector>

void print(const std::vector<int>& elements) {
    for (auto e: elements) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

std::vector<int> merge(const std::vector<int>& lhs,
                       const std::vector<int>& rhs)
{
    std::vector<int> ret;
    auto left_iterator = 0;
    auto right_iterator = 0;

    while (left_iterator != lhs.size() && right_iterator != rhs.size()) {
        if (lhs[left_iterator] < rhs[right_iterator]) {
            ret.push_back(lhs[left_iterator]);
            left_iterator++;
        }
        else {
            ret.push_back(rhs[right_iterator]);
            right_iterator++;
        }
    }

    for (int i=left_iterator; i<lhs.size(); i++) {
        ret.push_back(lhs[i]);
    }
    for (int i=right_iterator; i<rhs.size(); i++) {
        ret.push_back(rhs[i]);
    }
    return ret;
}

std::vector<int> merge_sort(const std::vector<int>& elements) {
    std::cout << "merge_sort: ";
    print(elements);
    if (elements.size() <= 1) {
        return elements;
    }
    else {
        auto middle = elements.size()/2;
        std::vector<int> left{elements.begin(), elements.begin() + middle};
        std::vector<int> right{elements.begin() + middle, elements.end()};

        left = merge_sort(left);
        right = merge_sort(right);

        return merge(left, right);
    }
}

int main() {
  std::vector<int> elements{9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::cout << "Initial vector!" << std::endl;
  print(elements);
  std::cout << "---\n";
  elements = merge_sort(elements);
  std::cout << "\nFinal order:\n";
  print(elements);
  std::cout << "---\n";
}
