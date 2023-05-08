#include "NodeStackNode.hpp"

NodeStackNode::NodeStackNode(Node* n){
    this->data = n;
    this->link = nullptr;
}