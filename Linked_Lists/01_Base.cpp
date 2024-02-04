#include <iostream>


using namespace std;

class Node{
public:
    Node(int data){
        next = nullptr;
        this->data = data;
    }
    Node(int data,Node* node){
        next = node;
        this->data = data;
    }

    Node() =default;
    Node* next;
    int data;
};

void insertBack(Node* tmp,int data){
    //Node *tmp = head;
    while(tmp->next){
        tmp = tmp->next;
    }
    tmp->next = new Node(data);
}

void display(Node* tmp){
    //Node *tmp = head;
    while(tmp){
        cout<<tmp->data<<"\t";
        tmp=tmp->next;
    }
    cout<<endl;
}

Node* del(Node* head, int numToDelete) {
    // Check if the list is empty or has only one node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Check if the node to delete is the head
    if (head->data == numToDelete) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }

    // Search for the node to delete
    Node* tmp = head;
    while (tmp->next && tmp->next->data != numToDelete) {
        tmp = tmp->next;
    }

    // If the node to delete is not found
    if (tmp->next == nullptr) {
        return head;
    }

    // Update the pointers to skip the node to delete
    Node* toDelete = tmp->next;
    tmp->next = tmp->next->next;
    delete toDelete;

    return head;
}

Node* delk(Node* head, int k){
    if (!head || k <= 0) {
        // Invalid input or k is non-positive
        return head;
    }

    if(k==1){
        Node* temp = head;
        head=head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr && --k){
        prev = temp;
        temp=temp->next;
    }

     if (temp == nullptr) {
        // k is greater than the length of the linked list
        return head;
    }

    prev->next =temp->next;
    free(temp);
    return head;
}

Node* insertHead(Node* head, int val){
    Node* newNode = new Node(val,head);
    return newNode;
}

Node* insertTail(Node* head, int val){
    Node* newNode = new Node(val);
    
    if (!head) {
        // If the list is empty, the new node becomes the head
        return newNode;
    }

    Node* tmp = head;
    while (tmp->next) {
        tmp = tmp->next;
    }

    tmp->next = newNode;
    return head;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* next = nullptr;

    while (head) {
        next = head->next;   // Save the next node
        head->next = prev;   // Reverse the link
        prev = head;         // Move prev one step forward
        head = next;         // Move head one step forward
    }

    return prev;  // Update head to the new first node (previous last node)
}

Node* deleteMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    while (fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        prev = slow;
    }

    Node* toDelete = prev->next;
    prev->next = prev->next->next;
    delete toDelete;
    return head;
}



int main(){
    Node* head = nullptr;
    head= insertTail(head,62);
    head = insertTail(head,78);
    display(head);
    insertBack(head,4);
    insertBack(head,6);
    insertBack(head,7);
    head = del(head,5);
    insertBack(head,8);
    insertBack(head,9);
    head = del(head,7);
    head = del(head,9);

    display(head);

    insertBack(head,4);
    insertBack(head,6);
    insertBack(head,7);
    display(head);

    head= delk(head,3);
    display(head);

    head = insertHead(head,6);
    head = insertTail(head,9);

    display(head);
    head = reverse(head);
    display(head);
    head = deleteMiddle(head);
    display(head);
    head = deleteMiddle(head);
    display(head);
    head = deleteMiddle(head);
    display(head);
    return 0;
}