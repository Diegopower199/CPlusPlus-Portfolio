#ifndef LISTA_H
#define LISTA_H
#include <memory>
#include <iostream>
#include <vector>
struct Pedido
{
   int cantidad;
   std::string fruta;
};

struct ElementoLista
{
   Pedido pedido;
   std::shared_ptr<ElementoLista> next = nullptr;

public:
   void setNext(const std::shared_ptr<ElementoLista> &value);
   std::shared_ptr<ElementoLista> getNext() const;
   Pedido getPedido() const;
};

class Lista
{
private:
   std::shared_ptr<ElementoLista> inicio = nullptr;

public:
   Lista() { inicio = nullptr; }

   Lista unificar(void) const;

   void print() const;

   std::shared_ptr<ElementoLista> getInicio() const;
   void push(Pedido const &);
   void setInicio(const ElementoLista &value);
};
int existing_fruit(std::shared_ptr<ElementoLista> const &fruit, std::vector<Pedido> const &v);

#endif
