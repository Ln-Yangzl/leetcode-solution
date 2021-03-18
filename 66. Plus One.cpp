#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    digits.back()++;
    for (int i = digits.size() - 1; i > 0;i--){
        digits[i - 1] += digits[i] / 10;
        digits[i] %= 10;
    }
    if(digits[0]>9){
        digits[0] %= 10;
        digits.insert(digits.begin(), 1);
    }
    return digits;
}