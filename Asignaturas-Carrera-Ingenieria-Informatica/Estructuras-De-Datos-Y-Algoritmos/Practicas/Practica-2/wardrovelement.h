#ifndef WARDROVELEMENT_H
#define WARDROVELEMENT_H
#include <memory>
#include <iostream>

class WardrobeElement
{
public:
    std::string owner;
    std::shared_ptr<WardrobeElement> next = nullptr;

public:
    WardrobeElement(const std::string &owner);
};
#endif
