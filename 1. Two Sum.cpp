#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using std::cin;		using std::cout;
using std::vector;	using std::copy;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> ans;
	vector<int> temp;
	temp = nums;
	int n = temp.size();
	std::sort(temp.begin(), temp.end());
	int i = 0, j = n - 1;
	while (i < j) 
	{
		if (temp[i] + temp[j] > target)j--;
		else if (temp[i] + temp[j] < target)i++;
		else break;
	}
	if (i < j) 
	{
		for (int k = 0; k < n; k++) 
		{
			if (i < n && nums[k] == temp[i])
			{
				ans.push_back(k);
				i = n;
			}
			else if (j < n && nums[k] == temp[j]) 
			{
				ans.push_back(k);
				j = n;
			}
			if (i == n && j == n)return ans;
		}
	}
	return ans;
}


int main()
{
	vector<int> nums, result;
	int temp, target;
	copy(std::istream_iterator<int>(cin), std::istream_iterator<int>(), std::back_insert_iterator<vector<int>>(nums));
	cin.clear();
	cin >> target;
	result = twoSum(nums, target);
	copy(result.begin(), result.end(), std::ostream_iterator<int>(cout, " "));
	return 0;
}