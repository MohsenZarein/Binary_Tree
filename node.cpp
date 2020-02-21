#include "node.h"
#include <iostream>

template <typename T>
Node<T>::Node(T data)
{
    this->data = data;
    left = nullptr;
    right = nullptr;
}

template class Node<int>;
template class Node<float>;
template class Node<std::string>;

