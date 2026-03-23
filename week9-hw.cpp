#include <iostream>
#include <cstdlib>
#include <random>
#include "QueueFactory.hpp"

using namespace std;

int main() {
    random_device numbergogo;  // "better" seed algo than srand apparently 
    mt19937 gen(numbergogo()); // good RNG algo, pass it seed above
    uniform_int_distribution<int> distDMV(-1, 1);  // distribution algo, feed it random num and map to our needs -1, 0, 1
    uniform_int_distribution<int> distBANK(-1, 2);  // distribution algo for bank scenario

// =========================  scenario 1 ======================
    int maxSize = 10;
    Queue<int>* dmvQ = QueueFactory<int>::GetQueue(maxSize);

    for (int i = 0; i < 100; ++i) {
        int rNum = distDMV(gen);
        
        ArrayQueue<int>* arrayQueuePtr = dynamic_cast<ArrayQueue<int>*>(dmvQ);  // needed for  isFull() 
        if (arrayQueuePtr) {
        switch (rNum) {  // oops i thought we were going to do more with the different numbers, hence the switch. should have read more first.
            case -1:  // call up to DMV window
                    if (!arrayQueuePtr->isEmpty()) {
                        cout << "Number " << arrayQueuePtr->getMaxSize() - arrayQueuePtr->getLength() << ", please proceed to window " << gen() << "." << endl;
                        arrayQueuePtr->dequeue();
                    }
            case 0:  // 0 and 1, new person enters DMV or gets told to GTFO
            case 1:  
                if (!arrayQueuePtr->isFull()) {
                    cout << "Welcome to the DMV, please take a number. We hope you brought snacks." << endl;
                    arrayQueuePtr->enqueue(1);
                } else cout << "Seat's taken." << endl;
            break;
        }
       } else cerr << "Dcast pointer broken" << endl;  // delete when done debugging?
    }

    delete dmvQ;

// ============================ scenario 2 ========================
    cout << endl;

    Queue<int>* bankQ = QueueFactory<int>::GetQueue();

    for (int i = 0; i < 100; ++i) {
        int rNum = distBANK(gen);

        switch (rNum) {  // an if (negative) would have worked just fine here, but too late
            case -1:  // call up to bank window
                    if (!bankQ->isEmpty()) {
                        cout << "Hello can we help you? Whoever's in front?" << endl;
                        bankQ->dequeue();
                    }
            case 0:  // new person enters bank or gets told to GTFO
            case 1:
            case 2:  
                    cout << "Welcome to the bank. We only have one window. Have fun." << endl;
                    bankQ->enqueue(1);
            break;
        }
    }

    delete bankQ;

    return 0;

}