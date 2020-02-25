#include "binarytree.h"
#include <iostream>

template<typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
    RecursiveDestroy(root);
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
void BinaryTree<T>::display_postorder()
{
    display_postorder(root);
}

template<typename T>
void BinaryTree<T>::Delete()
{
    std::cout<<"Enter your data in order to 'delete' : ";
    T tmpData;
    std::cin>>tmpData;
    Delete(tmpData,root);
}

template<typename T>
void BinaryTree<T>::RecursiveDestroy(Node<T>* aNode)
{
    if(aNode != nullptr) {
        RecursiveDestroy(aNode->left);
        RecursiveDestroy(aNode->right);
        delete aNode;
    }
}

template<typename T>
unsigned int BinaryTree<T>::count()
{
    return count(root);
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
Node<T>* BinaryTree<T>::Search(T data, Node<T>* aNode)
{
    if(aNode != nullptr) {
        if(data == aNode->data){
            std::cout<<"Found"<<std::endl;
            return aNode;
        }
        else if(data > aNode->data)
            return Search(data,aNode->right);
        else
            return Search(data,aNode->left);
    }
    else {
        std::cout<<"Not found"<<std::endl;
        return nullptr;
    }
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

template<typename T>
void BinaryTree<T>::display_postorder(Node<T>* aNode)
{
    if(aNode != nullptr){
        display_postorder(aNode->left);
        display_postorder(aNode->right);
        std::cout<<aNode->data<<std::endl;
    }

}

template<typename T>
Node<T>* BinaryTree<T>::FindMinValue(Node<T>* aNode)
{
    while(aNode->left != nullptr)
        aNode = aNode->left;
    return aNode;
}

template<typename T>
Node<T> *BinaryTree<T>::Delete(T data, Node<T>* aNode)
{
    if(aNode == nullptr){
        std::cout<<"No such data!"<<std::endl;
        return aNode;
    }
    else if(data < aNode->data)
        aNode->left = Delete(data,aNode->left);
    else if(data > aNode->data)
        aNode->right = Delete(data,aNode->right);
    else{
        if(aNode->left == nullptr && aNode->right == nullptr) {
            delete aNode;
            aNode = nullptr;
        }
        else if(aNode->left == nullptr) {
            Node<T>* tmpNode = aNode;
            aNode = aNode->right;
            delete tmpNode;
        }
        else if(aNode->right == nullptr) {
            Node<T>* tmpNode = aNode;
            aNode = aNode->left;
            delete tmpNode;
        }
        else {
            Node<T>* tmpNode = FindMinValue(aNode->right);
            aNode->data = tmpNode->data;
            aNode->right = Delete(tmpNode->data,aNode->right);
        }
    }
    return aNode;
}

template<typename T>
unsigned int BinaryTree<T>::count(Node<T>* aNode)
{
    if(aNode != nullptr)
        return 1+count(aNode->left)+count(aNode->right);
    return 0;
}

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;

