/* *************************
* FileName: HuffmanCoding.cpp
* Author: Jed Zhang
* Site: https://www.jedbit.com
* Date: 2018.7.4
* Description:
**************************/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<char, int> makeTable(const string str)
{
	map<char, int> table;
	for (char c : str) {
		table[c] += 1;
	}
	return table;
}
bool compare(pair<int, vector<char>> x, pair<int, vector<char>> y)
{
	return x.first > y.first;
}
int main()
{
	string ipt;
	while (getline(cin, ipt)) {
		auto table = makeTable(ipt);	// table
		vector<pair<int, vector<char>>> weights;	// weights
		for (auto it = table.begin(); it != table.end(); it++) {
			vector<char> temp;
			temp.push_back(it->first);
			weights.push_back(pair<int, vector<char>>(it->second, temp));
			//cout << it->first << " : " << it->second << " 次" << endl;
		}
		//cout << endl;

		map<char, int> codelen;	// codelen
		for (auto x : table) {
			codelen[x.first] = 0;
		}
		//for (auto it = codelen.begin(); it != codelen.end(); it++) {
		//	cout << it->first << " ~ " << it->second << endl;
		//}
		//cout << endl;

		sort(weights.begin(), weights.end(), compare);
		//for (auto it = weights.begin(); it != weights.end(); it++) {
		//	cout << it->first << " ## ";
		//	for (auto iter = it->second.begin(); iter != it->second.end(); iter++) {
		//		cout << *iter << " ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;

		/* 开始计算 */
		while (weights.size() > 1) {
			sort(weights.begin(), weights.end(), compare);
			int temp_weight = 0;
			vector<char> temp_vec;
			for (int i = 0; i < 2; i++) {
				temp_weight += weights.back().first;
				for (auto x : weights.back().second) {
					codelen[x]++;
					temp_vec.push_back(x);
				}
				weights.pop_back();
			}
			weights.push_back(pair<int, vector<char>>(temp_weight, temp_vec));
		}


		//for (auto it = codelen.begin(); it != codelen.end(); it++) {
		//	cout << it->first << " ~ " << it->second << endl;
		//}
		//cout << endl;

		int result = 0;
		for (auto it = codelen.begin(); it != codelen.end(); it++) {
			result += it->second * table[it->first];
		}
		cout << result << endl;
	}

	return 0;
}
