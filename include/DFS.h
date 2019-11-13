#ifndef DFS_H
#define DFS_H
#include "Graph.h"
#include "TreeNode.h"

class DFS
{
    public:
        DFS();
        virtual ~DFS();
        DFS(const DFS& other);
        DFS& operator=(const DFS& other);

        int* execute(Graph&, Vertice*);
        int* execute(Graph&, int*);
        void print(const Graph&, int*);

    protected:

    private:
        void visit(Graph&, Vertice*);
        int time;
        vector<int*>lastResults;
        vector<vector<TreeNode*>> lastTrees;
        int resultIndex;
};

#endif // DFS_H
