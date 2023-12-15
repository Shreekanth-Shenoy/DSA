
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

ListNode* removeKFromEnd(ListNode* head,int k){
    if(!head || k<=.0){
        return head;
    }
    ListNode* fast = head;
    ListNode* slow = head;

    while(k--){
        if(!fast){
            return head;
        }
        fast = fast->next;
    }

    // If k-th node is the head, remove it
    if (!fast) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }

    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* tmp = slow->next;
    slow->next = slow->next->next;

    delete(tmp); 
    return head;

}

int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    std::cout << "Original list: ";
    display(head);

    ListNode* result = removeKFromEnd(head,7);

    std::cout << "New list: ";
    display(result);



    ListNode* result1 = removeKFromEnd(result,0);

    std::cout << "New list1: ";
    display(result1);
    return 0;
}