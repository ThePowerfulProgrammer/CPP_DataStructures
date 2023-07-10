#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

#include "linkedListType.h"

using namespace std;

template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
    public:
        bool search(const Type& searchItem) const;
        // as stated in parent class
        void insertFirst(const Type& newItem);
        // as stated in parent class
        void insertLast(const Type& newItem);
        // as stated in parent class
        void deleteNode(const Type& deleteItem);
        // as stated in parent class

    protected:

    private:
};

class <template class>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
    newNode *temp;
    bool found = false;
    temp = this->first;
    while (temp != nullptr && !found)
        {
            if (temp->info == searchItem)
                {
                    found = true;
                }
            else
                {
                    temp = temp->link;
                }
        }
    return found;
}

class <template class>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    newNode<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = this->first;
    this->first = newNode;

    this->count++;

    if (this->last == nullptr)
        {
            last = newNode;
        }
}

class <template class>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
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
            this->last->link = newNode;
            this->last = newNode;
            this->count++;
        }
}

class <template class>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent; // pointer before current
    bool found;

    if (this->first == nullptr)
        {
            cout << "List is empty, No object to delete" << endl;
        }
    else
        {
            if (this->first->info == deleteItem)
                {
                    current = this->first;
                    this->first = this->first->link;
                    this->count--;

                    if (this->first == nullptr)
                        {
                            this->last = nullptr;
                        }
                    delete current;
                }
            else
                {
                    found = false;
                    trailCurrent = first;

                    current = this->first->link;
                    while (current != nullptr & !found)
                        {
                            if (current->info != deleteItem)
                                {
                                    trailCurrent = current;
                                    current = current->link;
                                }
                            else
                                {
                                    found = true;
                                }
                        }
                    if (found)
                        {
                            trailCurrent->link = current->link;
                            this->count--;

                            if (this->last==current)
                                {
                                    this->last = trailCurrent;
                                }
                            delete current;
                        }
                    else
                        {
                            cout << "The entire list has been searched and the item to be removed is not in the list :) " << endl;
                        }
                }
        }
}
#endif // UNORDEREDLINKEDLIST_H
