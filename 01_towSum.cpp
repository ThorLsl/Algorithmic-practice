﻿#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
/*
 *给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
 *你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 *
 *示例 :
 *	给定 nums = [2, 7, 11, 15], target = 9
 *	因为 nums[0] + nums[1] = 2 + 7 = 9
 *	所以返回[0, 1]
 *
 *	来源：力扣（LeetCode）
 *	链接：https ://leetcode-cn.com/problems/two-sum
 *	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
public:
	/*两数之和--解法一*/
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		for (int i = 0; i < nums.size(); ++i)
		{
			int k = target - nums.at(i);
			for (int j = 0; j < nums.size(); ++j)
			{
				if (i == j) continue;
				if (k == nums.at(j))
				{
					ret.push_back(i);
					ret.push_back(j);
					return ret;
				}
			}
		}
		return ret;
	}

	/*两数之和--解法二*/
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> answer;
		unordered_map<int, int> dictionary;
		dictionary.clear();
		for (int i = 0; i < nums.size(); i++)
		{
			int complement = target - nums.at(i);
			auto result = dictionary.find(complement);
			if (result != dictionary.end())
			{
				answer.push_back(dictionary.at(complement));
				answer.push_back(i);
				break;
			}
			else
			{
				dictionary.emplace(nums.at(i), i);
			}
		}
		return answer;
	}

};
/*
int main()
{
	vector<int> l1 = { 2,7,11,15 };
	vector<int> l2;
	Solution p;
	l2 = p.twoSum(l1, 9);
	system("pause");
	return 0;
}
*/