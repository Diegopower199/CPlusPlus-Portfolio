#include <iostream>
#include <memory>
#include <vector>

class Figura
{
public:
  Figura(){};
  virtual ~Figura(){};

  virtual float getArea()
  {
    std::cout << "No implementado\n";
    return 0;
  }
};

class Cuadrado : public Figura
{
public:
  Cuadrado(float a) : lado{a} {}
  float getArea()
  {
    return lado * lado;
  }

private:
  float lado;
};

class Triangulo : public Figura
{
public:
  Triangulo(float base, float altura) : base{base}, altura{altura} {}
  float getArea()
  {
    return base * altura;
  }

private:
  float base;
  float altura;
};

int main()
{
  std::vector<std::shared_ptr<Figura>> figuras;

  figuras.push_back(std::make_shared<Triangulo>(4, 5));
  figuras.push_back(std::make_shared<Cuadrado>(4));

  std::cout << figuras.at(1)->getArea();
}
