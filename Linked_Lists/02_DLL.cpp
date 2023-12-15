#include<iostream>

using namespace std;


class Node{
public:
    int data;
    Node* next;
    Node* back;
    Node()= default;
    Node(int data): data(data),next(nullptr),back(nullptr){ }
    Node(int data,Node* next,Node* back): data(data),next(next),back(back){ }

}; 

Node* insertFront(Node* head, int val){
    if(!head)
    {
        Node *newNode = new Node(val, nullptr,nullptr);
        return newNode;
    }

    Node *newNode = new Node(val, head,nullptr);
    head->back = newNode;
    head = newNode;

    return head;
}

Node* insertBack(Node* head, int val){

    if(!head)
    {
        Node *newNode = new Node(val, nullptr,nullptr);
        return newNode;
    }

    Node* tmp = head;
    while(tmp->next){
        tmp =tmp->next;
    }

    Node *newNode = new Node(val, nullptr,tmp);
    tmp->next = newNode;
    return head;

}

Node* insertAfter(Node* head, int newVal, int refVal){
    if(!head)
    {
        return nullptr;
    }
    Node* tmp = head;
    while(tmp && tmp->data!=refVal){
        tmp=tmp->next;
    }

    if (!tmp) {
        cout << "Error: Node with reference value " << refVal << " not found." << endl;
        return head;
    }


    Node* newNode = new Node(newVal,tmp->next,tmp);
    if (tmp->next) {
        tmp->next->back = newNode;
    }
    tmp->next = newNode;
    return head;
}


Node* deleteHead(Node* head){
    if(!head || !head->next)
    {
        delete head;
        return nullptr;
    }

    head = head->next;
    delete(head->back);
    head->back = nullptr;
    return head;
}

Node* deleteTail(Node* head){
    if(!head || !head->next)
    {
        delete head;
        return nullptr;
    }
    Node* tmp = head;
    while (tmp->next->next) {
        tmp = tmp->next;
    }

    delete tmp->next;
    tmp->next = nullptr;
    return head;
}

Node* deleteK(Node* head, int k) {
    // Check for invalid input or non-positive k
    if (!head || k <= 0) {
        return nullptr;
    }

    // Case: Deleting the head
    if (k == 1) {
        // If the list has only one node
        if (!head->next) {
            delete head;
            return nullptr;
        }

        // Update head to the next node
        head = head->next;

        // Delete the original first node (head->back is nullptr after the update)
        delete head->back;

        // Set the back pointer of the new head to nullptr
        head->back = nullptr;

        return head;
    }

    // Traverse the list to the node before the target position
    Node* tmp = head;
    while (tmp && --k) {
        tmp = tmp->next;
    }

    // If position doesn't exist
    if (!tmp) {
        return head;
    }

    // Adjust pointers to skip the node at position k
    tmp->back->next = tmp->next;
    tmp->next->back = tmp->back;

    // Delete the node at position k
    delete tmp;

    return head;
}

Node* reverse(Node* head){
    
    Node* curr = head;
    Node* tmp = nullptr;

    while(curr){
        tmp = curr->back;
        curr->back = curr->next;
        curr->next = tmp;

        curr= curr->back;
    }

    if (tmp != nullptr) {
        head = tmp->back;
    }
    return head;

}


void display(Node* head) {
    Node* tmp = head;
    cout<<"Front:  ";
    while (tmp) {
        std::cout << tmp->data << "\t";
        tmp = tmp->next;
    }
    std::cout << std::endl;

    tmp = head;
    while (tmp && tmp->next) {
        tmp = tmp->next;
    }
    cout<<"Back:  ";
    while (tmp) {
        std::cout << tmp->data << "\t";
        tmp = tmp->back;
    }

    std::cout << std::endl;
}

int main(){
    Node * head = new Node(5);
    head = insertBack(head, 7);
    head = insertFront(head, 4);
    head = insertAfter(head,6,5);
    head = insertAfter(head,8,7);
    head = deleteHead(head);
    head = deleteTail(head);
    head = insertFront(head, 4);
    head = insertFront(head, 3);
    head = insertFront(head, 2);
    head = insertFront(head, 8);
    head = insertFront(head, 1);
    head = deleteK(head,1);
    head = deleteK(head,2);
    display(head);
    head = reverse(head);
    display(head);
}