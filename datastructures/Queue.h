#include <iostream>
#include <string>
using namespace std;

// ── ATTACK JOB ───────────────────────────────────────────────
// One attack job holds which system is being attacked
// and which threat is doing the attacking
struct AttackJob {
    string systemName;  // target system e.g. MainServer
    string threatName;  // attacking threat e.g. Trojan
};

// ── QUEUE DATA STRUCTURE ──────────────────────────────────────
// Works like a real waiting line
// First person in line is first to be served
// This is called FIFO - First In First Out
// We use this to schedule attacks in order
// The first attack loaded is the first attack executed
// Just like a real attack pipeline

struct Queue {

    AttackJob data[100];  // array that holds attack jobs
    int front;            // index of first job
    int rear;             // index of last job
    int count;            // total jobs in queue

    // Constructor - queue starts empty
    Queue() {
        front = 0;
        rear  = -1;
        count = 0;
    }

    // ── isEmpty ───────────────────────────────────────────────
    // Returns true if no attack jobs are waiting
    bool isEmpty() {
        return count == 0;
    }

    // ── isFull ────────────────────────────────────────────────
    // Returns true if queue has reached max capacity
    bool isFull() {
        return count == 100;
    }

    // ── enqueue ───────────────────────────────────────────────
    // Adds a new attack job at the REAR of the queue
    // This proves FIFO - new jobs always go to the back
    void enqueue(string sysName, string thrName) {
        if (isFull()) {
            cout << "[QUEUE] Queue is full." << endl;
            return;
        }
        rear = (rear + 1) % 100;        // move rear forward
        data[rear].systemName = sysName; // store system name
        data[rear].threatName = thrName; // store threat name
        count++;
        cout << "[QUEUE] Attack queued: "
             << thrName << " -> " << sysName << endl;
    }

    // ── dequeue ───────────────────────────────────────────────
    // Removes and returns the FRONT attack job
    // This proves FIFO - oldest job always comes out first
    AttackJob dequeue() {
        AttackJob empty;
        empty.systemName = "";
        empty.threatName = "";

        if (isEmpty()) {
            cout << "[QUEUE] Queue is empty." << endl;
            return empty;
        }

        AttackJob job = data[front];    // get front job
        front = (front + 1) % 100;     // move front forward
        count--;
        return job;
    }

    // ── displayQueue ──────────────────────────────────────────
    // Shows all pending attacks in FIFO order
    // Proves to teacher that order is maintained
    void displayQueue() {
        if (isEmpty()) {
            cout << "No attacks in queue." << endl;
            return;
        }
        cout << "\n===== ATTACK QUEUE (FIFO ORDER) =====" << endl;
        cout << "First attack in line executes first" << endl;
        cout << "-------------------------------------" << endl;
        for (int i = 0; i < count; i++) {
            int index = (front + i) % 100;
            cout << "POS-" << i + 1
                 << " | " << data[index].threatName
                 << " -> " << data[index].systemName << endl;
        }
        cout << "-------------------------------------" << endl;
        cout << "Total attacks waiting: " << count << endl;
    }
};
