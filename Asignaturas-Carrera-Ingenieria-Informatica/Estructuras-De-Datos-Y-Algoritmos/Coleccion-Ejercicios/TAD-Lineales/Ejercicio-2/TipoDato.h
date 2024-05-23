#ifndef TIPODATO_H
#define TIPODATO_H

#include <string>

using namespace std;

class TipoDato
{
public:
    TipoDato(char token);
    char get_token() const;

private:
    char token;
};

#endif
