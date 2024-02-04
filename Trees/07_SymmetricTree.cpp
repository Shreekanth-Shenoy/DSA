#include<iostream>

using namespace std;

class Node {
public:
    Node(int val) : val(val), left(nullptr), right(nullptr) {}

    Node* left;
    Node* right;
    int val;
};

bool isSymmetric(Node* root1, Node* root2) {
    // If both trees are empty, they are identical
    if (!root1 && !root2)
        return true;

    // If one tree is empty and the other is not, they are not identical
    if (!root1 || !root2)
        return false;

    // Check if the values of the current nodes are equal
    if (root1->val != root2->val) {
        return false;
    }

    // Recursively check the left and right subtrees
    return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
}

int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);

    Node* root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->left->right = new Node(6);
    root2->right->left = new Node(5);
    root2->right->right = new Node(4);

    // Check if the trees are Symmetric
    if (isSymmetric(root1, root2))
        cout << "The trees are Symmetric." << endl;
    else
        cout << "The trees are not Symmetric." << endl;

    // Clean up memory (free allocated nodes)
    delete root1->left->left;
    delete root1->left->right;
    delete root1->right;
    delete root1->left;

    delete root2->left->left;
    delete root2->left->right;
    delete root2->right;
    delete root2->left;

    delete root1;
    delete root2;

    return 0;
}


