#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include "person.h"
#include <functional>
#include <memory>

void forEach(std::vector<std::shared_ptr<Person>> p, std::function<void(std::shared_ptr<Person>)> op)
{
    for (auto elem : p)
    {
        op(elem);
    }
}

std::shared_ptr<Person> find(std::vector<std::shared_ptr<Person>> p, std::function<bool(std::shared_ptr<Person>)> op)
{
    for (auto elem : p)
    {
        if (op(elem))
            return elem;
    }

    return nullptr;
}

std::vector<std::shared_ptr<Person>> filter(std::vector<std::shared_ptr<Person>> p, std::function<bool(std::shared_ptr<Person>)> op)
{
    std::vector<std::shared_ptr<Person>> result;
    for (auto elem : p)
    {
        if (op(elem))
            result.push_back(elem);
    }

    return result;
}

#endif
