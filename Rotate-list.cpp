struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k== 0) return head;

        //calculating length
        ListNode* current = head;
        int n = 1;
        while(current -> next){
            current  = current -> next;
            n++;
        }
        //effective rotations
        k %= n;
        if(k == 0) return head;

        //making the list circular
        current -> next = head;

        //new tail and head;
        int StepsNewTail = n - k;
        ListNode* newTail = head;
        for(int i = 1; i < StepsNewTail; i++){
            newTail = newTail -> next;
        }
        ListNode* newHead = newTail -> next;
        
        //breaking the circular list
        newTail -> next = nullptr;
        return newHead;
    }
};