#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int find_num(vector<int>& nums, int target) {
	int i = 0;
	while (i < nums.size()) {
		if (nums[i] == target) return i;
		i++;
	}
	return -1;
}

int search(vector<int>& nums, int target) {
	int start = 0, bound = nums.size() - 1, mid, tag;
	if (nums.size() < 4) return find_num(nums, target);
	if (nums[start] > target) {
		swap(start, bound);
		tag = nums[start];
		while (bound < start) {
			mid = (bound + start) / 2;
			while (nums[mid] > tag) {
				bound = mid + 1;
				mid = (bound + start) / 2;
			}
			if (nums[mid] < target) {
				bound = mid + 1;				//二分法向下取整，不能向上直至相等	case	[4,5,6,7,0,1,2] 3					
			}
			else if (nums[mid] > target) {
				start = mid;
			}
			else return mid;
		}
	}
	else {
		tag = nums[start];
		while (start < bound && nums[start] >= tag) {
			mid = (start + bound) / 2;
			while (nums[mid] < tag) {
				bound = mid;
				mid = (bound + start) / 2;
			}
			if (nums[mid] < target) {
				start = mid + 1;
			}
			else if (nums[mid] > target) {
				bound = mid;
			}
			else return mid;
		}
	}
	return nums[bound] == target ? bound : -1;
}

int main() {
	vector<int> nums;
	ifstream infile("test.txt");
	int target;
	infile >> target;
	int temp;
	while (infile >> temp) {
		nums.push_back(temp);
	}
	cout << search(nums, target) << endl;
	return 0;
}

/* Reference: simpler and better
* int search(int A[], int n, int target) {
        int lo=0,hi=n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(A[mid]>A[hi]) lo=mid+1;
            else hi=mid;
        }
        // lo==hi is the index of the smallest value and also the number of places rotated.
        int rot=lo;
        lo=0;hi=n-1;
        // The usual binary search and accounting for rotation.
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int realmid=(mid+rot)%n;
            if(A[realmid]==target)return realmid;
            if(A[realmid]<target)lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
*/