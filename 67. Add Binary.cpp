#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string addBinary(string a, string b) {
    if (a.size() < b.size()) {
        swap(a, b);
    }
    int index = a.size() - 1;
    for (int i = b.size() - 1; i > 0; i--) {
        int temp = a[index] - '0';
        temp += (b[i] - '0');
        int carray = temp / 2;
        temp %= 2;
        a[index] = temp + '0';
        // to avoid index-1, plus carray in the first step of the loop
        a[--index] += carray;
    }
    int carray = b[0] - '0';
    while (index >= 0) {
        int temp = a[index] - '0' + carray;
        carray = temp / 2;
        temp %= 2;
        a[index] = temp + '0';
        index--;
    }
    if (carray) {
        a.insert(a.begin(), carray + '0');
    }
    return a;
}