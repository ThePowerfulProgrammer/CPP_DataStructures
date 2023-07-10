#ifndef BINARYTREETYPE_H
#define BINARYTREETYPE_H
#include <iostream>
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *lLink;
    nodeType<Type> *rLink;
};

template <class Type>
class binaryTreeType
{
    public:
        const binaryTreeType<Type>& operator=(const binaryTreeType<Type>& otherTree);
        // overloads =
        bool isEmpty() const;
        // PC: Returns True if empty else
        // False
        void inOrderTraversal() const;
        // PC: nodes are printed inorder sequence
        void inOrderTraversal(void (*visit) (Type&)) const;
        // An inOrderTraversal that applies the funtion visit to each
        // node
        // PC: Each node visisted has the function visit appplied to it
        void inorder(nodeType<Type> *p,void (*visit) (Type&) ) const;
        void preOrderTraversal() const;
        // PC: Nodes are printed in preorder sequence
        void postOrderTraversal() const;
        // Nodes are printed in preorder sequence
        int treeHeight() const;
        // PC: returns the height of the binary tree
        // height = Number of nodes on the longest path from the root to a leaf
        int treeNodeCount() const;
        // PC: returns number of nodes in a Tree
        int treeLeavesCount() const;
        // PC: returns the number of leaves in the binary Tree
        void destroyTree();
        // PC: Deallocate memory occupied be each node
        virtual bool search(const Type& searchItem) const = 0;
        // PC: Returns true if searchItem in BT, else returns false
        virtual void insert(const Type& insertItem) = 0;
        // PC: if insertItem not in BT, insert insertItem, CHECKS FOR DUPLICATION
        virtual void deleteNode(const Type& deleteItem) = 0;
        // PC: Deletes node is node is in BT, if empty or node not in BT, return appropriate message
        binaryTreeType(const binaryTreeType<Type>& otherTree);
        // copy ctor
        binaryTreeType();
        // default ctor
        ~binaryTreeType();
        // dtor

        /* We can write non-recursive traversal algorithms*/

    protected:
        nodeType<Type> *root;

    private:
        /* p will typically point to root node of binary Tree */

        void copyTree(nodeType<Type>* &copiedTreeRoot,nodeType<Type>* otherTreeRoot);
        // Makes a copy of the binary tree to which otherTree points
        // PC: The pointer copiedTreeRoot points to
        //     the root of the copied binary tree
        void destory(nodeType<Type> * &p);
        // Function to destroy the binary tree to which p points
        // PC: Memory space occupied by each node, in
        //     the binary tree to which p points, is deallocated
        //     p = nullptr
        void inorder(nodeType<Type> *p) const;

        void preorder(nodeType<Type> *p) const;

        void postorder(nodeType<Type> *p) const;

        int height(nodeType<Type> *p) const;

        int max(int x, int y) const;
        // Function to determine the largest between x and y
        // PC: Returns the largest (x,y)
        int nodeCount(nodeType<Type> *p) const;
        // Function to determines the number of nodes on the binary tree to which p points
        // PC: The number of nodes in the binary tree to which p points is returned
        int leavesCount(nodeType<Type> *p) const;
        // Function to determine the number of leaves in the binary tree to which p points
        // PC: The number of leaves in the binary tree to which p points is returned
};

template <class Type>
binaryTreeType<Type>::binaryTreeType()
{
    root = nullptr;
}

template <class Type>
bool binaryTreeType<Type>::isEmpty() const
{
    return (root == nullptr);
}


template <class Type>
void binaryTreeType<Type>::inOrderTraversal() const
{
    inorder(root);
}

template <class Type>
void binaryTreeType<Type>::preOrderTraversal() const
{
    preorder(root);
}

template <class Type>
void binaryTreeType<Type>::postOrderTraversal() const
{
    postorder(root);
}

template <class Type>
int binaryTreeType<Type>::treeHeight() const
{
    return height(root);
}

template <class Type>
int binaryTreeType<Type>::treeNodeCount() const
{
    return nodeCount(root);
}

template <class Type>
int binaryTreeType<Type>::treeLeavesCount() const
{
    return leavesCount(root);
}

template <class Type>
void binaryTreeType<Type>::inorder(nodeType<Type> *p) const
{
    if (p != nullptr)
        {
            inorder(p->lLink);
            std::cout << p->info << " ";
            inorder(p->rLink);
        }
}

template <class Type>
void binaryTreeType<Type>::preorder(nodeType<Type> *p) const
{
    if (p == nullptr)
        {
            std::cout << p->info << " ";
            preorder(p->lLink);
            preorder(p->rLink);
        }
}

template <class Type>
void binaryTreeType<Type>::postorder(nodeType<Type> *p) const
{
    if (p != nullptr)
        {
            postorder(p->lLink);
            postorder(p->rLink);
            std::cout << p->info << " ";
        }
}

template <class Type>
int binaryTreeType<Type>::height(nodeType<Type> *p) const
{
    if (p == nullptr)
        {
            return 0;
        }
    else
        {
            return 1+max(height(p->lLink), height(p->rLink));
        }
}

template <class Type>
int binaryTreeType<Type>::max(int x, int y) const
{
    if (x>= y)
        {
            return x;
        }
    else
        {
            return y;
        }
}

template <class Type>
int binaryTreeType<Type>::nodeCount(nodeType<Type> * p) const
{
    if (p == nullptr)
        {
            return 0;
        }
    else
        {
            int leftCount = nodeCount(p->lLink);
            int rightCount = nodeCount(p->rLink);
            return leftCount + rightCount + 1; // Each stack call will sum results , add 1 for root node
        }
}


template<typename Type>
int binaryTreeType<Type>::leavesCount(nodeType<Type> *p) const {
    if (p == nullptr) {
        // Base case: an empty tree has zero leaves
        return 0;
    } else if (p->left == nullptr && p->right == nullptr) {
        // Base case: a tree with only one node is a leaf
        return 1;
    } else {
        // Recursively count leaves in the left and right subtrees
        int leftCount = leavesCount(p->left);
        int rightCount = leavesCount(p->right);

        return leftCount + rightCount;
    }
}


template <class Type>
void binaryTreeType<Type>::copyTree(nodeType<Type>* &copiedTreeRoot, nodeType<Type>* otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
        {
            copiedTreeRoot = nullptr;
        }
    else
        {
            copiedTreeRoot = new nodeType<Type>;
            copiedTreeRoot->info = otherTreeRoot->info;
            copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
            copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
        }
}

template <class Type>
void binaryTreeType<Type>::destory(nodeType<Type> * &p)
{
    if (p != nullptr)
        {
            destory(p->lLink);
            destory(p->rLink);
            delete p;
            p = nullptr;
        }
}

template <class Type>
void binaryTreeType<Type>::destroyTree()
{
    destroy(root);
}

template <class Type>
binaryTreeType<Type>::binaryTreeType(const binaryTreeType<Type> & otherTree)
{
    if (otherTree.root == nullptr)
        {
            root = nullptr;
        }
    else
        {
            copyTree(root, otherTree.root);
        }
}

template <class Type>
binaryTreeType<Type>::~binaryTreeType()
{
    destory(root);
}

template <class Type>
const binaryTreeType<Type>& binaryTreeType<Type>::operator=(const binaryTreeType<Type>& otherTree)
{
    if (this != &otherTree)
        {
            if (root != nullptr)
                {
                    destroy(root);
                }
            if (otherTree.root == nullptr)
                {
                    root = nullptr;
                }
            else
                {
                    copyTree(root, otherTree.root);
                }
        }
    return *this;
}

template <class Type>
void binaryTreeType<Type>::inOrderTraversal(void (*visit) (Type&)) const
{
    inorder(root,visit);
}

template <class Type>
void binaryTreeType<Type>::inorder(nodeType<Type>* p, void (*visit) (Type& item)) const
 {
    if (p != nullptr)
        {
            inorder(p->lLink,*visit);
            (*visit) (p->info);
            inorder(p->rLink, *visit);
        }
 }
 #endif // BINARYTREETYPE_H
