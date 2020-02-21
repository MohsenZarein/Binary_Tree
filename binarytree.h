#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "node.h"

template < typename T>
class BinaryTree
{
public:
    BinaryTree();
    void insert();
    void Search();
private:
    Node<T>* root;
    void insert(T,Node<T>*);
    Node<T>* Search(T,Node<T>*);

};

#endif // BINARYTREE_H
