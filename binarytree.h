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
    void display_preorder();
    void display_inorder();
    void display_postorder();
private:
    Node<T>* root;

    void insert(T,Node<T>*);
    Node<T>* Search(T,Node<T>*);
    void display_preorder(Node<T>*);
    void display_inorder(Node<T>*);
    void display_postorder(Node<T>*);


};

#endif // BINARYTREE_H
