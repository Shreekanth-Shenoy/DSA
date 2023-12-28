#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};



ListNode* find1stMiddle(ListNode* head) {
ListNode* slow = head;
ListNode* fast = head;

while(fast && fast->next && fast->next->next){
    fast = fast ->next ->next;
    slow = slow->next;
}

return slow;
}

ListNode* find2ndMiddle(ListNode* head) {
ListNode* slow = head;
ListNode* fast = head;

while(fast && fast->next){
    fast = fast ->next ->next;
    slow = slow->next;
}

return slow;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);


    std::cout<<"Even Number\n";

    ListNode* firstIntersection = find1stMiddle(head);
    std::cout << "Middle point value: " << firstIntersection->val << std::endl;

    ListNode* secondIntersection = find2ndMiddle(head);
    std::cout << "Middle point value: " << secondIntersection->val << std::endl;
   
    head->next->next->next->next->next->next = new ListNode(7);

    std::cout<<"Odd Number\n";

    firstIntersection = find1stMiddle(head);
    std::cout << "Middle point value: " << firstIntersection->val << std::endl;

    secondIntersection = find2ndMiddle(head);
    std::cout << "Middle point value: " << secondIntersection->val << std::endl;

    return 0;
}
