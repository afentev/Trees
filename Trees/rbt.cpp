//
// Created by afentev on 10/18/20.
//

#include "rbt.h"

// class RBTree implements the operations in Red Black Tree

// initializes the nodes with appropirate values
// all the pointers are set to point to the null pointer

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

bool RBTree::is_valid(RBTree* t) {
    if (t == nullptr) {
        t = this;
    }
    if (t->root == nullptr) {
        return false;
    }
    return t->root != t->TNULL;
}

