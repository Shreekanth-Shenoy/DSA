#include <iostream>
#include <unordered_map>
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int LeghthOfCycle(ListNode* head) {
    if(!head || !head->next){
        return -1;
    }

    ListNode* fast = head;
    ListNode* slow = head;
    int length = 0;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            fast = fast->next;
            while(fast!=slow){
                fast = fast->next;
                length++;
            }
            return length+1;
        }
    }
    return -1;
}

int LeghthOfCycleHapMapssMethod(ListNode* head) {
    if(!head || !head->next){
        return -1;
    }

    std::unordered_map<ListNode*,int> mp;
    int count =1;
    while(head){
        if (mp.find(head) == mp.end()) {
            mp[head] = count;
            count++;
        }
        else{
            return count-mp[head];
        }
        head= head->next;
    }
    return -1;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    //Following line creates a loop
    head->next->next->next->next = head->next;

    std::cout << "The linked list has a cycle of length" << LeghthOfCycleHapMapssMethod(head)<< std::endl;
    std::cout << "The linked list has a cycle of length" << LeghthOfCycle(head)<< std::endl;


    return 0;
}
