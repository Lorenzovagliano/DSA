#ifndef TREENODE_H
#define TREENODE_H

#include <string>

using namespace std;

class TreeNode {
    friend class NodeStackNode;
    
    public:
        string val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(string x);
};

#endif