//
// Created by afentev on 10/18/20.
//

#include "bst.h"

BST::BST() {
    left = nullptr;
    right = nullptr;
    inited = false;
}

BST::BST(int x) {
    left = nullptr;
    right = nullptr;
    elem = x;
    inited = true;
}

void BST::insert(int x, Tree*& ref) {
    if (!inited) {
        elem = x;
        inited = true;
        left = right = nullptr;
    } else {
        _insert(x, reinterpret_cast<BST *&>(ref));
    }
};

void BST::remove(int x, Tree*& t) {
    _remove(x, reinterpret_cast<BST *&>(t));
}
//virtual int height() override;
//virtual int width() override;
//virtual int leftLength() override;
//virtual int rightLength() override;

void BST::_insert(int x, BST*& cur) {
    if (cur == nullptr) {
        cur = new BST(x);
        return;
    }
    if (x < cur->getElem()) {
        return _insert(x, cur->left);
    } else if (x > cur->getElem()) {
        return _insert(x, cur->right);
    }
}

void BST::_remove(int x, BST*& cur) {
    if (cur == nullptr) return;
    if (cur->elem == x) {
        if (cur->left == nullptr && cur->right == nullptr) {
            delete cur;
            cur = nullptr;
        } else if (cur->right != nullptr) {
            BST* copy = cur->right;
            while (copy->left != nullptr) {
                copy = copy->left;
            }
            cur->elem = copy->elem;
            _remove(copy->elem, cur->right);
        } else if (cur->left != nullptr) {
            BST* copy = cur->left;
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

void BST::traverse() {
    BST* temp = this;
    _traverse(temp);
}

void BST::_traverse(BST*& cur) {
    if (cur == nullptr) return;
    std::cout << cur->elem << std::endl;
    _traverse(cur->left);
    _traverse(cur->right);
}

int BST::width_buffer(BST* cur, int level, std::__wrap_iter<std::vector<int,
                      std::allocator<int>>::pointer> mem) {
    if (cur == nullptr) {
        return 0;
    }
    return 1 + std::max(width_buffer(cur->left, level, mem), width_buffer(cur->right, level, mem));
//    if (level < mem.size()) {
//        mem[level]++;
//    } else {
//        mem.push_back(1);
//    }
//    width_buffer(cur->left, level + 1, mem);
//    width_buffer(cur->right, level + 1, mem);
}

int BST::width(BST* cur) {
    std::vector<int> w_helper;
    w_helper.push_back(0);
    return width_buffer(cur, 0, w_helper.begin());
//    width_buffer(cur, 0, w_helper);
    int s = 0;
    for (auto x: w_helper) {
        s += x;
    }
    return s;
    return *std::max_element(w_helper.begin(), w_helper.end());
}

int BST::leftV(BST* tree, int arg) {
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

int BST::rightV(BST* tree, int arg) {
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

int BST::height() {
    return 1 + _height(this);
}

int BST::width() {
    return leftLength() + rightLength();
}

int BST::leftLength() {
    return leftV(this, 0);
}

int BST::rightLength() {
    return rightV(this, 0);
}

int BST::_height(BST* arg) {
    if (arg == nullptr) {
        return 0;
    } else if (arg->left == nullptr && arg->right == nullptr) {
        return 0;
    } else {
        return 1 + std::max(_height(arg->left), _height(arg->right));
    }
}

BST* BST::getLeft() {
    return left;
}

BST* BST::getRight() {
    return right;
}

int BST::getElem() {
    return elem;
}

double BST::measure(int diver, Tree* tree) {
    if (tree == nullptr) {
        return 0;
    }
    return (tree->height() + BST::measure(1, tree->getLeft()) +
            BST::measure(1, tree->getRight()) - 1) / static_cast<double>(diver);
}
