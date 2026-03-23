#include <iostream>
#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"

template <typename T>
class QueueFactory {
    public:
        static Queue<T>* GetQueue(int maxSize = 0) {
            if (maxSize == 0) return new LinkedQueue<T>();
            else return new ArrayQueue<T>(maxSize);
        }
};