#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

// we start from nums1[m] to store the new number
// we reverse the array at the end to make it in right order
//void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//    int total = m + n;
//    int count_m = 0, count_n = 0, i;
//    for (i = m; count_m < m && count_n < n; i++) {
//        int temp;
//        if (nums1[count_m] < nums2[count_n]) {
//            temp = nums1[count_m++];
//        }
//        else {
//            temp = nums2[count_n++];
//        }
//        nums1[i % total] = temp;
//    }
//    if (count_m == m) {
//        while (count_n < n) {
//            nums1[i++ % total] = nums2[count_n++];
//        }
//    }
//    else {
//        while (count_m < m) {
//            nums1[i++ % total] = nums1[count_m++];
//        }
//    }
//    reverse(nums1.begin(), nums1.begin() + m);
//    reverse(nums1.begin() + m, nums1.end());
//    reverse(nums1.begin(), nums1.end());
//}

// we begin from the end to store the nums, which avoids reversing the arr at the end
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;
	while (i >= 0 && j >= 0)
	{
		if (nums1[i] > nums2[j])
			nums1[k--] = nums1[i--];
		else
			nums1[k--] = nums2[j--];
	}
	while (j >= 0)
		nums1[k--] = nums2[j--];
}