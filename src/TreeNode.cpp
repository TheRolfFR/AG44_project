#include <iostream>
#include "TreeNode.h"

TreeNode::TreeNode() : parent(), id(), children()
{
    //ctor
}

TreeNode::TreeNode(int id, TreeNode* parent) {
    this->parent = parent;
    this->id = id;
    this->children = std::vector<TreeNode>();
    std::cout << children.size();
}

TreeNode::~TreeNode()
{
    //dtor
}

TreeNode::TreeNode(const TreeNode& other) : parent(other.parent), id(other.id), children(other.children)
{
    //copy ctor
}

TreeNode& TreeNode::operator=(const TreeNode& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->parent = rhs.parent;
    this->id = rhs.id;
    this->children = rhs.children;

    return *this;
}

TreeNode& TreeNode::addLeaf(int id) {
    this->children.push_back(TreeNode(id, this));

    return this->children.back();
}

TreeNode* TreeNode::getParent() {
    return this->parent;
}

TreeNode* TreeNode::getChild(int theId) {
    TreeNode* result = NULL;
    TreeNode& me = *this;
    if(this->id == theId) {
            result = this;
    }

    int i = 0;
    while(i < (int) children.size() && result == NULL) {
        result = children[i].getChild(theId);

        ++i;
    }

    return result;
}
