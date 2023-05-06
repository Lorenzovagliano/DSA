#include "StackNode.hpp"

StackNode::StackNode(Node* n){
    this->data = n;
    this->link = nullptr;
}