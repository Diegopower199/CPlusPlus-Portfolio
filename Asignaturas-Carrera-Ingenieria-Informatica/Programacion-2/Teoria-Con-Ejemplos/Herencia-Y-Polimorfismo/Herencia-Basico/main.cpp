#include <iostream>

// La herencia consiste en la construcción de tipos de datos (Objetos) pasando de lo más genéricoa lo más particular.
class FigGeomRegular
{
public:
  FigGeomRegular(float _long, float _lados);
  float getArea() const;
  float getPerimeter() const;

private:
  int n_lados;
  float longitud;
};

// La clase TrianguloEq 'hereda' todos los atributos y funciones de la clase FigGeomRegular
class TrianguloEq : public FigGeomRegular
{
  TrianguloEq(float _long);
  float getHeight() const;
};

int main()
{
  TrianguloEq unTriangulo{5};
  std::cout << unTriangulo.getArea() << "\n";
  std::cout << "Hello World!\n";
}
