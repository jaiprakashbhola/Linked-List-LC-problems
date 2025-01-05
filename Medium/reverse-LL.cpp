struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        for(int i = 1; i < left; i++){
            prev = prev -> next;
        }

        ListNode* current = prev -> next;
        ListNode* next = nullptr;
        ListNode* tail = current;

        //reversing the list
        for(int i = 0; i < right - left + 1; i++){
            next = current -> next;
            current -> next = prev -> next;
            prev -> next = current;
            current = next;
        }
        //connects tail of the reversed list to the rest of the tail
        tail -> next = next;
        return dummy.next;
    }