#ifndef DB_H
#define DB_H

#include <memory>
#include <vector>
#include "data.h"
#include <functional>

using namespace std;

template <typename K, typename V>
class DB
{
public:
    DB(){};
    void push(Data<K, V> const &d)
    {
        db.push_back(make_shared<Data<K, V>>(d));
    }

    Data<K, V> at(int i) const
    {
        if (i < 0 || i >= db.size())
            throw string{"Out of bounds"};
        return *(db.at(i));
    }

    shared_ptr<Data<K, V>> find(function<bool(Data<K, V>)> f) const
    {
        for (auto elem : db)
        {
            if (f(*elem))
            {
                return elem;
            }
        }
        return nullptr;
    }

    DB<K, V> filter(function<bool(Data<K, V>)> f) const
    {
        DB<K, V> result;
        for (auto elem : db)
        {
            if (f(*elem))
            {
                result.push(*elem);
            }
        }
        return result;
    }

    void foreach (function<bool(Data<K, V>)> f) const
    {
        for (auto elem : db)
        {
            f(*elem);
        }
    }

private:
    vector<shared_ptr<Data<K, V>>> db;
};

#endif
