#include "binarytree.h"
#include <algorithm>

BinaryTree::BinaryTree() {}

BinaryTree::BinaryTree(const TipoDato &dato)
{
    root = std::make_shared<ElementoArbolBinario>(ElementoArbolBinario{dato});
}

void BinaryTree::add_left_subtree(const BinaryTree &subtree)
{
    root->left = subtree.root;
}

void BinaryTree::add_right_subtree(const BinaryTree &subtree)
{
    root->right = subtree.root;
}

int _height(std::shared_ptr<ElementoArbolBinario> element)
{
    if (element == nullptr)
    {
        return -1;
    }
    else
    {
        int height_left = _height(element->left);
        int height_right = _height(element->right);
        return 1 + std::max(height_left, height_right);
    }
}

int BinaryTree::height() const
{
    return _height(root);
}

int _size(std::shared_ptr<ElementoArbolBinario> element)
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
