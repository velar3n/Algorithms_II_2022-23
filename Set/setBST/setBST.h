#pragma once    
#include <iostream>
#include <cstdlib>


struct BSTNode {
    int value;
    BSTNode *left, *right;
    BSTNode() : value(0), left(nullptr), right(nullptr) {}
    BSTNode(const int& item) : value(item), left(nullptr), right(nullptr) {}
    ~BSTNode() {} // destruktor
    public :
        void inorder(BSTNode *node) { //rekurencyjnie
            if (node == nullptr) {
                return;
            }
            inorder(node->left);
            std::cout<<node<<" ";
            inorder(node->right);
        }
        BSTNode *add(BSTNode *node, int x) {
            if (node == nullptr) {
                return new BSTNode(x);
            }
            if (std::rand() % 2) {
                node->left = add(node->left, x);
            } else {
                node->right = add(node->right, x);
            }
            return node; // zwraca nowy korzen
        }

};

class setBST {
    BSTNode *root;
    int size;
public:
    setBST();
    int getSize();  
    void printSet(); 
    void insert(int x);
    void withdraw(BSTNode *node, int x);
    void clearSet(BSTNode *node);
    bool isInSet(BSTNode *node, int x); 
    setBST operator+(setBST& obj);  
    setBST operator*(setBST& obj);   
    setBST operator-(setBST& obj);
    bool operator==(setBST& obj);  
    bool operator<=(setBST& obj);
};
