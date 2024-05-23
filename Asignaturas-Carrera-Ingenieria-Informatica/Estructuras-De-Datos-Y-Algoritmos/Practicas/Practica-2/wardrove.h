#pragma once

#include "queue.h"

class WardrobeElement
{
public:
    std::string owner;
    std::shared_ptr<WardrobeElement> next = nullptr;

public:
    WardrobeElement(const std::string &dato_);
};

class Wardrobe
{
public:
    Wardrobe();

    int size() const;
    bool empty() const;

    void push(const std::string &dato);
    void pop();
    std::string &top() const;

protected:
    std::shared_ptr<WardrobeElement> front = nullptr;
};

void wardrobe(Queue &joy_slava, Wardrobe &men, Wardrobe &women);
