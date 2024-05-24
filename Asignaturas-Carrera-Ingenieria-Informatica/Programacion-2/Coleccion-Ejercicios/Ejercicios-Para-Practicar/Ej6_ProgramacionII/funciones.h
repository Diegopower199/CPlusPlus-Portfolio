#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include <functional>

template <class T>
T find(std::vector<T> v, std::function<bool(T)> op)
{
    for (T elem : v)
    {
        if (op(elem))
            return elem;
    }

    return nullptr;
}

#endif
