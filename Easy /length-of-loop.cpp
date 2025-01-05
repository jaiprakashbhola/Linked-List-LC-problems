struct Node{
    int data;
    Node *next;
 
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int findLength(Node* slow, Node* fast){
    int count = 1;

    fast = fast -> next;

    while(slow != fast){
        count++;
        fast = fast -> next;
    }
    return count;
}
int lengthOfLoop(Node *head) {
    // Write your code here

    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast){
            return findLength(slow, fast);
        }
    }
    return 0;
}
