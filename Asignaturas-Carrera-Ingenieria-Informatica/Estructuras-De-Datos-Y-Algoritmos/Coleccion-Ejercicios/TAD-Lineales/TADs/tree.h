#ifndef TREE_H
#define TREE_H

#include "elementoarbol.h"
#include <functional>
#include "cola.h"

using namespace std;

class Tree{
protected:
    shared_ptr<ElementoArbol> root = nullptr;

public:
    Tree(); // Creates empty tree
    Tree(const TipoDato& dato); // Creates tree with root node

    // Member functions (properties of the tree structure)
    int height() const;
    int size() const; // Returns number of nodes

    // A way to add subtrees to an existing tree
    void add_subtree(const Tree& substree);

    // Different traverse strategies
    void dfs_preorder(function<void (TipoDato&)> action) const;
    void dfs_postorder(function<void (TipoDato&)> action) const;
    void dfs_inorder(function<void (TipoDato&)> action) const;

    // Breadth-first search
    void bfs(function<void (TipoDato&)> action) const;
};

#endif // TREE_H
