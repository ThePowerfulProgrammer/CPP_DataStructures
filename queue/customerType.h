#ifndef CUSTOMERTYPE_H
#define CUSTOMERTYPE_H


class customerType
{
    public:
        customerType(int cN = 0, int arrvTime = 0, int wTime = 0, int tTime = 0);
        // ctor
        // If no value is specified in the object declaration, the default parameter values are assigned
        // PC: sets customerNumber = cN
        // arrivalTime = arrvTime
        // waitTime = wTime
        // transactionTime = tTime

        void setCustomterInfo(int customerNumber = 0, int arrvTime = 0, int wTime = 0, int tTime = 0);
        // what if we need to update data?
        // PC: sets customerNumber = cN
        // arrivalTime = arrvTime
        // waitTime = wTime
        // transactionTime = tTime

        int getWaitingTime() const;
        // PC: returned waiting time

        void setWaitingTime(int time);
        // PC: waitingTime = time

        void incrementWaitingTime();
        // PC: waitingTime++

        int getArrivalTime() const;
        // PC: returned arrival Time

        int getTransactionTime() const;
        // PC: returned transactionTime

        int getCustomerNumber() const;
        // PC: returned customerNumber
    protected:

    private:
        int customerNumber;
        int arrivalTime;
        int waitingTime;
        int transactionTime;
};


// ctor
customerType::customerType(int cN, int arrvTime, int wTime, int tTime):
    customerNumber(cN),
    arrivalTime(arrvTime),
    waitingTime(wTime),
    transactionTime(tTime)
{

}


void customerType::setCustomterInfo(int cN, int arrvTime, int wTime, int tTime)
{
    customerNumber = cN;
    arrivalTime = arrvTime;
    waitingTime = wTime;
    transactionTime = tTime;
}

int customerType::getWaitingTime() const
{
    return waitingTime;
}

void customerType::setWaitingTime(int time)
{
    waitingTime = time;
}

void customerType::incrementWaitingTime()
{
    waitingTime++;
}

int customerType::getArrivalTime() const
{
    return arrivalTime;
}

int customerType::getTransactionTime() const
{
    return transactionTime;
}

int customerType::getCustomerNumber() const
{
    return customerNumber;
}

#endif // CUSTOMERTYPE_H
