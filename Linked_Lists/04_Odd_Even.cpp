
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

ListNode* groupNodesByIndex(ListNode* head){
    if(!head || ! (head->next) ||! (head->next->next)){
        return head;
    }

    ListNode* evenHead = new ListNode(0);  // Dummy head for even-indexed nodes
    ListNode* oddHead = new ListNode(0);   // Dummy head for odd-indexed nodes
    ListNode* evenNode = evenHead;
    ListNode* oddNode = oddHead;
    int index = 3;
    while(head){
        if(index%2 == 0){

            evenNode->next = head;
            evenNode = evenNode->next;
        }
        else{

            oddNode->next = head;
            oddNode = oddNode->next;
        }
        head= head->next;
        index++;
    }
    evenNode->next = nullptr;
    oddNode->next = evenHead->next;
    return oddHead->next;

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

    ListNode* result = groupNodesByIndex(head);

    std::cout << "Grouped list: ";
    display(result);

    return 0;
}