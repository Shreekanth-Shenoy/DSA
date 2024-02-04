#include<iostream>

using namespace std;

class Node{
public:
    Node(int val):val(val){}
    
    Node* left = nullptr;
    Node* right = nullptr;
    int val;
};

int maxHeight(Node* root){
    if(!root)
        return 0;
    return 1+ max(maxHeight(root->left),maxHeight(root->right));
}


int main() {

    // Creating a sample tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(12);

    cout << "MaxHeight of Tree is : "<<    maxHeight(root);
    cout << endl;

    // Clean up memory (free allocated nodes)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}