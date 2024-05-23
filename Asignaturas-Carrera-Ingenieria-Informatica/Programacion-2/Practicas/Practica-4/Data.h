#ifndef DATA_H
#define DATA_H

#include <vector>
#include "Pair.h"
#include <string>

using namespace std;

template <typename K, typename V>
class Data
{
public:
    Data(){};
    void push(Pair<K, V> const &p)
    {
        data.push_back(p);
    }

    Pair<K, V> at(int i) const
    {
        if (i < 0 || i >= data.size())
            throw string{"Out of bounds"};
        return data.at(i);
    }

    vector<Pair<K, V>> getData() const
    {
        return data;
    }

private:
    vector<Pair<K, V>> data;
};

#endif
