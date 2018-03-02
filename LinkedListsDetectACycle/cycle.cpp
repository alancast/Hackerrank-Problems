/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

#include <iostream>

struct Node {
    int data;
    struct Node* next;
};

bool has_cycle(Node* head) {
    if (!head){
        return false;
    }

    // If there is a cycle fast will be guaranteed to catch up 
    // with slow at some point in the loop
    Node* slow = head; 
    Node* fast = head;
    // if there isn't a cycle fast will reach end of loop faster
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            return true;
        }
    }
    return false;
}

int main(int argc, char** argv){
    Node* head = new Node();
    head->data = 1;
    // head->next = head;
    head->next = nullptr;
    std::cout << has_cycle(head) << std::endl;
    return 0;
}