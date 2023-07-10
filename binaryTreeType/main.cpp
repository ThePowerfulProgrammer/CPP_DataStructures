#include <iostream>
#include "binarySearchTreeType.h"
using namespace std;

void print(int & x);
void update(int & x);

int main()
{
    binarySearchTreeType<int> treeRoot;
    int num;

    cout << "Enter num ending with -999: ";
    cin >> num;
    while (num != -999)
        {
            treeRoot.insert(num);
            cin >> num;
        }

    cout << endl << "Tree nodes in inorder: " << endl;
    treeRoot.inOrderTraversal(print);
    cout << endl << "Tree height: " ;
    cout << treeRoot.treeHeight() << endl;



    cout << endl <<"Update nodes: " << endl;
    treeRoot.inOrderTraversal(update);

    cout << endl << "After updating" << endl;
    treeRoot.inOrderTraversal(print);

    return 0;
}


void print(int& x)
{
    cout << x << endl;
}


void update(int& x)
{
    x = x * 2;
}
