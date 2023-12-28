
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

ListNode* reverse(ListNode* head){
    if (!head || !head->next){
        return head;
    }

    // Recursive case: reverse the rest of the list
    ListNode* newHead = reverse(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
    
}

/*Another method

ListNode* reverse(ListNode* head){
    // Base case: an empty list or a list with a single node
    if (!head || !head->next) {
        return head;
    }

    // Recursive case: reverse the rest of the list
    ListNode* reversedRest = reverseListRecursive(head->next);

    // Adjust the pointers to reverse the current node
    head->next->next = head;
    head->next = nullptr;

    // The new head is the last node in the reversed list
    return reversedRest;
    
}

*/

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

    ListNode* result = reverse(head);
 
    std::cout << "New list: ";
    display(result);

    return 0;
}