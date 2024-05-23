#ifndef ELEMENTOQUEUE_H
#define ELEMENTOQUEUE_H


struct ElementoQueue {
   ElementoArbol dato;
   std::shared_ptr<ElementoQueue> next = nullptr;
};

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

#endif // ELEMENTOQUEUE_H
