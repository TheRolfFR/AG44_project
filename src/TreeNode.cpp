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

void TreeNode::print() {
    // printing pretty message
    std::cout << std::endl;
    this->print(0);
}

void TreeNode::print(int spaces) {
    // first print the spaces
    for(int i = 0; i < spaces; ++i) { std::cout << "|"; }

    // print id and go to line
    std::cout << id << std::endl;

    // then print the children
    for(int i = 0; i < (int) children.size(); ++i) { children[i].print(spaces+1); }
}
