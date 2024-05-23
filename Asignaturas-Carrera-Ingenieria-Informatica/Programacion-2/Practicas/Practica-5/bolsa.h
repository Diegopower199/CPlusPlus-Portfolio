#ifndef BOLSA_H
#define BOLSA_H

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

class Bolsa
{
public:
    Bolsa();
    ~Bolsa();

    Bolsa(std::vector<int> &numeros);
    int sacarBola(std::vector<int> &vectorBolas);
    bool quedanBolas(std::vector<int> &vectorBolas);

private:
    std::vector<int> bolas;
};

#endif
