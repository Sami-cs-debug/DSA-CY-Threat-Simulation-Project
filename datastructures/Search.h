#include <iostream>
#include <string>
#include "Array.h"
using namespace std;

// ── LINEAR SEARCH ─────────────────────────────────────────────
// Searches for a system by name
// Scans array one by one from start to end
// Does not need array to be sorted
// Teacher question: what is linear search?
// Answer: check every element one by one until found
// Best case: found at position 0
// Worst case: found at last position or not found

SystemNode* linearSearch(SystemArray& systems, string name) {

    cout << "\n===== LINEAR SEARCH =====" << endl;
    cout << "Searching for: " << name    << endl;
    cout << "Scanning array one by one"  << endl;
    cout << "-------------------------"  << endl;

    for (int i = 0; i < systems.count; i++) {

        // Show each step of the search
        cout << "Checking [" << i + 1 << "] "
             << systems.data[i].name << "..." << endl;

        if (systems.data[i].name == name) {
            cout << "\n[FOUND] " << systems.data[i].name
                 << " | Vulnerability: "
                 << systems.data[i].vulnerabilityLevel
                 << endl;
            cout << "Threats on this system:" << endl;
            systems.data[i].threats.display();
            return &systems.data[i];
        }
    }

    cout << "[NOT FOUND] No system named: " << name << endl;
    return nullptr;
}

// ── BINARY SEARCH ─────────────────────────────────────────────
// Searches for systems above a vulnerability threshold
// Array MUST be sorted first using bubble sort
// Divides array in half each time - much faster than linear
// Teacher question: what is binary search?
// Answer: divide array in half, check middle, go left or right
// Much faster than linear - works only on sorted arrays

void binarySearch(SystemArray& systems, int threshold) {

    cout << "\n===== BINARY SEARCH =====" << endl;
    cout << "Looking for vulnerability >= " << threshold << endl;
    cout << "Array must be sorted first"    << endl;
    cout << "Dividing array in half each step" << endl;
    cout << "-------------------------"     << endl;

    int low  = 0;
    int high = systems.count - 1;
    bool found = false;

    while (low <= high) {
        // Find middle position
        int mid = (low + high) / 2;

        cout << "Low=" << low
             << " Mid=" << mid
             << " High=" << high
             << " | Checking: "
             << systems.data[mid].name
             << " (Vulnerability: "
             << systems.data[mid].vulnerabilityLevel
             << ")" << endl;

        if (systems.data[mid].vulnerabilityLevel == threshold) {
            found = true;
            break;
        }
        // If mid vulnerability is higher go right
        else if (systems.data[mid].vulnerabilityLevel > threshold) {
            low = mid + 1;
        }
        // If mid vulnerability is lower go left
        else {
            high = mid - 1;
        }
    }

    // Show all systems at or above threshold
    cout << "\nSystems with vulnerability >= "
         << threshold << ":" << endl;

    bool any = false;
    for (int i = 0; i < systems.count; i++) {
        if (systems.data[i].vulnerabilityLevel >= threshold) {
            cout << "  -> " << systems.data[i].name
                 << " | Vulnerability: "
                 << systems.data[i].vulnerabilityLevel
                 << endl;
            any = true;
        }
    }
    if (!any) {
        cout << "No systems found above threshold." << endl;
    }
}
