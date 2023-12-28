
#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


void display(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val;
        if (current->next) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}


ListNode* reverseList(ListNode* head){
    ListNode* curr= head;
    ListNode* next=nullptr;
    ListNode* prev = nullptr;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr =next;
    }
    return prev;
}

ListNode* addOne(ListNode* head){
    head = reverseList(head);

    ListNode *curr =head;
    ListNode* prev = nullptr;;
    int carry = 1;
    while(curr){
        int sum = curr->val + carry;
        curr->val = sum % 10;
        carry = sum / 10;

        prev = curr;
        curr = curr->next;
    }
    
    if(carry){
        ListNode* newNode = new ListNode(1);
        prev->next = newNode;
    }

    head = reverseList(head);
    return head;
}

int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(9);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);


    std::cout << "Original list: ";
    display(head);

    head = addOne(head);

    display(head);
 
    return 0;
}