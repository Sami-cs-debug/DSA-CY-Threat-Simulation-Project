#include <iostream>
#include <string>
using namespace std;

// ── List Node ─────────────────────────────────────────────────
// One node that holds a string value and points to next node
struct ListNode {
    string data;      // value stored in this node
    ListNode* next;   // pointer to next node

    // Store value and set next to null
    ListNode(string val) {
        data = val;
        next = nullptr;
    }
};

// ── Linked List ───────────────────────────────────────────────
// Chain of nodes connected through pointers
struct LinkedList {
    ListNode* head;  // points to first node
    int size;        // number of nodes in list

    // Start with empty list
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    // Add new node at the end of list
    void insertAtEnd(string val) {
        ListNode* newNode = new ListNode(val);

        // If list is empty this becomes first node
        if (head == nullptr) {
            head = newNode;
        } else {
            // Go to last node and attach new node
            ListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Add new node at the beginning of list
    void insertAtFront(string val) {
        ListNode* newNode = new ListNode(val);
        newNode->next     = head;
        head              = newNode;
        size++;
    }

    // Remove a node that matches the given value
    void deleteByValue(string val) {
        if (head == nullptr) return;

        // If first node matches delete it directly
        if (head->data == val) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            size--;
            return;
        }

        // Search rest of list for the value
        ListNode* temp = head;
        while (temp->next != nullptr) {
            if (temp->next->data == val) {
                ListNode* toDelete = temp->next;
                temp->next = toDelete->next;
                delete toDelete;
                size--;
                return;
            }
            temp = temp->next;
        }
    }

    // Search for value - returns true if found false if not
    bool search(string val) {
        ListNode* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    // Print all nodes in the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        ListNode* temp = head;
        int i = 1;
        while (temp != nullptr) {
            cout << "[" << i++ << "] "
                 << temp->data << endl;
            temp = temp->next;
        }
    }
};
