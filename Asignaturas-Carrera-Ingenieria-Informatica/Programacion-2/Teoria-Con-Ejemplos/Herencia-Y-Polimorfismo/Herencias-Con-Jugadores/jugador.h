#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador
{
public:
    Jugador();
    ~Jugador();
    virtual void chutar() const = 0;
};

#endif
