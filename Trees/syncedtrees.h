//
// Created by afentev on 10/18/20.
//

#ifndef TREES_SYNCEDTREES_H
#define TREES_SYNCEDTREES_H
#pragma once

#include "bst.h"
#include "avl.h"
#include "rbt.h"
#include "rbst.h"
#include "Tree.h"

class SyncedTrees: public Tree {
public:
    SyncedTrees();
    ~SyncedTrees();
    void insert(int, Tree*&) override;
    void remove(int, Tree*&) override;
    double measure(int, Tree*) override;
    int height() override;
    int width() override;
    int leftLength() override;
    int rightLength() override;
    Tree* getLeft() override;
    Tree* getRight() override;
    int getElem() override;
    Tree* getActive();
    void init();
    int name;

    RBTree* rbt_tree;
    BST* bst_tree;
private:
    AVL* avl_tree;
    RBST* rbst_tree;
    void _insert(int);
    void _remove(int);
    bool inited = false;
    double _measure(int, Tree*, bool);
};

#endif //TREES_SYNCEDTREES_H
