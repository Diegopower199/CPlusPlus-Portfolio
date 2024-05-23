#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <memory>

using namespace std;
struct TipoDato
{
    int a;
};
class ElementoQueue
{
public:
    TipoDato dato;
    ElementoQueue(TipoDato _dato);
    shared_ptr<ElementoQueue> next = nullptr;
};
class Queue
{
public:
    Queue();
    int size() const;

    bool empty() const;

    int front() const;

    int back() const;

    void push(const int &dato);

    void pop();
};

#endif
