#ifndef WEIGHTEDGRAPHTYPE_H
#define WEIGHTEDGRAPHTYPE_H

#include "graphType.h"


class weightedGraphType : public graphType
{
    public:
        void createWeightedGraph();

        void shortestPath(int vertex);

        void printShortestDistance(int vertex);

        weightedGraphType(int size = 0);

        ~weightedGraphType();

    protected:
        double **weights;
        double *smallestWeight;

    private:
};

#endif // WEIGHTEDGRAPHTYPE_H
