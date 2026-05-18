#include <iostream>
#include <string>
using namespace std;

// ATTACK JOB
struct AttackJob 
{
    string systemName;  // target system
    string threatName;  // attacking threat
};

// QUEUE DATA STRUCTURE
// First In First Out I use this to schedule attacks in order
struct Queue 
{

    AttackJob data[100];  // array that holds attack jobs
    int front;            // index of first job
    int rear;             // index of last job
    int count;            // total jobs in queue

    // Constructor - queue starts empty
    Queue() 
    {
        front = 0;
        rear  = -1;
        count = 0;
    }

    // isEmpty returns true if no attack jobs are waiting
    bool isEmpty() {
        return count == 0;
    }

    // isFull returns true if queue has reached max capacity
    bool isFull() 
    {
        return count == 100;
    }

    // enqueue adds a new attack job at the REAR of the queue
    void enqueue(string sysName, string thrName) 
    {
        if (isFull()) 
        {
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

    // dequeue removes and returns the FRONT attack job (FIFO)
    AttackJob dequeue() 
    {
        AttackJob empty;
        empty.systemName = "";
        empty.threatName = "";

        if (isEmpty()) 
        {
            cout << "[QUEUE] Queue is empty." << endl;
            return empty;
        }

        AttackJob job = data[front];    // get front job
        front = (front + 1) % 100;     // move front forward
        count--;
        return job;
    }

    // displayQueue shows all pending attacks in FIFO order
    void displayQueue() 
  {
        if (isEmpty()) 
        {
            cout << "No attacks in queue." << endl;
            return;
        }
        cout << "\n===== ATTACK QUEUE (FIFO ORDER) =====" << endl;
        cout << "First attack in line executes first" << endl;
        cout << "-------------------------------------" << endl;
        for (int i = 0; i < count; i++) 
        {
            int index = (front + i) % 100;
            cout << "POS-" << i + 1
                 << " | " << data[index].threatName
                 << " -> " << data[index].systemName << endl;
        }
        cout << "-------------------------------------" << endl;
        cout << "Total attacks waiting: " << count << endl;
    }
};
