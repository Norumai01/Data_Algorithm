/*
 Given an array positive numbers, find the maximum sum of a subsequence such that no two numbers in the sequence are adjacent in the array.
 Your algorithm should be O(n) where n is the number of elements in the array.
 Assume at least one element is present in the array
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::max;
using std::cout;
using std::endl;
using std::vector;

int maxSum(vector<int>& nums) {
// Your code here
	// Include current max at starting element.
	int incl = nums[0];
	int excl = 0;
	int excl_new = 0;

	for (int i = 1; i < nums.size(); i++) {
		// Current max excludes i.
		excl_new = max(incl, excl);
		
		// Incl is the current max sum and excl is the previous. 
		incl = excl + nums[i]; 
		excl = excl_new;
	}
	// Returns which incl or excl is the greatest. 
	return max(incl,excl);
}


int main() {
	vector<int> nums;
	// Test 1
	nums = {75, 105, 120, 75, 90, 135};
	cout << maxSum(nums) << endl; //330
	// Test 2
	nums = {5, 5, 10, 100, 10, 5};
	cout << maxSum(nums) << endl; //110
	// Test 3
	nums = {3, 2, 7, 10};
	cout << maxSum(nums) << endl; //13
	// Test 4
	nums = {3, 2, 5, 10, 7};
	cout << maxSum(nums) << endl; //15
}


