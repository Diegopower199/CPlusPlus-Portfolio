#include "priorityqueue.h"

PriorityQueue::PriorityQueue() {}

int PriorityQueue::size() const
{
    return _data.size();
}

bool PriorityQueue::empty() const
{
    return _data.empty();
}

const TipoDato &PriorityQueue::top() const
{
    return _data.at(0);
}

int PriorityQueue::parent(int index) const
{
    return (index - 1) / 2;
}

int PriorityQueue::left(int index) const
{
    return (index * 2 + 1);
}

int PriorityQueue::right(int index) const
{
    return (index * 2 + 2);
}

void PriorityQueue::heapify_up(int i)
{
    if (i == 0)
    {
        return;
    }

    if (_data.at(parent(i)) > _data.at(i))
    {

        std::swap(_data[i], _data[parent(i)]);

        heapify_up(parent(i));
    }
}

void PriorityQueue::push(const TipoDato &dato)
{
    _data.push_back(dato);

    int index = this->size() - 1;
    heapify_up(index);
}

void PriorityQueue::heapify_down(int i)
{
    int idx_left = left(i);
    int idx_right = right(i);

    int idx_lowest = i;
    if (idx_left < this->size() && _data.at(idx_lowest) > _data.at(idx_left))
    {
        idx_lowest = idx_left;
    }
    if (idx_right < this->size() && _data.at(idx_lowest) > _data.at(idx_right))
    {
        idx_lowest = idx_right;
    }

    if (idx_lowest != i)
    {
        std::swap(_data[i], _data[idx_lowest]);
        heapify_down(idx_lowest);
    }
}

void PriorityQueue::pop()
{
    if (this->empty())
    {
        return;
    }

    swap(_data.at(0), _data.at(_size - 1));

    heapify_down(0);
}

void PriorityQueue::create_from(const vector<TipoDato> &values)
{
    _data = values;
    _size = _data.size();

    for (int i = (_data.size() - 2) / 2; i >= 0; i--)
    {
        heapify_down(i);
    }
}
