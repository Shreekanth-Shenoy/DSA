#include <iostream>
#include <unordered_set>

// Node structure for a doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Function to find all pairs with the given sum in a DLL
void findPairsWithSum(Node* head, int targetSum) {

}

// Function to insert a node at the end of a DLL
Node* insertEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    std::cout<<"insertEnd "<<head<<std::endl;
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}

// Function to print the elements of a DLL
void printDLL(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    std::cout<<"head "<<head<<std::endl;
    // Insert elements into the doubly linked list
    head = insertEnd(head, 1);
    std::cout<<"head "<<head<<std::endl;

    head = insertEnd(head, 2);
    std::cout<<"head "<<head<<std::endl;

    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);
    head = insertEnd(head, 6);

    std::cout << "Original DLL: ";
    printDLL(head);
    
    int targetSum = 7;

    // Find pairs with the given sum
    findPairsWithSum(head, targetSum);

    return 0;
}
