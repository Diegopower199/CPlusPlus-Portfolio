#ifndef DATA_H
#define DATA_H

#include <vector>
#include "Pair.h"

template <class K, class V>
class Data
{
    template <class fK, class fV>
    friend std::ostream &operator<<(std::ostream &os, Data<fK, fV> const &d);

public:
    Data();
    void insert(Pair<K, V> *p);
    V value(K const &key);
    std::vector<K> getKeys();

private:
    std::vector<Pair<K, V> *> data;
};

template <class K, class V>
Data<K, V>::Data() {}

template <class K, class V>
void Data<K, V>::insert(Pair<K, V> *p)
{
    try
    {
        value(p->value());
        throw std::string{"Key already in data"};
    }
    catch (std::string e)
    {
        data.push_back(p);
    }
}

template <class K, class V>
V Data<K, V>::value(const K &key)
{
    for (auto elem : data)
    {
        if (elem->key() == key)
        {
            return elem->value();
        }
    }
    throw std::string{"Key not present"};
}

template <class K, class V>
std::vector<K> Data<K, V>::getKeys()
{
    std::vector<K> result;
    for (auto elem : data)
    {
        result.push_back(elem->key());
    }
    return result;
}

template <class K, class V>
std::ostream &operator<<(std::ostream &os, Data<K, V> const &d)
{
    for (auto pair : d.data)
    {
        os << *pair << "\n";
    }
    return os;
}

#endif
