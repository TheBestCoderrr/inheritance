#pragma once
#include <iostream>
using namespace std;

template<typename type>
class Node
{
public:
    explicit Node(type v, Node* n = nullptr, Node* p = nullptr) :value(v), next(n), prev(p) {};
    type getValue() const { return value; }
    void setValue(type v) { value = v; }
    Node* getNext() const { return next; }
    void setNext(Node* n) { next = n; }

    Node* getPrev() const { return prev; }
    void setPrev(Node* p) { prev = p; }

    void Print() const { cout << value << " | "; }

private:
    type value;
    Node* next;
    Node* prev;
};
