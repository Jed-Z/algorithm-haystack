#include <iostream>
#include <string>
#include <stack>
using namespace std;

string in_to_post(string postfix);
bool isoperator(char c);
int priority(char c);

int main()
{
	int t;
	cin >> t;
	while(t--){
		string infix;
		cin >> infix;
		cout << in_to_post(infix) << endl;
	}
	return 0;
}

string in_to_post(string infix)
{
	string result;
	stack<char> stk;
	for (char c : infix) {
		if (isoperator(c)) {	// In this case, '(' and ')' are not operators. 
			if (stk.empty() || priority(c)<priority(stk.top())) {
				stk.push(c);
			}
			else {
				while (!stk.empty() && c!='(' && c!=')' && priority(c) >= priority(stk.top())) {
					result += stk.top();
					stk.pop();
				}
				stk.push(c);
			}
		}
		else if(c=='('){
			stk.push(c);
		}
		else if(c==')'){
			while(!stk.empty() && stk.top()!='('){
				result += stk.top();
				stk.pop();
			}
			stk.pop();	// Pop the remaining '('. 
		}
		else {
			result += c;
		}
	}
	while (!stk.empty()) {
		result += stk.top();
		stk.pop();
	}
	return result;
}
bool isoperator(char c) {
	if (string("+-*/%").find(c) != string::npos) {
		return true;
	}
	else { return false; }
}
/* Priority Function
This function is used to determine an operator's priority.
Note that the priority is higher when the function returns a SMALLER value.
*/
int priority(char c) {
	if (isoperator(c)) {
		switch (c) {
		case '*':
		case '/':
		case '%':
			return 3;
		case '+':
		case '-':
			return 4;
		}
	}
	return 9;
}
