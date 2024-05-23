#include "priorityqueue.h"

PriorityQueue::PriorityQueue() {}

int PriorityQueue::size() const {
    return _data.size();
}

bool PriorityQueue::empty() const {
    return _data.empty();
}

const TipoDato &PriorityQueue::top() const {
    return _data.at(0);
}

int PriorityQueue::parent(int index) const {
    return (index-1) / 2;
}

int PriorityQueue::left(int index) const {
    return (index*2 + 1);
}

int PriorityQueue::right(int index) const {
    return (index*2 + 2);
}

// Recursive heapify-up algorithm
void PriorityQueue::heapify_up(int i) {
    if (i == 0) { return;}

    // check if the node at index `i` and its parent violate the heap property
    if (_data.at(parent(i)) > _data.at(i)) {
        // swap the two if heap property is violated
        std::swap(_data[i], _data[parent(i)]);

        // call heapify-up on the parent
        heapify_up(parent(i));
    }
}

void PriorityQueue::push(const TipoDato &dato) {
    // Insert at the end:
    _data.push_back(dato);

    // Get element index and call heapify-up procedura
    int index = this->size() - 1;
    heapify_up(index);
}

// Recursive heapify-down algorithm.
void PriorityQueue::heapify_down(int i) {
    // get left and right child of node at index `i`
    int idx_left = left(i);
    int idx_right = right(i);

    // Identify lowest element
    int idx_lowest = i;
    if (idx_left < this->size() && _data.at(idx_lowest) > _data.at(idx_left)) {
        idx_lowest = idx_left;
    }
    if (idx_right < this->size() && _data.at(idx_lowest) > _data.at(idx_right)) {
        idx_lowest = idx_right;
    }

    // swap with a child having lowest value and
    // call heapify-down on the child
    if (idx_lowest != i)
    {
        std::swap(_data[i], _data[idx_lowest]);
        heapify_down(idx_lowest);
    }
}

void PriorityQueue::pop() {
    if (this->empty()) {return;}

    // replace the root of the heap with the last element (and remove it)
    swap(_data.at(0), _data.at(_size-1));

    // call heapify-down on the root node
    heapify_down(0);
}

void PriorityQueue::create_from(const vector<TipoDato> &values) {
    _data = values;
    _size = _data.size();

    // Regular operations to satisfy heap property
    for(int i = (_data.size()-2)/2; i >= 0; i--){
        heapify_down(i);
    }
}
