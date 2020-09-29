#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

template <typename T, typename comp>
T mymax(const T& a, const T& b, comp test) {
    // Implement your function to use your comparator
    if (test(a, b)) return a;
    
    return b;
}
   
   
// Write a comparator to compare the size of 2 vectors of ints and return true if 
//  and only if the first parameter is the larger sized vector 
struct size_comp {
    bool operator()(const vector<int>& v1, const vector<int>& v2) {
        return v1.size() > v2.size();
    }
};
  
// Write a comparator to compare the sum of two vectors of  ints and return
// true if and only if the first parameter  vector has the larger sum
struct sum_comp {
    bool operator()(const vector<int>& v1, const vector<int>& v2) {
        int v1sum = 0;
        for (int i = 0; i< v1.size(); i++) {
        v1sum += v1[i];
        }
        int v2sum = 0;
        for(int i = 0; i < v2.size(); i++) {
        v2sum += v2[i];
        }
        return v1sum > v2sum;
    }
};


int main(){
    vector<int> a(10);
    vector<int> b(11);
    
    for (int i = 0; i < 10; i++ ) {
        a[i] = 2*(i+1);
        b[i] = i+1;
    }
    
    b[10] = 11;

    // Instantiate your size comparator
    size_comp c1;
    // Instantiate your sum comparator
    sum_comp c2;
    // Test each comparator with the vectors a, b and the function max
    vector<int> bigger_size = mymax(a, b, c1);
    if (bigger_size == a) {
        cout << "Vector A has a bigger size" << endl;
    } else {
        cout << "Vector B has a bigger size" << endl;
    }
    vector<int> bigger_sum = mymax(a, b, c2);
    if (bigger_sum == a) {
        cout << "Vector A has a bigger sum" << endl;
    } else {
        cout << "Vector B has a bigger sum" << endl;
    }
}
