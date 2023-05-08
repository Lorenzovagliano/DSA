#include "Node.hpp"
#include "NodeStack.hpp"
#include "CharStack.hpp"
#include "IntStack.hpp"
#include <string>
#include <stack>

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
    std::cout << root->data << ' ';
}
 
// Print the infix expression for an expression tree
void inorder(Node* root){
    if(root == nullptr){
        return;
    }
 
    // if the current token is an operator, print open parenthesis
    if(isOperator(root->data)){
        std::cout << "( ";
    }
 
    inorder(root->left);
    std::cout << root->data << ' ';
    inorder(root->right);
 
    // if the current token is an operator, print close parenthesis
    if(isOperator(root->data)){
        std::cout << " ) ";
    }
}
 
// Function to construct an expression tree from the given postfix expression
Node* constructPostfix(std::string postfix){
}

Node* constructInfix(std::string& s){
}

int evaluatePostfix(std::string exp)
{
    // Create a stack of capacity equal to expression size
    IntStack st;
 
    // Scan all characters one by one
    for (int i = 0; i < exp.size(); ++i) {
        if(isOperator(exp[i])){
            int val1 = st.getTop();
            st.pop();
            int val2 = st.getTop();
            st.pop();
            switch (exp[i]) {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            }
        }
        else{
            st.push(exp[i] - '0');
        }
    }
    return st.getTop();
}

Node* buildTree(std::string choice, std::string argument){
    if(choice == "postfix"){
        return constructPostfix(argument);
    }
    else if(choice == "infix"){
        return constructInfix(argument);
    }
    else{
        std::cout << "Invalid choice\n";
    }
}
 
int main(){
    std::string postfix = " 1 2 + 1 1 2 + * *";
    Node* root = constructPostfix(postfix);
    std::cout << "\nEvaluate postfix: " << evaluatePostfix(postfix) << std::endl;
 
    std::cout << "Postfix Expression: ";
    postorder(root);
 
    std::cout << "\nInfix Expression: ";
    inorder(root);

    std::cout << "\nEvaluate postfix: " << evaluatePostfix(postfix) << std::endl;

    //std::cout << '\n' << evaluatePostfix(postfix);

    /*std::string infix = "( ( 5 + 2 ) * ( 37 * ( 4 + 5 ) ) )";
    Node* root = constructInfix(infix);

    std::cout << "Infix Expression: ";
    inorder(root);

    std::cout << "\nPostfix Expression: ";
    postorder(root);*/
 
    return 0;
}