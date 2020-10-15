
#include <iostream>
#include <vector>
#include <string>
using namespace std;


void print_subsetsHelper(vector<string> stringSet, int k, vector<string> subset, int element) {
    if (subset.size() == k) {
        for (string s : subset) {
            cout << s << " ";
        }
        cout << endl;
    } else {
        if (element >= stringSet.size()) return;

        subset.push_back(stringSet[element]);
        print_subsetsHelper(stringSet, k, subset, element + 1);
        subset.pop_back();
        print_subsetsHelper(stringSet, k, subset, element + 1);
    }
}

// Implement this function recursively.
// You may use helper functions.
void print_subsets (vector<string> stringSet, int k) {
    vector<string> subset;
    print_subsetsHelper(stringSet, k, subset, 0);
}


int main()
{
    vector<string> s = {"cat", "dog", "rabbit", "robot"};
    print_subsets(s,3);
    return 0;
}
