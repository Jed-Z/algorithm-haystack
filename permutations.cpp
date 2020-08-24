#include <iostream>
//---------------------
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		if(nums.size() == 1) {
			result.push_back(nums);
		}
		else {
	    	sort(nums.begin(), nums.end());
	    	int last_num;
	    	
			for(int i = 0; i < nums.size(); i++) {
				if(i>0 && nums[i]==last_num) {
					continue;
				}
				else {
					last_num = nums[i];
				}
				int current = nums[i];
				vector<int> remain_nums = nums;
				remain_nums.erase(remain_nums.begin() + i);
				auto remain_permu = permuteUnique(remain_nums);
				for(int j = 0; j < remain_permu.size(); j++) {
					remain_permu[j].insert(remain_permu[j].begin(), current);
					result.push_back(remain_permu[j]);
				}
			}
		}
		return result;
    }
};
//---------------------

int main()
{
	Solution s;
	vector<int> vec = {1, 1, 2};
	auto result = s.permuteUnique(vec);
	for(int i = 0; i < result.size(); i++) {
		for(int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
