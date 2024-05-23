#ifndef AVLTREE_H
#define AVLTREE_H

#include <TipoDato.h>
#include "elementoarbolbinario.h"
#include <functional>

class AVLTree {
    protected:
        shared_ptr<ElementoArbolBinario> root = nullptr;

    public:
        AVLTree();
        AVLTree(const TipoDato& dato);

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

    private:
        void rebalance(); // Function to call after every insertion/removal
};

#endif // AVLTREE_H
