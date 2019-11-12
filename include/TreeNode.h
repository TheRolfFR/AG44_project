#ifndef TREENODE_H
#define TREENODE_H
#include <vector>

class TreeNode
{
    public:
        TreeNode();
        TreeNode(int, TreeNode*);
        virtual ~TreeNode();
        TreeNode(const TreeNode& other);
        TreeNode& operator=(const TreeNode& other);
        TreeNode* getParent();
        TreeNode& addLeaf(int);
        TreeNode* getChild(int);

    protected:

    private:
        TreeNode* parent;
        int id;
        std::vector<TreeNode> children;
};

#endif // TREENODE_H
