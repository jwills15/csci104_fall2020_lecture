#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isParenthesized(string expr) {
    stack<char> s;
    for (char c : expr) {
        if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
            s.pop();
        }
        else if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
    }

    if (!s.empty()) {
        return false;
    }

    return true;
}

int main()
{
    string test = "(9+8";
    cout << boolalpha << isParenthesized(test) << endl;
    return 0;
}
