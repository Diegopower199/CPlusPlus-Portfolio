#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#pragma once

#include <memory>
#include "binarytree.h"
#include <functional>

class ElementListaSimple {
    public:
        // Members
        TipoDato dato;
        std::shared_ptr<ElementListaSimple> next = nullptr;
    public:
        // Constructor
        ElementListaSimple(const TipoDato& dato_) : dato{dato_} {};
};



struct ElementoLista {
     TipoDato dato;
     std::shared_ptr<ElementoLista> next = nullptr;
};


// Una lista simple enlazada
class LinkedList {
     public:
         LinkedList() {};
         void push_back(const TipoDato& dato) {
             auto elem = std::make_shared<ElementoLista>(ElementoLista{dato});
             if (_front == nullptr) {
                 _front = elem;
             }
             else {
                 auto iterator = _front;
                 while (iterator->next != nullptr) {
                     iterator = iterator->next;
                 }
                 iterator->next = elem;
             }
         };

         void for_each(std::function<void (const TipoDato& dato)> action) {
             auto iterator = _front;
             while (iterator != nullptr) {
                 action(iterator->dato);
                 iterator = iterator->next;
             }
         }

     protected:
         std::shared_ptr<ElementoLista> _front = nullptr;
};


// Una pila
class Stack {
    public:
        Stack();

        int size() const;
        bool empty() const;

        void push(const TipoDato& dato);
        void pop() const;
        TipoDato& top() const;
    protected:
        std::shared_ptr<ElementListaSimple> front = nullptr;
};



struct ElementoQueue {
   ElementoArbol dato;
   std::shared_ptr<ElementoQueue> next = nullptr;
};


// Una cola
class Queue {
     public:
         Queue() {};
         bool empty() const { return _front == nullptr;}
         ElementoArbol& front() const { return _front->dato; };
         void push(const ElementoArbol& dato) {
             auto elem = std::make_shared<ElementoQueue>(ElementoQueue{dato});
             if (empty()) {
                 _front = _back = elem;
             }
             else {
                 _back->next = elem;
                 _back = _back->next;
             }
         };
         void pop() {
             _front = _front->next;
         };

     protected:
         std::shared_ptr<ElementoQueue> _front = nullptr;
         std::shared_ptr<ElementoQueue> _back = nullptr;
};

#endif // COLLECTIONS_H
