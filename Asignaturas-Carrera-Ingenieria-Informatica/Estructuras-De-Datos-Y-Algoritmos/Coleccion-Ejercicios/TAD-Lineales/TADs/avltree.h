#ifndef AVLTREE_H
#define AVLTREE_H

#include <TipoDato.h>
#include "elementoarbolbinario.h"
#include <functional>

class AVLTree
{
protected:
    shared_ptr<ElementoArbolBinario> root = nullptr;

public:
    AVLTree();
    AVLTree(const TipoDato &dato);

    int height() const;
    int size() const;

    const TipoDato &min() const;
    const TipoDato &max() const;

    void dfs_inorder(function<void(const TipoDato &)> action) const;

    bool find(const TipoDato &) const;
    void push(const TipoDato &);
    void remove(const TipoDato &);

private:
    void rebalance();
};

#endif
