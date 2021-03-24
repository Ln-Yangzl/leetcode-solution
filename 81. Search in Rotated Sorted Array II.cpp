#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//we try to find the pivot first, and then apply the normal binary search
bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        // for the situation 1, 3, 1, 1, 1 and 1, 1, 1, 3, 1 
        if (nums[left] == nums[right] && nums[left] == nums[mid]) {
            int i = mid;
            while (i != right && nums[i] == nums[mid]) i++;
            mid = i == right ? mid : i;
        }
        if (nums[mid] > nums[right]) left = mid + 1;
        else right = mid;
    }
    while (left > 0 && nums[left] == nums[left - 1]) left--;
    int pivot = left;
    left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int real_mid = (mid + pivot) % n;
        if (nums[real_mid] > target) right = mid - 1;
        else if (nums[real_mid] < target) left = mid + 1;
        else return true;
    }
    return false;
}

// we found that when we devided the arrary into two apart, at least one part is in order
// so we just judge whether the number is in ordered part, if is not ,the number is in the other part
// however, we still need to handle the situation 1, 3, 1, 1, 1

bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, mid;

    while (left <= right)
    {
        mid = (left + right) >> 1;
        if (nums[mid] == target) return true;

        // the only difference from the first one, trickly case, just updat left and right
        if ((nums[left] == nums[mid]) && (nums[right] == nums[mid])) { ++left; --right; }

        else if (nums[left] <= nums[mid])
        {
            if ((nums[left] <= target) && (nums[mid] > target)) right = mid - 1;
            else left = mid + 1;
        }
        else
        {
            if ((nums[mid] < target) && (nums[right] >= target)) left = mid + 1;
            else right = mid - 1;
        }
    }
    return false;
}