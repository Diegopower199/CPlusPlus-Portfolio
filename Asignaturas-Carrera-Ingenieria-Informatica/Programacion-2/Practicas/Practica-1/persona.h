#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona
{
private:
    int birth;
    string name;
    string dni;
    string tel;

public:
    Persona();
    int getBirth() const;
    void setBirth(int value);

    string getName() const;
    void setName(const string &value);

    string getDni() const;
    void setDni(const string &value);

    string getTel() const;
    void setTel(const string &value);

    void print() const;
    int age(int a) const;
    bool isAdult(int a) const;
};

#endif
