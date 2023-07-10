#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR_H

// represents a single node
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
    /*
    The variable declaration is
    nodeType *head;
    */
};

template <class Type>
class linkedListIterator
{
    public:
        linkedListIterator();
        linkedListIterator(nodeType<Type> *ptr);
        // current = ptr
        Type operator*();
        // overloader
        // returns the int contained in the node
        linkedListIterator<Type> operator++();
        // advances the iterator to the next node
        bool operator==(const linkedListIterator<Type> & right) const;
        // Returns trus if iterator is equal to iterator on the right , otherwise false
        bool operator!=(const linkedListIterator<Type> & right) const;
        // returns true if iterator comparison is not equal else returns false

        //~linkedListIterator();

    protected:

    private:
        nodeType<Type> *current; // pointer to point to current node
                                 // variable declaration is same as in struct
                                 // current-> info
                                 // current-> link
};


template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    //ctor
    current = nullptr; // assigns current the memory address of null
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)
{
    current = ptr;  // assigns current the memory address of ptr
}

template<class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info; // returns info stored at memory address pointed to by current
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
    current = current->link; // current stores memory and now stores the memory of the next node link
    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type> &right) const
{
    return (current==right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type> & right) const
{
    return (current != right.current);
}

/*linkedListIterator::~linkedListIterator()
{
    //dtor
}*/

#endif // LINKEDLISTITERATOR_H
