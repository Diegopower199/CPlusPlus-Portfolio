#ifndef INTEGER_H
#define INTEGER_H

#include <string>
#include <vector>

class Integer
{

    friend Integer operator*(Integer const &c1, Integer const &c2);
    friend Integer operator/(Integer const &c1, Integer const &c2);

public:
    Integer();
    Integer(int _numeroPositivo);

    int getNumeroPositivo() const;
    void setNumeroPositivo(int value);

    std::vector<int> getFactors();

    bool isPrime();

private:
    int numeroPositivo;
};

#endif
