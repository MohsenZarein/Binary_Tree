#include "binarytree.h"
#include <iostream>

template<typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template<typename T>
void BinaryTree<T>::insert()
{
    std::cout<<"Enter your data in order to insert : ";
    T tmpData;
    std::cin>>tmpData;
    if(root != nullptr)
        insert(tmpData,root);
    else{
        root = new Node<T>(tmpData);
        root->left = nullptr;
        root->right = nullptr;
    }
}

template<typename T>
void BinaryTree<T>::insert(T data, Node<T>* aNode)
{
    if(data < aNode->data) {
        if(aNode->left != nullptr)
            insert(data,aNode->left);
        else{
            aNode->left = new Node<T>(data);
            aNode->left->left = nullptr;
            aNode->left->right = nullptr;
        }
    }
    else if(data >= aNode->data) {
        if(aNode->right != nullptr)
            insert(data,aNode->right);
        else{
            aNode->right = new Node<T>(data);
            aNode->right->left = nullptr;
            aNode->right->right = nullptr;
        }
    }
}

template class BinaryTree<int>;
template class Node<float>;
template class BinaryTree<std::string>;

