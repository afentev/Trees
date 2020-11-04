//
// Created by afentev on 10/18/20.
//

#ifndef TREES_RBST_H
#define TREES_RBST_H

#include <iostream>

#include "Tree.h"

class RBST: public Tree {
public:
    RBST();
    void insert(int, Tree*&) override;
    void remove(int, Tree*&) override;
    double measure(int, Tree*) override;
    int height() override;
    int width() override;
    int leftLength() override;
    int rightLength() override;
    RBST* getLeft() override;
    RBST* getRight() override;
    static void fixsize (RBST*);
    int getElem() override;
    int elem{};
    int size = 0;

private:
    static int getsize (RBST*);
    static RBST* RR (RBST*);
    static RBST* LR (RBST*);
    static RBST* _merge(RBST*, RBST*);
    RBST* _insert (RBST*, int);
    RBST* _remove (RBST*, int);
    RBST* _insert_at_root (RBST*, int);
    static int leftV(RBST*, int);
    static int rightV(RBST*, int);
    static int _height(RBST*);
    RBST* left;
    RBST* right;
    bool inited = false;
};


#endif //TREES_RBST_H
