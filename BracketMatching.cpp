/*
Author: Jed Zhang
DateTime: 20180917 17:07
Note: 用STL的stack实现括号匹配。这是注重模块化（函数化）的写法，方便未来增加括号种类。
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check_matching(string exp);
bool is_left_bracket(char c);
bool is_right_bracket(char c);
bool bracket_match(char c1, char c2);
int main()
{
	int n;
	cin >> n;
	cin.clear();	// Discard the '\n' so that getline() will work correctly.
	cin.ignore();
	while(n--) {
		string expression;
		getline(cin, expression);
		cout << (check_matching(expression) ? "Yes" : "No") << endl;
	}
	return 0;
}

bool check_matching(string exp)
{
	stack<char> stk;
	for(char c: exp) {
		if(is_left_bracket(c)){
			stk.push(c);
		}
		else if(is_right_bracket(c)){
			if(!stk.empty() && bracket_match(stk.top(), c)){
				stk.pop();
			}
			else{
				return false;
			}
		}
	}
	if(stk.empty()){
		return true;
	}
	else{
		return false;
	}
}

bool is_left_bracket(char c)
{
	if(c=='('||c=='['||c=='{') {
		return true;
	} 
	else {
		return false;
	}
}
bool is_right_bracket(char c){
	if(c==')'||c==']'||c=='}') {
		return true;
	} 
	else {
		return false;
	}
}
bool bracket_match(char c1, char c2){
	if(is_left_bracket(c1) && is_right_bracket(c2)){
		if(c1=='(' && c2==')'){ return true; }
		else if(c1=='[' && c2==']'){ return true; }
		else if(c1=='{' && c2=='}'){ return true; }
		else return false;
	}
	else {return false; }
}
