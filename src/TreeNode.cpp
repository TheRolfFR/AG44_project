#include <iostream>
#include "TreeNode.h"

TreeNode::TreeNode() : parent(), id(), children()
{
    //ctor
}

TreeNode::TreeNode(int id, TreeNode* parent) : parent(), id(), children() {
    this->parent = parent;
    this->id = id;
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
    this->id = rhs.id;
    this->children = rhs.children;
    this->parent = rhs.parent;

    return *this;
}

TreeNode& TreeNode::addLeaf(int id) {
    this->children.push_back(TreeNode(id, this));

    return this->children.back();
}

TreeNode* TreeNode::getParent() {
    return this->parent;
}

TreeNode* TreeNode::getChild(int id) {
    TreeNode* result = NULL;
    if(this->id == id) { result = this; }

    int i = 0;
    while(i < (int) children.size() && result == NULL) {
        result = children[i].getChild(id);

        ++i;
    }

    return result;
}
