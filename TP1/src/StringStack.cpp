#include "StringStack.hpp"

StringStack::StringStack(){
    this->top = nullptr; 
}

void StringStack::push(std::string data){
    StringStackNode* temp = new StringStackNode(data);

    if (!temp) {
        std::cout << "\nStack Overflow";
        exit(1);
    }

    temp->data = data;
    temp->link = this->top;
    this->top = temp;
}

bool StringStack::isEmpty(){
    return top == nullptr;
}

std::string StringStack::getTop(){
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

void StringStack::pop(){
    StringStackNode* temp;

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