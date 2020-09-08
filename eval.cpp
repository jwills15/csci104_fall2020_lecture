#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

//double evaluate(string exp);
/** evaluate(“( ( 5 * 4 ) * (  2 + 3 ) )”) should return the value 100.0 **/
/** evaluate(“(  (1 + ( 5 * ( 3 + 1 ) ) ) / 4 )”) should return the value 5.25 **/


double evaluate(string expr){
    stringstream s(expr);
    string current_token;
    stack<string> ops;
    stack<double> vals;

    while (s >> current_token) {
        if (current_token == "(" || current_token == "*" || current_token == "+" || current_token == "-" || current_token == "/") {
            ops.push(current_token);
        }
        else if (current_token == ")") {
            double val1 = vals.top();
            vals.pop();
            string op = ops.top();
            ops.pop();
            while (op != "(") {
                if (op == "*") {
                    val1 *= vals.top();
                    vals.pop();
                }
                else if (op == "-") {
                    val1 = vals.top() - val1;
                    vals.pop();
                }
                else if (op == "+") {
                    val1 += vals.top();
                    vals.pop();
                }
                else if (op == "/") {
                    val1 = vals.top() / val1;
                    vals.pop();
                }

                op = ops.top();
                ops.pop();
            }
            vals.push(val1);
        }
        else {
            vals.push(stod(current_token));
        }
    }

    return vals.top();
}



int main()
{
    string test = "( ( 1 + ( 5 * ( 3 + 1 ) ) ) / 4 )";
    cout <<evaluate(test) << endl; // should print value 5.25
    cout << evaluate("( ( 5 * 4 ) * (  2 + 3 ) )") << endl; // should print value 100
    return 0;
}
