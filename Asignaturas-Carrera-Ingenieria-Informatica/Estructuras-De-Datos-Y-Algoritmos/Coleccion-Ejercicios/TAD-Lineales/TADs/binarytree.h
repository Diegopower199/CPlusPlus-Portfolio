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
    BinaryTree();
    BinaryTree(const TipoDato &dato);

    int height() const;
    int size() const;

    void add_left_subtree(const BinaryTree &substree);
    void add_right_substree(const BinaryTree &substree);

    void dfs_preorder(function<void(TipoDato &)> action) const;
    void dfs_postorder(function<void(TipoDato &)> action) const;
    void dfs_inorder(function<void(TipoDato &)> action) const;

    void bfs(function<void(TipoDato &)> action) const;
};

#endif
