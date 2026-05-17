#include <iostream>
#include <string>
using namespace std;


struct ThreatNode 
{
    string name;   // threat name 
    string type;   // threat type 
    int severity;  // danger level 
    ThreatNode* next;   

    
    ThreatNode()
	 {
        name  = "";
        type  = "";
        severity = 0;
        next = nullptr;
    }
};

// Threat Linked List 
struct ThreatList
 {
    ThreatNode* head;  

    ThreatList() 
	{
        head = nullptr;
    }

    void insert(string name, string type, int severity) 
	{
        ThreatNode* newNode = new ThreatNode();
        
        newNode->name = name;
        newNode->type = type;
        newNode->severity = severity;

        // If list is empty make this the first node
        if (head == nullptr)
		 {
            head = newNode;
            return;
        }

        // Go to last node
        ThreatNode* temp = head;
        while (temp->next != nullptr)
		 {
            temp = temp->next;
        }
        
        temp->next = newNode;
    }

    // Search threat  by name
    ThreatNode* find(string name)
	 {
        ThreatNode* temp = head;
        while (temp != nullptr)
		 {
            if (temp->name == name)
			 return temp;
            temp = temp->next;
        }
        
        return nullptr;
    }

    // display threats
    void display()
	 {
        if (head == nullptr)
		 {
            cout << "No threats assigned." << endl;
            return;
        }
        ThreatNode* temp = head;
        while (temp != nullptr)
		 {
            cout << "-> " << temp->name <<endl;
        cout << " Type: "     << temp->type <<endl;
         cout << " Severity: " << temp->severity<<endl;
                 cout<< endl;
            temp = temp->next;
        }
    }
};

// System Node

struct SystemNode
 {
    string name;              
    int vulnerabilityLevel;   
    ThreatList threats;      

    SystemNode()
	 {
        name = "";
        vulnerabilityLevel = 0;
    }
};
