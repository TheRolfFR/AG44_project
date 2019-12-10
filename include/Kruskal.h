#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "Graph.h"
#include "TreeNode.h"
#include <vector>
#include <set>

class Kruskal
{
    public:
        Kruskal();
        virtual ~Kruskal();
        Kruskal(const Kruskal& other);
        Kruskal& operator=(const Kruskal& other);
        void EraseElementFromVector(std::vector<TreeNode*>, TreeNode*);
        set<Edge*> execute(Graph&);
        void printResult(const set<Edge*>& edges);

    protected:

    private:
        bool containsAtMostOne(const set<Vertice*> vertices, Vertice* u, Vertice* v);
        bool contains(const set<Vertice*> vertices, Vertice* u);
};

#endif // KRUSKAL_H
