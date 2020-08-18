#include <iostream>
using namespace std;

int fastModularExponent(int b, int n, int m) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        int temp = fastModularExponent(b, n / 2, m);
        return temp * temp % m;
    } else {
        int temp = fastModularExponent(b, n / 2, m);
        return (b % m) * (temp * temp % m) % m;
    }
}

int main() {
    cout << fastModularExponent(123453, 4456456, 7277) << endl;
    return 0;
}