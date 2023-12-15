
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

ListNode* sortNodes(ListNode* head){
    if(!head || !head->next){
        return head;
    }

    ListNode* zeroHead = new ListNode(0); 
    ListNode* oneHead  = new ListNode(0); 
    ListNode* twoHead  = new ListNode(0); 
    ListNode* zeroNode = zeroHead;
    ListNode* oneNode = oneHead;
    ListNode* twoNode = twoHead;

    while(head){
        switch(head->val){
            case 0:
                zeroNode->next = head;
                zeroNode = zeroNode->next;
                break;
            case 1:
                oneNode->next = head;
                oneNode = oneNode->next;
                break;
            case 2:
                twoNode->next = head;
                twoNode = twoNode->next;
                break;
        }
        head = head->next; 
    }
    zeroNode->next = oneHead->next;
    oneNode ->next = twoHead->next;
    twoNode->next = nullptr;

    return zeroHead->next;
}

int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(2);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(1);

    std::cout << "Original list: ";
    display(head);

    ListNode* result = sortNodes(head);

    std::cout << "Sorted list: ";
    display(result);

    return 0;
}