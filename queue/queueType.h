#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include "queueADT.h"
#include <cassert>
#include <iostream>

using namespace std;

template <class Type>
class queueType : public queueADT<Type>
{
    public:
        const queueType<Type>& operator=(const queueType<Type>& otherQueue);
        // We must over the assignment operator

        bool isEmptyQueue() const;
        // We must define as it is declared in parent

        bool isFullQueue() const;
        // We must define as it is declared in parent

        void initialiseQueue();
        // We must define as it is declared in parent

        Type front() const;
        // We must define as it is declared in parent

        Type back() const;
        // PreCon: The queue exists and is not full
        // PC: If the queue is empty, terminate else return last element

        void addQueue(const Type& queueElement);
        // Defined in parent and therefore must be declared

        void deleteQueue();
        // Defined in parent and therefore must be declared

        queueType(int queueSize = 100);
        // Ctor

        queueType(const queueType<Type>& otherQueue);
        // copy CTOR

        ~queueType();
        // dtor

    protected:

    private:
        int maxQueueSize; // Max queue size
        int count; // stores number of elements in queue

        int queueFront; // points to first element of the queue

        int queueRear; // points to last element of the queue

        Type *list; // pointer to the array that holds the queue elements
};

template <class Type>
bool queueType<Type>::isEmptyQueue() const
{
    return (count == 0);
}

template <class Type>
bool queueType<Type>::isFullQueue() const
{
    return (count == maxQueueSize);
}

template <class Type>
void queueType<Type>::initialiseQueue()
{
    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
}

template <class Type>
Type queueType<Type>::front() const
{
    assert(!isEmptyQueue()); // equivalent to !this.isEmptyQueue()
    return list[queueFront];
}

template <class Type>
Type queueType<Type>::back() const
{
    assert(!isEmptyQueue());
    return list[queueRear];
}

template <class Type>
void queueType<Type>::addQueue(const Type& newElement)
{
    if (!isFullQueue())
        {
            queueRear = (queueRear + 1) % maxQueueSize;
            // Use the mod operator to advance queueRear because the array is cirular
            count++;
            list[queueRear] = newElement;
        }
    else
        {
            cout << "Cannot add to a full queue." << endl;
        }
}

template <class Type>
void queueType<Type>::deleteQueue()
{
    if (!isEmptyQueue())
        {
            count--;
            queueFront = (queueFront+1) % maxQueueSize;
        }
    else
        {
            cout << "Cannot delete from an empty queue." << endl;
        }
}


// Ctor and Dtor

template <class Type>
queueType<Type>::queueType(int queueSize)
{
    if (queueSize <= 0)
        {
            cout << "Creating an array of size 100" << endl;
            maxQueueSize = 100;
        }
    else
        {
            maxQueueSize = queueSize;
        }
    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
    list = new Type[maxQueueSize];
}

template <class Type>
queueType<Type>::~queueType()
{
    delete [] list;
}

template <class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue)
{
    delete [] list;
    maxQueueSize = otherQueue.maxQueueSize;
    queueFront = otherQueue.queueFront;
    queueRear = otherQueue.queueRear;
    count = otherQueue.count;

    // create a pointer to the queue
    list = new Type[maxQueueSize];

    for (int i=0;i<maxQueueSize;i++)
        {
            list[i] = otherQueue.list[i];
        }
}

template <class Type>
const queueType<Type>& queueType<Type>::operator=(const queueType<Type>& otherQueue)
{
    if (this != &otherQueue) // Check for self-assignment
    {
        // Deallocate existing memory
        delete[] list;

        // Copy data members from otherQueue
        maxQueueSize = otherQueue.maxQueueSize;
        queueFront = otherQueue.queueFront;
        queueRear = otherQueue.queueRear;
        count = otherQueue.count;

        // Allocate new memory and copy elements from otherQueue
        list = new Type[maxQueueSize];
        for (int i = 0; i < maxQueueSize; i++)
        {
            list[i] = otherQueue.list[i];
        }
    }

    return *this; // Return a reference to this object
}



#endif // QUEUETYPE_H
