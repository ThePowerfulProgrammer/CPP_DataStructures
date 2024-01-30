#ifndef LINKEDSTACKTYPE_H
#define LINKEDSTACKTYPE_H
#include "stackADT.h"

template <class Type>
struct nodeType
{
    Type info; // data
    nodeType<Type> *link; // pointer to address of next node
};

template <class Type>
class linkedStackType: public stackADT<Type>
{
    public:
        const linkedStackType<Type>& operator=(const linkedStackType<Type>&);
        // overload the assignment operator

        bool isEmptyStack() const;
        // PC: returns True if stack is empty, return (stackTop == nullptr)

        bool isFullStack() const;
        // PC: returns True if stack is full ;)

        void initializeStack();
        // init stack to empty state, linked->list therefore deallocates all memory
        // PC: the stack elements are removed; stackTop = nullptr

        void push(const Type& newItem);
        // PreCon: stack exists and is not full
        // PC: The stack is changed and newItem is added to top of stack

        Type top() const;
        // PreCon: stack exists and is not empty
        // PC: top of stack is returned

        void pop();
        // PreCon: The stack exists and is not empty
        // PC: The stack is changed and the top element is removed from the stack.

        linkedStackType();
        // ctor
        // PC: stackTop = nullptr;

        linkedStackType(const linkedStackType<Type>& otherStack);
        // copy ctor

        ~linkedStackType();
        // dtor
        // PC: All elements of the stack are removed from the stack, memory is dealloacted

    protected:

    private:
        nodeType<Type> *stackTop;

        void copyStack(const linkedStackType<Type>& otherStack);
        // PC: A copy of otherStack is created and assigned to this stack
};

template <class Type>
linkedStackType<Type>::linkedStackType()
{
    stackTop = nullptr;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return stackTop == nullptr;
}

template <class Type>
bool linkedStackType<Type>::isFullStack() const
{
    return false;
}

template <class Type>
void linkedStackType<Type>::initializeStack()
{
    nodeType<Type> *temp;

    while (stackTop != nullptr)
        {
            temp = stackTop; // // points to the same node as stackTop

            stackTop = stackTop->link; // advance stackTop to point to the next node

            delete temp;
        }
}

template <class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
    // Create a new nodeType<Type> pointer called 'newNode'.
    nodeType<Type> *newNode;

    // Allocate memory for a new node and make 'newNode' point to it.
    newNode = new nodeType<Type>;

    // Store the value of 'newElement' in the 'info' field of the new node.
    newNode->info = newElement;

    // Make the 'link' field of the new node point to the current top node of the stack.
    // This connects the new node to the existing stack.
    newNode->link = stackTop;

    // Update the 'stackTop' to point to the new node, making it the new top of the stack.
    stackTop = newNode;
}

template <class Type>
Type linkedStackType<Type>::top() const
{
    assert (stackTop != nullptr);
    return stackTop->info;
}

template <class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> *temp;

    // !this->isEmptyStack()
    if (!isEmptyStack())
        {
            temp = stackTop;
            stackTop = stackTop->link;

            delete temp;
        }
    else
        {
            cout << "Cannot pop from an empty stack" << endl;
        }
}


template <class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type>& otherStack)
{
    // Declare pointers 'newNode' (for creating new nodes),
    // 'current' (for traversing 'otherStack'), and 'last' (for connecting nodes).
    nodeType<Type> *newNode, *current, *last;

    // If the current stack is not empty, clear it by calling 'initializeStack()'.
    if (stackTop != nullptr)
    {
        initializeStack();
    }

    // Check if 'otherStack' is empty.
    if (otherStack.stackTop == nullptr)
    {
        // Set the current stack to empty since 'otherStack' is empty too.
        stackTop = nullptr;
    }
    else // 'otherStack' is not empty
    {
        // Start copying nodes from 'otherStack'.
        // Set 'current' to point to the top node of 'otherStack'.
        current = otherStack.stackTop;

        // Create a new node for the current stack with the same value as the top node of 'otherStack'.
        stackTop = new nodeType<Type>;
        stackTop->info = current->info;
        stackTop->link = nullptr;

        // 'last' points to the last node in the current stack (initialized as the top node).
        last = stackTop;

        // Move 'current' to the next node in 'otherStack'.
        current = current->link;

        // Loop through the rest of 'otherStack' and copy its nodes.
        while (current != nullptr)
        {
            // Create a new node for the current stack with the same value as the current node in 'otherStack'.
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = nullptr;

            // Connect the new node to the current stack. Create links.
            last->link = newNode;

            // Move 'last' to the newly added node, keeping track of the last node in the current stack.
            last = newNode;

            // Move 'current' to the next node in 'otherStack'.
            current = current->link;
        }
    }
}

template <class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type>& otherStack)
{
    stackTop = nullptr;
    copyStack(otherStack);
}

template <class Type>
linkedStackType<Type>::~linkedStackType()
{
    initializeStack();
}

template <class Type>
const linkedStackType<Type>& linkedStackType<Type>::operator=(const linkedStackType<Type>& otherStack)
{
    if (this != &otherStack) // say no to self-copy
        {
            copyStack(otherStack);
        }
    return *this;
}

#endif // LINKEDSTACKTYPE_H
