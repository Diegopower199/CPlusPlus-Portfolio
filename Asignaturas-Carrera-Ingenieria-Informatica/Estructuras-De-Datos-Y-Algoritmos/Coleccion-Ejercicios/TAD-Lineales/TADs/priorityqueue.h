#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "TipoDato.h"
#include <vector>

using namespace std;

class PriorityQueue
{
public:
    PriorityQueue();

    int size() const;
    bool empty() const;

    const TipoDato &top() const;

    void push(const TipoDato &dato);
    void pop();

    void create_from(const vector<TipoDato> &values);

private:
    vector<TipoDato> _data;

    void heapify_up(int i);
    void heapify_down(int i);

    int parent(int index) const;
    int left(int index) const;
    int right(int index) const;
    int _size;
};

#endif
