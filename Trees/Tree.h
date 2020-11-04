//
// Created by afentev on 10/28/20.
//

#ifndef TREES_TREE_H
#define TREES_TREE_H

#pragma once

class Tree {
public:
    virtual void insert(int, Tree*&) = 0;
    virtual void remove(int, Tree*&) = 0;
    virtual double measure(int, Tree*) = 0;
    virtual int height() = 0;
    virtual int width() = 0;
    virtual int leftLength() = 0;
    virtual int rightLength() = 0;
    virtual Tree* getLeft() = 0;
    virtual Tree* getRight() = 0;
    virtual int getElem() = 0;
};

#endif //TREES_TREE_H
