#ifndef _NODE_H_
#define _NODE_H_

template <class T> class Node
{
public:

    Node(const T & value, Node<T> *next= nullptr) : value(value), next(next) {}
    Node(Node<T> *next= nullptr) : next(next) {}

    T value;
    Node<T> *next;
};
#endif //_NODE_H_
