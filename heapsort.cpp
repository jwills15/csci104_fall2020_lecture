#include <iostream> 
#include <queue> 
#include <stdlib.h>
using namespace std; 

int main () 
{
    // how to get a random integer between 0 and 999
    int k = rand()%1000;
    
    cout<< "Sorting elements..." << endl;
    // print integers in order from smallest to largest
    priority_queue<int, vector<int>, greater<int>> elements;
    
    for (int i = 0; i < 10; ++i) {
        elements.push(rand()%1000);
    }

    while (!elements.empty()) {
        cout << elements.top() << endl;
        elements.pop();
    }


}
