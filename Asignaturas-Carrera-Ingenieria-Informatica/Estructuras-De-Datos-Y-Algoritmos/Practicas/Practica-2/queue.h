#ifndef QUEUE_H
#define QUEUE_H
#include "elementoslistadoble.h"
using namespace std;

class Queue
{
public:
    Queue();

    int size() const;
    bool empty() const;

    Persona &front() const;
    Persona &back() const;

    void push(const Persona &dato);
    void pop();

    void sneak_in(const Persona &contact, Queue &friends);

protected:
    std::shared_ptr<ElementListaDoble> _front = nullptr;
    std::shared_ptr<ElementListaDoble> _back = nullptr;
};

#endif
