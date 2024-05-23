#ifndef DEFENSA_H
#define DEFENSA_H

#include "jugador.h"

class Defensa : public Jugador
{
public:
    Defensa();
    void chutar() const;
};

#endif
