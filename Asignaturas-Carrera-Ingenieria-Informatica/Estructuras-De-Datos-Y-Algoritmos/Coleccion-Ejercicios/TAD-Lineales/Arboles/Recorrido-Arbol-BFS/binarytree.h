#ifndef BINARYTREE_H
#define BINARYTREE_H


#pragma once

#include <memory>
#include <functional>
#include "collections.h"

using TipoDato = std::string;

struct ElementoArbol {
   TipoDato dato;
   std::shared_ptr<ElementoArbol> left = nullptr;
   std::shared_ptr<ElementoArbol> right = nullptr;
};

class BinaryTree {
   protected:
     std::shared_ptr<ElementoArbol> root = nullptr;

   public:
     BinaryTree(const TipoDato& dato) {
         root = std::make_shared<ElementoArbol>(ElementoArbol{dato});
     }

     void add_left(BinaryTree& tree) { root->left = tree.root; }
     void add_right(BinaryTree& tree) { root->right = tree.root; }

     // Breadth first search (recorrido en anchura)
     void bfs(std::function<void (const TipoDato&)> action) const {
         Queue queue;
         queue.push(*root);
         while (!queue.empty()) {
             ElementoArbol elem = queue.front();
             queue.pop();
             action(elem.dato);
             if (elem.left) { queue.push(*elem.left);}
             if (elem.right) { queue.push(*elem.right);}
         }
     }
};

#endif // BINARYTREE_H
