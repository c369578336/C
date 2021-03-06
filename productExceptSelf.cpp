// productExceptSelf.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int length = nums.size();
		vector<int> l(length);
		l[0] = 1;
		l[length - 1] = 1;
		int r=1;
		for (int i = 1; i < length; i++)
		{
			l[i] = l[i - 1] * nums[i - 1];
		}
		for (int i = length-1; i >= 0; i--)
		{
			l[i] *= r;
			r *= nums[i];
		}
		return l;
	}
};

int main()
{
	vector<int> nums{ 1, 2, 3, 4, 5 };
	Solution a;
	nums=a.productExceptSelf(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i]<<' ';
	}
    return 0;
}

