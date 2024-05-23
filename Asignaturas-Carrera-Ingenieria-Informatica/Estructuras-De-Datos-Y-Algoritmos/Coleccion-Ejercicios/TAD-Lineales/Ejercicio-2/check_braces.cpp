#include "check_braces.h"
#include "stack.h"

bool check_braces(const std::string &braces)
{
    Stack chequeador;

    for (auto token : braces)
    {
        if (token == '(' || token == '[')
        {
            chequeador.push(TipoDato{token});
        }
        else if (token == ')' || token == ']')
        {
            auto last = chequeador.top();
            chequeador.pop();
            if ((token == ')' && last.get_token() != '(') || (token == ']' && last.get_token() != '['))
            {
                return false;
            }
        }
    }

    if (chequeador.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
