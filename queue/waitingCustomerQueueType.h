#ifndef WAITINGCUSTOMERQUEUETYPE_H
#define WAITINGCUSTOMERQUEUETYPE_H
#include "customerType.h"
#include <queueType.h>


class waitingCustomerQueueType : public queueType<customerType>
{
    public:
        waitingCustomerQueueType(int size = 100);
        // CTOR
        // PC: Initialise queue to param size, size is passed to the ctor of queueType

        void updateWaitingQueue();
        // PC: incremented waiting time of each customer in the queue by one unit.

    protected:

    private:
};

waitingCustomerQueueType::waitingCustomerQueueType(int size) :queueType<customerType>(size)
{

}

void waitingCustomerQueueType::updateWaitingQueue()
{
    customerType cust;

    cust.setWaitingTime(-1);
    int wTime = 0;

    addQueue(cust);

    while (wTime != -1)
        {
            cust = front();
            deleteQueue();

            wTime = cust.getWaitingTime();
            if (wTime == -1)
                {
                    break;
                }
            cust.incrementWaitingTime();
            this->addQueue(cust);
        }
}

#endif // WAITINGCUSTOMERQUEUETYPE_H
