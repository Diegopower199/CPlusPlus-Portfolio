#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct ElementoLista
{
    TipoDato dato;
    std::shared_ptr<ElementoLista> next = nullptr;
};

class LinkedList
{
public:
    LinkedList(){};
    void push_back(const TipoDato &dato)
    {
        auto elem = std::make_shared<ElementoLista>(ElementoLista{dato});
        if (_front == nullptr)
        {
            _front = elem;
        }
        else
        {
            auto iterator = _front;
            while (iterator->next != nullptr)
            {
                iterator = iterator->next;
            }
            iterator->next = elem;
        }
    };

    void for_each(std::function<void(const TipoDato &)> action)
    {
        auto iterator = _front;
        while (iterator != nullptr)
        {
            action(iterator->dato);
            iterator = iterator->next;
        }
    }

protected:
    std::shared_ptr<ElementoLista> _front = nullptr;
};

#endif
