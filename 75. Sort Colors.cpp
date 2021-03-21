#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void sortColors(vector<int>& nums) {
    // store the number 0 and 2 from start and end, make 'zero' and 'two' to point the valible pos
    int zero = 0, two = nums.size() - 1;
    for (int i = 0; i <= two; i += (nums[i] == 1 || i < zero)) {
        switch (nums[i])
        {
        case 0:
            swap(nums[i], nums[zero++]);
            break;
        case 2:
            swap(nums[i], nums[two--]);
            break;
        default:
            break;
        }
    }
}