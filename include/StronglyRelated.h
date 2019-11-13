#ifndef STRONGLYRELATED_H
#define STRONGLYRELATED_H
#include "TopologicalSort.h"

class StronglyRelated
{
    friend class Graph;
    public:
        StronglyRelated();
        virtual ~StronglyRelated();
        StronglyRelated(const StronglyRelated& other);
        StronglyRelated& operator=(const StronglyRelated& other);
        int* execute(Graph& g);
        void printLatestTree(); // must not be const

    protected:

    private:
        DFS dfs;
        TopologicalSort tos;
};

#endif // STRONGLYRELATED_H
