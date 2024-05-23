#ifndef PAIR_H
#define PAIR_H

template <typename K, typename V>
class Pair
{
public:
    Pair(K key, V value) : key{key}, value{value} {}

    K getKey() const
    {
        return key;
    }

    V getValue() const
    {
        return value;
    }

private:
    K key;
    V value;
};

#endif
