#include <iostream>
#include <string>
#include "datastructures/Array.h"
#include "datastructures/LinkedList.h"
#include "datastructures/Stack.h"
#include "datastructures/Queue.h"
#include "datastructures/BST.h"
#include "datastructures/Search.h"
#include "datastructures/Sort.h"
#include "FileHandler.h"
#include "Simulator.h"
using namespace std;

int main() {

    // ── Create all data structures ────────────────────────────
    SystemArray systems;   // array holds all network systems
    Queue       queue;     // queue schedules attacks in FIFO
    Stack       stack;     // stack logs alerts in LIFO
    BST         bst;       // BST ranks threats by severity
    FileHandler fileHandler; // reads input files
    bool        dataLoaded = false;
    int         choice     = 0;

    do {
        // ── CLI MENU ──────────────────────────────────────────
        cout << "\n========================================" << endl;
        cout << "    CYBER SECURITY THREAT SIMULATOR"       << endl;
        cout << "    Data Structures Project - C++"          << endl;
        cout << "========================================"   << endl;
        cout << " 1. Load data from files"                  << endl;
        cout << " 2. Display all systems and threats"       << endl;
        cout << " 3. Sort systems by vulnerability"         << endl;
        cout << " 4. Show attack queue (FIFO order)"        << endl;
        cout << " 5. Run attack simulation"                  << endl;
        cout << " 6. View alert log (LIFO order)"           << endl;
        cout << " 7. View threat priority report (BST)"     << endl;
        cout << " 8. Search system by name (Linear)"        << endl;
        cout << " 9. Search by vulnerability (Binary)"      << endl;
        cout << " 0. Exit"                                  << endl;
        cout << "========================================"   << endl;
        cout << " Enter choice: ";
        cin  >> choice;

        switch (choice) {

            // ── Load all data from input files ────────────────
            case 1: {
                fileHandler.loadAll(systems, queue);

                // Build BST from all threats in all systems
                for (int i = 0; i < systems.count; i++) {
                    ThreatNode* t = systems.data[i].threats.head;
                    while (t != nullptr) {
                        bst.insert(t->name,
                                   t->type,
                                   t->severity);
                        t = t->next;
                    }
                }
                dataLoaded = true;
                cout << "BST built from all threats." << endl;
                break;
            }

            // ── Show all systems and their linked lists ───────
            case 2: {
                if (!dataLoaded) {
                    cout << "Load data first." << endl;
                    break;
                }
                systems.display();
                break;
            }

            // ── Bubble sort systems by vulnerability ──────────
            case 3: {
                if (!dataLoaded) {
                    cout << "Load data first." << endl;
                    break;
                }
                bubbleSort(systems);
                displaySorted(systems);
                break;
            }

            // ── Show queue in FIFO order ──────────────────────
            case 4: {
                if (!dataLoaded) {
                    cout << "Load data first." << endl;
                    break;
                }
                queue.displayQueue();
                break;
            }

            // ── Run simulation - brain of project ─────────────
            case 5: {
                if (!dataLoaded) {
                    cout << "Load data first." << endl;
                    break;
                }
                runSimulation(systems, queue, stack);
                break;
            }

            // ── Show alert log from stack in LIFO order ───────
            case 6: {
                stack.displayAll();
                break;
            }

            // ── Show BST inorder traversal ────────────────────
            case 7: {
                if (!dataLoaded) {
                    cout << "Load data first." << endl;
                    break;
                }
                bst.inOrderTraversal();
                break;
            }

            // ── Linear search by system name ──────────────────
            case 8: {
                if (!dataLoaded) {
                    cout << "Load data first." << endl;
                    break;
                }
                string name;
                cout << "Enter system name: ";
                cin  >> name;
                linearSearch(systems, name);
                break;
            }

            // ── Binary search by vulnerability threshold ──────
            case 9: {
                if (!dataLoaded) {
                    cout << "Load data first." << endl;
                    break;
                }
                int threshold;
                cout << "Enter vulnerability threshold: ";
                cin  >> threshold;
                bubbleSort(systems);
                binarySearch(systems, threshold);
                break;
            }

            case 0: {
                cout << "\nGoodbye!" << endl;
                break;
            }

            default: {
                cout << "Invalid choice." << endl;
            }
        }

    } while (choice != 0);

    return 0;
}
