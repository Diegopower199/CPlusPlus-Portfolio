#include "avltree.h"

AVLTree::AVLTree() : root{nullptr}{}

AVLTree::AVLTree(const TipoDato &dato){
    root = make_shared<ElementoArbolBinario>(ElementoArbolBinario{dato});
}

void _push(std::shared_ptr<ElementoArbolBinario>& element, const TipoDato& dato) { // Note the reference
    // Handle corner case
    if (element == nullptr) {
        element = std::make_shared<ElementoArbolBinario>(dato);
        return;
    }

    // Do actual work
    if (element->dato > dato) {
        _push(element->left, dato);
    }
    else if (element->dato < dato) {
        _push(element->right, dato);
    }
    else {
        // It is a duplicated element! Do nothing, raise exception,...
    }
}

bool _find(std::shared_ptr<ElementoArbolBinario> element, const TipoDato& dato) {
    // Handle corner case
    if (element == nullptr) {
        return false;
    }

    // Do actual work
    if (element->dato > dato) {
        return _find(element->left, dato);
    }
    else if (element->dato < dato) {
        return _find(element->right, dato);
    }
    else {
        return element->dato == dato;
    }
}

bool AVLTree::find(const TipoDato& dato) const {
    return _find(root, dato);
}

void AVLTree::push(const TipoDato& dato) {
    _push(root, dato);
    rebalance();
}

const TipoDato& _min(std::shared_ptr<ElementoArbolBinario> element) {
    if (element->left != nullptr) {
        return _min(element->left);
    }
    else {
        return element->dato;
    }
}

const TipoDato& AVLTree::min() const {
    return _min(root);
}

const TipoDato& _max(std::shared_ptr<ElementoArbolBinario> element) {
    if (element->right != nullptr) {
        return _max(element->right);
    }
    else {
        return element->dato;
    }
}

const TipoDato& AVLTree::max() const {
    return _max(root);
}

void AVLTree::remove(const TipoDato& dato) {
    // Find the element (keep a reference to its parent)
    auto elem = root;
    std::shared_ptr<ElementoArbolBinario> parent = nullptr;
    while (elem != nullptr) {
        if (elem->dato == dato) {
            break;
        }
        parent = elem;
        elem = (dato < elem->dato) ? elem->left : elem->right;
    }

    // If not found, nothing to do
    if (elem == nullptr) {
        return;
    }

    // If it has two childs, replace with the max element in the subtree
    if (elem->left != nullptr && elem->right != nullptr) {
        elem->dato = _max(elem->left);

        // Now the element to remove is the one at that max position
        parent = elem;
        elem = elem->left;
        while (elem->right != nullptr) {
            parent = elem;
            elem = elem->right;
        }
    }

    // Now the node to remove only has 1 or 0 childs
    auto next = (elem->left != nullptr) ? elem->left : elem->right;
    if (parent == nullptr) {
        root = next;
    }
    else {
        if (parent->left == elem) {
            parent->left = next;
        }
        else {
            parent->right = next;
        }
    }

    // After everything is done, rebalance
    rebalance();
}

int _height(shared_ptr<ElementoArbolBinario> element) {
    if(element == nullptr){
        return -1;
    }
    else{
        int height_left = _height(element->left);
        int height_right = _height(element->right);
        return 1 + max(height_left, height_right);
    }
}

int AVLTree::height() const {
    return _height(root);
}

int _size(shared_ptr<ElementoArbolBinario> element) {
    if(element == nullptr){
        return 0;
    }
    else{
        int size_left = _size(element->left);
        int size_right = _size(element->right);
        return 1 + size_left + size_right;
    }
}

int AVLTree::size() const {
    return _size(root);
}

int factor_equilibrio(std::shared_ptr<ElementoArbolBinario> element) {
    return _height(element->right) - _height(element->left);
}

void rotate_left(std::shared_ptr<ElementoArbolBinario>& element) { // Note the reference
    auto old_parent = element;
    element = element->left;
    old_parent->left = element->right;
    element->right = old_parent;
}

void rotate_right(std::shared_ptr<ElementoArbolBinario>& element) { // Note the reference
    auto old_parent = element;
    element = element->right;
    old_parent->right = element->left;
    element->left = old_parent;
}

void _rebalance(std::shared_ptr<ElementoArbolBinario>& element) { // Note the reference
    // DFS post-order strategy:
    if (element->left) {
        _rebalance(element->left);
    }
    else if (element->right) {
        _rebalance(element->right);
    }

    if (factor_equilibrio(element) == -2) {
        if (factor_equilibrio(element->left) == 1) {
            // First, rotate the child right
            rotate_right(element->left);
        }
        rotate_left(element);
    }
    else if (factor_equilibrio(element) == 2) {
        if (factor_equilibrio(element->right) == -1) {
            // First, rotate the child left
            rotate_left(element->right);
        }
        rotate_right(element);
    }
}

void AVLTree::rebalance() {
    if (root != nullptr) {
        _rebalance(root);
    }
}
