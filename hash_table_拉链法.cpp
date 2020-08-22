#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
const int HASH_SIZE = 13;

class HashTable {
private:
	list<int> table[HASH_SIZE];
	int myhash(int value) const {
		return value % HASH_SIZE;
	}
public:
	HashTable() {}
	void clear() {
		for (int i = 0; i < HASH_SIZE; i++) {
			table[i].clear();
		}
	}
	bool insert(const int &data) {
		int hashValue = myhash(data);
		if (find(table[hashValue].begin(), table[hashValue].end(), data) == table[hashValue].end()) {
			table[myhash(data)].push_back(data);
			return true;
		}
		else {
			return false;
		}
	}
	const int operator[](const int data) const {    // retrieve 
		int hashValue = myhash(data);
		auto result = find(table[hashValue].begin(), table[hashValue].end(), data);
		if (result != table[hashValue].end()) {
			return *result;
		}
		else {
			return INT_MAX;
		}
	}
};

int main()
{
	HashTable test;
	test.insert(13);
	test.insert(39);
	test.insert(25);
	test.insert(26);
	test.insert(26);
	test.insert(26);

	cout << test[10] << endl;
	cout << test[39] << endl;
	cout << test[13] << endl;
	cout << test[26] << endl;
	system("pause");
}
