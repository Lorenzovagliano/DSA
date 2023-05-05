#include "Node.hpp"

Node::Node(char data){
    this->data = data;
    this->left = this->right = nullptr;
}

Node::Node(char data, Node *left, Node *right){
    this->data = data;
    this->left = left;
    this->right = right;
};