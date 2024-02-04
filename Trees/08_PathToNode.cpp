#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Node{
public:
    Node(int val):val(val){}
    
    Node* left = nullptr;
    Node* right = nullptr;
    int val;
};

bool pathFromRootToNode(Node* root,int nodeVal,vector<int>& path){
    if(!root){
        return false;
    }

    path.push_back(root->val);

    if(root->val == nodeVal){
        return true;
    }

    bool leftPath = pathFromRootToNode(root->left,nodeVal,path);
    bool rightPath = pathFromRootToNode(root->right,nodeVal,path);

    if(leftPath || rightPath){
        return true;
    }

    path.pop_back();
    return false;


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
    
    vector<int> result;
    pathFromRootToNode(root,6,result);

    for(int node: result){
        cout << node << " ";

    }

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