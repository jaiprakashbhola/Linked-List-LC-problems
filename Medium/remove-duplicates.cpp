//REMOVE DUPLICATES FROM SORTED LIST II
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while(head){
            //checks duplicates
            if(head->next && head->val == head->next->val){
                //skips them
                while(head->next && head->val == head->next->val){
                    head = head -> next;
                }
                prev -> next = head -> next;
            }
            else{
                prev = prev -> next;
            }
            head = head -> next;
        }
        return dummy -> next;
    }
};