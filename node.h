#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
    Node(T);
    T data;
    Node<T>* left;
    Node<T>* right;
};

#endif // NODE_H
