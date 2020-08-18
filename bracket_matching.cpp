#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool is_left_bracket(char c) {
    return c == '(' || c == '[' || c == '{';
}
bool is_right_bracket(char c) {
    return c == ')' || c == ']' || c == '}';
}

bool bracket_match(char c1, char c2) {
    if (is_left_bracket(c1) && is_right_bracket(c2)) {
        if (c1 == '(' && c2 == ')') {
            return true;
        } else if (c1 == '[' && c2 == ']') {
            return true;
        } else if (c1 == '{' && c2 == '}') {
            return true;
        } else
            return false;
    } else {
        return false;
    }
}

bool check_matching(string exp) {
    stack<char> stk;
    for (char c : exp) {
        if (is_left_bracket(c)) {
            stk.push(c);
        } else if (is_right_bracket(c)) {
            if (!stk.empty() && bracket_match(stk.top(), c)) {
                stk.pop();
            } else {
                return false;
            }
        }
    }
    return stk.empty();
}

int main() {
    string expression;
    getline(cin, expression);
    cout << (check_matching(expression) ? "Yes" : "No") << endl;
    return 0;
}