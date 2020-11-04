//
// Created by afentev on 10/18/20.
//

#include "rbst.h"

RBST::RBST() {
    left = nullptr;
    right = nullptr;
}

RBST* RBST::_insert (RBST* tree, int vertex) {
    int r;
    if (tree == nullptr) {
        RBST* t = new RBST;
        t->size = 1;
        t->elem = vertex;
        t->inited = true;
        return t;
    } else {
        r = rand() % tree->size + 1;
        if (r == tree->size) {
            return _insert_at_root(tree, vertex);
        }
    }
    if (vertex < tree->elem) {
        tree->left = _insert(tree->left, vertex);
    } else {
        tree->right = _insert(tree->right, vertex);
    }
    fixsize(tree);
    return tree;
}

RBST* RBST::_remove (RBST* tree, int vertex) {
    if (getsize(tree) == 0) {
        return tree;
    } else if (vertex < tree->elem) {
        tree->left = _remove(tree->left, vertex);
    } else if (vertex > tree->elem) {
        tree->right = _remove(tree->right, vertex);
    } else {
        RBST* q = _merge(tree->left, tree->right);
        delete tree;
        tree = nullptr;
        tree = q;
    }
    return tree;
}

void RBST::fixsize (RBST* tree) {
    tree->size = getsize(tree->left) + getsize(tree->right) + 1;
}

int RBST::getsize (RBST* tree) {
    if (tree == nullptr) {
        return 0;
    }
    return tree->size;
}

RBST* RBST::RR (RBST* tree) {
    RBST* q = tree->left;
    if (!q) {
        return tree;
    }
    tree->left = q->right;
    q->right = tree;
    q->size = tree->size;
    fixsize(tree);
    fixsize(q);
    return q;
}

RBST* RBST::LR (RBST* tree) {
    RBST* p = tree->right;
    if (!p) {
        return tree;
    }
    tree->right = p->left;
    p->left = tree;
    p->size = tree->size;
    fixsize(tree);
    fixsize(p);
    return p;
}

RBST* RBST::_merge(RBST* left, RBST* right) {
    int m = getsize(left);
    int n = getsize(right);
    int total = n + m;
    if (total == 0) {
        RBST* tree = nullptr;
        return tree;
    } else if (m == 0) {
        return right;
    } else if (n == 0) {
        return left;
    }
    int r = rand() % total + 1;
    if (r < m) {
        left->right = _merge(left->right, right);
        fixsize(left);
        return left;
    }

    right->left = _merge(left, right->left);
    fixsize(right);
    return right;
}

RBST* RBST::_insert_at_root (RBST* tree, int vertex) {
    if (tree == nullptr) {
        RBST* t = new RBST;
        t->size = 1;
        t->elem = vertex;
        t->inited = true;
        return t;
    }
    if (vertex < tree->elem) {
        tree->left = _insert_at_root(tree->left, vertex);
        return RR(tree);
    } else {
        tree->right = _insert_at_root(tree->right, vertex);
        return LR(tree);
    }
}

void RBST::insert(int x, Tree *& tree) {
    if (!inited) {
        this->elem = x;
        this->size = 1;
        this->inited = true;
    } else {
        tree = _insert(dynamic_cast<RBST *>(tree), x);
    }
}

void RBST::remove(int x, Tree*& q) {
    q = dynamic_cast<RBST*>(q)->_remove(dynamic_cast<RBST *>(q), x);
}

int RBST::height() {
    return 1 + _height(this);
}

int RBST::width() {
    return leftLength() + rightLength();
}

int RBST::leftLength() {
    return leftV(this, 0);
}

int RBST::rightLength() {
    return rightV(this, 0);
}

RBST* RBST::getLeft() {
    return left;
}

RBST* RBST::getRight() {
    return right;
}

int RBST::getElem() {
    return elem;
}

int RBST::rightV(RBST* tree, int arg) {
    if (tree == nullptr) {
        return std::max(0, arg);
    }
    if (tree->right == nullptr && tree->left != nullptr) {
        return std::max(0, rightV(tree->left, arg - 1));
    }
    if (tree->right != nullptr && tree->left == nullptr) {
        return std::max(0, rightV(tree->right, arg + 1));
    }
    return std::max(0, std::max(rightV(tree->left, arg - 1), rightV(tree->right, arg + 1)));
}

int RBST::leftV(RBST* tree, int arg) {
    if (tree == nullptr) {
        return std::max(0, arg);
    }
    if (tree->right == nullptr && tree->left != nullptr) {
        return std::max(0, leftV(tree->left, arg + 1));
    }
    if (tree->right != nullptr && tree->left == nullptr) {
        return std::max(0, leftV(tree->right, arg - 1));
    }
    return std::max(0, std::max(leftV(tree->left, arg + 1), leftV(tree->right, arg - 1)));
}

int RBST::_height(RBST* arg) {
    if (arg == nullptr) {
        return 0;
    } else if (arg->left == nullptr && arg->right == nullptr) {
        return 0;
    } else {
        return 1 + std::max(_height(arg->left), _height(arg->right));
    }
}

double RBST::measure(int diver, Tree* tree) {
    if (tree == nullptr) {
        return 0;
    }
    return (tree->height() + RBST::measure(1, tree->getLeft()) +
            RBST::measure(1, tree->getRight()) - 1) / static_cast<double>(diver);
}
