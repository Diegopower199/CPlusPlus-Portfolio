#include "stack.h"
#include <iostream>

Stack::Stack()
{

}

// Inserts an element to the top of the stack (first element in list)
void Stack::push(const TipoDato& dato) {
    auto elem = std::make_shared<ElementoSimpleLista>(ElementoSimpleLista{dato});
    if (front != nullptr) {
        elem->next = front;
        front = elem;
        back  = elem;
    }
    else {
        front = elem;
        //back -> next = elem;
        back = elem;
    }
    std::cout << front << "\n";
}

// Removes the element at the top of the stack (removes first element)
void Stack::pop() {
    if (front != nullptr) {
            front = front -> next; //AQUI SE ELIMINA EL 555
            std::cout << front;
        }
}

// Returns the element at the top of the stack (returns first element)
TipoDato & Stack::top() {
    //front -> dato;
    std::cout << front;
    return front ->dato;
}

void Stack::for_each (std::function <void (TipoDato & )> action) {
    std::shared_ptr <ElementoSimpleLista> iterator = front;
    while (iterator !=  nullptr){
        action (iterator -> dato);
        iterator = iterator -> next;
    }
}

int Stack::size ()  {
    std::shared_ptr <ElementoSimpleLista> iterator = front;
    int posElemento = 0;
    while (iterator !=  nullptr){
        iterator = iterator -> next;
        posElemento++;
    }
    return posElemento;
}
