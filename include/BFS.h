#ifndef BFS_H
#define BFS_H
#include "Graph.h"


class BFS
{
    public:
        BFS();
        virtual ~BFS();
        BFS(const BFS& other);
        BFS& operator=(const BFS& other);
        int* execute(Graph&, Vertice* s);
        void printResult(int* result, Graph& graph);
    private:
        void visit(Vertice* s);
        vector<int*> lastResults;
        int resultIndex;
};

#endif // BFS_H
