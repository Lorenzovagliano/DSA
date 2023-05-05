#include "Node.hpp"
#include "StackNode.hpp"
#include "Stack.hpp"
#include <string>

// Function to check if a given token is an operator
bool isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
        return true;
    }
    else{
        return false;
    }
}
 
// Print the postfix expression for an expression tree
void postorder(Node* root){
    if(root == nullptr){
        return;
    }
 
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data;
}
 
// Print the infix expression for an expression tree
void inorder(Node* root){
    if(root == nullptr){
        return;
    }
 
    // if the current token is an operator, print open parenthesis
    if(isOperator(root->data)){
        std::cout << "(";
    }
 
    inorder(root->left);
    std::cout << root->data;
    inorder(root->right);
 
    // if the current token is an operator, print close parenthesis
    if(isOperator(root->data)){
        std::cout << ")";
    }
}
 
// Function to construct an expression tree from the given postfix expression
Node* construct(std::string postfix){
    // base case
    if(postfix.length() == 0){
        return nullptr;
    }
 
    // create an empty stack to store tree pointers
    Stack s;
 
    // traverse the postfix expression
    for(char c: postfix){
        // if the current token is an operator
        if(isOperator(c)){
            // pop two nodes `x` and `y` from the stack
            Node* x = s.getTop();
            s.pop();
 
            Node* y = s.getTop();
            s.pop();
 
            // construct a new binary tree whose root is the operator and whose
            // left and right children point to `y` and `x`, respectively
            Node* node = new Node(c, y, x);
 
            // push the current node into the stack
            s.push(node);
        }
 
        // if the current token is an operand, create a new binary tree node
        // whose root is the operand and push it into the stack
        else{
            s.push(new Node(c));
        }
    }
 
    // a pointer to the root of the expression tree remains on the stack
    return s.getTop();
}
 
int main(){
    std::string postfix = "ab+cde+**";
    Node* root = construct(postfix);
 
    std::cout << "Postfix Expression: ";
    postorder(root);
 
    std::cout << "\nInfix Expression: ";
    inorder(root);
 
    return 0;
}