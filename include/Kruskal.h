#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "Graph.h"
#include "TreeNode.h"
#include <vector>

class Kruskal
{
    public:
        Kruskal();
        virtual ~Kruskal();
        Kruskal(const Kruskal& other);
        Kruskal& operator=(const Kruskal& other);
        void EraseElementFromVector(vector<TreeNode*>, TreeNode*);
        std::vector<TreeNode*> execute(Graph&);

    protected:

    private:
};

#endif // KRUSKAL_H
