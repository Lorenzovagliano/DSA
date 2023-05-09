#include "Node.hpp"

Node::Node(std::string data){
    this->data = data;
    this->left = this->right = nullptr;
}

Node::Node(std::string data, Node *left, Node *right){
    this->data = data;
    this->left = left;
    this->right = right;
};