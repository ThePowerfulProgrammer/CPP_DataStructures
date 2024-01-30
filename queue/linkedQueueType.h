#ifndef LINKEDQUEUETYPE_H
#define LINKEDQUEUETYPE_H

#include "queueADT.h"
#include <cassert>
#include <iostream>

using namespace std;

// definition of the node
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};


template <class Type>
class linkedQueueType : public queueADT<Type>
{
    public:
        linkedQueueType();
        // Ctor

        ~linkedQueueType();
        // Dtor

        linkedQueueType(const linkedQueueType& other);
        // Copy Ctor

        const linkedQueueType<Type>& operator=(const linkedQueueType<Type>& otherQueue);
        // assignment operator overload

        bool isEmptyQueue() const;

        bool isFullQueue() const;

        void initialiseQueue();

        Type front() const ;

        Type back() const ;

        void addQueue(const Type& queueElement);

        void deleteQueue();

    protected:

    private:
        nodeType<Type> *queueFront; // pointer to front of queue
        nodeType<Type> *queueRear; // pointer to rear of queue
};


template <class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
    return (queueFront == nullptr);
}

template <class Type>
bool  linkedQueueType<Type>::isFullQueue() const
{
    return false;
}

template <class Type>
void linkedQueueType<Type>::initialiseQueue()
{
    nodeType<Type> *temp;
    // clean current queue
    while (queueFront != nullptr)
        {
            temp = queueFront;
            queueFront = queueFront->link;
            delete temp;
        }
    queueRear = nullptr;
}

template <class Type>
Type linkedQueueType<Type>::front() const
{
    assert(queueFront != nullptr);
    return queueFront->info;
}

template <class Type>
Type linkedQueueType<Type>::back() const
{
    assert (queueRear != nullptr);
    return queueRear->info;
}

template <class Type>
void linkedQueueType<Type>::addQueue(const Type& queueElement)
{
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;

    newNode->info = queueElement;
    newNode->link = nullptr;

    // If the linked list is empty
    if (queueFront == nullptr)
    {
        // Both queueFront and queueRear point to the new node
        queueFront = newNode; // queueFront points to newNode
        queueRear = newNode;  // queueRear also points to newNode

        // This handles the special case where the linked list is being
        // created with the first node.
    }
    else
    {
        // Append the new node to the end of the linked list
        queueRear->link = newNode; // Link the current last node to the new node
        queueRear = newNode;       // Update queueRear to point to the new last node

        // This adds the new node to the end of the existing linked list.
    }
}

template <class Type>
void linkedQueueType<Type>::deleteQueue()
{
    nodeType<Type> *temp;

    if (!isEmptyQueue())
        {
            temp = queueFront;
            queueFront = queueFront->link;

            delete temp;

            if (queueFront == nullptr)
                {
                    queueRear = nullptr;
                }
        }
    else
        {
            cout << "Cannot elimate elements from an empty queue. :)" << endl;
        }
}

template <class Type>
linkedQueueType<Type>::linkedQueueType()
{
    queueFront = nullptr;
    queueRear = nullptr;
}

template <class Type>
linkedQueueType<Type>::~linkedQueueType()
{
    initialiseQueue();
}

// copy  ctor
template <class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType& other)
{
    nodeType<Type> *newNode;
    nodeType<Type> *current;

    // delete nodes if needed
    if (queueFront == nullptr)
        {
            initialiseQueue();
        }

    // start copying
    if (other.queueFront == nullptr)
        {
            queueFront = nullptr;
            queueRear = nullptr;
        }
    else
        {
            current = other.queueFront; // current is now the same as other.queueFront

            // copy the first node
            queueFront = new nodeType<Type>;
            queueFront->info = current->info;
            queueFront->link = nullptr;

            queueRear = queueFront; // now the first and last node are the same

            current = current->link; // advance current to the next node in the otherQueue

            // copy the remaining node in the otherQueue
            while (current != nullptr)
                {
                    newNode = new nodeType<Type>;
                    newNode->info = current->info;
                    newNode->link = nullptr;

                    queueRear->link = newNode; // attach newNode to the end of the current Queue,by linked previous last node to NN, QR --> NN
                    queueRear = newNode; // advance queueRear so that it is now the last node, as it should be, NN == QR

                    current = current->link;
                }
        }
}

// assignment operator
template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=(const linkedQueueType<Type>& otherQueue)
{
    if (this != &otherQueue)
    {
        // Clear the existing queue
        while (queueFront != nullptr)
        {
            nodeType<Type> *temp = queueFront;
            queueFront = queueFront->link;
            delete temp;
        }

        // Copy from otherQueue
        if (otherQueue.queueFront == nullptr)
        {
            queueFront = nullptr;
            queueRear = nullptr;
        }
        else
        {
            nodeType<Type> *current = otherQueue.queueFront;

            queueFront = new nodeType<Type>;
            queueFront->info = current->info;
            queueFront->link = nullptr;

            queueRear = queueFront;

            current = current->link;

            while (current != nullptr)
            {
                nodeType<Type> *newNode = new nodeType<Type>;
                newNode->info = current->info;
                newNode->link = nullptr;

                queueRear->link = newNode;
                queueRear = newNode;

                current = current->link;
            }
        }
    }
    else
        {
            cout << "Queues are equal" << endl;
        }
    return *this;
}


#endif // LINKEDQUEUETYPE_H
