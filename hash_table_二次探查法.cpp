#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int HASH_SIZE = 13;

class HashTable {
private:
    int table[HASH_SIZE];
    int myhash(int value) const {
        return value % HASH_SIZE;
    }
public:
    HashTable() {
        clear();
    }
    void clear() {
        for (int i = 0; i < HASH_SIZE; i++) {
            table[i] = INT_MAX;
        }
    }
    bool insert(const int &data) {
        /* 二次探查法 */
        int hashValue = myhash(data);
        int increment = 1;
        int probeCount = 0;
        while (probeCount++ < (HASH_SIZE + 1) / 2) {
            if (table[hashValue] == INT_MAX || table[hashValue] == data) {
                table[hashValue] = data;
                return true;
            }
            else {
                hashValue = (hashValue + increment) % HASH_SIZE;
                increment += 2;
            }
        }
        return false;
    }
    const int &operator[](const int& data) const {
        int hashValue = myhash(data);
        int increment = 1;
        int probeCount = 0;
        while (probeCount++ < (HASH_SIZE + 1) / 2) {
            if (table[hashValue] == data) {
                return data;
            }
            else {
                hashValue = (hashValue + increment) % HASH_SIZE;
                increment += 2;
            }
        }
        return INT_MAX;
    }
    void print() const {
        for (int i = 0; i < HASH_SIZE; i++) {
            if (table[i] != INT_MAX) {
                cout << table[i] << " ";
            }
            else {
                cout << "X ";
            }
        }
        cout << endl;
    }
};

int main()
{
    HashTable test;
    test.insert(26);
    test.insert(15);
    test.print();
    cout << test[26] << endl;
    cout << test[13] << endl;
    test.insert(16);
    test.insert(33);
    test.insert(100);
    test.insert(0);
    test.insert(28);
    test.print();
    cout << test[100] << endl;
    cout << test[99] << endl;
    cout << test[28] << endl;
    system("pause");
}