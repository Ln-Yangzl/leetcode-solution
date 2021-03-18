#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int left = 0, right = nums.size();
	nums.push_back(INT_MAX);
	while (left < right) {
		int mid = (left + right) / 2;
		if (nums[mid] < target) left = mid + 1;
		else if (nums[mid] > target) right = mid;
		else return mid;
	}
	return right;
}

/* Reference: it's important to handle the situation[1,3,5,6] 7 expecte 4
* int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;

        // Invariant: the desired index is between [low, high+1]
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }

        // (1) At this point, low > high. That is, low >= high+1
        // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
        // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
        //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
        return low;
    }
*/