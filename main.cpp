```cpp
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

    SystemArray systems;
    Queue queue;
    Stack stack;
    BST bst;
    FileHandler fileHandler;

    bool dataLoaded = false;
    int choice = 0;

    do {

        cout << "\n========================================" << endl;
        cout << "    CYBER SECURITY THREAT SIMULATOR" << endl;
        cout << "    Data Structures Project - C++" << endl;
        cout << "========================================" << endl;
        cout << " 1. Load data from files" << endl;
        cout << " 2. Display all systems and threats" << endl;
        cout << " 3. Sort systems by vulnerability" << endl;
        cout << " 4. Show attack queue (FIFO order)" << endl;
        cout << " 5. Run attack simulation" << endl;
        cout << " 6. View alert log (LIFO order)" << endl;
        cout << " 7. View threat priority report (BST)" << endl;
        cout << " 8. Search system by name (Linear)" << endl;
        cout << " 9. Search by vulnerability (Binary)" << endl;
        cout << " 0. Exit" << endl;
        cout << "========================================" << endl;
        cout << " Enter choice: ";

        cin >> choice;

        switch (choice) {

            case 1: {

                fileHandler.loadAll(systems, queue);

                for (int i = 0; i < systems.count; i++) {

                    ThreatNode* t = systems.data[i].threats.head;

                    while (t != nullptr) {

                        bst.insert(
                            t->name,
                            t->type,
                            t->severity
                        );

                        t = t->next;
                    }
                }

                dataLoaded = true;

                cout << "BST built from all threats." << endl;

                break;
            }

            case 2: {

                if (!dataLoaded) {

                    cout << "Load data first." << endl;
                    break;
                }

                systems.display();

                break;
            }

            case 3: {

                if (!dataLoaded) {

                    cout << "Load data first." << endl;
                    break;
                }

                bubbleSort(systems);
                displaySorted(systems);

                break;
            }

            case 4: {

                if (!dataLoaded) {

                    cout << "Load data first." << endl;
                    break;
                }

                queue.displayQueue();

                break;
            }

            case 5: {

                if (!dataLoaded) {

                    cout << "Load data first." << endl;
                    break;
                }

                runSimulation(systems, queue, stack);

                break;
            }

            case 6: {

                stack.displayAll();

                break;
            }

            case 7: {

                if (!dataLoaded) {

                    cout << "Load data first." << endl;
                    break;
                }

                bst.inOrderTraversal();

                break;
            }

            case 8: {

                if (!dataLoaded) {

                    cout << "Load data first." << endl;
                    break;
                }

                string name;

                cout << "Enter system name: ";
                cin >> name;

                linearSearch(systems, name);

                break;
            }

            case 9: {

                if (!dataLoaded) {

                    cout << "Load data first." << endl;
                    break;
                }

                int threshold;

                cout << "Enter vulnerability threshold: ";
                cin >> threshold;

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
```
