//
// Created by afentev on 10/18/20.
//

#ifndef TREES_RBT_H
#define TREES_RBT_H

#include <iostream>

#include "Tree.h"

class RBT: public Tree {
public:
    RBT();
    explicit RBT(int, RBT*);
    void insert(int, Tree*&) override;
    void remove(int, Tree*&) override;
    double measure(int, Tree*) override;
    int height() override;
    int width() override;
    int leftLength() override;
    int rightLength() override;
    RBT* getLeft() override;
    RBT* getRight() override;
    int getElem() override;

    RBT* right;
    RBT* left;
    RBT* parent;
    int elem{};
    bool color{};
    bool inited = false;

private:
    RBT* _insert_recurs(int, RBT*&);
    static void _remover(RBT*&);
    static void _remove_recurs(int, RBT*&);
    void fill (int, RBT*, bool, RBT*, RBT*);
    static RBT* uncle (RBT*&);
    static RBT* sibling (RBT*&);
    static RBT* grandfather (RBT*&);
    static void LR (RBT*);
    static void RR (RBT*);
    static void _insert_repair (RBT*);
    static void _repairer3 (RBT*&);
    static void _repairer4 (RBT*);
    static void _repairer5 (RBT*);
    static void _replace_node (RBT*, RBT*);
    static int leftV(RBT*, int);
    static int rightV(RBT*, int);
    static int _height(RBT*);
    void _insert(int, RBT*&);
    void _remove(int, RBT*&);
};

struct Node {
    int data; // holds the key
    Node *parent; // pointer to the parent
    Node *left; // pointer to left child
    Node *right; // pointer to right child
    int color; // 1 -> Red, 0 -> Black
};

class RBTree: public Tree {
public:
    RBTree();

    void insert(int, Tree*&) override;
    void remove(int, Tree*&) override;
    double measure(int, Tree*) override;
    int height() override;
    int width() override;
    int leftLength() override;
    int rightLength() override;
    RBTree* getLeft() override;
    RBTree* getRight() override;
    int getElem() override;

    int rightV(Node*, int);
    int leftV(Node*, int);
    int _height(Node*);

    void init();
    void preorder();
    void inorder();
    void postorder();
    Node* searchTree(int k);
    Node* minimum(Node* node);
    Node* maximum(Node* node);
    Node* successor(Node* x);
    Node* predecessor(Node* x);
    void leftRotate(Node* x);
    void rightRotate(Node* x);
    void insert(int key);
    Node* getRoot();
    void deleteNode(int data);
    void prettyPrint();

    bool is_valid(RBTree* = nullptr);

private:
    Node* root;
    Node* TNULL;
    void initializeNULLNode(Node* node, Node* parent);
    void preOrderHelper(Node* node);
    void inOrderHelper(Node* node);
    void postOrderHelper(Node* node);
    Node* searchTreeHelper(Node* node, int key);
    void fixDelete(Node* x);
    void rbTransplant(Node* u, Node* v);
    void deleteNodeHelper(Node* node, int key);
    void fixInsert(Node* k);
    void printHelper(Node* root, std::string indent, bool last);
};


#endif //TREES_RBT_H
