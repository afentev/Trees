//
// Created by afentev on 10/18/20.
//

#ifndef TREES_BST_H
#define TREES_BST_H

#include <iostream>
#include <vector>

#include "Tree.h"

class BST: public Tree {
public:
    BST();
    explicit BST(int);
    void insert(int, Tree*&) override;
    void remove(int, Tree*&) override;
    double measure(int, Tree*) override;
    int height() override;
    int width() override;
    int leftLength() override;
    int rightLength() override;
    BST* getLeft() override;
    BST* getRight() override;
    int getElem() override;

    bool inited = false;
private:
    void _traverse(BST*&);
    static int width_buffer(BST*, int, std::__wrap_iter<std::vector<int, std::allocator<int>>::pointer>);
    void _insert(int, BST*&);
    void _remove(int, BST*&);
    void traverse();
    static int width(BST*);
    static int leftV(BST*, int);
    static int rightV(BST*, int);
    static int _height(BST*);

    int elem{};
    BST* left;
    BST* right;
};


#endif //TREES_BST_H
