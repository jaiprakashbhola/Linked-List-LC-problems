struct Node{
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = nullptr;
    }
};

Node* reverseLinkedList(Node *head){            //recursive approach
    // Write your code here
    if(head == nullptr || head->next == nullptr) return head;

    Node* newHead = reverseLinkedList(head->next);

    Node* front = head->next;

    front->next = head;

    head->next = nullptr;

    return newHead;
}