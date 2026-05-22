#include <iostream>
#include <fstream>
#include <string>
#include "datastructures/Array.h"
#include "datastructures/Stack.h"
#include "datastructures/Queue.h"
using namespace std;

// ── getDamage ─────────────────────────────────────────────────
// Returns damage description based on severity
string getDamage(int severity) 
{
    if (severity <= 3) 
        return "Minor probe - system stable";
    if (severity <= 6) 
        return "Partial breach - some data exposed";
    if (severity <= 8) 
        return "Critical breach - major damage done";
    return "SYSTEM COMPROMISED - taken offline";
}

// ── getThreatLevel ────────────────────────────────────────────
// Returns threat level label based on severity number
string getThreatLevel(int severity) {
    if (severity <= 3) return "LOW";
    if (severity <= 6) return "MEDIUM";
    if (severity <= 8) return "HIGH";
    return "CRITICAL";
}

// THE BRAIN - runSimulation 
// Uses Queue to get attacks in FIFO order
// Uses Array and LinkedList to find systems and threats
// Uses Stack to log every alert in LIFO order
// Writes results to output files
void runSimulation(SystemArray& systems,Queue& queue,Stack& stack) 
{
    ofstream reportFile("output/attack_report.txt");
    reportFile << "===== CYBER SECURITY ATTACK REPORT =====\n\n";

    cout << "\n========================================" << endl;
    cout << "       SIMULATION STARTING" << endl;
    cout << "========================================" << endl;
    cout << "Attacks will execute in FIFO order" << endl;
    cout << "Alerts will be logged in LIFO order" << endl;
    cout << "========================================\n" << endl;

    if (queue.isEmpty()) 
    {
        cout << "No attacks loaded in queue." << endl;
        return;
    }

    int attackNumber = 1;

    // ── MAIN SIMULATION LOOP ──────────────────────────────────
    // Keep running until queue is empty
    // Each loop = one attack dequeued and executed
    while (!queue.isEmpty()) 
    {

        // STEP 1 - Dequeue next attack (FIFO - oldest first)
        AttackJob job = queue.dequeue();

        cout << "----------------------------------------" << endl;
        cout << "ATTACK #" << attackNumber << endl;
        cout << "----------------------------------------" << endl;

        // STEP 2 - Search Array for target system by name
        // This is LINEAR SEARCH inside findByName
        SystemNode* target = systems.findByName(job.systemName);

        if (target == NULL) 
        {
            cout << "[SKIPPED] System not found: "
                 << job.systemName << endl;
            continue;
        }

        // STEP 3 - Search LinkedList for threat by name
        // This traverses the linked list node by node
        ThreatNode* threat = target->threats.find(job.threatName);

        if (threat == NULL) 
        {
            cout << "[SKIPPED] Threat not found: "
                 << job.threatName << endl;
            continue;
        }

        // STEP 4 - Execute attack and print details
        string level  = getThreatLevel(threat->severity);
        string damage = getDamage(threat->severity);

        cout << "TARGET SYSTEM  : " << target->name << endl;
        cout << "VULNERABILITY  : "
             << target->vulnerabilityLevel << "/10" << endl;
        cout << "THREAT NAME    : " << threat->name << endl;
        cout << "THREAT TYPE    : " << threat->type << endl;
        cout << "SEVERITY       : "
             << threat->severity << "/10" << endl;
        cout << "THREAT LEVEL   : " << level  << endl;
        cout << "DAMAGE RESULT  : " << damage << endl;
        cout << "STATUS         : Attack Executed" << endl;

        // STEP 5 - Write to attack report file
        reportFile << "ATTACK #" << attackNumber << "\n";
        reportFile << "Target     : " << target->name     << "\n";
        reportFile << "Threat     : " << threat->name     << "\n";
        reportFile << "Type       : " << threat->type     << "\n";
        reportFile << "Severity   : " << threat->severity << "\n";
        reportFile << "Level      : " << level            << "\n";
        reportFile << "Damage     : " << damage           << "\n\n";

        // STEP 6 - Push alert onto Stack (LIFO)
        // Most recent attack alert always on top
        string alert = "ATTACK#" + to_string(attackNumber) +
                       " | " + level +
                       " | " + threat->name +
                       " hit " + target->name +
                       " | Severity:" +
                       to_string(threat->severity) +
                       " | " + damage;

        stack.push(alert);

        attackNumber++;
    }

    // ── SIMULATION COMPLETE ───────────────────────────────────
    cout << "\n========================================" << endl;
    cout << "  SIMULATION COMPLETE" << endl;
    cout << "  Total attacks executed: "
         << attackNumber - 1 << endl;
    cout << "  Alerts stored in stack: "
         << stack.top + 1 << endl;
    cout << "========================================" << endl;

    reportFile << "Total attacks: " << attackNumber - 1 << "\n";
    reportFile << "===== END OF REPORT =====\n";
    reportFile.close();

    // SAVE ALERT LOG FROM STACK 
    // Pop all alerts from stack and write to file
    // This proves stack behavior to the teacher
    ofstream alertFile("output/alert_log.txt");
    alertFile << "===== ALERT LOG =====\n";
    alertFile << "Order: LIFO - Most recent alert first\n\n";

    int alertNum = 1;
    // Create a temporary stack copy to display
    Stack tempStack = stack;
    while (!tempStack.isEmpty()) {
        string alert = tempStack.pop();
        alertFile << alertNum << ". " << alert << "\n";
        alertNum++;
    }

    alertFile << "\n===== END OF ALERT LOG =====\n";
    alertFile.close();

    cout << "\nFiles saved:" << endl;
    cout << "  output/attack_report.txt" << endl;
    cout << "  output/alert_log.txt"     << endl;
}
