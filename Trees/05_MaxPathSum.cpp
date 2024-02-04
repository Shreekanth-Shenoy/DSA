#include<iostream>
#include <climits>
using namespace std;

class Node{
public:
    Node(int val):val(val){}
    
    Node* left = nullptr;
    Node* right = nullptr;
    int val;
};

int maxPathSum(Node* root,int& result){
    if(!root)
        return 0;
    int lh = max(0,maxPathSum(root->left,result));
    int rh = max(0,maxPathSum(root->right,result));
    result = max((root->val + max(lh, rh)),result);
    return root->val + max(lh, rh);
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
    root->right->right->right->right = new Node(20);
    root->right->right->right->right->left = new Node(34);
    int result = INT_MIN;
    cout << "maxPathSum is  " << maxPathSum(root,result) << endl;

    // Clean up memory (free allocated nodes)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root->right->right->right;
    delete root->right->right->right->right;
    delete root;

    return 0;
}