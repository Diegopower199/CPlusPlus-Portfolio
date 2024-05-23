#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include "person.h"
#include <functional>

void forEach(std::vector<Person *> p, std::function<void(Person *)> op)
{
    for (auto elem : p)
    {
        op(elem);
    }
}

Person *find(std::vector<Person *> p, std::function<bool(Person *)> op)
{
    for (auto elem : p)
    {
        if (op(elem))
            return elem;
    }

    return nullptr;
}

std::vector<Person *> filter(std::vector<Person *> p, std::function<bool(Person *)> op)
{
    std::vector<Person *> result;
    for (auto elem : p)
    {
        if (op(elem))
            result.push_back(elem);
    }

    return result;
}

#endif
