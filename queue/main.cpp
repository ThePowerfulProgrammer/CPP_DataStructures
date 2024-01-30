#include <iostream>
#include "queueType.h"
#include "linkedQueueType.h"
#include "customerType.h"
#include "serverType.h"
#include "serverListType.h"
#include "waitingCustomerQueueType.h"
using namespace std;

void setSimulationParameters(int& sTime, int& numOfServers,int& transTime, int& tBetweenCArrivals)
{
    cout << "Enter the sTime, numOfServers, transTime, tBetweenCArrivals: " ;
    cin >> sTime >> numOfServers >> transTime >> tBetweenCArrivals;
    cout << endl;
}

void runSimulation()
{
    // Declare and initialize variables
    int simulationTime = 100;
    int clock, totalWait = 0, numCustomersArrived = 0, numCustomersServed = 0;
    int numCustomersLeftQueue = 0, numCustomersLeftServers = 0;
    int transTime = 5; // Average transaction time in time units

    // Create instances of required classes
    linkedQueueType<customerType> waitingCustomersQueue;
    serverListType serverList(1); // Assuming one server

    // Main simulation loop
    for (clock = 1; clock <= simulationTime; clock++)
    {
        // Update server transaction times and decrement by one
        serverList.updateServers();

        // Increment waiting time of each customer in queue
        waitingCustomersQueue.updateWaitingQueue();

        // Simulate customer arrival
        double rNum = /* Generate a random number between 0 and 1 */;
        if (rNum <= 0.25)
        {
            // A customer arrives
            customerType newCustomer(clock, 0, 0, transTime);
            waitingCustomersQueue.addQueue(newCustomer);
            numCustomersArrived++;
        }

        // Serve customers
        if (serverList.serverFree(0) && !waitingCustomersQueue.isEmpty())
        {
            customerType servingCustomer = waitingCustomersQueue.front();
            waitingCustomersQueue.deleteQueue();
            totalWait += servingCustomer.getWaitingTime();

            serverList.setServerBusy(0, servingCustomer, transTime);
            numCustomersServed++;
        }
    }

    // Calculate remaining customers in queue and servers
    numCustomersLeftQueue = waitingCustomersQueue.queueLength();
    numCustomersLeftServers = serverList.numBusyServers();

    // Print results
    cout << "Customers left in queue: " << numCustomersLeftQueue << endl;
    cout << "Customers left with servers: " << numCustomersLeftServers << endl;
    cout << "Number of customers arrived: " << numCustomersArrived << endl;
    cout << "Number of customers served: " << numCustomersServed << endl;
}


int main()
{
    linkedQueueType<int> queue;
    int x,y;

    queue.initialiseQueue();
    x = 4;
    y = 5;
    queue.addQueue(x);
    queue.addQueue(y);
    x = queue.front();
    queue.addQueue(x+5);
    queue.addQueue(16);
    queue.addQueue(x);
    queue.addQueue(y-3);

    cout << "Queue elements: ";
    while (!queue.isEmptyQueue())
        {
            cout << queue.front() << " ";
            queue.deleteQueue();
        }
    cout << endl;

    for (int i=0;i<10;i++)
        {
            cout << "\n" << endl;
        }


    return 0;
}
