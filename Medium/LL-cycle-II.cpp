struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
};

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while(slow != nullptr && fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;

            }
            return slow;
        }
    }
    return nullptr;
  }