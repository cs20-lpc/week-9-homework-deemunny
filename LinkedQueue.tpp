#pragma once
#include "LinkedQueue.hpp"  // remove before compiling? or pragma is sufficient

template <typename T>
LinkedQueue<T>::LinkedQueue() : head(nullptr), last(nullptr) {
    // TODO ctor 
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj)  : LinkedQueue() {  // call def ctor to make sure head and last are init, otherwise they are temp garbage values
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>  
T LinkedQueue<T>::back() const {  // reminder to self, back = last
    if (isEmpty()) throw string("Queue is empty, nothing in back.");
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    while (head) {
        Node* delMe = head;
        head = head->next;
        delete delMe;
    }
    last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    Node* curr = copyObj.head;
    
    while (curr) {
        enqueue(curr->value);
        curr = curr->next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() { // reminder to self, dequeue = remove head
    // TODO
    if (isEmpty()) throw string("Queue is empty, nothing to call.");
    Node* delMe = head;
    head = head->next;
    delete delMe;
    if (head == nullptr) last = nullptr;
    --this->length;
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {  //reminder to self, enqueue = put at end of list as last
    // TODO
    Node* newNode = new Node(elem);

    // check if empty
    if (isEmpty()) head = newNode;
    else last->next = newNode;
    last = newNode;
    ++this->length;
}

template <typename T>
T LinkedQueue<T>::front() const { // reminder to self, front = head
    // TODO
    if (isEmpty()) throw string("Queue is empty, nothing in front.");
    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}


template <typename T>
void LinkedQueue<T>::printQueue() const {
    if (isEmpty()) throw string("Queue is empty, nothing to print");

    Node* curr = head;
    while (curr) {
        cout << curr->value << " -> ";
        curr = curr->next;
    } 
    cout << endl;
}