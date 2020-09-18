/*
Description
 一个后缀表达式可能包含浮点数，小写英文字母和＋，－，＊和／等运算。表达式可能包含空格。
例如，12.02  x + 2  3 * +.
请设计一个计算后缀表达式值的函数。

Input
第一行是一个正整数，表示测试样例数。接下来是若干测试样例。
每个测试样例的第一行是一个后缀表达式，第二行是其中字母出现的个数，然后是每个字母及其代入值。

Output
 对每个测试样例，输出表达式的值，保留3位小数。每个输出占一行。如果表达式中有除数为0的情况，则除数‘Error'.

Sample Input
2
ab + 2.3 +
2
a:1
b:2.1
a b/
2
a:1
b:0

Sample Output
5.400
Error
*/
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <string>
using namespace std;
double eval(string e, map<char, double> f);

int main() {
    int t;
    cin >> t;
    cin.clear();
    cin.ignore();  // Eat the '\n'.
    while (t--) {
        string s;
        getline(cin, s);
        int n;
        cin >> n;
        cin.clear();  // Don't forget this!
        cin.ignore();
        map<char, double> mymap;
        while (n--) {
            char tmp_c;
            double tmp_d;
            cin >> tmp_c;
            cin.clear();
            cin.ignore();  // Eat the ':'.
            cin >> tmp_d;
            cin.clear();
            cin.ignore();  // Eat the '\n'.
            mymap[tmp_c] = tmp_d;
        }

        try {
            cout << fixed << setprecision(3) << eval(s, mymap) << endl;
        } catch (const char*) {
            cout << "Error" << endl;
        }
    }
    return 0;
}

double eval(string e, map<char, double> f) {
    stack<double> stk;
    for (int i = 0; i < e.length(); i++) {
        char c = e[i];

        if (c >= '0' && c <= '9') {
            ostringstream os;
            while ((e[i] >= '0' && e[i] <= '9') || e[i] == '.') {  // Read the whole number into os.
                os << e[i];
                i++;
            }
            stk.push(stod(os.str()));
        } else if (c >= 'a' && c <= 'z') {
            stk.push(f[c]);
        } else {
            if (c == '+') {
                double z = stk.top();
                stk.pop();
                double y = stk.top();
                stk.pop();
                stk.push(y + z);
            }
            if (c == '-') {
                double z = stk.top();
                stk.pop();
                double y = stk.top();
                stk.pop();
                stk.push(y - z);
            }
            if (c == '*') {
                double z = stk.top();
                stk.pop();
                double y = stk.top();
                stk.pop();
                stk.push(y * z);
            }
            if (c == '/') {
                double z = stk.top();
                stk.pop();
                double y = stk.top();
                stk.pop();
                if (z == 0) {
                    throw "Division by zero.";
                }
                stk.push(y / z);
            }
        }
    }
    return stk.top();
}
