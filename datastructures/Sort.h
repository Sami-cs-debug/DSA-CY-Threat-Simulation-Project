#include <iostream>
#include "Array.h"
using namespace std;

// ── Bubble Sort ───────────────────────────────────────────────
// Sorts all systems from highest vulnerability to lowest
// Works by comparing two systems next to each other
// If left is smaller than right it swaps them
// Keeps repeating until everything is in order
void bubbleSort(SystemArray& systems) {
    int n = systems.count;

    // Outer loop - number of passes
    for (int i = 0; i < n - 1; i++) {

        // Inner loop - compare each pair
        for (int j = 0; j < n - i - 1; j++) {

            // Swap if left system has lower vulnerability than right
            if (systems.data[j].vulnerabilityLevel 
                systems.data[j + 1].vulnerabilityLevel) {

                SystemNode temp      = systems.data[j];
                systems.data[j]      = systems.data[j + 1];
                systems.data[j + 1]  = temp;
            }
        }
    }
    cout << "\n[SORTED] Systems sorted highest to lowest." << endl;
}

// Print all systems after sorting
void displaySorted(SystemArray& systems) {
    cout << "\n===== SYSTEMS BY VULNERABILITY =====" << endl;
    for (int i = 0; i < systems.count; i++) {
        cout << "[" << i + 1 << "] "
             << systems.data[i].name
             << " — Vulnerability: "
             << systems.data[i].vulnerabilityLevel
             << endl;
    }
}
