//
// Created by afentev on 10/18/20.
//

#ifndef TREES_RBT_H
#define TREES_RBT_H

#include <iostream>

#include "Tree.h"

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
    Node* minimum(Node* node);
    Node* maximum(Node* node);
    void leftRotate(Node* x);
    void rightRotate(Node* x);
    void insert(int key);
    Node* getRoot();
    void deleteNode(int data);

    bool is_valid(RBTree* = nullptr);

private:
    Node* root;
    Node* TNULL;
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
