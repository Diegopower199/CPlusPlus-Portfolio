#include "binarysearchtree.h"

BinarySearchTree::BinarySearchTree() : root{nullptr} {}

BinarySearchTree::BinarySearchTree(const TipoDato &dato)
{
    root = make_shared<ElementoArbolBinario>(ElementoArbolBinario{dato});
}

const TipoDato &_min(std::shared_ptr<ElementoArbolBinario> element)
{
    if (element->left != nullptr)
    {
        return _min(element->left);
    }
    else
    {
        return element->dato;
    }
}

const TipoDato &BinarySearchTree::min() const
{
    return _min(root);
}

const TipoDato &_max(std::shared_ptr<ElementoArbolBinario> element)
{
    if (element->right != nullptr)
    {
        return _max(element->right);
    }
    else
    {
        return element->dato;
    }
}

const TipoDato &BinarySearchTree::max() const
{
    return _max(root);
}

bool _find(std::shared_ptr<ElementoArbolBinario> element, const TipoDato &dato)
{

    if (element == nullptr)
    {
        return false;
    }

    if (element->dato > dato)
    {
        return _find(element->left, dato);
    }
    else if (element->dato < dato)
    {
        return _find(element->right, dato);
    }
    else
    {
        return element->dato == dato;
    }
}

bool BinarySearchTree::find(const TipoDato &dato) const
{
    return _find(root, dato);
}

void _push(std::shared_ptr<ElementoArbolBinario> &element, const TipoDato &dato)
{
    if (element == nullptr)
    {
        element = std::make_shared<ElementoArbolBinario>(dato);
        return;
    }

    if (element->dato > dato)
    {
        _push(element->left, dato);
    }
    else if (element->dato < dato)
    {
        _push(element->right, dato);
    }
    else
    {
    }
}

void BinarySearchTree::push(const TipoDato &dato)
{
    return _push(root, dato);
}

void BinarySearchTree::remove(const TipoDato &dato)
{
    auto elem = root;
    std::shared_ptr<ElementoArbolBinario> parent = nullptr;
    while (elem != nullptr)
    {
        if (elem->dato == dato)
        {
            break;
        }
        parent = elem;
        elem = (dato < elem->dato) ? elem->left : elem->right;
    }

    if (elem == nullptr)
    {
        return;
    }

    if (elem->left != nullptr && elem->right != nullptr)
    {
        elem->dato = _max(elem->left);

        parent = elem;
        elem = elem->left;
        while (elem->right != nullptr)
        {
            parent = elem;
            elem = elem->right;
        }
    }

    auto next = (elem->left != nullptr) ? elem->left : elem->right;
    if (parent == nullptr)
    {
        root = next;
    }
    else
    {
        if (parent->left == elem)
        {
            parent->left = next;
        }
        else
        {
            parent->right = next;
        }
    }
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

int BinarySearchTree::height() const
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

int BinarySearchTree::size() const
{
    return _size(root);
}
