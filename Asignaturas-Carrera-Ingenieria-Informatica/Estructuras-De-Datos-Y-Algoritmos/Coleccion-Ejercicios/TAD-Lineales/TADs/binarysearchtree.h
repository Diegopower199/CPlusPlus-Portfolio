#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <TipoDato.h>
#include "elementoarbolbinario.h"
#include <functional>

using namespace std;

class BinarySearchTree {
    protected:
        shared_ptr<ElementoArbolBinario> root = nullptr;

    public:
        BinarySearchTree();  // Creates empty tree
        BinarySearchTree(const TipoDato& dato);  // Creates tree with root node

        // Same as BinaryTree
        int height() const;
        int size() const; // Number of nodes

        // Get data
        const TipoDato& min() const;
        const TipoDato& max() const;

        // Traverse the tree
        void dfs_inorder(function<void (const TipoDato&)> action) const;

        // Operations
        bool find(const TipoDato&) const;
        void push(const TipoDato&);
        void remove(const TipoDato&);
};

#endif // BINARYSEARCHTREE_H
