#ifndef TREENODE_H
#define TREENODE_H
#include <vector>

class TreeNode
{
    friend class Kruskal;
    public:
        TreeNode();
        TreeNode(int, TreeNode*);
        virtual ~TreeNode();
        TreeNode(const TreeNode& other);
        TreeNode& operator=(const TreeNode& other);
        TreeNode* getParent();
        TreeNode* addLeaf(int);
        TreeNode* getChild(int);
        void addChild(TreeNode*);
        void print();
    private:
        void print(int);

        TreeNode* parent;
        int id;
        std::vector<TreeNode*> children;
};

#endif // TREENODE_H
