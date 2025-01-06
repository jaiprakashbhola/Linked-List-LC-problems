#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int key;
    int val;
    Node*next;
    Node*prev;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        next=nullptr;
        prev=nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mpp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int size;
    LRUCache(int capacity) {
       size = capacity;
       head->next = tail;
       tail->prev = head;
    }
    void deleteNode(Node* p){
       Node* pre = p->prev;
       Node* nex = p->next;
       pre->next = nex;
       nex->prev = pre;
    }
    void addNode(Node* newNode){
        Node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        Node* p = mpp[key];
        deleteNode(p);
        addNode(p);
        mpp[key] = head->next;
        return head->next->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!= mpp.end()){
            Node* c = mpp[key];
            deleteNode(c);
            c->val = value;
            addNode(c);
            mpp[key] = head->next;
        }
        else{
            if(mpp.size() == size){
                Node* prev = tail->prev;
                deleteNode(prev);
                Node* l = new Node(key,value);
                addNode(l);
                mpp.erase(prev->key);
                mpp[key] = head->next;
            }
            else{
                 Node* l = new Node(key,value);
                addNode(l);
                mpp[key] = head->next; 
            }
        }
    }
};
