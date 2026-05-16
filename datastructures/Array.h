#include <iostream>
#include <string>
using namespace std;

// ── Threat Node ───────────────────────────────────────────────
// One threat stored as a node with a pointer to next threat
struct ThreatNode {
    string name;        // threat name e.g. Trojan
    string type;        // threat type e.g. Malware
    int severity;       // danger level 1-10
    ThreatNode* next;   // pointer to next threat in list

    // Set default values when node is created
    ThreatNode() {
        name     = "";
        type     = "";
        severity = 0;
        next     = nullptr;
    }
};

// ── Threat Linked List ────────────────────────────────────────
// Each system has its own linked list of threats
struct ThreatList {
    ThreatNode* head;   // points to first threat in list

    // Start with empty list
    ThreatList() {
        head = nullptr;
    }

    // Add a new threat at the end of the list
    void insert(string name, string type, int severity) {
        ThreatNode* newNode = new ThreatNode();
        newNode->name       = name;
        newNode->type       = type;
        newNode->severity   = severity;

        // If list is empty make this the first node
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Go to last node then attach new node
        ThreatNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Search for a threat by name and return it
    ThreatNode* find(string name) {
        ThreatNode* temp = head;
        while (temp != nullptr) {
            if (temp->name == name) return temp;
            temp = temp->next;
        }
        // Return null if not found
        return nullptr;
    }

    // Print all threats in this list
    void display() {
        if (head == nullptr) {
            cout << "    No threats assigned." << endl;
            return;
        }
        ThreatNode* temp = head;
        while (temp != nullptr) {
            cout << "    -> " << temp->name
                 << " | Type: "     << temp->type
                 << " | Severity: " << temp->severity
                 << endl;
            temp = temp->next;
        }
    }
};

// ── System Node ───────────────────────────────────────────────
// One system in the network e.g. Server, Database
struct SystemNode {
    string name;              // system name
    int vulnerabilityLevel;   // how easy it is to attack
    ThreatList threats;       // this system's linked list of threats

    // Set default values when node is created
    SystemNode() {
        name               = "";
        vulnerabilityLevel = 0;
    }
};

// ── System Ar
