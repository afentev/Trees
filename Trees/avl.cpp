//
// Created by afentev on 10/18/20.
//

#include "avl.h"

AVL::AVL() {
    left = nullptr;
    right = nullptr;
}

AVL::AVL(int x) {
    elem = x;
    left = nullptr;
    right = nullptr;
    balance = 1;
}

void AVL::_insert(int x, AVL*& cur) {  // return value: is stop?
    if (cur == nullptr) {
        cur = new AVL(x);
        cur->left = cur->right = nullptr;
        cur->inited = true;
    } else if (x < cur->elem) {
        _insert(x, cur->left);
        update_heights(cur);
    } else if (x > cur->elem) {
        _insert(x, cur->right);
        update_heights(cur);
    }

    int balance_ = 0;
    if (cur->right == nullptr && cur->left != nullptr) {
        balance_ = -cur->left->balance;
    } else if (cur->right != nullptr && cur->left == nullptr) {
        balance_ = cur->right->balance;
    } else if (cur->right != nullptr && cur->left != nullptr) {
        balance_ = cur->right->balance - cur->left->balance;
    }
    if (balance_ == 2) {
        int bb = 0;
        if (cur->right->left == nullptr) {
            bb = -1;  // rnd
        } else if (cur->right->right == nullptr) {
            bb = 1;  // rnd
        } else {
            bb = cur->right->left->balance - cur->right->right->balance;
        }
        if (bb <= 0) {
            SLR(cur);
        } else {
            BLR(cur);
        }
    } else if (-balance_ == 2) {
        int bb = 0;
        if (cur->left->right == nullptr) {
            bb = -1;  // rnd
        } else if (cur->left->left == nullptr) {
            bb = 1;  // rnd
        } else {
            bb = cur->left->right->balance - cur->left->left->balance;
        }

        if (bb <= 0) {
            SRR(cur);
        } else {
            BRR(cur);
        }
    }
    update_heights(cur);
}

void AVL::_remove(int x, AVL*& cur) {
    if (cur == nullptr) return;
    if (cur->elem == x) {
        if (cur->left == nullptr && cur->right == nullptr) {
            delete cur;
            cur = nullptr;
        } else if (cur->right != nullptr) {
            AVL* copy = cur->right;
            while (copy->left != nullptr) {
                copy = copy->left;
            }
            cur->elem = copy->elem;
            _remove(copy->elem, cur->right);
        } else if (cur->left != nullptr) {
            AVL* copy = cur->left;
            while (copy->right != nullptr) {
                copy = copy->right;
            }
            cur->elem = copy->elem;
            _remove(copy->elem, cur->left);
        }
    } else if (x < cur->elem) {
        _remove(x, cur->left);
    } else if (x > cur->elem) {
        _remove(x, cur->right);
    }
}

void AVL::SLR (AVL*& cur) {
    AVL* b = cur->right;
    cur->right = b->left;
    b->left = cur;
    update_heights(cur);
    update_heights(b);
    cur = b;
}

void AVL::BLR (AVL*& cur) {
    SRR(cur->right);
    SLR(cur);
}

void AVL::SRR (AVL*& cur) {
    AVL* b = cur->left;
    cur->left = b->right;
    b->right = cur;
    update_heights(cur);
    update_heights(b);
    cur = b;
}

void AVL::BRR (AVL*& cur) {
    SLR(cur->left);
    SRR(cur);
}

void AVL::update_heights(AVL*& cur) {
    if (cur->left == nullptr && cur->right == nullptr) {
        cur->balance = 1;
    } else if (cur->left == nullptr) {
        cur->balance = cur->right->balance + 1;
    } else if (cur->right == nullptr) {
        cur->balance = cur->left->balance + 1;
    } else {
        cur->balance = std::max(cur->left->balance, cur->right->balance) + 1;
    }
}

void AVL::insert(int x, Tree*& ref) {
    if (!inited) {
        elem = x;
        balance = 1;
        inited = true;
    } else {
        _insert(x, reinterpret_cast<AVL *&>(ref));
    }
}

void AVL::remove(int x, Tree*& t) {
    _remove(x, reinterpret_cast<AVL *&>(t));
}

int AVL::height() {
    return 1 + _height(this);
}

int AVL::width() {
    return leftLength() + rightLength();
}

int AVL::leftLength() {
    return leftV(this, 0);
}

int AVL::rightLength() {
    return rightV(this, 0);
}

AVL* AVL::getLeft() {
    return left;
}

AVL* AVL::getRight() {
    return right;
}

int AVL::getElem() {
    return elem;
}

int AVL::_height(AVL* arg) {
    if (arg == nullptr) {
        return 0;
    } else if (arg->left == nullptr && arg->right == nullptr) {
        return 0;
    } else {
        return 1 + std::max(_height(arg->left), _height(arg->right));
    }
}

int AVL::leftV(AVL* tree, int arg) {
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

int AVL::rightV(AVL* tree, int arg) {
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

double AVL::measure(int diver, Tree* tree) {
    if (tree == nullptr) {
        return 0;
    }
    return (tree->height() + AVL::measure(1, tree->getLeft()) +
                             AVL::measure(1, tree->getRight()) - 1) / static_cast<double>(diver);
}
