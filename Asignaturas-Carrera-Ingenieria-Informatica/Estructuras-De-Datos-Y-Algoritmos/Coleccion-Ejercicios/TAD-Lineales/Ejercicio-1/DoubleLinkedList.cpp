#include "DoubleLinkedList.h"

using namespace std;

DoubleLinkedList::DoubleLinkedList() : front{nullptr}, back{nullptr}
{
}

void DoubleLinkedList::for_each(std::function<void(TipoDato &)> action) const
{
    shared_ptr<ElementoListaDoble> iterator = front;
    while (iterator != nullptr)
    {
        action(iterator->datos);
        iterator = iterator->next;
    }
}

void DoubleLinkedList::for_each_reverse(std::function<void(TipoDato &)> action) const
{
    shared_ptr<ElementoListaDoble> iterator = back;
    while (iterator != nullptr)
    {
        action(iterator->datos);
        iterator = iterator->prev;
    }
}

int DoubleLinkedList::size() const
{
    shared_ptr<ElementoListaDoble> iterator = front;
    int idx = 0;
    while (iterator != nullptr)
    {
        iterator = iterator->next;
        idx++;
    }
    return idx;
}

bool DoubleLinkedList::empty() const
{
    return (front == nullptr && back == nullptr);
}

void DoubleLinkedList::push_back(const TipoDato &dato)
{
    shared_ptr<ElementoListaDoble> elem = make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
    if (front == nullptr)
    {
        front = back = elem;
    }
    else
    {
        back->next = elem;
        elem->prev = back;
        back = elem;
    }
}

void DoubleLinkedList::push_front(const TipoDato &dato)
{
    shared_ptr<ElementoListaDoble> elem = make_shared<ElementoListaDoble>(ElementoListaDoble{dato});
    if (front == nullptr)
    {
        front = back = elem;
    }
    else
    {
        front->prev = elem;
        elem->next = front;
        front = elem;
    }
}
