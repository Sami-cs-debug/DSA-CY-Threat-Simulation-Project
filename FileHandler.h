#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "datastructures/Array.h"
#include "datastructures/Queue.h"
using namespace std;

struct FileHandler 
{
    void loadSystems(SystemArray& systems) 
    {
        ifstream file("input/systems.txt");

        if (!file.is_open()) 
        {
            cout << "[ERROR] Cannot open systems.txt" << endl;
            return;
        }

        string line;
        while (getline(file, line)) 
        {
            if (line.empty()) 
            {
                continue;
            }

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

    void loadThreats(SystemArray& systems) 
    {
        ifstream file("input/threats.txt");

        if (!file.is_open()) 
        {
            cout << "[ERROR] Cannot open threats.txt" << endl;
            return;
        }

        string line;
        int count = 0;

        while (getline(file, line)) 
        {
            if (line.empty()) 
            {
                continue;
            }

            stringstream ss(line);
            string sysName, thrName, type, sevStr;
            getline(ss, sysName, ',');
            getline(ss, thrName, ',');
            getline(ss, type,    ',');
            getline(ss, sevStr,  ',');

            SystemNode* sys = systems.findByName(sysName);

            if (sys != nullptr) 
            {
                sys->threats.insert(thrName, type, stoi(sevStr));
                cout << "  [+] Threat added: " << thrName
                     << " -> " << sysName << endl;
                count++;
            }
        }
        file.close();
        cout << "  Total threats: " << count << endl;
    }

    void loadAssignments(Queue& queue) 
    {
        ifstream file("input/assignments.txt");

        if (!file.is_open()) 
        {
            cout << "[ERROR] Cannot open assignments.txt" << endl;
            return;
        }

        string line;
        int count = 0;

        while (getline(file, line)) 
        {
            if (line.empty()) 
            {
                continue;
            }

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

    void loadAll(SystemArray& systems, Queue& queue) 
    {
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
