#include <iostream>
#include <string>
using namespace std;

// List Node 
struct ListNode
 {
    string data;     
    ListNode* next;   

    // Store value and set next to null
    ListNode(string val)
	 {
        data = val;
        next = nullptr;
    }
};

//  Linked List 
struct LinkedList
 {
    ListNode* head;  
    int size;     

    LinkedList()
	 {
        head = nullptr;
        size = 0;
    }

    // Add new node at the end of list
    void insertAtEnd(string val) 
	{
        ListNode* newNode = new ListNode(val);

        if (head == nullptr) 
		{
            head = newNode;
        }
		 else 
		{
            ListNode* temp = head;
            while (temp->next != nullptr)
			 {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    void insertAtFront(string val)
	 {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Remove a node
    void deleteByValue(string val)
	 {
        if (head == nullptr) return;

        if (head->data == val)
		 {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        // Search rest of list for the value
        ListNode* temp = head;
        while (temp->next != nullptr)
		 {
            if (temp->next->data == val)
			 {
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
    bool search(string val)
	 {
        ListNode* temp = head;
        while (temp != nullptr)
		 {
            if (temp->data == val)
            {

			 return true;
		}
            temp = temp->next;
        }
        return false;
    }

    // Print all nodes in the list
    void display() 
	{
        if (head == nullptr)
		 {
            cout <<"List is empty."<< endl;
            return;
        }
        ListNode* temp = head;
        int i = 1;
        while (temp != nullptr)
		 {
            cout << "[" << i << "] " << temp->data << endl;
            temp = temp->next;
            i++;
        }
    }
};
