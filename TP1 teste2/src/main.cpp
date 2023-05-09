#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include <chrono>

#include "TreeNode.hpp"
#include "NodeStack.hpp"
#include "StringStack.hpp"

using namespace std;

bool isOperator(string c){
    return c == "+" || c == "-" || c == "*" || c == "/";
}

int getOperatorPrecedence(string op){
    if(op == "+" || op == "-") return 1;
    if(op == "*" || op == "/") return 2;
    return 0;
}

float evaluate(float a, float b, string op){
    if(op == "+") return a + b;
    if(op == "-") return a - b;
    if(op == "*") return a * b;
    if(op == "/") return a / b;
    return 0;
}

TreeNode* buildPostfixExpressionTree(string postfix){
    NodeStack st;
    stringstream ss(postfix);
    string token;
    while(ss >> token){
        if(isOperator(token)){
            TreeNode* node = new TreeNode(token);
            node->right = st.getTop();
            st.pop();
            node->left = st.getTop();
            st.pop();
            st.push(node);
        } 
        else{
            TreeNode* node = new TreeNode(token);
            st.push(node);
        }
    }
    return st.getTop();
}

float evaluatePostfixExpressionTree(TreeNode* root){
    if(!root){
        return 0;
    }

    if(!root->left && !root->right){
        return stof(root->val);
    }

    float left = evaluatePostfixExpressionTree(root->left);
    float right = evaluatePostfixExpressionTree(root->right);

    if(right == 0 && root->val == "/"){
        cout << "Divisão por zero: ERRO\n";
    }
    return evaluate(left, right, root->val);
}

void postfixToInfix(TreeNode* root){
    if(!root) return;
    if(!root->left && !root->right){
        cout << root->val << " ";
        return;
    }
    cout << "( ";
    cout << "( ";
    postfixToInfix(root->left);
    cout << ") ";
    cout << root->val << " ";
    cout << "( ";
    postfixToInfix(root->right);
    cout << ") ";
    cout << ") ";
}

TreeNode* buildInfixExpressionTree(string infix){
    NodeStack st;
    StringStack op_st;
    stringstream ss(infix);
    string token;
    while (ss >> token){
        if(token == "("){
            op_st.push(token);
        } 
        
        else if(token == ")"){
            while(op_st.getTop() != "("){
                TreeNode* node = new TreeNode(op_st.getTop());
                op_st.pop();
                node->right = st.getTop();
                st.pop();
                node->left = st.getTop();
                st.pop();
                st.push(node);
            }
            op_st.pop();
        } 
        
        else if(isOperator(token)){
            while(!op_st.isEmpty() && op_st.getTop() != "(" && getOperatorPrecedence(token) <= getOperatorPrecedence(op_st.getTop())){
                TreeNode* node = new TreeNode(op_st.getTop());
                op_st.pop();
                node->right = st.getTop();
                st.pop();
                node->left = st.getTop();
                st.pop();
                st.push(node);
            }
            op_st.push(token);
        } 
        else{
            TreeNode* node = new TreeNode(token);
            st.push(node);
        }
    }
    while(!op_st.isEmpty()){
        TreeNode* node = new TreeNode(op_st.getTop());
        op_st.pop();
        node->right = st.getTop();
        st.pop();
        node->left = st.getTop();
        st.pop();
        st.push(node);
    }
    return st.getTop();
}

float evaluateInfixExpressionTree(TreeNode* root){
    if(!root){
        return 0;
    }

    if(!root->left && !root->right){
       return stof(root->val); 
    }

    float left = evaluateInfixExpressionTree(root->left);
    float right = evaluateInfixExpressionTree(root->right);

    if(right == 0 && root->val == "/"){
        cout << "Divisão por zero: ERRO\n";
    }
    return evaluate(left, right, root->val);
}

void infixToPostfix(TreeNode* root){
    if(!root){
        return;
    }
    
    bool hasLeftChild = (root->left != nullptr);
    bool hasRightChild = (root->right != nullptr);
    bool hasChildren = hasLeftChild || hasRightChild;
    infixToPostfix(root->left);
    infixToPostfix(root->right);
    cout << root->val << " ";
}

int main() {
    string comando;
    string comando2;
    string posfixa;
    string infixa;

    cout << "Comandos:" << endl;
    cout << "\tLER INFIXA <expressão infixa>:  " << "Registra um expressão infixa.\n";
    cout << "\tLER POSFIXA <expressão posfixa>:  " << "Registra um expressão posfixa.\n";
    cout << "\tPOSFIXA:  " << "Converte um expressão infixa em posfixa.\n";
    cout << "\tINFIXA:  " << "Converte um expressão posfixa em infixa.\n";
    cout << "\tRESOLVE:  " << "Gera o resultado de uma expressão. A função usada para cálcular vai depender do tipo da expressão registrada por LER.\n" << endl;
    cout << "Expressões devem estar no formato correto, como exemplificadas pelas entradas de teste disponibilizadas\n";
    cout << "Formatos:  Infixa: ( ( 1 ) + ( 2 ) )    Posfixa:  1 2 +\n";
    cout << "Insira o input. Ele deve ser feito linha por linha, NÃO COPIE INPUTS COM MAIS DE UMA LINHA.\n";
    cout << "Input:\n";
    while(cin >> comando){
        if(comando == "LER"){
            while(cin >> comando2){
                if(comando2 == "POSFIXA"){
                    while(getline(cin, posfixa)){
                        TreeNode* postFixRoot = buildPostfixExpressionTree(posfixa);
                        cout << "Posfixa lida: " << posfixa  << endl;
                        break;
                    }
                    break;
                }
                else if(comando2 == "INFIXA"){
                    while(getline(cin, infixa)){
                        TreeNode* inFixRoot = buildPostfixExpressionTree(infixa);
                        cout << "Infixa lida: " << infixa  << endl;
                        break;
                    }
                    break;
                }
                else{
                    cout << "Comando inválido\n";
                }
            }
        }

        else if(comando == "INFIXA"){
            TreeNode* postFixRoot = buildPostfixExpressionTree(posfixa);
            cout << "Expressão posfixa convertida para infixa: ";
            postfixToInfix(postFixRoot);
            cout << '\n';
        }
        
        else if(comando == "POSFIXA"){
            TreeNode* inFixRoot = buildInfixExpressionTree(infixa);
            cout << "Expressão infixa convertida para posfixa: ";
            infixToPostfix(inFixRoot);
            cout << '\n';
        }

        else if(comando == "RESOLVE"){
            if(comando2 == "POSFIXA"){
                TreeNode* postFixRoot = buildPostfixExpressionTree(posfixa);
                cout << "Resolução da expressão posfixa: ";
                cout << evaluatePostfixExpressionTree(postFixRoot) << endl;
            }
            else if(comando2 == "INFIXA"){
                TreeNode* inFixRoot = buildInfixExpressionTree(infixa);
                cout << "Resolução da expressão infixa: ";
                cout << evaluateInfixExpressionTree(inFixRoot) << endl;
            }
            break;
        }
    }

    return 0;
}
