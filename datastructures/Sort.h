#include <iostream>
#include "Array.h"
using namespace std;

// Bubble Sort 
void bubbleSort(SystemArray& systems) 
{
 int pass = 0;
    int n = systems.count;
    SystemNode temp;

    cout << "Input list ...\n";	
    
    for (int i = 0; i < n - 1; i++)
	 {
	 	
        for (int j = 0; j < n - i - 1; j++)
		 {
    if(systems.data[j].vulnerabilityLevel < systems.data[j + 1].vulnerabilityLevel)
{
temp = systems.data[j];
systems.data[j] = systems.data[j + 1];
systems.data[j + 1] = temp;
    
      }              
        }
        pass++;
    }
    cout << "\n[SORTED] Systems sorted highest to lowest." << endl;
}

void displaySorted(SystemArray& systems) 
{
    cout << "\n===== SYSTEMS BY VULNERABILITY =====" << endl;
    for (int i = 0; i < systems.count; i++)
	 {
       cout << i + 1 << endl;
        cout << systems.data[i].name << endl;
        cout << systems.data[i].vulnerabilityLevel << endl;
        cout << endl;  
    }
}
