#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "node.h"

template < typename T>
class BinaryTree
{
public:
    BinaryTree();
    void insert();
private:
    Node<T>* root;
    void insert(T,Node<T>*);

};

#endif // BINARYTREE_H
