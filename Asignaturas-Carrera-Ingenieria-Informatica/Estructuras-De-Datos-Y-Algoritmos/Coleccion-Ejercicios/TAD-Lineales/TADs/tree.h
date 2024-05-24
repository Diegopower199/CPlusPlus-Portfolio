#ifndef TREE_H
#define TREE_H

#include "elementoarbol.h"
#include <functional>
#include "cola.h"

using namespace std;

class Tree
{
protected:
    shared_ptr<ElementoArbol> root = nullptr;

public:
    Tree();
    Tree(const TipoDato &dato);

    int height() const;
    int size() const;

    void add_subtree(const Tree &substree);

    void dfs_preorder(function<void(TipoDato &)> action) const;
    void dfs_postorder(function<void(TipoDato &)> action) const;
    void dfs_inorder(function<void(TipoDato &)> action) const;

    void bfs(function<void(TipoDato &)> action) const;
};

#endif
