#include <iostream>
#include <memory>
#include <vector>
#include <functional>

using namespace std;

struct Persona
{
    string nombre;
    int edad;
    string telefono;
};

shared_ptr<vector<shared_ptr<Persona>>> filter(vector<shared_ptr<Persona>> const &p, function<bool(Persona)> f)
{
    shared_ptr<vector<shared_ptr<Persona>>> p_result;
    for (auto p_elem : p)
    {
        if (f(*p_elem))
            p_result->push_back(p_elem);
    }
    return p_result;
}

int main()
{
    vector<shared_ptr<Persona>> vv;

    auto p1 = make_shared<Persona>(Persona{"Maria", 28, "11111"});
    auto p2 = make_shared<Persona>(Persona{"Luis", 8, "11111"});
    auto p3 = make_shared<Persona>(Persona{"Lucia", 19, "11111"});
    auto p4 = make_shared<Persona>(Persona{"Josemi", 12, "11111"});

    vv.push_back(p1);
    vv.push_back(p2);
    vv.push_back(p3);
    vv.push_back(p4);

    auto yy = filter(vv, [](Persona p)
                     { return p.edad > 18; });

    for (auto p : *yy)
    {
        cout << p->nombre << "\n";
    }

    p1->telefono = "3333333";

    for (auto p : *yy)
    {
        cout << p->telefono << "\n";
    }
}
