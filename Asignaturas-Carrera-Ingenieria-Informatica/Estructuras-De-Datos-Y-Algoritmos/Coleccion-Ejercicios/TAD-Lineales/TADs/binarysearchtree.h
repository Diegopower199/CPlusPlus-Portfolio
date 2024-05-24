#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <TipoDato.h>
#include "elementoarbolbinario.h"
#include <functional>

using namespace std;

class BinarySearchTree
{
protected:
    shared_ptr<ElementoArbolBinario> root = nullptr;

public:
    BinarySearchTree();
    BinarySearchTree(const TipoDato &dato);

    int height() const;
    int size() const;

    const TipoDato &min() const;
    const TipoDato &max() const;

    void dfs_inorder(function<void(const TipoDato &)> action) const;

    bool find(const TipoDato &) const;
    void push(const TipoDato &);
    void remove(const TipoDato &);
};

#endif
