#include <iostream>
#include <string>
using namespace std;

// STACK DATA STRUCTURE (We use this to store alerts )
struct Stack 
{
    string data[100];  
    int top;           

    // Constructor
    Stack() 
   {
        top = -1;
    }

    // ── isEmpty (Returns true if stack has nothing in it)
    bool isEmpty() 
    {
        return top == -1;
    }

    // isFull (Returns true if stack has reached max capacity)
    bool isFull() 
   {
        return top == 99;
    }

    // push (Every time an attack happens we push an alert here)
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

    // pop (Removes and returns the top alert)
    string pop() 
{
        if (isEmpty()) {
            cout << "[STACK] Stack is empty." << endl;
            return "";
        }
        string alert = data[top];  // get top alert
        top--;                     // move top down by one
        return alert;
    }

    // peek (Shows top alert without removing it)
    string peek() 
   {
        if (isEmpty()) 
            return "Stack is empty";
        return data[top];
    }

    // displayAll (Shows all alerts from top to bottom)
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
