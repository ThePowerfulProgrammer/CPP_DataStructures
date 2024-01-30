#ifndef STACKTYPE_H
#define STACKTYPE_H
#include <iostream>
#include <cassert>

#include "stackADT.h"

using namespace std;


/**
In this implementation of a stack, stack elements are stored in an array, and an array is
a random access data structure; that is, you can directly access any element of the array.
However, by definition, a stack is a data structure in which the elements are accessed
(popped or pushed) at only one end—that is, a LIFO data structure. Thus, a stack element
is accessed only through the top, not through the bottom or middle. This feature
of a stack is extremely important and must be recognized in the beginning.

*/

template <class Type>
class stackType: public stackADT<Type>
{
    public:
        const stackType<Type>& operator=(const stackType<Type>&);
        // Overload the assignment operator
        // We have a pointer member, we must overload assignment and include the copy constructor
        // and destructor

        void initializeStack();
        // PC: stackTop = 0

        bool isEmptyStack() const;
        // PC: returns true if empty, else false

        bool isFullStack() const;
        // PC: Returns true if the stack is full, else false

        void push(const Type& newItem);
        // PreCon: The stack exists and is not full
        // PC: The stack is changed and newItem is added to the top of the stack

        Type top() const;
        // PreCon: The stack exists and is not empty
        // PC: If isEmptyStack() program terminates, else returns top of stack

        void pop();
        // PreCon: Stack exits and is not empty
        // PC: Stack is changed and top element is removed

        stackType(int stackSize = 100);
        // Ctor
        // Create an array of size stackSize to hold the stack elements
        // PC: The variable list contains the base address of the array, stackTop = 0, and maxStackSize = stackSize

        stackType(const stackType<Type>& otherStack);
        // copy ctor

        ~stackType();
        // Dtor
        // Removes all elements from stack
        // PC: The array (list) holding the stack elements are deleted

    protected:

    private:
        int maxStackSize; // Max stack size
        int stackTop; // Top of stack / deck . Must be in the range of 0 - maxStackSize
        Type *list; // pointer to the ARRAY that holds the stack elements

        void copyStack(const stackType<Type> &otherStack);
        // Makes a copy of otherStack
        // PC: A copy of otherStack is created and assigned to this stack.
};

/*
Because C++ arrays begin with the index 0, we need to distinguish between the value of
stackTop and the array position indicated by stackTop. If stackTop is 0, the stack
is empty; if stackTop is nonzero, then the stack is nonempty and the top element of the
stack is given by stackTop - 1.
Notice that the function copyStack is included as a private member. This is because
we want to use this function only to implement the copy constructor and overload the
assignment operator. To copy a stack into another stack, the program can use the assignment operator.

stackTop = non-zero
stackTop is also number of elements in stack
array[stackTop-1] = element at the top of the stack

*/

template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return (stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const
{
    return (stackTop == maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type& newItem)
{
    if (!isFullStack())
        {
            list[stackTop] = newItem; // add new element to top of stack

            stackTop++; // Increment stack
        }
    else
        {
            // Overflow occurs
            cout << "Stack is full " << "Consider popping elements " << endl;
        }
}

template <class Type>
Type stackType<Type>::top() const
{
    assert(stackTop != 0);

    return list[stackTop-1]; // e.g, stackTop = 4, therefore top element is list[4-1] = list[3] = top element
}

template <class Type>
void stackType<Type>::pop()
{
    if (!isEmptyStack())
        {
            stackTop--;
        }
    else
        {
            // underflow
            cout << "Stack is empty" << endl;
        }
}



template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
    delete [] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;

    list = new Type[maxStackSize];

    for (int i=0;i<stackTop;i++)
        {
            list[i] = otherStack.list[i];
        }
}


template <class Type>
stackType<Type>::stackType(int stackSize)
{
    if (stackSize < 0)
        {
            cout << "Number of positions cannot be negative. " << "Default set to 100 positions" << endl;
            maxStackSize = 100;
        }
    else
        {
            maxStackSize = stackSize;
        }
    stackTop = 0;
    list = new Type[maxStackSize];
}

template <class Type>
stackType<Type>::~stackType()
{
    delete [] list;
}

// Copy ctor is called when a stack object is passed as a (value) parameter to a function
template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = nullptr;
    copyStack(otherStack);
}

// IT is paramount to overload the = operator for classes with pointer variables
template <class Type>
const stackType<Type> & stackType<Type>::operator=(const stackType<Type>& otherStack)
{
    if (this != &otherStack)
        {
            copyStack(otherStack);
        }
    return *this;
}

#endif // STACKTYPE_H
