#include<iostream>
#include<algorithm>
#include<vector>

using std::vector;		using std::cout;
using std::endl;		using std::max;
using std::min;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	if (nums1.size() > nums2.size()) {
		return findMedianSortedArrays(nums2, nums1);
	}

	int size1 = nums1.size(), size2 = nums2.size();
	int left = 0, right = size1;
	//���������Ҫ��Ԫ�ظ���
	int total_left = (size1 + size2 + 1) / 2;

	while (left < right)
	{
		//nums1�ķָ���
		int i = (left + right + 1) / 2;
		//nums2�ķָ���
		int j = total_left - i;
		int nums1_left_max = i == 0 ? INT_MIN : nums1[i - 1];
		int nums2_right_min = j == size2 ? INT_MAX : nums2[j];
		/*
		 *�����ƼȲ���Խ�磬Ҳ����������ѭ��
		 *��߽���Զ����һ�������ָ��߰�������
		 *����һ��Ѱ�Ҳ����ظ�Ѱ����һ���ҵ��ı߽�
		*/
		if (nums1_left_max <= nums2_right_min) {
			left = i;
		}
		else {
			right = i - 1;
		}
	}

	int i = (left + right + 1) / 2, j = total_left - i;
	//��Խ�磬��ֵΪ�����Сֵ
	int nums1_left_max = i == 0 ? INT_MIN : nums1[i - 1];
	int nums2_left_max = j == 0 ? INT_MIN : nums2[j - 1];
	int nums1_right_min = i == size1 ? INT_MAX : nums1[i];
	int nums2_right_min = j == size2 ? INT_MAX : nums2[j];

	if ((size1 + size2) % 2) {
		return max(nums1_left_max, nums2_left_max);
	}
	else {
		return (max(nums1_left_max, nums2_left_max) + min(nums1_right_min, nums2_right_min)) / 2.0;
	}
}

int main()
{
	vector<int> nums1 = { 3 };
	vector<int>	nums2 = { -2,-1 };
	double result = findMedianSortedArrays(nums1, nums2);
	cout << result << endl;
	return 0;
}