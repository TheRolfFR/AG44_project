#include "Kruskal.h"
#include <bits/stdc++.h>
#include <limits>

Kruskal::Kruskal()
{
    //ctor
}

Kruskal::~Kruskal()
{
    //dtor
}

Kruskal::Kruskal(const Kruskal& other)
{
    //copy ctor
}

Kruskal& Kruskal::operator=(const Kruskal& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Kruskal::EraseElementFromVector(vector<TreeNode*> myvector, TreeNode* node) {
    if(node == NULL)
        return;

    int i = 0;
    int foundIndex = -1;
    while(i < (int) myvector.size() && foundIndex != -1) {
        if(myvector[i]->id == node->id)
            foundIndex = i;

        ++i;
    }
}

std::vector<TreeNode*> Kruskal::execute(Graph& g) {
            std::cout << "coucou";
    // creating a result
    std::vector<TreeNode*> result = std::vector<TreeNode*>();

    //sorting the edges by increasing order
    sort(g.listEdge.begin(), g.listEdge.end());
    // for each edge
    for(int edgeIndex = 0; edgeIndex < (int) g.listEdge.size(); ++edgeIndex) {

        Edge& tmpEdge = g.listEdge[edgeIndex];

        // if there is no result yet
        if(result.size() == 0) {
            // create a root
            TreeNode* root = new TreeNode(tmpEdge.src->getId(), NULL);
            // and create its leaf
            root->addLeaf(tmpEdge.dst->getId());

            // then push the root
            result.push_back(root);
        } else {
            // try to find one of the destination
            TreeNode* srcNode = NULL;
            TreeNode* dstNode = NULL;
            int resultIndex = 0;

            // try to search
            while(resultIndex < (int) result.size() && (srcNode == NULL || dstNode == NULL)) {
                srcNode = result[resultIndex]->getChild(tmpEdge.src->getId());
                dstNode = result[resultIndex]->getChild(tmpEdge.dst->getId());

                ++resultIndex;
            }

            // if you found already 2 trees
            if(srcNode != NULL && dstNode != NULL) {
                //if dst node is a root
                if(dstNode->parent == NULL) {
                    // add it to the source tree children
                    srcNode->addChild(dstNode);
                    EraseElementFromVector(result, dstNode);
                } // else if the source node is a root
                else if(srcNode->parent == NULL) {
                    dstNode->addChild(srcNode);
                    EraseElementFromVector(result, srcNode);
                } // else add it if does not a loop
            } else {
                // if he didn't found any common point
                if(srcNode == NULL && dstNode == NULL) {
                    // add a root and its child
                    TreeNode* root = new TreeNode(tmpEdge.src->getId(), NULL);
                    root->addLeaf(tmpEdge.dst->getId());
                    // then push the root
                    result.push_back(root);
                } // if only the src node cannot be found
                else if(srcNode == NULL) {
                    // add a leaf with src id
                    dstNode->addLeaf(tmpEdge.src->getId());
                } // else the dst node cannot be found
                else {
                    srcNode->addLeaf(tmpEdge.src->getId());
                }
            }
        }
    }

    return result;
}

void Kruskal::print(std::vector<TreeNode*> trees) {
    for(int i = 0; i < (int) trees.size(); ++i) {
        trees[i]->print();
    }
}
