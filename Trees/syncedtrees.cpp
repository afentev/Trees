//
// Created by afentev on 10/18/20.
//

#include "syncedtrees.h"

#include <utility>

SyncedTrees::SyncedTrees() {
    init();
}

SyncedTrees::~SyncedTrees() {
    while (bst_tree != nullptr) {
        bst_tree->remove(bst_tree->getElem(), reinterpret_cast<Tree *&>(bst_tree));
    }
    delete bst_tree;

    while (avl_tree != nullptr) {
        avl_tree->remove(avl_tree->getElem(), reinterpret_cast<Tree *&>(avl_tree));
    }
    delete avl_tree;

    while (rbt_tree != nullptr && rbt_tree->inited) {
        rbt_tree->remove(rbt_tree->elem, reinterpret_cast<Tree *&>(rbt_tree));
    }
    delete rbt_tree;

    while (rbst_tree != nullptr) {
        rbst_tree->remove(rbst_tree->elem, reinterpret_cast<Tree *&>(rbst_tree));
    }
    delete rbst_tree;
}

void SyncedTrees::_insert(int x) {
    if (!inited) {
        bst_tree->insert(x, reinterpret_cast<Tree *&>(bst_tree));

        avl_tree->insert(x, reinterpret_cast<Tree *&>(avl_tree));

        rbst_tree->insert(x, reinterpret_cast<Tree *&>(rbst_tree));

        rbt_tree->insert(x, reinterpret_cast<Tree *&>(rbt_tree));

        inited = true;
        return;
    }
    bst_tree->insert(x, reinterpret_cast<Tree *&>(bst_tree));
    avl_tree->insert(x, reinterpret_cast<Tree *&>(avl_tree));
    rbt_tree->insert(x, reinterpret_cast<Tree *&>(rbt_tree));
    rbst_tree->insert(x, reinterpret_cast<Tree *&>(rbst_tree));
    RBST::fixsize(rbst_tree);
}

void SyncedTrees::_remove(int x) {
    bst_tree->remove(x, reinterpret_cast<Tree *&>(bst_tree));
    avl_tree->remove(x, reinterpret_cast<Tree *&>(avl_tree));
    rbt_tree->remove(x, reinterpret_cast<Tree *&>(rbt_tree));
    rbst_tree->remove(x, reinterpret_cast<Tree *&>(rbst_tree));
}

void SyncedTrees::remove(int x, Tree*&) {
    if (bst_tree == nullptr || !bst_tree->inited) return;
    _remove(x);
}

void SyncedTrees::insert(int x, Tree *&) {
    _insert(x);
}

int SyncedTrees::getElem() {
    if (name == 0) {
        return bst_tree->getElem();
    } else if (name == 1) {
        return avl_tree->getElem();
    } else if (name == 3) {
        return rbt_tree->elem;
    } else if (name == 2) {
        return rbst_tree->elem;
    } else if (name == 3) {
        return rbt_tree->elem;
    }
}

Tree* SyncedTrees::getRight() {
    if (name == 0) {
        return bst_tree->getRight();
    } else if (name == 1) {
        return avl_tree->getRight();
    } else if (name == 2) {
        return rbst_tree->getRight();
    } else if (name == 3) {
        return rbt_tree->getRight();
    }
}

Tree* SyncedTrees::getLeft() {
    if (name == 0) {
        return bst_tree->getLeft();
    } else if (name == 1) {
        return avl_tree->getLeft();
    } else if (name == 2) {
        return rbst_tree->getLeft();
    } else if (name == 3) {
        return rbt_tree->getLeft();
    }
}

int SyncedTrees::rightLength() {
    if (name == 0) {
        return bst_tree->rightLength();
    } else if (name == 1) {
        return avl_tree->rightLength();
    } else if (name == 2) {
        return rbst_tree->rightLength();
    } else if (name == 3) {
        return rbt_tree->rightLength();
    }
}

int SyncedTrees::leftLength() {
    if (name == 0) {
        return bst_tree->leftLength();
    } else if (name == 1) {
        return avl_tree->leftLength();
    } else if (name == 2) {
        return rbst_tree->leftLength();
    } else if (name == 3) {
        return rbt_tree->leftLength();
    }
}

int SyncedTrees::width() {
    if (name == 0) {
        return bst_tree->width();
    } else if (name == 1) {
        return avl_tree->width();
    } else if (name == 2) {
        return rbst_tree->width();
    } else if (name == 3) {
        return rbt_tree->width();
    }
}

int SyncedTrees::height() {
    if (bst_tree == nullptr) {
        return 0;
    }
    if (name == 0) {
        return bst_tree->height();
    } else if (name == 1) {
        return avl_tree->height();
    } else if (name == 2) {
        return rbst_tree->height();
    } else if (name == 3) {
        return rbt_tree->height();
    }
}

Tree *SyncedTrees::getActive() {
    if (name == 0) {
        return bst_tree;
    } else if (name == 1) {
        return avl_tree;
    } else if (name == 2) {
        return rbst_tree;
    } else if (name == 3) {
        return rbt_tree;
    }
}

void SyncedTrees::init() {
    bst_tree = new BST;
    avl_tree = new AVL;
    rbt_tree = new RBT;
    rbst_tree = new RBST;
    name = 1;
}

double SyncedTrees::measure(int diver, Tree* tree) {
    return _measure(diver, tree, true);
}

double SyncedTrees::_measure(int diver, Tree* tree, bool first) {
    if (tree == nullptr) {
        return 0;
    } else if (first) {
        if (name == 3 && !dynamic_cast<SyncedTrees*>(tree)->rbt_tree->inited) {
            return 0;
        }
        if (dynamic_cast<SyncedTrees*>(tree)->bst_tree == nullptr) {
            return 0;
        }
    } else {
        if (name == 3 && !reinterpret_cast<RBT*>(tree)->inited) {
            return 0;
        }
    }
    return (tree->height() + _measure(1, tree->getLeft(), false) +
        _measure(1, tree->getRight(), false) - 1) / static_cast<double>(diver);
}
