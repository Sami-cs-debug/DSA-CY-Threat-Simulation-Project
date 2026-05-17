#include <iostream>
#include <string>
#include "datastructures/Array.h"
#include "datastructures/Queue.h"
using namespace std;

// ── FILE HANDLER ─────────────────────────────────────────────
// Reads all three input text files
// Fills Array LinkedList and Queue with data
// No file reading means no data in the system
// Teacher question: why use files?
// Answer: project guidelines require file based input

struct FileHandler {

    // ── loadSystems ───────────────────────────────────────────
    // Opens systems.txt and reads each line
    // Each line has SystemName and VulnerabilityLevel
    // Adds each system into the Array
    void loadSystems(SystemArray& systems) {
        ifstream file("input/systems.txt");

        if (!file.is_open()) {
            cout << "[ERROR] Cannot open systems.txt" << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;

            stringstream ss(line);
            string name, vulStr;
            getline(ss, name,   ',');
            getline(ss, vulStr, ',');

            systems.add(name, stoi(vulStr));
            cout << "  [+] System added: " << name
                 << " | Vulnerability: "   << vulStr << endl;
        }
        file.close();
        cout << "  Total systems: " << systems.count << endl;
    }

    // ── loadThreats ───────────────────────────────────────────
    // Opens threats.txt and reads each line
    // Each line has SystemName ThreatName Type and Severity
    // Finds the system in Array then adds threat to
    // that system LinkedList
    void loadThreats(SystemArray& systems) {
        ifstream file("input/threats.txt");

        if (!file.is_open()) {
            cout << "[ERROR] Cannot open threats.txt" << endl;
            return;
        }

        string line;
        int count = 0;
        while (getline(file, line)) {
            if (line.empty()) continue;

            stringstream ss(line);
            string sysName, thrName, type, sevStr;
            getline(ss, sysName, ',');
            getline(ss, thrName, ',');
            getline(ss, type,    ',');
            getline(ss, sevStr,  ',');

            SystemNode* sys = systems.findByName(sysName);
            if (sys != nullptr) {
                sys->threats.insert(thrName, type, stoi(sevStr));
                cout << "  [+] Threat added: " << thrName
                     << " -> " << sysName << endl;
                count++;
            }
        }
        file.close();
        cout << "  Total threats: " << count << endl;
    }

    // ── loadAssignments ───────────────────────────────────────
    // Opens assignments.txt and reads each line
    // Each line has SystemName and ThreatName
    // Adds each as an AttackJob into the Queue
    // First line in file = first job in queue = proves FIFO
    void loadAssignments(Queue& queue) {
        ifstream file("input/assignments.txt");

        if (!file.is_open()) {
            cout << "[ERROR] Cannot open assignments.txt" << endl;
            return;
        }

        string line;
        int count = 0;
        while (getline(file, line)) {
            if (line.empty()) continue;

            stringstream ss(line);
            string sysName, thrName;
            getline(ss, sysName, ',');
            getline(ss, thrName, ',');

            queue.enqueue(sysName, thrName);
            cout << "  [+] Attack queued: " << thrName
                 << " -> " << sysName << endl;
            count++;
        }
        file.close();
        cout << "  Total queued: " << count << endl;
    }

    // ── loadAll ───────────────────────────────────────────────
    // Loads all three files in correct order
    // Systems must be loaded first so threats can find them
    void loadAll(SystemArray& systems, Queue& queue) {
        cout << "\n===== LOADING DATA =====" << endl;
        cout << "\nLoading Systems into Array..." << endl;
        loadSystems(systems);
        cout << "\nLoading Threats into LinkedLists..." << endl;
        loadThreats(systems);
        cout << "\nLoading Assignments into Queue..." << endl;
        loadAssignments(queue);
        cout << "\n========================" << endl;
        cout << "All data loaded." << endl;
        cout << "========================\n" << endl;
    }
};
