#include <iostream>
#include <string>
using namespace std;

// STACK DATA STRUCTURE (LIFO)
// I use this to store alerts most recent alert always comes out first
struct Stack 
{

    string data[100];  // array that holds the alerts
    int top;           // tracks the top position

    // Constructor
    Stack() 
    {
        top = -1;
    }

    // isEmpty returns true if stack has nothing in it
    bool isEmpty() 
    {
        return top == -1;
    }

    // isFull returns true if stack has reached max capacity
    bool isFull() 
    {
        return top == 99;
    }

    // push adds a new alert on top of the stack
    void push(string alert) 
   {
        if (isFull()) 
        {
            cout << "[STACK] Stack is full." << endl;
            return;
        }
        top++;               
        data[top] = alert;   // store alert at new top
        cout << "[STACK] Alert pushed: " << alert << endl;
    }

    // pop removes and returns the top alert (LIFO)
    string pop() 
   {
        if (isEmpty()) 
        {
            cout << "[STACK] Stack is empty." << endl;
            return "";
        }
        string alert = data[top];  // get top alert
        top--;                     
        return alert;
    }

    // peek shows top alert without removing it
    string peek() 
    {
        if (isEmpty()) return "Stack is empty";
        return data[top];
    }

    // displayAll 
    void displayAll() 
   {
        if (isEmpty()) 
        {
            cout << "No alerts in stack." << endl;
            return;
        }
        cout << "\n===== ALERT STACK (LIFO ORDER) =====" << endl;
        cout << "Most recent alert is at the top" << endl;
        cout << "------------------------------------" << endl;
        for (int i = top; i >= 0; i--) 
        {
            cout << "TOP-" << (top - i)
                 << " | " << data[i] << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Total alerts: " << top + 1 << endl;
    }
};
