#include "NodeStack.hpp"

NodeStack::NodeStack(){
    this->top = nullptr; 
}

void NodeStack::push(TreeNode* data){
    NodeStackNode* temp = new NodeStackNode(data);

    if (!temp) {
        std::cout << "\nStack Overflow";
        exit(1);
    }

    temp->data = data;
    temp->link = this->top;
    this->top = temp;
}

bool NodeStack::isEmpty(){
    return top == nullptr;
}

TreeNode* NodeStack::getTop(){
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

void NodeStack::pop(){
    NodeStackNode* temp;

    if (top == nullptr) {
        std::cout << "\nStack Underflow" << std::endl;
        exit(1);
    }
    else {
        temp = top;
        top = top->link;

        free(temp);
    }
}