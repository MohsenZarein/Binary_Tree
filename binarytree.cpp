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
    std::cout<<"Enter your data in order to 'insert' : ";
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
void BinaryTree<T>::Search()
{
    std::cout<<"Enter the data you are looking for : ";
    T tmpData;
    std::cin>>tmpData;
    Search(tmpData,root);
}

template<typename T>
void BinaryTree<T>::display_preorder()
{
    display_preorder(root);
}

template<typename T>
void BinaryTree<T>::display_inorder()
{
    display_inorder(root);
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

template<typename T>
Node<T> *BinaryTree<T>::Search(T data, Node<T>* aNode)
{
    if(aNode != nullptr) {
        if(data == aNode->data)
            return aNode;
        else if(data > aNode->data)
            return Search(data,aNode->right);
        else
            return Search(data,aNode->left);
    }
    else return nullptr;
}

template<typename T>
void BinaryTree<T>::display_preorder(Node<T>* aNode)
{
    if(aNode != nullptr) {
        std::cout<<aNode->data<<std::endl;
        display_preorder(aNode->left);
        display_preorder(aNode->right);
    }
}

template<typename T>
void BinaryTree<T>::display_inorder(Node<T>* aNode)
{
    if(aNode != nullptr) {
        display_inorder(aNode->left);
        std::cout<<aNode->data<<std::endl;
        display_inorder(aNode->right);
    }
}

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;

