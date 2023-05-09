#ifndef NODESTACKNODE_H
#define NODESTACKNODE_H

#include "TreeNode.hpp"

class NodeStackNode {
    friend class NodeStack;
    
    private:
        TreeNode* data;
        NodeStackNode* link;
    
    public:
        NodeStackNode(TreeNode* n);
};

#endif