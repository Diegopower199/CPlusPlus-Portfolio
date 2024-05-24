#include <iostream>
#include <memory>

using namespace std;

class Foo
{
public:
    Foo();
    Foo(int a, int b, int c);
    Foo(int _a, int _b);
    int getA() const { return a; }

private:
    int a;
    int b;
    int c;
};

Foo::Foo()
{
    cout << "Soy el constructor\n";
}

Foo::Foo(int a, int b, int c) : a{a}, b{b}, c{c}
{
    cout << "constructor";
}

Foo::Foo(int _a, int _b)
{
    a = _a;
    b = _b;
    cout << "sobrecarga";
}

int main()
{
    cout << 1;
    Foo a;
    cout << 2;
    shared_ptr<Foo> p_a;
    cout << 3;
    p_a = make_shared<Foo>();
    cout << 4;
}
