#ifndef QUEUEADT_H
#define QUEUEADT_H


template <class Type>
class queueADT
{
    public:
        virtual bool isEmptyQueue() const = 0;
        // PC: return whether or not queue is empty

        virtual bool isFullQueue() const = 0;
        // PC: return whether or not queue is full

        virtual void initialiseQueue() = 0;
        // PC: The queue is set to empty

        virtual Type front() const = 0;
        // PreCon: Queue exists and is not empty
        // PC: returns front of queue

        virtual Type back() const = 0;
        // PreCon: Queue exists
        // PC: returns back of queue

        virtual void addQueue(const Type& queueElement) = 0;
        // PreCon: Queue exists and is not empty
        // PC: add queueElement to queue

        virtual void deleteQueue() = 0;
        // PreCon: Queue exists and is not empty
        // delete element from front of queue

};
#endif // QUEUEADT_H
