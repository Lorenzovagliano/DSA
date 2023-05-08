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
    std::string result;
    for(char c : postfix){
        if(!isspace(c)){
            result += c;
        }
    }
    postfix = result;

    // base case
    if(postfix.length() == 0){
        return nullptr;
    }
 
    // create an empty stack to store tree pointers
    NodeStack s;
 
    // traverse the postfix expression
    for(int i = 0; i < postfix.size(); i++){
        char c = postfix[i];
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

Node* constructInfix(std::string& s){
 
    // Stack to hold nodes
    NodeStack stN;
 
    // Stack to hold chars
    CharStack stC;
    Node* t; Node* t1; Node* t2;
 
    // Prioritising the operators
    int p[123] = { 0 };
    p['+'] = p['-'] = 1, p['/'] = p['*'] = 2, p['^'] = 3,
    p[')'] = 0;
 
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(') {
 
            // Push '(' in char stack
            stC.push(s[i]);
        }
 
        // Push the operands in node stack
        else if (isalpha(s[i]) || isdigit(s[i]))
        {
            t = new Node(s[i]);
            stN.push(t);
        }
        else if (p[s[i]] > 0)
        {
            // If an operator with lower or
            // same associativity appears
            while (
                !stC.isEmpty() && stC.getTop() != '('
                && ((s[i] != '^' && p[stC.getTop()] >= p[s[i]])
                    || (s[i] == '^'
                        && p[stC.getTop()] > p[s[i]])))
            {
 
                // Get and remove the getTop element
                // from the character stack
                t = new Node(stC.getTop());
                stC.pop();
 
                // Get and remove the getTop element
                // from the node stack
                t1 = stN.getTop();
                stN.pop();
 
                // Get and remove the currently getTop
                // element from the node stack
                t2 = stN.getTop();
                stN.pop();
 
                // Update the tree
                t->left = t2;
                t->right = t1;
 
                // Push the node to the node stack
                stN.push(t);
            }
 
            // Push s[i] to char stack
            stC.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!stC.isEmpty() && stC.getTop() != '(')
            {
                t = new Node(stC.getTop());
                stC.pop();
                t1 = stN.getTop();
                stN.pop();
                t2 = stN.getTop();
                stN.pop();
                t->left = t2;
                t->right = t1;
                stN.push(t);
            }
            stC.pop();
        }
    }
    t = stN.getTop();
    return t;
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