#include <iostream>
#include <vector>
#include <climits> // for INT_MAX

using namespace std;

int minSubArraySum(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int min_ending_here = nums[0];
    int min_so_far = nums[0];

    for (int i = 1; i < n; ++i) {
        min_ending_here = min(nums[i], min_ending_here + nums[i]);
        min_so_far = min(min_so_far, min_ending_here);
    }

    return min_so_far;
}

int main() {
    vector<int> nums = {3, -4, 2, -3, -1, 7, -5}; // Example input
    cout << "Minimum subarray sum is " << minSubArraySum(nums) << endl;
    return 0;
}
