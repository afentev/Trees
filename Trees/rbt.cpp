//
// Created by afentev on 10/18/20.
//

#include "rbt.h"

RBT::RBT() {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

RBT::RBT(int x, RBT* p = nullptr) {
    left = nullptr;
    right = nullptr;
    parent = p;
    elem = x;
    color = true;
    inited = true;

    left = new RBT;
    left->inited = false;
    left->color = true;
    left->parent = this;
    right = new RBT;
    right->inited = false;
    right->color = true;
    right->parent = this;
}

void RBT::_insert(int x, RBT*& cur) {
    cur = _insert_recurs(x, cur);
    _insert_repair(cur);
    while (cur->parent != nullptr && cur->parent->inited) {
        cur = cur->parent;
    }
}

void RBT::_remove (int x, RBT*& cur) {
    if (cur == nullptr || !cur->inited) {return;}
    if (x == cur->elem) {
        if (cur->right == nullptr || cur->left == nullptr) {
            _remove_recurs(x, cur);
        }
        if (cur->right->inited && cur->left->inited) {
            RBT* copy = cur->left;
            while (copy->right != nullptr && copy->right->inited) {
                copy = copy->right;
            }
            cur->elem = copy->elem;
            _remove_recurs(copy->elem, copy);
        } else {
            _remove_recurs(x, cur);
        }
    } else if (x < cur->elem) {
        _remove(x, cur->left);
    } else {
        _remove(x, cur->right);
    }
}

void RBT::fill (int x, RBT* p, bool c, RBT* l = nullptr, RBT* r = nullptr) {
    elem = x;
    parent = p;
    color = c;
    left = l;
    right = r;
    inited = true;

    if (left == nullptr) {
        left = new RBT;
        left->inited = false;
        left->color = true;
        left->parent = this;
    }
    if (right == nullptr) {
        right = new RBT;
        right->inited = false;
        right->color = true;
        right->parent = this;
    }
}

RBT* RBT::grandfather (RBT*& vertex) {
    if (vertex != nullptr && vertex->inited) {
        if (vertex->parent != nullptr && vertex->parent->inited) {
            return vertex->parent->parent;
        }
    }
    RBT* tree = nullptr;
    return tree;
}

RBT* RBT::uncle (RBT*& vertex) {
    RBT* grandpa = grandfather(vertex);
    if (grandpa == nullptr || !grandpa->inited) {
        RBT* tree = nullptr;
        return tree;
    }
    if (vertex->parent == grandpa->left) {
        return grandpa->right;
    } else {
        return grandpa->left;
    }
}

RBT* RBT::sibling (RBT*& vertex) {
    RBT* p = vertex->parent;
    if (p == nullptr || !p->inited) {
        RBT* tree = nullptr;
        return tree;
    }
    if (vertex == p->right) {
        return p->left;
    } else {
        return p->right;
    }
}

void RBT::LR (RBT* cur) {
    RBT* nnew = cur->right;
    RBT* p = cur->parent;
    if (nnew == nullptr) {throw std::runtime_error(
                "nnew is nullptr (wtf) https://en.wikipedia.org/wiki/Red–black_tree");}

    cur->right = nnew->left;
    nnew->left = cur;
    cur->parent = nnew;
    if (cur->right != nullptr && cur->right->inited) {
        cur->right->parent = cur;
    }

    if (p != nullptr && p->inited) {
        if (cur == p->left) {
            p->left = nnew;
        } else if (cur == p->right) {
            p->right = nnew;
        }
    }
    nnew->parent = p;
}

void RBT::RR (RBT* cur) {
    RBT* nnew = cur->left;
    RBT* p = cur->parent;
    if (nnew == nullptr) {throw std::runtime_error(
                "nnew is nullptr (wtf) https://en.wikipedia.org/wiki/Red–black_tree");}

    cur->left = nnew->right;
    nnew->right = cur;
    cur->parent = nnew;
    if (cur->left != nullptr && cur->left->inited) {
        cur->left->parent = cur;
    }

    if (p != nullptr && p->inited) {
        if (cur == p->left) {
            p->left = nnew;
        } else if (cur == p->right) {
            p->right = nnew;
        }
    }
    nnew->parent = p;
}

RBT* RBT::_insert_recurs(int x, RBT*& cur) {
    if (cur == nullptr || !cur->inited) {
        cur = new RBT;
        cur->fill(x, nullptr, false);
        return cur;
    } else {
        if (x < cur->elem) {
            if (cur->left != nullptr && cur->left->inited) {
                return _insert_recurs(x, cur->left);
            } else {
                cur->left = new RBT;
                cur->left->fill(x, cur, false);
                return cur->left;
            }
        } else if (x > cur->elem) {
            if (cur->right != nullptr && cur->right->inited) {
                return _insert_recurs(x, cur->right);
            } else {
                cur->right = new RBT;
                cur->right->fill(x, cur, false);
                return cur->right;
            }
        }
    }
    return cur;
}

void RBT::_insert_repair (RBT* cur) {
    if (cur->parent == nullptr || !cur->inited) {
        cur->color = true;
        return;
    } else if (cur->parent->color) {
        return;
    } else if (uncle(cur) != nullptr && uncle(cur)->inited) {
        if (!uncle(cur)->color) {
            _repairer3(cur);
            return;
        }
    }
    _repairer4(cur);
}

void RBT::_repairer3 (RBT*& cur) {
    cur->parent->color = true;
    uncle(cur)->color = true;
    grandfather(cur)->color = false;
    _insert_repair(grandfather(cur));
}

void RBT::_repairer4 (RBT* cur) {
    RBT* p = cur->parent;
    RBT* g = grandfather(cur);

    if (cur == p->right && p == g->left) {
        LR(p);
        cur = cur->left;
    } else if (cur == p->left && p == g->right) {
        RR(p);
        cur = cur->right;
    }
    _repairer5(cur);
}

void RBT::_repairer5 (RBT* cur) {
    RBT* p = cur->parent;
    RBT* g = grandfather(cur);

    if (cur == p->left) {
        RR(g);
    } else if (cur == p->right) {
        LR(g);
    }
    p->color = true;
    g->color = false;
}

void RBT::_replace_node (RBT* p, RBT* ch) {
    ch->parent = p->parent;
    if (p->parent == nullptr || !p->parent->inited) {
        return;
    }
    if (p == p->parent->left) {
        p->parent->left = ch;
    } else {
        p->parent->right = ch;
    }
}

void RBT::_remove_recurs(int x, RBT*& cur) {
    // cur here MUST have only 1 child
    RBT* child = (cur->right == nullptr || !cur->right->inited) ? cur->left : cur->right;

    _replace_node(cur, child);
    if (cur->color) {
        if (!child->color) {
            _remover(child);
        } else {
            child->color = false;
        }
    }
    std::cout << "removed" << std::endl;
    delete cur;
    cur = nullptr;
    cur = child;
}

void RBT::_remover(RBT*& cur) {
    if (cur->parent != nullptr && cur->parent->inited) {
        RBT* sib = sibling(cur);
        if (!sib->color) {
            cur->parent->color = false;
            sib->color = true;
            if (cur == cur->parent->left) {
                LR(cur->parent);
            } else {
                RR(cur->parent);
            }
        }

        if (sib->left == nullptr || sib->right == nullptr) {
            return;
        }
        if (!cur->parent->color && cur->color && sib->left->color && sib->right->color) {
            sib->color = false;
            cur->parent->color = true;
        } else {
            if (sib->color) {
                if (cur == cur->parent->left && sib->right->color && !sib->left->color) {
                    sib->color = false;
                    sib->left->color = true;
                    RR(sib);
                } else if (cur == cur->parent->right && sib->left->color && !sib->right->color) {
                    sib->color = false;
                    sib->right->color = true;
                    LR(sib);
                }
            }
            sib->color = cur->parent->color;
            cur->parent->color = true;
            if (cur == cur->parent->left) {
                sib->right->color = true;
                LR(cur->parent);
            } else {
                sib->left->color = true;
                RR(cur->parent);
            }
        }
    }
}

void RBT::insert(int x, Tree *& tree) {
    if (!inited) {
        inited = true;
        elem = x;
        color = true;
        parent = nullptr;
        left = new RBT;
        left->inited = false;
        left->color = true;
        left->parent = this;
        right = new RBT;
        right->inited = false;
        right->color = true;
        right->parent = this;
    } else {
        _insert(x, reinterpret_cast<RBT *&>(tree));
    }
}

void RBT::remove(int x, Tree *& t) {
    dynamic_cast<RBT*>(t)->_remove(x, reinterpret_cast<RBT *&>(t));
}

int RBT::height() {
    return _height(this);
}

int RBT::width() {
    return leftLength() + rightLength();
}

int RBT::leftLength() {
    return leftV(this, 0);
}

int RBT::rightLength() {
    return rightV(this, 0);
}

RBT* RBT::getRight() {
    return right;
}

RBT* RBT::getLeft() {
    return left;
}

int RBT::getElem() {
    return elem;
}

int RBT::leftV(RBT* tree, int arg) {
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

int RBT::rightV(RBT* tree, int arg) {
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

int RBT::_height(RBT* arg) {
    if (arg == nullptr) {
        return 0;
    } else if (!arg->inited) {
        return 0;
    } else if (arg->left == nullptr && arg->right == nullptr) {
        return 0;
    } else {
        if (arg->left != nullptr && arg->right != nullptr) {
            if (!arg->left->inited && !arg->right->inited) {
                return 0;
            }
        }
        return 1 + std::max(_height(arg->left), _height(arg->right));
    }
}

double RBT::measure(int diver, Tree* tree) {
    if (tree == nullptr || !dynamic_cast<RBT*>(tree)->inited) {
        return 0;
    }
    return (tree->height() + RBT::measure(1, tree->getLeft()) +
            RBT::measure(1, tree->getRight()) - 1) / static_cast<double>(diver);
}
