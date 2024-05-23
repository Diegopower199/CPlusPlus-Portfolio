#include <iostream>
#include "templates.h"

using namespace std;

int main()
{
    Pair<std::string, int> myPair{"tel", 34434423};
    std::cout << myPair.key() << ": " << myPair.value() << "\n";
    myPair.print();
    return 0;
}
