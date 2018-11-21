#include <iostream>

/* TIJIAO */
#include <vector> 
using namespace std;
typedef int Comparable;
Comparable find_median(const vector<Comparable> &l1, const vector<Comparable> &l2){
	int mid1 = (l1.size()+1) / 2 - 1, mid2 = l2.size() / 2 - 1;    // mid belongs to the left side.
	while(l1[mid1] > l2[mid2+1]){
		--mid1;
		++mid2;
	}
	while(l2[mid2] > l1[mid1+1]){
		--mid2;
		++mid1;
	}
	return l1[mid1]>l2[mid2] ? l1[mid1] : l2[mid2];
}
/* TIJIAO */

int main()
{
	vector<int> vec1, vec2;
	vec1.push_back(1);
	vec1.push_back(8);
	vec2.push_back(3);
	vec2.push_back(4);
	vec2.push_back(5);
	vec2.push_back(6);
	
	cout << find_median(vec1, vec2) << endl;
}
