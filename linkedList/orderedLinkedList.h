#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

#include "linkedListType.h"

template <class Type>
class orderedLinkedList :  public linkedListType<Type>
{
    public:
        bool search(const Type& searchItem) const;
        // as stated in parent class
        void insertFirst(const Type& newItem);
        // as stated in parent class
        void insert(const Type& newItem);
        // insert newItem at the proper location
        // PC: newItem added to correct position , count++
        void insertLast(const Type& newItem);
        // as stated in parent class
        void deleteNode(const Type& deleteItem);
        // as stated in parent class

    protected:

    private:
};

template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem)  const
{
    bool found = false;
    nodeType<Type> *current;

    current = this->first;


    while (current != nullptr && !found)
        {
            if (current->info == searchItem)
                {
                    found = true;
                    cout << "Object has been found" << endl;
                }
            else
                {
                    current = current->link;
                }
        }
    if (found)
        {
            found = (current->info == searchItem);
        }
    return found;
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent = nullptr;
    bool found;

    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = nullptr;

    if (this->first == nullptr)
        {
            this->first = newNode;
            this->last = newNode;
            this->count++;
        }
    else
        {
            current = this->first;
            found = false;

            while (current != nullptr && !found)
                {
                    if (current->info >= newItem)
                        {
                            found = true;
                        }
                    else
                        {
                            trailCurrent = current;
                            current = current->link;
                        }
                }
         if (current == this->first)
            {
                newNode->link = this->first;
                this->first = newNode;
                this->count++;
            }
        else
            {
                trailCurrent->link = newNode;
                newNode->link = current;

                if (current == nullptr)
                    {
                        this->last = newNode;
                    }
                this->count++;
            }
        }
}


/*
    The function definitions of insertFirst() and insertLast() do not apply as this is a orderedLinkedList but
    these declarations were provided as pure virtual in parent class and therfore must be defined here
*/

template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}

// ----------------------------------------------------------

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;

    bool found;

    if (this->first == nullptr)
        {
            cout << "List is empty, function is terminated" << endl;
        }
    else
        {
            current = this->first;
            found = false;

            while (current != nullptr && !found)
                {
                    if (current->info >= deleteItem)
                        {
                            found = true;
                        }
                    else
                        {
                            trailCurrent = current;
                            current = current->link;
                        }
                }
            if (current == nullptr)
                {
                    cout << "Item to be Yeeted is not in list" << endl;
                }
            else
                {
                    if (current->info == deleteItem)
                        {
                            if (this->first == current)
                                {
                                    this->first = this->first->link;
                                    if (this->first == nullptr)
                                        {
                                            this->last = nullptr;
                                        }
                                    delete current;
                                }
                            else
                                {
                                    trailCurrent->link = current->link;

                                    if (current == this->last)
                                        {
                                            this->last = trailCurrent;
                                        }
                                    delete current;
                                }
                            this->count--;
                        }
                    else
                        {
                            cout << "The item to be removed is not in the list" << endl;
                        }
                }
        }
}

#endif // ORDEREDLINKEDLIST_H
