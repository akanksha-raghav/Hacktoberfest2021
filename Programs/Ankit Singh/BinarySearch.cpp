#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums, int &target) {
    int l = -1, int r = nums.size(), m;
    while(r > l + 1) {
        m = (l + r) / 2;
        if(a[m] >= target) r = m;
        else l = m;
    }

    return r;
}

int main() {
    vector<int> nums = {1, 2, 2, 5, 6, 9, 11};
    int target = 6;
    cout << binarySearch(nums, target) << "\n";
    
    return 0;
}