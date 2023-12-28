#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};



ListNode* findIntersection(ListNode* headA, ListNode* headB) {
    
    ListNode* currA = headA;
    ListNode* currB = headB;
    
    while(true){
        if(currA == currB){
            return currA;
        }
        if(!currA){
            currA=headB;
        }
        if(!currB){
            currB = headA;
        }
        currA=currA->next;
        currB=currB->next;
    }
}

int main() {
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    headA->next->next->next->next->next = new ListNode(7);

    ListNode* headB = new ListNode(6);
    headB->next = headA->next->next; // Connect B to the common node


    ListNode* intersection = findIntersection(headA, headB);

    if (intersection) {
        std::cout << "Intersection point value: " << intersection->val << std::endl;
    } else {
        std::cout << "No intersection point found." << std::endl;
    }

    return 0;
}
