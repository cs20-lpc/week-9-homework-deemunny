#pragma once
#include "ArrayQueue.hpp"

template <typename T>
ArrayQueue<T>::ArrayQueue(int i) : maxSize(i), frontIndex(0), backIndex(maxSize - 1), buffer(new T[i]{}) {}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    if (isEmpty()) throw string("Queue is empty, nothing in back.");
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    delete[] buffer;
    buffer = nullptr;
    this->length = 0;
    frontIndex = 0;
    backIndex = -1;
    maxSize = 0;  // this 0 out necessary?
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
    maxSize = copyObj.getMaxSize();
    backIndex = copyObj.backIndex;
    frontIndex = copyObj.frontIndex;
    this->length = copyObj.getLength();
    buffer = new T[maxSize];    

    for (int i = 0; i < maxSize; ++i) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    if (isEmpty()) throw string("Queue is empty, nothing to remove");
    frontIndex = (frontIndex + 1) % maxSize;  // auto "loops" around if front would overflow
    --this->length;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if (isFull()) {  
        int newSize = maxSize * 2 + 1;
        T* newBuffer = new T[newSize];
        for (int i = 0; i < this->length; ++i) {
            newBuffer[i] = buffer[(frontIndex + i) % maxSize];
        }        
        delete[] buffer;
        buffer = newBuffer;
        maxSize = newSize;
        frontIndex = 0;
        backIndex = this->length - 1;
    } 

    backIndex = (backIndex + 1) % maxSize;
    buffer[backIndex] = elem;
    ++this->length;        
}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    if (isEmpty()) throw string("Queue is empty, nothing in front");
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
void ArrayQueue<T>::printQueue() const {
    if (isEmpty()) throw string("Quueueueeueu is empty, nothing to print");
    for (int i = 0; i < this->length; ++i) {
        cout << "[" << buffer[(frontIndex + i) % maxSize] << "] ";
    }
    cout << endl;
}