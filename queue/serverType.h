#ifndef SERVERTYPE_H
#define SERVERTYPE_H
#include "customerType.h"

class serverType
{
    public:
        serverType();

        bool isFree() const;

        void setBusy();

        void setFree();

        void setTransactionTime(int t);

        void setTransactionTime();

        int getRemainingTransactionTime() const;

        void decreaseTransactionTime();

        void setCurrentCustomer(customerType cCustomer);

        int getCurrentCustomerNumber() const;

        int getCurrentCustomerArrivalTime() const;

        int getCurrentCustomerWaitingTime() const;

        int getCurrentCustomerTransactionTime() const;

    protected:

    private:
        customerType currentCustomer;
        string status;
        int transactionTime;
};

serverType::serverType()
{
    status = "Free";
    transactionTime = 0;
}

bool serverType::isFree() const
{
    return status == "Free";
}

void serverType::setBusy()
{
    status = "Busy";
}

void serverType::setFree()
{
    status = "Free";
}

void serverType::setTransactionTime(int t)
{
    transactionTime = t;
}

void serverType::setTransactionTime()
{
    int time;

    time = currentCustomer.getTransactionTime();

    transactionTime = time;
}

int serverType::getRemainingTransactionTime() const
{
    return transactionTime;
}

void serverType::decreaseTransactionTime()
{
    transactionTime--;
}

void serverType::setCurrentCustomer(customerType cCustomer)
{
    int customerN = cCustomer.getCustomerNumber();
    int arrTime = cCustomer.getArrivalTime();
    int wTime = cCustomer.getWaitingTime();
    int tTime = cCustomer.getTransactionTime();

    // dude I could create a new customer object, and since customerType has no pointers, I could just do customer = CCustomer to copy all values
    currentCustomer.setCustomterInfo(customerN,arrTime,wTime,tTime);
}

int serverType::getCurrentCustomerNumber() const
{
    return currentCustomer.getCustomerNumber();
}

int serverType::getCurrentCustomerArrivalTime() const
{
    return currentCustomer.getArrivalTime();
}

int serverType::getCurrentCustomerWaitingTime() const
{
    return currentCustomer.getWaitingTime();
}

int serverType::getCurrentCustomerTransactionTime() const
{
    return currentCustomer.getTransactionTime();
}


#endif // SERVERTYPE_H
