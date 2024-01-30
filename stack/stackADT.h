#ifndef STACKADT_H
#define STACKADT_H


template <class Type>
class stackADT
{
    public:
        virtual void initializeStack() = 0;
        // Method to init the stack to an empty state.
        // PC: stack is empty

        virtual bool isEmptyStack() const = 0;
        // PC: returns true if empty, else false

        virtual bool isFullStack() const = 0;
        // PC: returns true if full, else false

        virtual void push(const Type& newItem) = 0;
        // Adds newItem to stack
        // PreCon: Stack exists and is not full
        // PC: The stack is changed and newItem is added to the top of the stack

        virtual Type top() const = 0;
        // PreCon: Stack exists and is not empty
        // PC: If isEmptyStack(): terminate, else return top of stack

        virtual void pop() = 0;
        // PreCon: Stack exists and is not empty
        // PC: Stack is changed and top element is removed (LIFO)

    protected:

    private:
};

#endif // STACKADT_H
