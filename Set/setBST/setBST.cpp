#include <iostream>
#include <cstdlib>
#include <stack>
#include "setBST.h"



setBST::setBST() : root(nullptr), size(0) {}

int setBST::getSize() {
    return size;
}

void setBST::printSet() { //z użyciem przejścia przez drzewo inorder 
    std::cout << "{ ";
    root->inorder(root);
    std::cout<<"}"<<std::endl;
}

void setBST::insert(int x) {
    if(!isInSet(root, x)) {
        root = root->add(root, x);
        size++;
    }
}

/*void setBST::withdraw(BSTNode *node, int x) {
    if(!isInSet(root, x)) {
        return;
    }
    
}*/

void clearSet(BSTNode *node) {
    if(node->left!=nullptr) {
        clearSet(node->left);
    }
    if(node->right!=nullptr) {
        clearSet(node->right);
    }
    delete node;
}

bool setBST::isInSet(BSTNode* node, int x) {
    if (node == nullptr) {
        return false;
    }
    if(node->value == x) {
        return true;
    }
    return isInSet(node->left, x) | isInSet(node->right, x);
}

setBST setBST::operator+(setBST& obj) {
    setBST newSet;
    std::stack<BSTNode> nodeStack;
    std::stack<BSTNode> nodeStack1;
    nodeStack.push(root);
    nodeStack1.push(obj.root);

    while(!nodeStack.empty()) {
        BSTNode* node;
        node = nodeStack.top();
        nodeStack.pop();
        newSet.insert(node->value);

        if(node->right) {
            nodeStack.push(node->right);
        }
        if(node->left) {
            nodeStack.push(node->left);
        }
    }

    while (!nodeStack1.empty()) {
        BSTNode* node;
        node = nodeStack1.top();
        nodeStack1.pop();
        newSet.insert(node->value);

        if(node->right) {
            nodeStack1.push(node->right);
        }
        if(node->left) { 
            nodeStack1.push(node->left);
        }
    }
    return newSet;
}

setBST setBST::operator*(setBST& obj) {
    setBST newSet;
    std::stack<BSTNode> nodeStack;
    nodeStack.push(root);
 
    while(!nodeStack.empty()) {
        BSTNode* node;
        node = nodeStack.top();
        nodeStack.pop();
        if(obj.isInSet(node->value)) {
            newSet.insert(node->value);
        }
        if(node->right) {
            nodeStack.push(node->right);
        }
        if(node->left) {
            nodeStack.push(node->left);
        }
    }
    return newStack;
}

setBST setBST::operator-(setBST& obj) {
    setBST newSet;
    std::stack<BSTNode> nodeStack;
    nodeStack.push(this->root);
 
    while(!nodeStack.empty()) {
        BSTNode* node;
        node = nodeStack.top();
        nodeStack.pop();
        if(!obj.isInSet(node->value)) {
            newSet.insert(node->value);
        }
        if(node->right) {
            nodeStack.push(node->right);
        }
        if(node->left) {
            nodeStack.push(node->left);
        }
    }
    return newSet;
}

bool setBST::operator==(setBST& obj) {
    if(size != obj.getSize()) {
        return false;
    }
    std::stack<BSTNode> nodeStack;
    nodeStack.push(this->root);

    while (!nodeStack.empty()) {
        BSTNode* node;
        node = nodeStack.top();
        nodeStack.pop();
        if(!obj.isInSet(node->value)) {
            return false;
        }
        if(node->right) {
            nodeStack.push(node->right);
        }
        if(node->left) {
            nodeStack.push(node->left);
        }
    }
    return true;
}

bool setBST::operator<=(setBST& obj) {
    if(size < obj.getSize()) {
        return false;
    }
    std::stack<BSTNode> nodeStack;
    nodeStack.push(this->obj.root);

    while (!nodeStack.empty()) {
        BSTNode* node;
        node = nodeStack.top();
        nodeStack.pop();
        if(!isInSet(node->value)) {
            return false;
        }
        if(node->right) {
            nodeStack.push(node->right);
        }
        if(node->left) {
            nodeStack.push(node->left);
        }
    }
    return true;
}
