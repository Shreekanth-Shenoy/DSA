
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

bool isPalindrome(ListNode* head){

    if (!head || !head->next) {
        return true; // An empty list or a single-node list is a palindrome
    }

    ListNode* fast = head;
    ListNode* slow = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast ->next->next;
    }
    slow = reverse(slow);
    while(slow){
        if(slow->val != head->val){
            return false;
        }
        slow =slow->next;
        head= head->next;
    }
    return true; 
}

int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next->next = new ListNode(2);

    std::cout << "Original list: ";
    display(head);

    if(isPalindrome(head)){
        std::cout << "List is a palindrome";
    }else{
        std::cout << "List is not a palindrome";

    }
 
    return 0;
}