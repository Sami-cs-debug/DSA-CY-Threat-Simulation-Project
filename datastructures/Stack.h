#include <iostream>
#include <string>
using namespace std;

// ── STACK DATA STRUCTURE ─────────────────────────────────────
// Works like a pile of plates
// You can only add or remove from the TOP
// This is called LIFO - Last In First Out
// We use this to store alerts
// The most recent alert always comes out first
// Just like a real security dashboard

struct Stack {

    string data[100];  // array that holds the alerts
    int top;           // tracks the top position

    // Constructor - stack starts empty
    // top = -1 means nothing is in the stack yet
    Stack() {
        top = -1;
    }

    // ── isEmpty ───────────────────────────────────────────────
    // Returns true if stack has nothing in it
    // top == -1 means we never pushed anything
    bool isEmpty() {
        return top == -1;
    }

    // ── isFull ────────────────────────────────────────────────
    // Returns true if stack has reached max capacity
    bool isFull() {
        return top == 99;
    }

    // ── push ──────────────────────────────────────────────────
    // Adds a new alert on top of the stack
    // Every time an attack happens we push an alert here
    void push(string alert) {
        if (isFull()) {
            cout << "[STACK] Stack is full." << endl;
            return;
        }
        top++;               // move top up by one
        data[top] = alert;   // store alert at new top
        cout << "[STACK] Alert pushed: " << alert << endl;
    }

    // ── pop ───────────────────────────────────────────────────
    // Removes and returns the top alert
    // This proves LIFO - last alert pushed comes out first
    string pop() {
        if (isEmpty()) {
            cout << "[STACK] Stack is empty." << endl;
            return "";
        }
        string alert = data[top];  // get top alert
        top--;                     // move top down by one
        return alert;
    }

    // ── peek ──────────────────────────────────────────────────
    // Shows top alert without removing it
    string peek() {
        if (isEmpty()) return "Stack is empty";
        return data[top];
    }

    // ── displayAll ────────────────────────────────────────────
    // Shows all alerts from top to bottom
    // Proves LIFO order visually to the teacher
    void displayAll() {
        if (isEmpty()) {
            cout << "No alerts in stack." << endl;
            return;
        }
        cout << "\n===== ALERT STACK (LIFO ORDER) =====" << endl;
        cout << "Most recent alert is at the top" << endl;
        cout << "------------------------------------" << endl;
        for (int i = top; i >= 0; i--) {
            cout << "TOP-" << (top - i)
                 << " | " << data[i] << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Total alerts: " << top + 1 << endl;
    }
};
