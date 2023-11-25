#pragma once
#include "Node.h"

template<typename type>
class List {
public:
    List() :head(nullptr), tail(nullptr), counter(0) {}
    List(const List& other);
    ~List() { clear(); }
    size_t size() const { return counter; }
    void push_back(type v);
    void push_front(type v);
    void pop_front();
    void pop_back();
    void clear();
    void print() const;
    void printReverse() const;

    Node<type>* findNode(size_t index) const;
    void insert(size_t index, type v);
    void pop_position(size_t index);
    int Replace(type fv, type v);
    void Reverse();

    List& operator=(const List& other);
private:
    Node<type>* head;
    Node<type>* tail;
    size_t counter;
};

template<typename type>
void List<type>::print() const {
    Node<type>* cur = head;
    while (cur) {
        cur->Print();
        cur = cur->getNext();
    }
    cout << endl;
}

template<typename type>
void List<type>::printReverse() const {
    Node<type>* cur = tail;
    while (cur) {
        cur->Print();
        cur = cur->getPrev();
    }
    cout << endl;
}

template<typename type>
List<type>::List(const List& other)
{
    *this = other;
}

template<typename type>
void List<type>::push_back(type v) {
    Node<type>* temp = new Node<type>(v, nullptr, tail);
    if (tail)
        tail->setNext(temp);
    else
        head = temp;
    tail = temp;
    ++counter;
}

template<typename type>
void List<type>::push_front(type v) {
    Node<type>* temp = new Node<type>(v, head);
    if (head) head->setPrev(temp);
    else tail = temp;
    head = temp;
    ++counter;
}

template<typename type>
void List<type>::pop_front() {
    if (head) {
        Node<type>* temp = head;
        head = head->getNext();
        head->setPrev(nullptr);
        if (!tail) tail = nullptr;
        delete temp;
        --counter;
    }
}

template<typename type>
void List<type>::pop_back()
{
    if (!head) return;
    else if (head == tail) {
        delete head;
        head = nullptr;
        counter = 0;
        return;
    }
    Node<type>* temp = head;
    while (temp->getNext() != tail)
        temp = temp->getNext();
    tail = temp;
    tail->setNext(nullptr);
    delete temp->getNext();
    --counter;
}

template<typename type>
void List<type>::clear() { while (counter > 0)pop_back(); }

template<typename type>
Node<type>* List<type>::findNode(size_t index) const
{
    if (index >= counter) return nullptr;
    size_t n = 0;
    Node<type>* cur = head;
    while (cur) {
        if (n == index) break;
        cur = cur->getNext();
        n++;
    }
    return cur;
}

template<typename type>
void List<type>::insert(size_t index, type v)
{
    if (index > counter) return;
    if (index == 0) { push_front(v); return; }
    if (index == counter) { push_back(v); return; }
    Node<type>* prev = findNode(index - 1);
    Node<type>* temp = new Node<type>(v, prev->getNext(), prev);
    prev->setNext(temp);
    temp->getNext()->setPrev(temp);
    ++counter;
}

template <class type>
void List<type>::pop_position(size_t index) {
    if (index >= counter) return;
    if (index == 0) { pop_front(); return; }
    if (index == counter - 1) { pop_back(); return; }
    Node<type>* prev = findNode(index - 1);
    Node<type>* temp = prev->getNext();
    prev->setNext(temp->getNext());
    temp->getNext()->setPrev(prev);
    delete temp;
    --counter;
}

template <class type>
int List<type>::Replace(type fv, type v) {
    Node<type>* cur = head;
    int count = 0;
    while (cur) {
        if (cur->getValue() == fv) {
            count++;
            cur->setValue(v);
        }
        cur = cur->getNext();
    }
    return count > 0 ? count : -1;
}

template<class T>
void List<T>::Reverse() {
    Node<T>* temp;
    Node<T>* cur = head;
    while (cur) {
        temp = cur->getNext();
        cur->setNext(cur->getPrev());
        cur->setPrev(temp);
        cur = cur->getPrev();
    }
    swap(head, tail);
}

template<typename type>
List<type>& List<type>::operator=(const List& other)
{
    clear();
    Node<type>* cur = other.head;
    while (cur) {
        push_back(cur->getValue());
        cur = cur->getNext();
    }
    return *this;
}
