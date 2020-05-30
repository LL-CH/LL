#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

//效率太低
//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		priority_queue<int> q;
//		for (auto a : nums)
//		{
//			q.push(a);
//		}
//		for (int i = 0; i < k - 1; i++)
//		{
//			q.pop();
//		}
//		return q.top();
//	}
//};

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		//建立k个数的小堆
		priority_queue<int, vector<int>, greater<int>> heap;
		size_t i = 0;
		for (i; i < k; i++){
			heap.push(nums[i]);
		}
		for (i; i<nums.size(); i++)
		{
			if (nums[i]>heap.top())
			{
				heap.pop();
				heap.push(nums[i]);
			}
		}
		return heap.top();
	}
};

int main(){
	Solution s1;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(8);
	nums.push_back(5);
	cout << s1.findKthLargest(nums, 3)<<endl;


	system("pause");
}