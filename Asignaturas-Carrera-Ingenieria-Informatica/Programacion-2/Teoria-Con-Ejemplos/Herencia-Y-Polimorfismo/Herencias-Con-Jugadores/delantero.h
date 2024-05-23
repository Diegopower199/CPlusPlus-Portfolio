#ifndef DELANTERO_H
#define DELANTERO_H

#include "jugador.h"

class Delantero : public Jugador
{
public:
    Delantero();
    void chutar() const;
};

#endif
