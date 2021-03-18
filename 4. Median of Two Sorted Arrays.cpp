#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;		using std::cin;
using std::cout;		using std::endl;
using std::min;


/*以下是二分查找方法*/
/*找到第key小的数据*/
int find_key_num(vector<int>& nums1, vector<int>& nums2, int k)
{
	int size1 = nums1.size(), size2 = nums2.size();
	int ptr1 = 0, ptr2 = 0;

	while (true)
	{
		//已达边界情况
		if (ptr1 == size1) {
			return nums2[ptr2 + k - 1];
		}
		if (ptr2 == size2) {
			return nums1[ptr1 + k - 1];
		}
		if (k == 1) {
			return min(nums1[ptr1], nums2[ptr2]);
		}

		int new_ptr1 = min(ptr1 + k / 2 - 1, size1 - 1);
		int new_ptr2 = min(ptr2 + k / 2 - 1, size2 - 1);
		if (nums1[new_ptr1] <= nums2[new_ptr2]) {
			k -= new_ptr1 - ptr1 + 1;
			ptr1 = new_ptr1 + 1;
		}
		else {
			k -= new_ptr2 - ptr2 + 1;
			ptr2 = new_ptr2 + 1;
		}
	}
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	int totalLength = nums1.size() + nums2.size();
	if (totalLength % 2 == 1) {
		return find_key_num(nums1, nums2, (totalLength + 1) / 2);
	}
	else {
		return (find_key_num(nums1, nums2, totalLength / 2) + find_key_num(nums1, nums2, totalLength / 2 + 1)) / 2.0;
	}

}

int main()
{
	vector<int> nums1 = { 1,3 };
	vector<int>	nums2 = { 2 };
	double result = findMedianSortedArrays(nums1, nums2);
	cout << result << endl;
	return 0;
}