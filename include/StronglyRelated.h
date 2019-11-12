#ifndef STRONGLYRELATED_H
#define STRONGLYRELATED_H
#include "DFS.h"


class StronglyRelated
{
    friend class Graph;
    public:
        StronglyRelated();
        virtual ~StronglyRelated();
        StronglyRelated(const StronglyRelated& other);
        StronglyRelated& operator=(const StronglyRelated& other);
        void execute(Graph& g);

    protected:

    private:
        DFS dfs;
};

#endif // STRONGLYRELATED_H
