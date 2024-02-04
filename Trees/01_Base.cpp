#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node {
public:
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
    Node* left;
    Node* right;
    int value;
};

void recursiveInOrderTraversal(Node* root) {
    if (!root)
        return;
    recursiveInOrderTraversal(root->left);
    cout << root->value << " ";
    recursiveInOrderTraversal(root->right);
}

void recursivePreOrderTraversal(Node* root){
    if(!root)
        return;
    cout<<root->value<<" ";
    recursivePreOrderTraversal(root->left);
    recursivePreOrderTraversal(root->right);
}

void recursivePostOrderTraversal(Node* root){
    if(!root)
        return;
    recursivePostOrderTraversal(root->left);
    recursivePostOrderTraversal(root->right);
    cout<<root->value<<" ";
}

void levelOrderTraversal(Node* root){

    if(!root)
        return;
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        cout<<current->value<<" ";

        if(current->left)  q.push(current->left);
        if(current->right) q.push(current->right);
    }

}

void levelOrderTraversal_LevelWise(Node* root){

    if(!root)
        return;
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i =0;i<size;i++){
            Node* current = q.front();
            q.pop();
            cout<<current->value<<" ";
            if(current->left)  q.push(current->left);
            if(current->right) q.push(current->right);
        }
        cout<<endl;
    }

}

void iterrativePreOrderTraversal(Node* root){
    if(!root)
        return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* current = st.top();
        st.pop();
        cout<<current->value<<" ";
        if(current->right)
            st.push(current->right);
        if(current->left)
            st.push(current->left);
    }
}

void iterrativeInOrderTraversal(Node* root){
    if(!root)
        return;
    stack<Node*> st;
    while(true){
        if(root){
            st.push(root);
            root = root->left;
        }
        else{
            if(st.empty())
                break;
            root = st.top();
            st.pop();
            cout << root->value << " ";            
            root = root->right;
        }
    }
}

void iterrativePostOrderTraversal(Node* root){
    if(!root)
        return;
    stack<Node*> st1,st2;
    st1.push(root);
    while(!st1.empty()){
        root =st1.top();
        st1.pop();
        st2.push(root);
        if(root->left)
            st1.push(root->left);
        if(root->right)
            st1.push(root->right);
    }
    while(!st2.empty()){
        cout << st2.top()->value << " ";
        st2.pop();            
    }
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

    cout << "In-order traversal: ";
    recursiveInOrderTraversal(root);
    cout << "\nPre-order traversal: ";
    recursivePreOrderTraversal(root);
    cout << "\nPost-order traversal: ";
    recursivePostOrderTraversal(root);


    cout << "\nLevel-order traversal: ";
    levelOrderTraversal(root);
    cout << "\nLevel-order traversal LevelWise: \n";
    levelOrderTraversal_LevelWise(root);

    
    cout << "\nIterrative In-order traversal: ";
    iterrativeInOrderTraversal(root);
    cout << "\nIterrative Pre-order traversal: ";
    iterrativePreOrderTraversal(root);
    cout << "\nIterrative Post-order traversal: ";
    iterrativePostOrderTraversal(root);

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
