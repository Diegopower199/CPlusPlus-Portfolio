#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <memory>
#include <functional>
#include "elementoarbolbinario.h"
#include "TipoDato.h"

class BinaryTree
{
protected:
    std::shared_ptr<ElementoArbolBinario> root = nullptr;

public:
    BinaryTree();
    BinaryTree(const TipoDato &dato);

    int height() const;
    int size() const;

    void add_left_subtree(const BinaryTree &subtree);
    void add_right_subtree(const BinaryTree &subtree);

    void dfs_preorder(std::function<void(TipoDato &)> action) const;
    void dfs_postorder(std::function<void(TipoDato &)> action) const;
    void dfs_inorder(std::function<void(TipoDato &)> action) const;

    void bfs(std::function<void(TipoDato &)> action) const;
};

#endif
