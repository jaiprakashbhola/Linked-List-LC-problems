struct ListNode{
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 0; i < n; i++){
            fast = fast -> next;
        }

        if(fast == nullptr){
            return head -> next;
        }
        
        while(fast->next != nullptr){
            slow = slow -> next;
            fast = fast -> next;
        }
        //incase of memory leak
        ListNode* deleteNode = slow -> next;
        slow -> next = slow -> next -> next;
        delete deleteNode;

        return head;
    }