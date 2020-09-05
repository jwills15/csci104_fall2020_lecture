#include "int_queue.h"
#include "int_queue_list.h"
#include "int_queue_vector.h"
#include <iostream>
#include <chrono>


using namespace std;


int main(){

    // Change this for whatever queue you are testing
    list_IntQueue test_queue;
    vector_IntQueue vt_queue;
//    AbstractIntQueue &q = vt_queue;
    AbstractIntQueue &q = test_queue;




//  This should be constant time in both implemenations, e.g. O(1)
    cout << boolalpha << q.empty() << endl;

  // Is there any difference between the STL List and Queue implementations
  // for adding to the end of the queue? Run tests increasing the size...
  // What measurements can you take? Time for timing experiments.
    for (size_t i = 0; i < 100000; i++){
         q.push_back(i);
    }


//  This should be constant time in both implemenations, e.g. O(1)
    cout << q.size() << endl;

  // Is there any difference between the STL List and Queue implementations
  // for adding to the end of the queue? Run tests increasing the size...
  // What measurements can you take? Time for timing experiments.
  // Print queue elements and remove them from the front

  // Start the timer by getting the current time
  std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

  while (!q.empty()) {
//     cout << q.front() << " "; // Should be O(1) in both
     q.pop_front(); // Which is faster??
  }
 // cout << endl;

   // End timer by getting current time when you have finished what you
   // would like to measure
  std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();

  // Get the duration of your experiment
  std::chrono::duration<double, std::milli> fp_ms = stop - start;

  // Output or save the duration of your experiment
  cout << "The experiment took " << fp_ms.count() << " ms" << endl;
}
