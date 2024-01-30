#include <iostream>
#include <cassert>
#include "orderedLinkedList.h"

using namespace std;

/*
    OVERVIEW:
    A linked list is a collection of objects call nodes
    Each node is compound: It contains info and a link(memory address) that points to the next node
    The link can be seen as the following metaphor: A chain is a collection of links
    The link makes the list
    The address of the first node is stored separately in a location called (Head/First)

                NODE1       NODE2        NODE3
    first--->|date|link|->|date|link|->|data|link|->nullptr

    The order of the nodes is detemined by the link
    ie:Where the link points

    The last link points to null, representing the end

*/

int main()
{
    orderedLinkedList<int> list1, list2;
    int num;

    cout << "Enter numbers into the linkedList, stop with -999: " << endl;
    cin >> num;


    while (num != -999)
        {
            list1.insert(num);
            cout << "Enter a number, stop with -999: " << endl;
            cin >> num;
        }

    cout << endl;

    cout << "List 1: " << endl;
    list1.print();
    cout << endl;

    list2 = list1;

    cout << "List 2: " << endl;
    list2.print();
    cout <<endl;

    cout << "enter the number to be deleted: " << endl;
    cin >> num;
    cout << endl;

    list2.deleteNode(num);

    cout << "After deleting: " << num << " from list 2: " << endl;
    list2.print();
    cout << endl;

    cout << endl << endl << endl << endl;
    cout << "How can we reverse the linked list using recursion? " << endl;
    cout << "Below is a linked list reversed" << endl;
    // call parent method
    list1.printListReverse();


    return 0;
}
