#include <iostream>
using namespace std;
int foo(int, int, int);
int main()
{
	cout << foo(123453, 4456456, 7277) << endl;
	system("pause");
}
int foo(int b, int n, int m)
{
	if(n==0) {
		return 1;
	}
	if(n%2==0) {
		int temp = foo(b, n / 2, m);
		return temp * temp % m;
	} else {
		int temp = foo(b, n / 2, m);
		return (b % m) * (temp * temp % m) % m;
	}
}
