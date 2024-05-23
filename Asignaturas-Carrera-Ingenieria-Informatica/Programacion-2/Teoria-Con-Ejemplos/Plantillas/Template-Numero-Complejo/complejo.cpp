#include "complejo.h"

Complejo::Complejo(float r, float i) : r{r}, i{i}
{
}

float Complejo::getReal() const
{
    return r;
}

float Complejo::getImaginario() const
{
    return i;
}
