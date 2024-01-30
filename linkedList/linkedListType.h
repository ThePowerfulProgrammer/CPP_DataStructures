#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H
#include <iostream>
#include "linkedListIterator.h"
using namespace std;

template <class Type>
class linkedListType
{
    public:
        const linkedListType<Type>&operator=(const linkedListType<Type>&);
        // oberload assignment operator
        void initializeList();
        // initilize list to empty state
        // PC: first = nullptr,last=nullptr, count=0
        bool isEmptyList() const;
        // PC: return true if list is empty else return false
        void print();
        // output the data contained in each node
        int length() const;
        // PC: returns count(Number of nodes in list)
        void destroyList();
        // destroys all nodes in my llist
        // PC: first = nullptr. last=nullptr, count=0
        Type front() const;
        // returns first node data
        // PreCon: List must not be empty
        // PC: If list empty, terminate else return first element of list
        Type back() const;
        // returns last node data
        // PreCon: list must not be empty
        // PC: terminates if list empty, else returns last element of list
        virtual bool search(const Type& searchItem) const = 0;
        // Checks if searchItem is in list
        // PC: returns true if searchItem in list else returns false
        virtual void insertFirst(const Type& newItem) = 0;
        // Inserts newItem at beginning of list
        /* PC, first points to new list, newItem
           is inserted at the beginning of the list, last points to the last node and count incremented by 1*/
        virtual void insertLast(const Type& newItem) = 0;
        // Inserts newItem at end of list
        /* PC, first points to new list, newItem
           is inserted at the end of the list, last points to the last node and count incremented by 1*/

        virtual void deleteNode(const Type& deleteItem) = 0;
        /*
            deletes deleteItem from list
            PC: if found, the node containing deleteItem is removed(destroyed) from list,
            first points to the first node, last points to the last node of the updated List, count--;
        */
        linkedListIterator<Type> begin();
        // function to return an iterator at the beginning of LL
        // PC: returns an iterator such that current is set to first
        linkedListIterator<Type> end();
        // returns an iterator one element past the last element of the list
        // returns an iterator such that current = nullptr
        linkedListType();
        // Initializes list to empty state
        // PC: first = nullptr, last=nullptr, count=0
        linkedListType(const linkedListType<Type>& otherlist);
        // copy Ctor lListA = lListB
        ~linkedListType();
        // dtor
        // deletes all nodes
        // PC: List is destroyed

        void reversePrint(nodeType<Type>* current) const;
        // Reverse print a linked -> list
        void printListReverse() const;

    protected:
        int count;
        nodeType<Type> *first; // pointer to the first node in the LinkedList Data structure
        nodeType<Type> *last;  // pointer to the last node of the LinkedList

    private:
        void copyList(const linkedListType<Type> & otherlist);
        // makes a deepcopy
        // PC: copy of otherlist created and assigned to this list
};


template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == nullptr);
}

template <class Type>
linkedListType<Type>::linkedListType()
{
    first = nullptr;
    last = nullptr;
    count = 0;
    //ctor
}

template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp;

    while (first != nullptr)
        {
            temp = first; // temp is a pointer that stores the memory of first
            first = first->link; // first is set to the next available link(memory) of a node
            delete temp;    // visualize YOU FOOL
        }
    last = nullptr;
    count = 0;
    cout << "Deallocted!" << endl;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList();
}

template <class Type>
void linkedListType<Type>::print()
{
    // book uses current :)
    nodeType<Type>* temp;
    temp = first;
    while (temp != nullptr)
        {
            cout << temp->info << endl;
            temp = temp->link;
        }
}

template <class Type>
int linkedListType<Type>::length() const
{
    return (count);
}

template <class Type>
Type linkedListType<Type>::front() const
{
   assert(first != nullptr);
   return first->info; //return the info of the first node
}

template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last != nullptr); // last != last->link
    return (last->info);
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);
    return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(last);
    return temp;
}

template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type> & otherList)
{
    nodeType<Type> *newNode;
    nodeType<Type> *current;

    if (first != nullptr) { destroyList(); } // if original list not empty we make it EMPTY :-)
    if (otherList.first == nullptr)
        {
            first = nullptr;
            last = nullptr;
            count = 0;
        }
    else
        {
            current = otherList.first; // current points to list to be copied
            count = otherList.count;

            // begin copying
            first = new nodeType<Type>;

            first->info = current->info;
            first->link = nullptr;

            last = first;
            current = current->link;
            // copy rest

            while (current != nullptr)
                {
                    newNode = new nodeType<Type>;
                    newNode->info = current->info;
                    newNode->link = nullptr;

                    last->link = newNode;
                    last = newNode;

                    current = current->link;
                }
        }
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type> & otherList)
{
    first = nullptr;
    copylist(otherList);
}

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type> &otherList)
{
    if (this != &otherList)
        {
            copyList(otherList);
        }
    return *this;
}

template <class Type>
linkedListType<Type>::~linkedListType()
{
    //dtor
    destroyList();
}







// Reverse print the LL, starting from the last node and moving toward the first node
template <class Type>
void linkedListType<Type>::reversePrint(nodeType<Type>* current) const
{
    // Base case
    if (current != nullptr)
        {
            // RC the function reversePrint on the next node, until we reach a null
            reversePrint(current->link);

            // Print info of the current node
            cout << current->info << " " ;
        }
}

template <class Type>
void linkedListType<Type>::printListReverse() const
{
    reversePrint(first);
    cout << endl;
}

#endif // LINKEDLISTTYPE_H
