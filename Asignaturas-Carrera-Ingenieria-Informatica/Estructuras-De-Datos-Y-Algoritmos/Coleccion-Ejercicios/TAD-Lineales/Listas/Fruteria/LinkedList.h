#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <functional>
#include "ElementoListaDoble.h"

template <typename T>
class LinkedList
{
public:
    LinkedList(){};
    void push_back(const T &fru)
    {
        if (_front == nullptr)
        {
            _front = std::make_shared<ElementoListaDoble<T>>(ElementoListaDoble<T>(fru));
        }
        else
        {
            auto it = _front;
            while (it->next != nullptr)
            {
                it = it->next;
            }
            auto elem = std::make_shared<ElementoListaDoble<T>>(ElementoListaDoble<T>(fru));
            it->next = elem;
            elem->prev = it;
        }
    }
    void for_each(std::function<void(T &)> &action)
    {
        auto it = _front;
        while (it != nullptr)
        {

            action(it->dato);
            it = it->next;
        }
    }

private:
    std::shared_ptr<ElementoListaDoble<T>> _front = nullptr;
};

#endif
