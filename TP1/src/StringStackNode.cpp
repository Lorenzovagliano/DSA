#include "StringStackNode.hpp"

StringStackNode::StringStackNode(std::string n){
    this->data = n;
    this->link = nullptr;
}