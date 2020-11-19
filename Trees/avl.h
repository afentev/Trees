//
// Created by afentev on 10/18/20.
//

#ifndef TREES_AVL_H
#define TREES_AVL_H

#include <iostream>

#include "Tree.h"

class AVL: public Tree {
public:
    AVL();
    explicit AVL(int);
    void insert(int, Tree*&) override;
    void remove(int, Tree*&) override;
    double measure(int, Tree*) override;
    int height() override;
    int width() override;
    int leftLength() override;
    int rightLength() override;
    AVL* getLeft() override;
    AVL* getRight() override;
    int getElem() override;

private:
    AVL* right;
    AVL* left;
    static void SLR(AVL*&);
    static void BLR(AVL*&);
    static void SRR(AVL*&);
    static void BRR(AVL*&);
    static void update_heights(AVL*&);
    static int _height(AVL*);
    static int leftV(AVL*, int);
    static int rightV(AVL*, int);
    void _insert(int, AVL*&);
    void _remove(int, AVL*&);
    static void balance_func(AVL*&);
    int elem{};
    int balance{};
    int balance_ = 0;
    bool inited = false;
};


#endif //TREES_AVL_H
