#ifndef BINARYSEARCHTREETYPE_H
#define BINARYSEARCHTREETYPE_H

#include "binaryTreeType.h"

template <class Type>
class binarySearchTreeType: public binaryTreeType<Type>
{
    public:
        bool search(const Type& searchItem) const;
        // PC: returns true if searchItem in Tree else returns false

        void insert(const Type& insertItem) ;
        // PC: creates a newNode and inserts into correct position iff node does not already exist
        // duplicates not allowed

        void deleteNode(const Type& deleteItem);
        // PC: Search Tree and if deleteItem is found, delete Node
        // If tree empty or deleteItem not found , display appropriate message



    protected:

    private:
        void deleteFromTree(nodeType<Type>* &p);
        // Function to delete the node to which p points is
        // deleted from the binary search tree.
        // PC: The node to which p points is deleted from the binary search tree
};

template <class Type>
bool binarySearchTreeType<Type>::search(const Type& searchItem) const
{
    nodeType<Type>  *current;
    bool found = false;

    if (this->root == nullptr)
        {
            std::cout << "Binary Search Tree is empty, cannnot search" << std::endl;
        }
    else
        {
            current = this->root;
            while (current != nullptr && !found)
                {
                    if (current->info == searchItem)
                        {
                            found = true;
                        }
                    else if (current->info > searchItem)
                        {
                            // search right
                            current = current->rLink;
                        }
                    else
                        {
                            current = current->lLink;
                        }
                }
        }
    return found;
}

template <class Type>
void binarySearchTreeType<Type>::insert(const Type& insertItem)  // Must still be a binaryTree
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    nodeType<Type> *newNode;

    newNode = new nodeType<Type>;
    newNode->info = insertItem;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;


    if (this->root == nullptr)
        {
            this->root = newNode;
        }
    else
        {
            current = this->root;
            while (current != nullptr)
                {
                    trailCurrent = current;


                    if (current->info == insertItem)
                        {
                            std::cout << "Cannot insert duplicates in a binaryTree" << std::endl;
                            return;
                        }
                    else if (current->info > insertItem)
                        {
                            current = current->lLink;
                        }
                    else
                        {
                            current = current->rLink;
                        }
                }
            if (trailCurrent->info > insertItem)
                {
                    trailCurrent->lLink = newNode;
                }
            else
                {
                    trailCurrent->rLink = newNode;
                }
        }
}

template <class Type>
void binarySearchTreeType<Type>::deleteFromTree(nodeType<Type>* &p)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    nodeType<Type> *temp;

    if (p == nullptr)
        {
            std::cout << "The node to be deleted does not exist" << std::endl;
            return;
        }
    else if (p->lLink == nullptr && p->rLink == nullptr)
        {
            temp = p;
            p = nullptr;
            delete temp;
        }
    else if (p->lLink == nullptr)
        {
            temp = p;
            p = temp->rLink;
            delete temp;
        }
    else if (p->rLink == nullptr)
        {
            temp = p;
            p = temp->lLink;
            delete temp;
        }
    else
        {
            current = p->lLink;
            trailCurrent = nullptr;

            while (current->rLink != nullptr)
                {
                    trailCurrent = current;
                    current = current->rLink;
                }
            p->info = current->info;

            if (trailCurrent == nullptr)
                {
                    p->lLink = current->lLink;
                }
            else
                {
                    trailCurrent->rLink = current->lLink;
                }
            delete current;
        }
}

template <class Type>
void binarySearchTreeType<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found = false;

    if (this->root == nullptr)
        {
            std::cout << "Cannot delete from an empty tree" << std::endl;
        }
    else
        {
            current = this->root;
            trailCurrent = this->root;

            while (current != nullptr && !found)
                {
                    if (current->info == deleteItem)
                        {
                            found = true;
                        }
                    else
                        {
                            trailCurrent = current;
                            if (current->info > deleteItem)
                                {
                                    current = current->lLink;
                                }
                            else
                                {
                                    current = current->rLink;
                                }
                        }
                }
            if (current == nullptr)
                {
                    std::cout << "The item to be deleted is not in the tree" << std::endl;
                }
            else if (found)
                {
                    if (current == this->root)
                        {
                            deleteFromTree(this->root);
                        }
                    else if (trailCurrent->info > deleteItem)
                        {
                            deleteFromTree(trailCurrent->lLink);
                        }
                    else
                        {
                            deleteFromTree(trailCurrent->rLink);
                        }
                }
            else
                {
                    std::cout << "The item to be deleted is not in binary Search Tree" << std::endl;
                }
        }

}




#endif // BINARYSEARCHTREETYPE_H
