#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "elementoarbolbinario.h"
#include "math.h"
#include <functional>

class BinaryTree
{
protected:
    shared_ptr<ElementoArbolBinario> root = nullptr;

public:
    BinaryTree(); // Creates empty tree
    BinaryTree(const TipoDato & dato); // Creates tree with root nodes

    // Member functions (properties of the tree structure)
    int height() const;
    int size() const; // Returns numbers of nodes

    // A way to add subtrees to an existing tree
    void add_left_subtree(const BinaryTree& substree);
    void add_right_substree(const BinaryTree& substree);

    // Depth-first search
    void dfs_preorder(function<void (TipoDato &)> action) const;
    void dfs_postorder(function<void (TipoDato &)> action) const;
    void dfs_inorder(function<void (TipoDato &)> action) const;

    // Breadth-first search
    void bfs(function<void (TipoDato &)> action) const;
};

#endif // BINARYTREE_H
