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
    /*
    RBT* p = cur;
    while (p->elem != x) {
        if (p->elem < x) {
            p = p->right;
        } else {
            p = p->left;
        }
    }
    if (p->left == nullptr && p->right == nullptr) {
        if (p == cur) {
            cur = nullptr;
        } else {
            if (p->parent->right == p) {
                delete p->parent->right;
                p->parent->right = nullptr;
            } else {
                delete p->parent->left;
                p->parent->left = nullptr;
            }
        }
        return;
    }
    RBT* y = nullptr;
    RBT* q = nullptr;
    if (p->left != nullptr && p->right == nullptr) {
        delete p->parent->left;
        p->parent->left = nullptr;
    } else if (p->left == nullptr && p->right != nullptr) {
        delete p->parent->right;
        p->parent->right = nullptr;
    } else {
        y = p;
        while (y->left != nullptr) {
            y = y->left;
        }
        if (y->right != nullptr) {
            y->right->parent = y->parent;
        }
        if (y == cur) {
            cur = y->right;
        } else {
            if (y->parent->left == y) {
                y->parent->left = y->right;
            } else {
                y->parent->right = y->right;
            }
        }
    }

    if (y != p) {
        p->color = y->color;
        p->elem = y->elem;
    }
    if (y->color) {
        q = y;
        while (q->color && q->parent != nullptr) {
            if (q->parent->left == q) {
                RBT* sib = sibling(q);
                if (!sib->color) {
                    sib->color = true;
                    q->parent->color = false;
                    LR(q->parent);
                }
                bool yes = false;
                if (sib->left != nullptr && sib->right != nullptr) {
                    if (sib->left->color && sib->right->color) {
                        sib->color = false;
                        yes = true;
                    }
                }

                if (!yes) {
                    yes = false;
                    if (sib->right != nullptr) {
                        if (sib->right->color) {
                            sib->left->color = true;
                            sib->color = false;
                            RR(sib);
                            yes = true;
                        }
                    }
                    if (!yes) {
                        sib->color = q->color;
                        q->parent->color = true;
                        sib->right->color = true;
                        LR(q->parent);
                        while (q->parent != nullptr) {
                            q = q->parent;
                        }
                    }
                }
            } else {
                RBT* sib = sibling(q);
                if (!sib->color) {
                    sib->color = true;
                    q->parent->color = false;
                    RR(q->parent);
                }
                bool yes = false;
                if (sib->right != nullptr && sib->left != nullptr) {
                    if (sib->right->color && sib->left->color) {
                        sib->color = false;
                        yes = true;
                    }
                }

                if (!yes) {
                    yes = false;
                    if (sib->left != nullptr) {
                        if (sib->left->color) {
                            sib->right->color = true;
                            sib->color = false;
                            LR(sib);
                            yes = true;
                        }
                    }
                    if (!yes) {
                        sib = q->parent;
                        q->parent->color = true;
                        sib->left->color = true;
                        RR(q->parent);
                        while (q->parent != nullptr) {
                            q = q->parent;
                        }
                    }
                }
            }
        }
        q->color = true;
        RBT* w = q;
        while (w->parent != nullptr) {
            w = w->parent;
        }
        w->color = true;
    }*/
    if (cur == nullptr || !cur->inited) {return;}
    if (x == cur->elem) {
        if (cur->right == nullptr || cur->left == nullptr) {
            _remove_recurs(x, cur);
        } else if (cur->right->inited && cur->left->inited) {
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
            child->color = true;
        } else {
            _remover(child);
        }
    }
    std::cout << "removed" << std::endl;
    delete cur;
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
        if (cur->parent->color && cur->color && sib->left->color && sib->right->color) {
            sib->color = false;
            _remover(cur->parent);
        } else if (!cur->parent->color && sib->color && sib->left->color && sib->right->color) {
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

    RBT* tr = dynamic_cast<RBT*>(t);
    while (tr->parent != nullptr) {
        tr = tr->parent;
    }

    t = dynamic_cast<Tree*>(tr);

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
    if (right != nullptr) {
        if (!right->inited) {
            return nullptr;
        }
    }
    return right;
}

RBT* RBT::getLeft() {
    if (left != nullptr) {
        if (!left->inited) {
            return nullptr;
        }
    }
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

// class RBTree implements the operations in Red Black Tree

// initializes the nodes with appropirate values
// all the pointers are set to point to the null pointer
void RBTree::initializeNULLNode(Node* node, Node* parent) {
    node->data = 0;
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = 0;
}

void RBTree::preOrderHelper(Node* node) {
    if (node != TNULL) {
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }
}

void RBTree::inOrderHelper(Node* node) {
    if (node != TNULL) {
        inOrderHelper(node->left);
        inOrderHelper(node->right);
    }
}

void RBTree::postOrderHelper(Node* node) {
    if (node != TNULL) {
        postOrderHelper(node->left);
        postOrderHelper(node->right);
    }
}

Node* RBTree::searchTreeHelper(Node* node, int key) {
    if (node == TNULL || key == node->data) {
        return node;
    }

    if (key < node->data) {
        return searchTreeHelper(node->left, key);
    }
    return searchTreeHelper(node->right, key);
}

// fix the rb tree modified by the delete operation
void RBTree::fixDelete(Node* x) {
    Node* s;
    while (x != root && x->color == 0) {
        if (x == x->parent->left) {
            s = x->parent->right;
            if (s->color == 1) {
                // case 3.1
                s->color = 0;
                x->parent->color = 1;
                leftRotate(x->parent);
                s = x->parent->right;
            }

            if (s->left->color == 0 && s->right->color == 0) {
                // case 3.2
                s->color = 1;
                x = x->parent;
            } else {
                if (s->right->color == 0) {
                    // case 3.3
                    s->left->color = 0;
                    s->color = 1;
                    rightRotate(s);
                    s = x->parent->right;
                }

                // case 3.4
                s->color = x->parent->color;
                x->parent->color = 0;
                s->right->color = 0;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            s = x->parent->left;
            if (s->color == 1) {
                // case 3.1
                s->color = 0;
                x->parent->color = 1;
                rightRotate(x->parent);
                s = x->parent->left;
            }

            if (s->left->color == 0 && s->right->color == 0) {
                // case 3.2
                s->color = 1;
                x = x->parent;
            } else {
                if (s->left->color == 0) {
                    // case 3.3
                    s->right->color = 0;
                    s->color = 1;
                    leftRotate(s);
                    s = x->parent->left;
                }

                // case 3.4
                s->color = x->parent->color;
                x->parent->color = 0;
                s->left->color = 0;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = 0;
}


void RBTree::rbTransplant(Node* u, Node* v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left){
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void RBTree::deleteNodeHelper(Node* node, int key) {
    // find the node containing key
    Node* z = TNULL;
    Node* x;
    Node* y;
    while (node != TNULL){
        if (node->data == key) {
            z = node;
        }

        if (node->data <= key) {
            node = node->right;
        } else {
            node = node->left;
        }
    }

    if (z == TNULL) {
        return;
    }

    y = z;
    int y_original_color = y->color;
    if (z->left == TNULL) {
        x = z->right;
        rbTransplant(z, z->right);
    } else if (z->right == TNULL) {
        x = z->left;
        rbTransplant(z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            rbTransplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        rbTransplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    delete z;
    if (y_original_color == 0){
        fixDelete(x);
    }
}

// fix the red-black tree
void RBTree::fixInsert(Node* k) {
    Node* u;
    while (k->parent->color == 1) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left; // uncle
            if (u->color == 1) {
                // case 3.1
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    // case 3.2.2
                    k = k->parent;
                    rightRotate(k);
                }
                // case 3.2.1
                k->parent->color = 0;
                k->parent->parent->color = 1;
                leftRotate(k->parent->parent);
            }
        } else {
            u = k->parent->parent->right; // uncle

            if (u->color == 1) {
                // mirror case 3.1
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    // mirror case 3.2.2
                    k = k->parent;
                    leftRotate(k);
                }
                // mirror case 3.2.1
                k->parent->color = 0;
                k->parent->parent->color = 1;
                rightRotate(k->parent->parent);
            }
        }
        if (k == root) {
            break;
        }
    }
    root->color = 0;
}

void RBTree::printHelper(Node* root, std::string indent, bool last) {
    // print the tree structure on the screen
    if (root != TNULL) {
        if (last) {
            indent += "     ";
        } else {
            indent += "|    ";
        }

        std::string sColor = root->color?"RED":"BLACK";
        printHelper(root->left, indent, false);
        printHelper(root->right, indent, true);
    }
    // cout<<root->left->data<<endl;
}

void RBTree::init() {
    TNULL = new Node;
    TNULL->color = 0;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    TNULL->data = 1.1e9;
    root = TNULL;
}

RBTree::RBTree() {
    init();
}

// Pre-Order traversal
// Node->Left Subtree->Right Subtree
void RBTree::preorder() {
    preOrderHelper(this->root);
}

// In-Order traversal
// Left Subtree -> Node -> Right Subtree
void RBTree::inorder() {
    inOrderHelper(this->root);
}

// Post-Order traversal
// Left Subtree -> Right Subtree -> Node
void RBTree::postorder() {
    postOrderHelper(this->root);
}

// search the tree for the key k
// and return the corresponding node
Node* RBTree::searchTree(int k) {
    return searchTreeHelper(this->root, k);
}

// find the node with the minimum key
Node* RBTree::minimum(Node* node) {
    while (node->left != TNULL) {
        node = node->left;
    }
    return node;
}

// find the node with the maximum key
Node* RBTree::maximum(Node* node) {
    while (node->right != TNULL) {
        node = node->right;
    }
    return node;
}

// find the successor of a given node
Node* RBTree::successor(Node* x) {
    // if the right subtree is not null,
    // the successor is the leftmost node in the
    // right subtree
    if (x->right != TNULL) {
        return minimum(x->right);
    }

    // else it is the lowest ancestor of x whose
    // left child is also an ancestor of x.
    Node* y = x->parent;
    while (y != TNULL && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

// find the predecessor of a given node
Node* RBTree::predecessor(Node* x) {
    // if the left subtree is not null,
    // the predecessor is the rightmost node in the
    // left subtree
    if (x->left != TNULL) {
        return maximum(x->left);
    }

    Node* y = x->parent;
    while (y != TNULL && x == y->left) {
        x = y;
        y = y->parent;
    }

    return y;
}

// rotate left at node x
void RBTree::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != TNULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// rotate right at node x
void RBTree::rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    if (y->right != TNULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

// insert the key to the tree in its appropriate position
// and fix the tree
void RBTree::insert(int key) {
    // Ordinary Binary Search Insertion
    Node* node = new Node;
    node->parent = nullptr;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1; // new node must be red

    Node* y = nullptr;
    Node* x = this->root;

    while (x != TNULL) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    // y is parent of x
    node->parent = y;
    if (y == nullptr) {
        root = node;
    } else if (node->data < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }

    // if new node is a root node, simply return
    if (node->parent == nullptr){
        node->color = 0;
        return;
    }

    // if the grandparent is null, simply return
    if (node->parent->parent == nullptr) {
        return;
    }

    // Fix the tree
    fixInsert(node);
}

Node* RBTree::getRoot() {
    return this->root;
}

// delete the node from the tree
void RBTree::deleteNode(int data) {
    deleteNodeHelper(this->root, data);
}

// print the tree structure on the screen
void RBTree::prettyPrint() {
    if (root) {
        printHelper(this->root, "", true);
    }
}

void RBTree::insert(int x, Tree *&) {
    insert(x);
}

void RBTree::remove(int x, Tree *&) {
    deleteNode(x);
}

int RBTree::getElem() {
    if (root == nullptr) {
        return 0;
    } else if (root == TNULL) {
        return 0;
    }
    return root->data;
}

RBTree *RBTree::getLeft() {
    if (root == nullptr) {
        return nullptr;
    } else if (root == TNULL) {
        return nullptr;
    }
    Node* x = root->left;
    auto* t = new RBTree;
    t->root = x;
    return t;
}

RBTree *RBTree::getRight() {
    if (root == nullptr) {
        return nullptr;
    } else if (root == TNULL) {
        return nullptr;
    }
    Node* x = root->right;
    auto* t = new RBTree;
    t->root = x;
    return t;
}

int RBTree::rightV(Node* tree, int arg) {
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

int RBTree::rightLength() {
    return rightV(root, 0);
}

int RBTree::leftLength() {
    return leftV(root, 0);
}

int RBTree::leftV(Node* tree, int arg) {
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

int RBTree::width() {
    return leftLength() + rightLength();
}

int RBTree::height() {
    return 0;
}

int RBTree::_height(Node* arg) {
    if (arg == nullptr) {
        return 0;
    } else if (arg == TNULL) {
        return 0;
    } else if (arg->left == nullptr && arg->right == nullptr) {
        return 0;
    } else {
        if (arg->left != nullptr && arg->right != nullptr) {
            if (arg->left == TNULL && arg->right == TNULL) {
                return 0;
            }
        }
        return 1 + std::max(_height(arg->left), _height(arg->right));
    }
}

double RBTree::measure(int diver, Tree* tree) {
    if (tree == nullptr || !dynamic_cast<RBT*>(tree)->inited) {
        return 0;
    }
    return (tree->height() + RBTree::measure(1, tree->getLeft()) +
            RBTree::measure(1, tree->getRight()) - 1) / static_cast<double>(diver);
}

bool RBTree::is_valid(RBTree* t) {
    if (t == nullptr) {
        t = this;
    }
    if (t->root == nullptr) {
        return false;
    }
    return t->root != t->TNULL;
}

