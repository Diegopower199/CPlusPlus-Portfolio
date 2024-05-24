#include "stack.h"
#include <iostream>

Stack::Stack()
{
}

void Stack::push(const TipoDato &dato)
{
    auto elem = std::make_shared<ElementoSimpleLista>(ElementoSimpleLista{dato});
    if (front != nullptr)
    {
        elem->next = front;
        front = elem;
        back = elem;
    }
    else
    {
        front = elem;

        back = elem;
    }
    std::cout << front << "\n";
}

void Stack::pop()
{
    if (front != nullptr)
    {
        front = front->next;
        std::cout << front;
    }
}

TipoDato &Stack::top()
{

    std::cout << front;
    return front->dato;
}

void Stack::for_each(std::function<void(TipoDato &)> action)
{
    std::shared_ptr<ElementoSimpleLista> iterator = front;
    while (iterator != nullptr)
    {
        action(iterator->dato);
        iterator = iterator->next;
    }
}

int Stack::size()
{
    std::shared_ptr<ElementoSimpleLista> iterator = front;
    int posElemento = 0;
    while (iterator != nullptr)
    {
        iterator = iterator->next;
        posElemento++;
    }
    return posElemento;
}
