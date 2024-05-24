#include "binarytree.h"

BinaryTree::BinaryTree() : root{nullptr} {}

BinaryTree::BinaryTree(const TipoDato &dato)
{
    root = make_shared<ElementoArbolBinario>(ElementoArbolBinario{dato});
}

int _height(shared_ptr<ElementoArbolBinario> element)
{
    if (element == nullptr)
    {
        return -1;
    }
    else
    {
        int height_left = _height(element->left);
        int height_right = _height(element->right);
        return 1 + max(height_left, height_right);
    }
}

int BinaryTree::height() const
{
    return _height(root);
}

int _size(shared_ptr<ElementoArbolBinario> element)
{
    if (element == nullptr)
    {
        return 0;
    }
    else
    {
        int size_left = _size(element->left);
        int size_right = _size(element->right);
        return 1 + size_left + size_right;
    }
}

int BinaryTree::size() const
{
    return _size(root);
}

void BinaryTree::add_left_subtree(const BinaryTree &substree)
{
    root->left = substree.root;
}

void BinaryTree::add_right_substree(const BinaryTree &substree)
{
    root->right = substree.root;
}
