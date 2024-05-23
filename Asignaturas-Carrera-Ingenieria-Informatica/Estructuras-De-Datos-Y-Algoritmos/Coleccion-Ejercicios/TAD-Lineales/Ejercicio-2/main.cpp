#include <iostream>
#include "stack.h"
#include "check_braces.h"

using namespace std;

int main()
{
    string braces{"([([((()))])])"};

    cout << check_braces(braces) << endl;
}
